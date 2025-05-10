#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == S21_NULL || needle == S21_NULL) return S21_NULL;

  char *result = S21_NULL;
  if (*needle == '\0')
    result = (char *)haystack;
  else {
    const char *h = haystack;
    const char *n = needle;

    while (*h != '\0') {
      const char *h_ptr = h;
      const char *n_ptr = n;

      while (*h_ptr == *n_ptr && *n_ptr != '\0') {
        h_ptr++;
        n_ptr++;
      }

      if (*n_ptr == '\0') {
        result = (char *)h;
        break;
      }

      h++;
    }
  }

  return result;
}
