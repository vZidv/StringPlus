#ifndef S21_HELPERS_H
#define S21_HELPERS_H

#include <math.h>
#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  bool aligmentLeft;
  bool signNumber;
  bool lattice;
  bool zeroFilling;
  bool isAccuracy;
  bool spaceFlag;

  s21_size_t subStrLen;
  s21_size_t size;
  s21_size_t accuracy;

  char lenghModificator;

} s21_specificatorSettings;

void s21_setWidthAndAccuracy(const char **format,
                             s21_specificatorSettings **settings, va_list args);
void s21_setSettings(s21_specificatorSettings **settings, const char **format);
s21_size_t s21_intToOctal(unsigned int value, char *buffer, int accuracy);
unsigned long long s21_strToDecimal(char *str, int system);
long long s21_strToLongLong(char *str);
char *s21_reverseStr(char *str);

#endif