#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "../s21_helpers.h"
#include "../s21_string.h"

s21_size_t s21_readString_wchar(const char **src, wchar_t *arg,
                                s21_specificatorSettings *settings);
s21_size_t s21_readString(const char **str, char *arg,
                          s21_specificatorSettings *settings);
long double s21_parseExponential(char *str);
long double s21_strToDouble(char *str);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int result = 0;

  while (*format) {
    if (*format == '%') {
      format++;

      s21_specificatorSettings *settings =
          calloc(1, sizeof(s21_specificatorSettings));
      if (!settings)
        result = 0;
      else {
        s21_setSettings(&settings, &format);

        s21_setWidthAndAccuracy(&format, &settings, args);

        switch (*format) {
          case 'c': {
            void *arg = S21_NULL;
            int width = (settings->size > 0) ? settings->size : 1;

            if (settings->lenghModificator == 'l') {
              wchar_t *warg = va_arg(args, wchar_t *);
              for (int i = 0; i < width && *str != '\0'; i++) {
                mbtowc(warg++, str, MB_CUR_MAX);
                str += mblen(str, MB_CUR_MAX);
              }
              arg = warg;
            } else {
              char *carg = va_arg(args, char *);
              s21_strncpy(carg, str, width);
              str += width;
              arg = carg;
            }

            if (arg != S21_NULL) result++;

            free(settings);

            break;
          } break;
          case 's': {
            void *arg = S21_NULL;
            s21_size_t len = 0;
            if (settings->lenghModificator != 'l') {
              arg = va_arg(args, char *);
              len = s21_readString(&str, arg, settings);
            } else {
              arg = va_arg(args, wchar_t *);
              len = s21_readString_wchar(&str, arg, settings);
            }

            if (len > 0) result++;

            free(settings);
          } break;
          case 'd': {
            char *subSting = malloc(12 * sizeof(char));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;

              switch (settings->lenghModificator) {
                case 'h':
                  arg = va_arg(args, short *);
                  *(short *)arg = (short)s21_strToLongLong(subSting);
                  break;
                case 'l':
                  arg = va_arg(args, long *);
                  *(long *)arg = (long)s21_strToLongLong(subSting);
                  break;
                case 'L':
                  arg = va_arg(args, long long *);
                  *(long long *)arg = s21_strToLongLong(subSting);
                  break;

                default:
                  arg = va_arg(args, int *);
                  *(int *)arg = (int)s21_strToLongLong(subSting);
                  break;
              }

              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'f': {
            char *subSting = malloc(5 * sizeof(double));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;

              switch (settings->lenghModificator) {
                case 'l':
                  arg = va_arg(args, double *);
                  *(double *)arg = (double)s21_strToDouble(subSting);
                  break;
                case 'L':
                  arg = va_arg(args, long double *);
                  *(long double *)arg = (long double)s21_strToDouble(subSting);
                  break;
                default:
                  arg = va_arg(args, float *);
                  *(float *)arg = (float)s21_strToDouble(subSting);

                  break;
              }

              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'u': {
            char *subSting = malloc(11 * sizeof(char));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;

              switch (settings->lenghModificator) {
                case 'h':
                  arg = va_arg(args, unsigned short *);
                  *(unsigned short *)arg =
                      (unsigned short)s21_strToLongLong(subSting);
                  break;
                case 'l':
                  arg = va_arg(args, unsigned long *);
                  *(unsigned long *)arg =
                      (unsigned long)s21_strToLongLong(subSting);
                  break;
                case 'L':
                  arg = va_arg(args, unsigned long *);
                  *(unsigned long long *)arg =
                      (unsigned long long)s21_strToLongLong(subSting);
                  break;
                default:
                  arg = va_arg(args, unsigned int *);
                  *(unsigned int *)arg =
                      (unsigned int)s21_strToLongLong(subSting);

                  break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);

            break;
          }
          case 'x': {
            char *subSting = malloc(11 * sizeof(char));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;

              switch (settings->lenghModificator) {
                case 'h':
                  arg = va_arg(args, unsigned short *);
                  *(unsigned short *)arg =
                      (unsigned short)s21_strToDecimal(subSting, 16);
                  break;
                case 'l':
                  arg = va_arg(args, unsigned long *);
                  *(unsigned long *)arg =
                      (unsigned long)s21_strToDecimal(subSting, 16);
                  break;
                default:
                  arg = va_arg(args, unsigned int *);
                  *(unsigned int *)arg =
                      (unsigned int)s21_strToDecimal(subSting, 16);
                  break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'X': {
            char *subSting = malloc(11 * sizeof(char));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;

              switch (settings->lenghModificator) {
                case 'h':
                  arg = va_arg(args, unsigned short *);
                  *(unsigned short *)arg =
                      (unsigned short)s21_strToDecimal(subSting, 16);
                  break;
                case 'l':
                  arg = va_arg(args, unsigned long *);
                  *(unsigned long *)arg =
                      (unsigned long)s21_strToDecimal(subSting, 16);
                  break;
                default:
                  arg = va_arg(args, unsigned int *);
                  *(unsigned int *)arg =
                      (unsigned int)s21_strToDecimal(subSting, 16);
                  break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'o': {
            char *subSting = malloc(11 * sizeof(char));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;

              switch (settings->lenghModificator) {
                case 'h':
                  arg = va_arg(args, unsigned short *);
                  *(unsigned short *)arg =
                      (unsigned short)s21_strToDecimal(subSting, 8);
                  break;
                case 'l':
                  arg = va_arg(args, unsigned long *);
                  *(unsigned long *)arg =
                      (unsigned long)s21_strToDecimal(subSting, 8);
                  break;
                default:
                  arg = va_arg(args, unsigned int *);
                  *(unsigned int *)arg =
                      (unsigned int)s21_strToDecimal(subSting, 8);
                  break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'p': {
            char *original_ptr = malloc(32 * sizeof(char));
            if (!original_ptr) result = 0;

            {
              char *subSting = original_ptr;
              s21_size_t len = s21_readString(&str, subSting, settings);

              if (s21_strncmp(subSting, "0x", 2) == 0 ||
                  s21_strncmp(subSting, "0X", 2) == 0) {
                subSting += 2;
              }

              void **arg = va_arg(args, void **);
              unsigned long long num = s21_strToDecimal(subSting, 16);
              *arg = (void *)num;

              free(original_ptr);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'g': {
            char *subSting = malloc(128 * sizeof(char));
            if (!subSting)
              result = 0;
            else {
              s21_size_t len = s21_readString(&str, subSting, settings);

              bool isExponential = (s21_strchr(subSting, 'e') != S21_NULL) ||
                                   (s21_strchr(subSting, 'E') != S21_NULL);

              switch (settings->lenghModificator) {
                case 'L': {
                  long double *arg = va_arg(args, long double *);
                  *arg = isExponential
                             ? (long double)s21_parseExponential(subSting)
                             : (long double)s21_strToDouble(subSting);
                } break;
                case 'l': {
                  double *arg = va_arg(args, double *);
                  *arg = isExponential ? (double)s21_parseExponential(subSting)
                                       : (double)s21_strToDouble(subSting);
                } break;
                default: {
                  float *arg = va_arg(args, float *);
                  *arg = isExponential ? (float)s21_parseExponential(subSting)
                                       : (float)s21_strToDouble(subSting);
                } break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'G': {
            char *subSting = malloc(128 * sizeof(char));
            if (!subSting)
              result = 0;
            else

            {
              s21_size_t len = s21_readString(&str, subSting, settings);

              bool isExponential = (s21_strchr(subSting, 'e') != S21_NULL) ||
                                   (s21_strchr(subSting, 'E') != S21_NULL);

              switch (settings->lenghModificator) {
                case 'L': {
                  long double *arg = va_arg(args, long double *);
                  *arg = isExponential
                             ? (long double)s21_parseExponential(subSting)
                             : (long double)s21_strToDouble(subSting);
                } break;
                case 'l': {
                  double *arg = va_arg(args, double *);
                  *arg = isExponential ? (double)s21_parseExponential(subSting)
                                       : (double)s21_strToDouble(subSting);
                } break;
                default: {
                  float *arg = va_arg(args, float *);
                  *arg = isExponential ? (float)s21_parseExponential(subSting)
                                       : (float)s21_strToDouble(subSting);
                } break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'e': {
            char *subSting = malloc(40 * sizeof(char));
            if (!subSting) result = 0;
            {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;
              switch (settings->lenghModificator) {
                case 'L':
                  arg = va_arg(args, long double *);
                  *(long double *)arg =
                      (long double)s21_parseExponential(subSting);
                  break;
                case 'l':
                  arg = va_arg(args, double *);
                  *(double *)arg = (double)s21_parseExponential(subSting);
                  break;
                default:
                  arg = va_arg(args, float *);
                  *(float *)arg = (float)s21_parseExponential(subSting);
                  break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case 'E': {
            char *subSting = malloc(40 * sizeof(char));
            if (!subSting) result = 0;

            {
              s21_size_t len = s21_readString(&str, subSting, settings);

              void *arg = S21_NULL;
              switch (settings->lenghModificator) {
                case 'L':
                  arg = va_arg(args, long double *);
                  *(long double *)arg =
                      (long double)s21_parseExponential(subSting);
                  break;
                case 'l':
                  arg = va_arg(args, double *);
                  *(double *)arg = (double)s21_parseExponential(subSting);
                  break;
                default:
                  arg = va_arg(args, float *);
                  *(float *)arg = (float)s21_parseExponential(subSting);
                  break;
              }
              free(subSting);

              if (len > 0) result++;
            }
            free(settings);
          } break;
          case '%': {
            char *arg = va_arg(args, char *);
            if (arg != NULL) {
              *arg = '%';
              str++;
              result++;
            }
            free(settings);
          } break;
        }
      }
    } else
      format++;
  }

  va_end(args);
  return result;
}

s21_size_t s21_readString(const char **str, char *arg,
                          s21_specificatorSettings *settings) {
  if (!str || !arg) return 0;

  while (*(*str) == ' ') (*str)++;

  s21_size_t len = 0;
  while (*(*str) != ' ' && *(*str) != '\0' &&
         (settings->size <= 0 || len < settings->size))
    arg[len++] = *(*str)++;

  arg[len] = '\0';

  return len;
}

s21_size_t s21_readString_wchar(const char **src, wchar_t *arg,
                                s21_specificatorSettings *settings) {
  if (!src || !*src || !arg) return 0;

  const char *str = *src;
  s21_size_t wide_len = 0;

  while (*str == ' ') str++;

  while (*str != '\0' && *str != ' ' &&
         (settings->size <= 0 || wide_len < settings->size)) {
    wchar_t wc;
    int mb_len = mbtowc(&wc, str, MB_CUR_MAX);

    if (mb_len <= 0) break;

    *arg++ = wc;
    wide_len++;
    str += mb_len;
  }

  *arg = L'\0';
  *src = str;

  return wide_len;
}

long double s21_strToDouble(char *str) {
  long double result = 0.0;
  int signVal = 1;

  char mantis[s21_strlen(str) + 1];

  s21_size_t index = 0;
  while (*str != '\0' && *str != '.') mantis[index++] = *str++;

  mantis[index] = '\0';
  if (mantis[0] == '-') signVal = -1;

  result += s21_strToLongLong(mantis) * signVal;

  if (*str == '.') {
    str++;

    char decimalPart[s21_strlen(str) + 1];

    index = 0;
    while (*str != '\0') decimalPart[index++] = *str++;

    decimalPart[index] = '\0';
    int exponent = s21_strlen(decimalPart) * -1;

    result += pow(10, exponent) * s21_strToLongLong(decimalPart);
  }

  return result * signVal;
}

long double s21_parseExponential(char *str) {
  long double result = 0.0;
  char subString[40];
  s21_size_t index = 0;

  while (*str != 'e' && *str != 'E' && *str != '\0')
    subString[index++] = *str++;

  subString[index] = '\0';

  result = s21_strToDouble(subString);
  if (*str == 'e' || *str == 'E') {
    str++;

    int exponentSign = 1;
    if (*str == '+')
      str++;
    else if (*str == '-') {
      exponentSign = -1;
      str++;
    }

    int exponent = (int)s21_strToLongLong(str);

    result *= pow(10, exponent * exponentSign);
  }
  return result;
}
