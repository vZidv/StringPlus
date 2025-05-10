#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *state = S21_NULL;
  char *result = S21_NULL;

  if (str != S21_NULL) state = str;

  if (state != S21_NULL && *state != '\0') {
    s21_size_t len = s21_strcspn(state, delim);

    if (len > 0) {
      result = state;
      state += len;

      if (*state != '\0') {
        *state = '\0';
        state++;
      }
    } else {
      state++;
      result = s21_strtok(S21_NULL, delim);
    }
  }

  return result;
}