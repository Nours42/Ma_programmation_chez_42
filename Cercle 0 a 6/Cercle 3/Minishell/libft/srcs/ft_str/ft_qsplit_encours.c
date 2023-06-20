/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsplit_encours.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:42:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/20 17:32:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

typedef struct s_string_info
{
	char	original_string[MAX_STRING_LENGTH];
	int		num_words;
	char	**words;
	int		*word_start_indices;
	int		*word_lengths;
	int		num_and_operators;
	int		*and_operator_indices;
	int		num_or_operators;
	int		*or_operator_indices;
}				t_string_info;

typedef struct s_process
{
	int		word_start_index;
	int		word_length;
	int		in_escape;
	int		in_and_operator;
	int		in_or_operator;
	int		in_double_quotes;
	int		in_single_quotes;
	int		i;
	int		string_length;
	char	current_char;
}				t_process;

void	init_string_info(char *input_string, t_string_info *info)
{
	int	string_length;

	ft_strcpy(info->original_string, input_string);
	info->num_words = 0;
	info->num_and_operators = 0;
	info->num_or_operators = 0;
	string_length = ft_strlen(input_string);
	info->words = malloc(sizeof(char *) * string_length);
	info->word_start_indices = malloc(sizeof(int) * string_length);
	info->word_lengths = malloc(sizeof(int) * string_length);
	info->and_operator_indices = malloc(sizeof(int) * string_length);
	info->or_operator_indices = malloc(sizeof(int) * string_length);
}

void	add_word_to_string(t_string_info *info, int start_idx, int length)
{
	info->words[info->num_words] = malloc(sizeof(char) * (length + 1));
	ft_strncpy(info->words[info->num_words],
		info->original_string + start_idx, length);
	info->words[info->num_words][length] = '\0';
	info->word_start_indices[info->num_words] = start_idx;
	info->word_lengths[info->num_words] = length;
	info->num_words++;
}

void	init_p_process(char *input_string, t_string_info *info, t_process *p)
{
	p->i = 0;
	p->string_length = ft_strlen(input_string);
	p->in_escape = 0;
	p->in_and_operator = 0;
	p->in_or_operator = 0;
	p->in_double_quotes = 0;
	p->in_single_quotes = 0;
	p->word_start_index = -1;
	p->word_length = 0;
	init_string_info(input_string, info);
}

void	handle_operator(int i, t_string_info *info, t_process *p)
{
	if (i == 0)
	{
		p->in_and_operator = 1;
		info->and_operator_indices[info->num_and_operators] = p->i;
	}
	else if (i == 1)
		p->in_or_operator = 1;
	else if (i == 2)
		p->in_or_operator = 1;
	else if (i == 3)
	{
		p->in_and_operator = 0;
		info->num_and_operators++;
	}
	else if (i == 4)
	{
		p->in_or_operator = 0;
		info->num_or_operators++;
	}
	if (i == 0 || i == 1)
		p->i++;
	if (i == 1 || i == 2)
		info->or_operator_indices[info->num_or_operators] = p->i;
}

// add_word_to _string est simplifiable

void	process_char(char c_char, char *i_s, t_string_info *info, t_process *p)
{
	if (c_char == '\\' && !p->in_escape)
		p->in_escape = 1;
	else if (p->in_escape)
		p->in_escape = 0;
	else
	{
		if (c_char == ' ' && !p->in_and_operator && !p->in_or_operator
			&& !p->in_double_quotes && !p->in_single_quotes
			&& p->word_start_index != -1)
		{
			add_word_to_string(info, p->word_start_index, p->word_length);
			p->word_start_index = -1;
			p->word_length = 0;
		}
		else if (c_char == '&' && p->i + 1 < p->string_length
			&& i_s[p->i + 1] == '&' && !p->in_and_operator && !p->in_or_operator
			&& !p->in_double_quotes && !p->in_single_quotes)
			handle_operator(0, info, p);
		else if (c_char == '|' && p->i + 1 < p->string_length
			&& i_s[p->i + 1] == '|' && !p->in_and_operator && !p->in_or_operator
			&& !p->in_double_quotes && !p->in_single_quotes)
			handle_operator(1, info, p);
		else if (c_char == '|' && !p->in_and_operator && !p->in_or_operator
			&& !p->in_double_quotes && !p->in_single_quotes)
			handle_operator(2, info, p);
		else if (c_char == '"' && !p->in_escape && !p->in_single_quotes)
			p->in_double_quotes = !p->in_double_quotes;
		else if (c_char == '\'' && !p->in_escape && !p->in_double_quotes)
			p->in_single_quotes = !p->in_single_quotes;
		else
		{
			if (p->in_and_operator && c_char != '&')
				handle_operator(3, info, p);
			else if (p->in_or_operator && c_char != '|')
				handle_operator(4, info, p);
			if (c_char != ' ' || p->in_double_quotes || p->in_single_quotes)
			{
				if (p->word_start_index == -1)
					p->word_start_index = p->i;
				p->word_length++;
			}
		}
	}
}

void	process_string(char *input_string, t_string_info *info)
{
	char		current_char;
	t_process	p;

	init_p_process(input_string, info, &p);
	while (p.i < p.string_length)
	{
		current_char = input_string[p.i];
		process_char(current_char, input_string, info, &p);
		p.i++;
	}
	if (p.word_start_index != -1)
		add_word_to_string(info, p.word_start_index, p.word_length);
}

/*void	freet_string_info(t_string_info *info)
{
	int	i;

	i = -1;
	while (i++ < info->num_words)
		free(info->words[i]);
	free(info->words);
	free(info->word_start_indices);
	free(info->word_lengths);
	free(info->and_operator_indices);
	free(info->or_operator_indices);
}

void	printt_string_info(t_string_info *info)
{
	int	i;

	i = 0;
	printf("Original String: %s\n", info->original_string);
	printf("Words:\n");
	while (i < info->num_words)
	{
		printf("  %d: \"%s\" (Start Index: %d, Length: %d)\n",
			i, info->words[i], info->word_start_indices[i],
			info->word_lengths[i]);
		i++;
	}
	printf("&& Operators (%d):\n", info->num_and_operators);
	i = 0;
	while (i < info->num_and_operators)
	{
		printf("  %d: Index: %d\n", i, info->and_operator_indices[i]);
		i++;
	}
	printf("| Operators (%d):\n", info->num_or_operators);
	i = 0;
	while (i < info->num_or_operators)
	{
		printf("  %d: Index: %d\n", i, info->or_operator_indices[i]);
		i++;
	}
}

int	main(void)
{
	char			*input_string;
	t_string_info	info;

	input_string = "word1 && word2 | word3 word4 && 'word5 | \"word6 word7";
	process_string(input_string, &info);
	printt_string_info(&info);
	freet_string_info(&info);
	return (0);
}*/
