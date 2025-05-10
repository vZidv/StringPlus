#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;

  char *result = S21_NULL;
  char *strFind = (char *)&str[s21_strlen(str)];
  do {
    if (*strFind == c) {
      result = (char *)strFind;
      break;
    }
  } while (strFind-- != str);

  return result;
}
