#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_helpers.h"
#include "../s21_string.h"

s21_size_t s21_intToHex(s21_size_t value, char *buffer,
                        s21_specificatorSettings *settings, bool uppercase);
s21_size_t s21_formatG(double value, char *buffer,
                       s21_specificatorSettings **settings, bool uppercase);
s21_size_t s21_doubleToStr(double value, char *buffer,
                           s21_specificatorSettings **settings);
s21_size_t s21_intToStr(int value, char *buffer,
                        s21_specificatorSettings *settings);
s21_size_t s21_unIntToStr(unsigned int value, char *buffer, int accuracy);
s21_size_t s21_pointToString(void *ptr, char *buffer,
                             s21_specificatorSettings *settings);
void s21_formatString(s21_specificatorSettings **settings, char **subString,
                      char **buffer, const char **format, int *result);
void s21_enterSubString(char **buffer, char *subString, s21_size_t subStrLen,
                        const char **format, int *result);
void s21_toExponential(double value, char *buffer,
                       s21_specificatorSettings **settings, bool uppercase);
void s21_alignmenSubString(s21_specificatorSettings **settings,
                           char **subString);

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int result = 0;

  while (*format != '\0') {
    if (*format == '%') {
      format++;

      char *subString;

      s21_specificatorSettings *settings =
          calloc(1, sizeof(s21_specificatorSettings));
      if (!settings)
        result = 1;
      else {
        s21_setSettings(&settings, &format);

        s21_setWidthAndAccuracy(&format, &settings, args);

        switch (*format) {
          case 'c': {
            subString = malloc(sizeof(char));

            if (subString == NULL)
              result = 1;
            else {
              subString[0] = (char)va_arg(args, int);
              settings->subStrLen = 1;

              s21_alignmenSubString(&settings, &subString);
              s21_enterSubString(&buffer, &subString[0], settings->subStrLen,
                                 &format, &result);
              free(subString);
              subString = S21_NULL;
            }
            free(settings);

          } break;
          case 's': {
            char *str = va_arg(args, char *);
            s21_size_t strLen = s21_strlen(str);

            if (settings->isAccuracy)
              settings->subStrLen =
                  (strLen < settings->accuracy) ? strLen : settings->accuracy;
            else
              settings->subStrLen = strLen;

            subString = calloc(settings->subStrLen + 1, sizeof(char));

            if (subString == NULL)
              result = 1;
            else {
              s21_strncpy(subString, str, settings->subStrLen);
              subString[settings->subStrLen] = '\0';

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'd': {
            int valInt = va_arg(args, int);
            subString = calloc(1024 + settings->accuracy, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              s21_intToStr(valInt, subString, settings);
              settings->subStrLen = s21_strlen(subString);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'f': {
            double valDouble = va_arg(args, double);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              s21_doubleToStr(valDouble, subString, &settings);

              settings->subStrLen = s21_strlen(subString);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'u': {
            unsigned int valInt = (va_arg(args, unsigned int));
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              s21_unIntToStr(valInt, subString, settings->accuracy);
              settings->subStrLen = s21_strlen(subString);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'x': {
            unsigned int valInt = va_arg(args, unsigned int);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              settings->subStrLen =
                  s21_intToHex(valInt, subString, settings, false);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'X': {
            unsigned int valInt = va_arg(args, unsigned int);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              settings->subStrLen =
                  s21_intToHex(valInt, subString, settings, true);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'o': {
            unsigned int valInt = va_arg(args, unsigned int);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              if (settings->lattice) {
                s21_strncpy(subString, "0", 2);
                settings->subStrLen =
                    s21_intToOctal(valInt, subString + 1, settings->accuracy) +
                    1;
              } else {
                settings->subStrLen =
                    s21_intToOctal(valInt, subString, settings->accuracy);
              }

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'p': {
            void *ptr = va_arg(args, void *);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              settings->subStrLen = s21_pointToString(ptr, subString, settings);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'g': {
            double valDouble = va_arg(args, double);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              settings->subStrLen =
                  s21_formatG(valDouble, subString, &settings, false);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'G': {
            double valDouble = va_arg(args, double);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              settings->subStrLen =
                  s21_formatG(valDouble, subString, &settings, true);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'e': {
            double valDouble = va_arg(args, double);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              s21_toExponential(valDouble, subString, &settings, false);
              settings->subStrLen = s21_strlen(subString);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case 'E': {
            double valDouble = va_arg(args, double);
            subString = calloc(256, sizeof(char));

            if (subString == S21_NULL)
              result = 1;
            else {
              s21_toExponential(valDouble, subString, &settings, true);
              settings->subStrLen = s21_strlen(subString);

              s21_formatString(&settings, &subString, &buffer, &format,
                               &result);
            }
            free(settings);
          } break;
          case '%': {
            buffer[result++] = '%';
            format++;
            free(settings);
            continue;
          } break;
        }
      }
    } else
      buffer[result++] = *format++;
  }

  buffer[result] = '\0';

  va_end(args);
  return result;
}

void s21_enterSubString(char **buffer, char *subString, s21_size_t subStrLen,
                        const char **format, int *result) {
  s21_strncat(*buffer, subString, subStrLen);

  *result += subStrLen;
  (*format)++;
}

void s21_formatString(s21_specificatorSettings **settings, char **subString,
                      char **buffer, const char **format, int *result) {
  s21_alignmenSubString(&(*settings), &(*subString));
  s21_enterSubString(&(*buffer), (*subString), (*settings)->subStrLen,
                     &(*format), &(*result));
  free(*subString);
  (*subString) = S21_NULL;
}

void s21_alignmenSubString(s21_specificatorSettings **settings,
                           char **subString) {
  if ((*settings)->size < (*settings)->subStrLen) return;

  s21_size_t padding = (*settings)->size - (*settings)->subStrLen;
  char *temp = malloc(((*settings)->size + 1) * sizeof(char));

  if (!temp) {
    *subString = S21_NULL;
    free(*subString);
    return;
  }

  s21_memset(temp, ' ', (*settings)->size);
  temp[(*settings)->size] = '\0';

  if ((*settings)->aligmentLeft) {
    s21_strncpy(temp, *subString, (*settings)->subStrLen);
    s21_memset(temp + (*settings)->subStrLen, ' ', padding);
  } else {
    if ((*settings)->zeroFilling && !((*settings)->isAccuracy)) {
      char sign = 0;

      if ((*subString)[0] == '+' || (*subString)[0] == '-')
        sign = (*subString)[0];

      s21_memset(temp, '0', (*settings)->size);

      if (sign != 0) {
        temp[0] = sign;
        s21_strncpy(temp + 1 + padding, *subString + 1,
                    (*settings)->subStrLen - 1);
      } else {
        s21_strncpy(temp + padding, *subString, (*settings)->subStrLen);
      }
    } else {
      s21_memset(temp, ' ', padding);
      s21_strncpy(temp + padding, *subString, (*settings)->subStrLen);
    }
  }
  free(*subString);
  *subString = temp;
  (*settings)->subStrLen = (*settings)->size;
}

s21_size_t s21_doubleToStr(double value, char *buffer,
                           s21_specificatorSettings **settings) {
  if (!(*settings)->isAccuracy) {
    (*settings)->accuracy = 6;
    (*settings)->lattice = false;
  }

  double factor = pow(10, (*settings)->accuracy + 1.0);
  double scaled = (value * factor) / 10.0;
  scaled = round(scaled) / pow(10, (*settings)->accuracy);

  double intPartD;
  double fractionalPart = modf(scaled, &intPartD);
  int intPart = (int)intPartD;

  if (fractionalPart < 0) {
    fractionalPart = -fractionalPart;
    intPart = -intPart;
  }

  if (fractionalPart < 0) fractionalPart = -fractionalPart;
  s21_size_t result = 0;
  s21_specificatorSettings *setForInt =
      calloc(1, sizeof(s21_specificatorSettings));
  if (!setForInt)
    result = -1;
  else {
    s21_memcpy(setForInt, *settings, sizeof(s21_specificatorSettings));
    setForInt->accuracy = 0;

    s21_size_t index = s21_intToStr(intPart, buffer, setForInt);
    free(setForInt);

    if ((*settings)->accuracy > 0) {
      buffer[index++] = '.';

      fractionalPart *= pow(10, (*settings)->accuracy);
      long long fractionalDigits = (long long)round(fractionalPart);

      for (s21_size_t i = 0; i < (*settings)->accuracy; i++) {
        buffer[index + (*settings)->accuracy - i - 1] =
            '0' + (fractionalDigits % 10);
        fractionalDigits /= 10;
      }

      index += (*settings)->accuracy;
    } else if ((*settings)->lattice) {
      buffer[index++] = '.';
    }

    buffer[index] = '\0';
    result = index;
  }

  return result;
}

s21_size_t s21_formatG(double value, char *buffer,
                       s21_specificatorSettings **settings, bool uppercase) {
  if (buffer == S21_NULL || settings == S21_NULL || *settings == S21_NULL)
    return 0;

  if (!(*settings)->isAccuracy) (*settings)->accuracy = 6;

  char tempBuffer[256] = {0};
  int exponent = (value == 0) ? 0 : (int)floor(log10(fabs(value)));
  bool useExponential =
      (exponent < -4 || exponent >= (int)((*settings)->accuracy));

  if (useExponential) {
    (*settings)->accuracy =
        (*settings)->accuracy > 0 ? (*settings)->accuracy - 1 : 0;
    (*settings)->isAccuracy = true;

    s21_toExponential(value, tempBuffer, &(*settings), uppercase);
  } else {
    (*settings)->accuracy =
        (s21_size_t)((*settings)->accuracy - exponent - 1 > 0)
            ? (*settings)->accuracy - exponent - 1
            : 0;
    (*settings)->isAccuracy = true;

    s21_doubleToStr(value, tempBuffer, &(*settings));
  }

  char *dot = s21_strchr(tempBuffer, '.');
  if (dot) {
    char *end = tempBuffer + s21_strlen(tempBuffer) - 1;
    while (end > dot && *end == '0') *end-- = '\0';
    if (end == dot) *dot = '\0';
  }

  s21_strncpy(buffer, tempBuffer, s21_strlen(tempBuffer));
  buffer[s21_strlen(tempBuffer)] = '\0';

  return s21_strlen(buffer);
}

s21_size_t s21_intToHex(s21_size_t value, char *buffer,
                        s21_specificatorSettings *settings, bool uppercase) {
  if (value == 0) {
    buffer[0] = '0';
    return 1;
  }
  const unsigned char *hexChar =
      (const unsigned char *)(uppercase ? "0123456789ABCDEF"
                                        : "0123456789abcdef");
  char tempBuffer[256];
  s21_size_t index = 0;

  while (value != 0 || index < (s21_size_t)settings->accuracy) {
    unsigned int temp = (value % 16);
    value /= 16;

    tempBuffer[index++] = hexChar[temp];
  }

  if (settings->zeroFilling && index < settings->size) {
    while (index != settings->size) tempBuffer[index++] = '0';
    if (settings->lattice) tempBuffer[index - 2] = 'x';
  } else if (settings->lattice) {
    tempBuffer[index++] = uppercase ? 'X' : 'x';
    tempBuffer[index++] = '0';
  }

  tempBuffer[index] = '\0';

  s21_reverseStr(tempBuffer);
  s21_memcpy(buffer, tempBuffer, index);

  return index;
}

s21_size_t s21_intToStr(int value, char *buffer,
                        s21_specificatorSettings *settings) {
  bool isNegative = false;
  s21_size_t index = 0;

  if (value < 0) {
    isNegative = true;
    value *= -1;
  }
  do {
    buffer[index++] = (char)(value % 10) + '0';
    value = value / 10;
  } while (value != 0);

  while (index < settings->accuracy) buffer[index++] = '0';

  if (isNegative)
    buffer[index++] = '-';
  else if (!isNegative && settings->signNumber)
    buffer[index++] = '+';
  else if (!isNegative && settings->spaceFlag)
    buffer[index++] = ' ';

  buffer[index] = '\0';

  s21_reverseStr(buffer);
  return index;
}

s21_size_t s21_pointToString(void *ptr, char *buffer,
                             s21_specificatorSettings *settings) {
  if (ptr == S21_NULL) {
    s21_strncat(buffer, "(nil)", 5);
    return 5;
  }
  s21_size_t address = (s21_size_t)ptr;
  char tempBuffer[256];

  s21_size_t addressLen = 0;

  if (settings->signNumber)
    tempBuffer[addressLen++] = '+';
  else if (settings->spaceFlag)
    tempBuffer[addressLen++] = ' ';

  tempBuffer[addressLen++] = '0';
  tempBuffer[addressLen++] = 'x';

  addressLen += s21_intToHex(address, &tempBuffer[addressLen], settings, false);

  s21_memcpy(buffer, tempBuffer, addressLen);
  return addressLen;
}

s21_size_t s21_unIntToStr(unsigned int value, char *buffer, int accuracy) {
  s21_size_t index = 0;
  do {
    buffer[index++] = (char)(value % 10) + '0';
    value = value / 10;
  } while (value != 0);

  while (index < (s21_size_t)accuracy) buffer[index++] = '0';

  buffer[index] = '\0';

  s21_reverseStr(buffer);
  return index;
}

void s21_toExponential(double value, char *buffer,
                       s21_specificatorSettings **settings, bool uppercase) {
  if (!(*settings)->isAccuracy) (*settings)->accuracy = 6;

  if (isnan(value)) {
    s21_sprintf(buffer, uppercase ? "NAN" : "nan");
    return;
  }
  if (isinf(value)) {
    s21_sprintf(buffer, value < 0 ? "-%s" : "%s", uppercase ? "INF" : "inf");
    return;
  }

  int exponent = (value == 0) ? 0 : (int)floor(log10(fabs(value)));
  double mantisa = value / pow(10, exponent);

  if (mantisa >= 10.0) {
    mantisa /= 10.0;
    exponent += 1;
  }

  char *temp = buffer;
  if ((*settings)->signNumber && value > 0) {
    *buffer = '+';
    temp++;
  } else if ((*settings)->spaceFlag) {
    *buffer = ' ';
    temp++;
  }

  char expChar = uppercase ? 'E' : 'e';

  if ((*settings)->lattice && (*settings)->accuracy == 0)
    s21_sprintf(temp, "%.*f.%c%+03d", (int)((*settings)->accuracy), mantisa,
                expChar, exponent);
  else
    s21_sprintf(temp, "%.*f%c%+03d", (int)((*settings)->accuracy), mantisa,
                expChar, exponent);
}