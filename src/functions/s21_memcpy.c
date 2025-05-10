#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest == S21_NULL || src == S21_NULL) return S21_NULL;

  unsigned char *destCh = dest;
  const unsigned char *srcCh = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) *destCh++ = *srcCh++;

  return dest;
}