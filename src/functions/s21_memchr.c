#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (str == S21_NULL) return S21_NULL;

  void *result = S21_NULL;

  const unsigned char *byte_ptr = (const unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    if (byte_ptr[i] == (unsigned char)c) {
      result = (void *)(byte_ptr + i);
      break;
    }
  }

  return result;
}
