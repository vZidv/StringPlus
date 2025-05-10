#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest == S21_NULL || src == S21_NULL) return S21_NULL;

  s21_size_t catStart = s21_strlen(dest);
  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++)
    dest[catStart + i] = src[i];

  dest[catStart + n] = '\0';
  return dest;
}