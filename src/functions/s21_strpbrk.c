#include <stdbool.h>

#include "../s21_string.h"

char *s21_strpbrk(const char *str, const char *delim) {
  if (str == S21_NULL || delim == S21_NULL) return S21_NULL;

  char *result = S21_NULL;

  bool lookup[256] = {false};
  for (const char *p = delim; *p != '\0'; p++) lookup[(unsigned char)*p] = true;

  for (const char *p = str; *p != '\0'; p++) {
    if (lookup[(unsigned char)*p]) {
      result = (char *)p;
      break;
    }
  }

  return result;
}