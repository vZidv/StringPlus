#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str == S21_NULL) return S21_NULL;

  unsigned char *strCh = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) *strCh++ = (unsigned char)c;
  return str;
}
