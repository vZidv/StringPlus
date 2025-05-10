#include "../s21_helpers.h"

void s21_setSettings(s21_specificatorSettings **settings, const char **format) {
  while (**format == '-' || **format == '+' || **format == '#' ||
         **format == '0' || **format == ' ' || **format == 'h' ||
         **format == 'l' || **format == 'L') {
    switch (**format) {
      case '-':
        (*settings)->aligmentLeft = true;
        break;
      case '+':
        (*settings)->signNumber = true;
        break;
      case '#':
        (*settings)->lattice = true;
        break;
      case '0':
        (*settings)->zeroFilling = true;
        break;
      case ' ':
        (*settings)->spaceFlag = true;
        break;
      case 'h':
        (*settings)->lenghModificator = 'h';
        break;
      case 'l':
        (*settings)->lenghModificator = 'l';
        break;
      case 'L':
        (*settings)->lenghModificator = 'L';
        break;
    }
    (*format)++;
  }
}

void s21_setWidthAndAccuracy(const char **format,
                             s21_specificatorSettings **settings,
                             va_list args) {
  (*settings)->accuracy = 0;

  while (**format != '\0' && **format != '%' &&
         (**format < 'a' || **format > 'z') &&
         (**format < 'A' || **format > 'Z')) {
    if (**format == '.') {
      (*settings)->isAccuracy = true;
      (*format)++;
    }
    int number = 0;

    if (**format == '*') {
      int valInt = va_arg(args, int);

      if (!((*settings)->isAccuracy))
        (*settings)->size =
            (valInt < 0) ? (s21_size_t)(-valInt) : (s21_size_t)valInt;
      else
        (*settings)->accuracy = (valInt < 0) ? 0 : (s21_size_t)valInt;

      (*format)++;
    } else {
      while (*(*format) >= 48 && *(*format) <= 57)
        number = number * 10 + ((*(*format)++) - '0');

      if (!((*settings)->isAccuracy))
        (*settings)->size = number;
      else
        (*settings)->accuracy = number;
    }
  }
}

long long s21_strToLongLong(char *str) {
  if (str == S21_NULL) return 0;

  int signVal = 1;

  if (*str == '+')
    str++;
  else if (*str == '-') {
    signVal = -1;
    str++;
  }

  long long result = 0;
  while (*str != '\0') {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result * signVal;
}

s21_size_t s21_intToOctal(unsigned int value, char *buffer, int accuracy) {
  if (value == 0) {
    buffer[0] = '0';
    return 1;
  }

  char tempBuffer[256];
  s21_size_t index = 0;

  while (value != 0 || index < (s21_size_t)accuracy) {
    tempBuffer[index++] = (value % 8) + '0';
    value /= 8;
  }

  tempBuffer[index] = '\0';
  s21_reverseStr(tempBuffer);

  s21_memcpy(buffer, tempBuffer, index);

  return index;
}

char *s21_reverseStr(char *str) {
  s21_size_t index = s21_strlen(str);
  for (s21_size_t i = 0; i < index / 2; i++) {
    char temp = str[index - i - 1];
    str[index - i - 1] = str[i];
    str[i] = temp;
  }
  return str;
}

unsigned long long s21_strToDecimal(char *str, int system) {
  unsigned long long result = 0;
  int isNegative = 1;
  int digit;

  if (system < 2 || system > 36 || str == S21_NULL) return 0;

  if (*str == '-') {
    isNegative = -1;
    str++;
  }
  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
    str += 2;
  }

  for (; *str != '\0'; str++) {
    if (*str >= '0' && *str <= '9')
      digit = *str - '0';
    else if (*str >= 'a' && *str <= 'z')
      digit = *str - 'a' + 10;
    else if (*str >= 'A' && *str <= 'Z')
      digit = *str - 'A' + 10;
    else
      continue;

    if (digit >= system) {
      result = 0;
      break;
    }

    result = result * system + digit;
  }
  return result * isNegative;
}
