#include "../s21_string.h"
#include "stdlib.h"

void *s21_to_upper(const char *str) {
  if (!str) return S21_NULL;

  s21_size_t strLen = s21_strlen(str);
  char *temp = malloc(strLen + 1);
  if (!temp)
    temp = S21_NULL;
  else {
    for (s21_size_t i = 0; i < strLen; i++)
      temp[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];

    temp[strLen] = '\0';
  }
  return temp;
}