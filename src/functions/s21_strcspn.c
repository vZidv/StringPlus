#include <stdbool.h>

#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str, const char *reject) {
  if (str == S21_NULL || reject == S21_NULL) return 0;

  bool lookup[256] = {false};
  for (const char *p = reject; *p != '\0'; p++)
    lookup[(unsigned char)*p] = true;

  s21_size_t count = 0;
  for (const char *p = str; *p != '\0'; p++) {
    if (lookup[(unsigned char)*p]) break;
    count++;
  }
  return count;
}