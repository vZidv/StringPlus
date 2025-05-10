#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const unsigned char *str1Ch = (const unsigned char *)str1;
  const unsigned char *str2Ch = (const unsigned char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    result = *str1Ch++ - *str2Ch++;
    if (result != 0) break;
  }

  return result;
}