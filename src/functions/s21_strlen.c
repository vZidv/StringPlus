#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  if (str == S21_NULL) return 0;

  s21_size_t count = 0;

  while (str[count] != '\0') count++;

  return count;
}