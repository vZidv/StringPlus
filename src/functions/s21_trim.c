#include <stdlib.h>

#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;

  if (src && trim_chars) {
    s21_size_t src_len = s21_strlen(src);

    if (src_len > 0) {
      s21_size_t start_index = 0;
      while (start_index < src_len &&
             s21_strchr(trim_chars, src[start_index]) != S21_NULL)
        start_index++;

      s21_size_t end_index = src_len;
      while (end_index > start_index &&
             s21_strchr(trim_chars, src[end_index - 1]) != S21_NULL)
        end_index--;

      s21_size_t new_len = end_index - start_index;

      char *temp_result = malloc(new_len + 1);
      if (temp_result) {
        s21_strncpy(temp_result, &src[start_index], new_len);
        temp_result[new_len] = '\0';
        result = temp_result;
      }
    } else
      result = calloc(1, sizeof(char));
  }

  return result;
}