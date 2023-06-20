#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct s_string_info {
    char original_string[MAX_STRING_LENGTH];
    int num_words;
    char **words;
    int *word_start_indices;
    int *word_lengths;
    int num_and_operators;
    int *and_operator_indices;
    int num_or_operators;
    int *or_operator_indices;
} t_string_info;

typedef struct s_process {
    int word_start_index;
    int word_length;
    int in_escape;
    int in_and_operator;
    int in_or_operator;
    int in_double_quotes;
    int in_single_quotes;
    int i;
    int string_length;
    char current_char;
	int	word_to_ignore;
} t_process;

void init_string_info(char *input_string, t_string_info *info) {
    strcpy(info->original_string, input_string);
    info->num_words = 0;
    info->num_and_operators = 0;
    info->num_or_operators = 0;
    info->words = malloc(sizeof(char *) * MAX_STRING_LENGTH);
    info->word_start_indices = malloc(sizeof(int) * MAX_STRING_LENGTH);
    info->word_lengths = malloc(sizeof(int) * MAX_STRING_LENGTH);
    info->and_operator_indices = malloc(sizeof(int) * MAX_STRING_LENGTH);
    info->or_operator_indices = malloc(sizeof(int) * MAX_STRING_LENGTH);
}

void add_word_to_string(t_string_info *info, int start_idx, int length) {
    info->words[info->num_words] = malloc(sizeof(char) * (length + 1));
    strncpy(info->words[info->num_words], info->original_string + start_idx, length);
    info->words[info->num_words][length] = '\0';
    info->word_start_indices[info->num_words] = start_idx;
    info->word_lengths[info->num_words] = length;
    info->num_words++;
}

void init_p_process(char *input_string, t_string_info *info, t_process *p) {
    p->i = 0;
    p->string_length = strlen(input_string);
    p->in_escape = 0;
    p->in_and_operator = 0;
    p->in_or_operator = 0;
    p->in_double_quotes = 0;
    p->in_single_quotes = 0;
    p->word_start_index = -1;
    p->word_length = 0;
	p->word_to_ignore = 0;
    init_string_info(input_string, info);
}

void handle_operator(int i, t_string_info *info, t_process *p)
{
	if (i == 0)
	{
    	p->in_and_operator = 1;
    	info->and_operator_indices[info->num_and_operators] = p->i;
	}
	else if (i == 1)
	{
		p->in_or_operator = 1;
    	info->or_operator_indices[info->num_or_operators] = p->i;
	}
    p->i++;
}

void process_operator(char c_char, char *i_s, t_string_info *info, t_process *p) {
    if (c_char == '&' && p->i + 1 < p->string_length && i_s[p->i + 1] == '&' &&
        !p->in_and_operator && !p->in_or_operator && !p->in_double_quotes &&
        !p->in_single_quotes)
        handle_and_operator(info, p);
    else if (c_char == '|' && p->i + 1 < p->string_length && i_s[p->i + 1] == '|' &&
        !p->in_and_operator && !p->in_or_operator && !p->in_double_quotes &&
        !p->in_single_quotes)
        handle_or_operator(info, p);
    else if (c_char == '|' && !p->in_and_operator && !p->in_or_operator &&
        !p->in_double_quotes && !p->in_single_quotes)
        handle_or_operator(info, p);
}

void toggle_double_quotes(int i, t_process *p)
{
    if (i == 0)
        p->in_double_quotes = !p->in_double_quotes;
    else if (i == 1)
        p->in_single_quotes = !p->in_single_quotes;
}


void process_double_quotes(char c_char, t_process *p) {
    if (c_char == '"' && !p->in_escape && !p->in_single_quotes)
        toggle_double_quotes(p);
}

void process_single_quotes(char c_char, t_process *p) {
    if (c_char == '\'' && !p->in_escape && !p->in_double_quotes)
        toggle_single_quotes(p);
}

void word_to_string(t_string_info *info, t_process *p) {
    add_word_to_string(info, p->word_start_index, p->word_length);
    p->word_start_index = -1;
    p->word_length = 0;
}

void process_word(char c_char, t_string_info *info, t_process *p) {
    if ((c_char != ' ' && c_char != '&') || p->in_double_quotes || p->in_single_quotes) {
        if (p->word_start_index == -1)
            p->word_start_index = p->i;
        p->word_length++;
    } else if (p->word_start_index != -1) {
        if (c_char == '&' && p->i + 1 < p->string_length && info->original_string[p->i + 1] == '&') {
            // Treat '&&' as an operator, not a word
            p->word_to_ignore = 1;
            p->word_length++;
            p->i++;
        } else {
            word_to_string(info, p);
        }
    }
}

void process_string(char *input_string, t_string_info *info) {
    t_process p;
    init_p_process(input_string, info, &p);

    while (p.i < p.string_length) {
        char current_char = input_string[p.i];
        process_word(current_char, info, &p);
        process_double_quotes(current_char, &p);
        process_single_quotes(current_char, &p);
        process_operator(current_char, input_string, info, &p);
        p.i++;
    }

    if (p.word_start_index != -1)
        word_to_string(info, &p);
}

void free_string_info(t_string_info *info) {
    for (int i = 0; i < info->num_words; i++)
        free(info->words[i]);

    free(info->words);
    free(info->word_start_indices);
    free(info->word_lengths);
    free(info->and_operator_indices);
    free(info->or_operator_indices);
}

void print_string_info(t_string_info *info) {
    printf("Original String: %s\n", info->original_string);
    printf("Words:\n");
    for (int i = 0; i < info->num_words; i++) {
        printf("  %d: \"%s\" (Start Index: %d, Length: %d)\n",
               i, info->words[i], info->word_start_indices[i],
               info->word_lengths[i]);
    }
    printf("&& Operators (%d):\n", info->num_and_operators);
    for (int i = 0; i < info->num_and_operators; i++) {
        printf("  %d: Index: %d\n", i, info->and_operator_indices[i]);
    }
    printf("| Operators (%d):\n", info->num_or_operators);
    for (int i = 0; i < info->num_or_operators; i++) {
        printf("  %d: Index: %d\n", i, info->or_operator_indices[i]);
    }
}

int main(void) {
    char *input_string = "word1 && word2 | word3 word4 && 'word5 | \"word6 word7";
    t_string_info info;

    process_string(input_string, &info);
    print_string_info(&info);
    free_string_info(&info);

    return 0;
}
