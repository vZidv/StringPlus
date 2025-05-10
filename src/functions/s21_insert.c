#include <stdlib.h>

#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t strLen = s21_strlen(str);
  s21_size_t srcLen = s21_strlen(src);

  if (!src || !str || start_index > srcLen) return S21_NULL;

  s21_size_t tempLen = srcLen + strLen;

  char *temp = malloc(tempLen + 1);

  if (!temp)
    temp = S21_NULL;

  else {
    s21_strncpy(temp, src, start_index);
    s21_strncpy(&temp[start_index], str, strLen);
    s21_strncpy(&temp[start_index + strLen], &src[start_index],
                srcLen - start_index);
    temp[tempLen] = '\0';
  }

  return temp;
}