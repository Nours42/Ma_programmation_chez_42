#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>
#include <locale.h>
#include <ctype.h>


/**
 * A list of strings, where each string represents the contents of a file.
 */
typedef struct stringArray
{
  int length;
  char** items;
}             stringArray;

/**
 * @param file_contents A list of strings, where each string represents the contents of a file.
 * @return The contents of the merged file.
 */



int find_name(char *res, char *search, char *insert)
{
  int i;
  int j;
  char *s_cat;

  i = -1;
  j = -1;
  s_cat = 0;
  while(res[++j] != '=')
    s_cat[j] = res[j];
  while (res[++i])
  {
    if (ft_strncmp(res, s_cat, j) == 0)
      return (i);
  }
  return (-1);
}

char* mergeFiles(stringArray file_contents)
{
  int i;
  int j;
  int part;
  char  *res;

  i = -1;
  j = -1;
  res = 0;
  while (++i < file_contents.length)
  {
    part = 0;
    while (file_contents.items[++j])
    {
        if (ft_strncmp(file_contents.items[j], "=", 1) == 0)
          part = 1;
        else if (ft_strncmp(file_contents.items[j], ";", 1) == 0)
          part = 0;
        if (part == 0)
          fprintf(stderr, "0 - %s\n", file_contents.items[j]);
        else if (part == 1)
          fprintf(stderr, "1 - %s\n", file_contents.items[j]);
    }
  }
  return (res);
}

/* Ignore and do not change the code below */

void trySolution(char* merged_file) {
  struct json_object *output_json;
  output_json = json_object_new_string(merged_file);
  printf("%s\n", json_object_to_json_string_ext(output_json, 0));
  json_object_put(output_json);
}

int main () {
  setlocale(LC_ALL, "en_US.UTF-8");
  char *line;
  size_t len = 0;

  line = NULL;
  getline(&line, &len, stdin);
  struct json_object *parsed_json0 = json_tokener_parse(line);
  free(line);
  stringArray file_contents;

  stringArray array = {json_object_array_length(parsed_json0), malloc(sizeof(char*) * array.length)};

  for (int i = 0 ; i < array.length ; i++) {
    struct json_object* json_object_tmp = json_object_array_get_idx(parsed_json0, i);
    char* json_string_tmp2 = malloc(sizeof(char) * (json_object_get_string_len(json_object_tmp) + 1));
    strcpy(json_string_tmp2, json_object_get_string(json_object_tmp));
    array.items[i] = json_string_tmp2;
  }
  file_contents = array;

  json_object_put(parsed_json0);
  char* output = mergeFiles(file_contents);

  trySolution(output);
}
/* Ignore and do not change the code above */
