#include "s21_string.h"
int s21_sprintf(char *str, const char *format, ...) {
  va_list argc;  //указывает на список аргументов переменной длины(там где у нас
                 //точки короче)
  va_start(argc, format);  // argc принимает след аргумент после format
  int result = 0;
  while (*format) {
    if (*format == '%') {
      int count = 0;
      int format_count = spec_in_format(str, format, argc, &count);
      format += count;
      result += format_count;
      str += format_count;
      *str = '\0';
    } else {
      *str = *format;
      str++;
      *str = '\0';
      result++;
    }
    format++;
  }
  va_end(argc);
  return result;
}

int spec_in_format(char *str, const char *format, va_list argc, int *count) {
  int result = 0;
  Specifiers specifiers = {0};
  specifiers.precision = -1;
  while (specifiers.spec_count != 1) {
    format++;
    *count = *count + 1;
    char numbers[24] = "*0123456789";
    if (*format == ' ')
      specifiers.space = 1;
    else if (*format == '#')
      specifiers.notation += 1;
    else if (*format == '0' && specifiers.width_count == 0 &&
             specifiers.precision_count == 0) {
      specifiers.zero += 1;
    } else if (s21_strrchr(numbers, *format)) {
      if (!specifiers.dot)
        specifiers = width_in_format(format, specifiers, numbers, argc);
      else
        specifiers = precision_in_format(format, specifiers, numbers, argc);

    } else if (*format == '.') {
      specifiers.dot += 1;
    } else {
      specifiers = read_spec(format, specifiers);
      result += input_to_str(str, argc, specifiers);
      str += result;
    }
  }
  return result;
}

Specifiers precision_in_format(const char *format, Specifiers specifiers,
                               char numbers[24], va_list argc) {
  if (specifiers.precision_count > 0)
    specifiers.precision *= 10;
  else
    specifiers.precision = 0;
  specifiers.precision_count++;
  char *array = s21_strrchr(numbers, *format);
  int num = 0;
  if (*array == '*') {
    num = (int)va_arg(argc, int);
  } else {
    num = (int)array[0] - 48;
  }
  specifiers.precision += num;
  return specifiers;
}

Specifiers width_in_format(const char *format, Specifiers specifiers,
                           char numbers[24], va_list argc) {
  specifiers.width *= 10;
  specifiers.width_count++;
  int num = 0;
  char *array = s21_strrchr(numbers, *format);
  if (*array == '*') {
    num = (int)va_arg(argc, int);
  } else {
    num = (int)array[0] - 48;
  }
  if (num == 0 && specifiers.width_count == 1) specifiers.width = 0;
  specifiers.width += num;
  return specifiers;
}

Specifiers read_spec(const char *format, Specifiers specifiers) {
  switch (*format) {
    case 'c':
      specifiers.c += 1;
      specifiers.spec_count += 1;
      break;
    case 'd':
      specifiers.d += 1;
      specifiers.spec_count += 1;
      break;
    case 'f':
      specifiers.f += 1;
      specifiers.spec_count += 1;
      break;
    case 's':
      specifiers.s += 1;
      specifiers.spec_count += 1;
      break;
    case 'u':
      specifiers.u += 1;
      specifiers.spec_count += 1;
      break;
    case 'o':
      specifiers.o += 1;
      specifiers.spec_count += 1;
      break;
    case 'x':
      specifiers.x += 1;
      specifiers.spec_count += 1;
      break;
    case 'X':
      specifiers.X += 1;
      specifiers.spec_count += 1;
      break;
    case 'p':
      specifiers.p += 1;
      specifiers.spec_count += 1;
      break;
    case 'e':
      specifiers.e += 1;
      specifiers.spec_count += 1;
      break;
    case 'E':
      specifiers.E += 1;
      specifiers.spec_count += 1;
      break;
    case 'h':
      specifiers.h += 1;
      break;
    case 'l':
      specifiers.l += 1;
      break;
    case 'L':
      specifiers.L += 1;
      break;
    case '-':
      specifiers.minus += 1;
      break;
    case '+':
      specifiers.plus += 1;
      break;
    default:
      break;
  }
  return specifiers;
}

int input_to_str(char *str, va_list argc, Specifiers specifiers) {
  int result = 0;
  if (specifiers.c) {
    result = for_char(str, argc, specifiers);
  } else if (specifiers.d) {
    result = for_int(str, argc, specifiers);
  } else if (specifiers.s) {
    result = for_str(str, argc, specifiers);
  } else if (specifiers.f) {
    result = for_float(str, argc, specifiers);
  } else if (specifiers.u) {
    result = for_unsigned_int(str, argc, specifiers);
  } else if (specifiers.o) {
    result = for_o(str, argc, specifiers);
  } else if (specifiers.x || specifiers.X) {
    result = for_xX(str, argc, specifiers);
  } else if (specifiers.p) {
    result = for_p(str, argc, specifiers);
  } else if (specifiers.e || specifiers.E) {
    result = for_e(str, argc, specifiers);
  }

  return result;
}

int for_char(char *str, va_list argc, Specifiers specifiers) {
  int result = 0;
  char sym = (char)va_arg(argc, int);

  for (int i = 1; i <= 2; i++) {
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= 1;
      result += width_to_str(str, specifiers);
      str += result;
      specifiers.width = 0;
    } else {
      specifiers.minus -= 1;
      *str = sym;
      str++;
      *str = '\0';
      result += 1;
      if (specifiers.width == 0) i++;
    }
  }
  return result;
}

int for_str(char *str, va_list argc, Specifiers specifiers) {
  int result = 0;
  char *buff_str = va_arg(argc, char *);
  int len = s21_strlen(buff_str);
  if (specifiers.precision != -1 && len - specifiers.precision > 0) {
    len = specifiers.precision;
  }
  for (int i = 1; i <= 2; i++) {
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= len;
      if (specifiers.precision > -1 && len != 0)
        specifiers.width -= specifiers.precision - len;
      result += width_to_str(str, specifiers);
      str += result;
      specifiers.width = 0;
    } else {
      while (len-- > 0) {
        specifiers.minus -= 1;
        *str = *buff_str;
        buff_str++;
        str++;
        result++;
        if (specifiers.width == 0) i++;
      }
    }
  }
  return result;
}

int for_int(char *str, va_list argc, Specifiers specifiers) {
  long int number = 0;

  if (specifiers.l) {
    number = (long int)va_arg(argc, long int);
  }
  if (specifiers.h) {
    number = (short int)va_arg(argc, int);
  }
  if (!specifiers.l && !specifiers.h) {
    number = va_arg(argc, int);
  }
  int result = 0, count = 0;
  long int buff_num = number;
  if (number != 0) {
    while (buff_num != 0) {
      buff_num /= 10;
      count++;
    }
  } else
    count++;
  result += int_num_to_str(str, specifiers, number, count);
  return result;
}

int int_num_to_str(char *str, Specifiers specifiers, long int number,
                   long int count) {
  int result = 0, flag = 0;
  if (specifiers.zero || specifiers.minus || specifiers.width < 1) flag = 1;
  for (int i = 1; i <= 2; i++) {
    if ((number < 0 || specifiers.plus || specifiers.space) && flag == 1) {
      if (number < 0)
        *str = '-';
      else if (specifiers.plus)
        *str = '+';
      else if (specifiers.space)
        *str = ' ';
      if (number < 0 || specifiers.plus || specifiers.space) {
        str++;
        result++;
        if (specifiers.precision != -1) specifiers.precision += 1;
      }
      flag = 0;
    }
    if (specifiers.width > 0 && specifiers.minus != 1) {
      if (number < 0 || specifiers.plus || specifiers.space)
        specifiers.width -= 1;
      specifiers.width -= count;
      if (specifiers.precision != -1)
        specifiers.width -= specifiers.precision - count;
      int m = width_to_str(str, specifiers);
      result += m;
      str += m;
      specifiers.width = 0;
      if (specifiers.zero == 0) flag = 1;
    } else {
      if (specifiers.precision_count > 0 && !specifiers.f && !specifiers.zero) {
        if (number < 0 || specifiers.plus) result--;
        int n = precision_for_int(str, count, specifiers);
        result += n;
        str += n;
        if (number < 0 || specifiers.plus) str--;
      }
      if (number < 0) number *= -1;
      for (int del = pow(10, count - 1); del != 0; del /= 10) {
        int num = number / del;
        *str = num + 48;
        str++;
        result++;
        number = number % del;
        if (specifiers.width == 0) i++;
        specifiers.minus -= 1;
      }
    }
  }
  return result;
}

int for_float(char *str, va_list argc, Specifiers specifiers) {
  int result = 0, count_num = 0;
  long double number1;
  if (specifiers.L)
    number1 = va_arg(argc, long double);
  else
    number1 = va_arg(argc, double);
  int buff_num = (int)number1;
  int precision = 6;
  if (specifiers.precision > 0) {
    precision = specifiers.precision;
  }
  if (buff_num != 0) {
    while (buff_num != 0) {
      buff_num /= 10;
      count_num++;
    }
  } else
    count_num++;
  result += float_num_to_str(str, specifiers, number1, count_num, precision);
  str += result;
  return result;
}

int float_num_to_str(char *str, Specifiers specifiers, double number1,
                     int count_num, int precision) {
  int result = 0, flag = 0;
  int buff_num = (int)number1;
  if (specifiers.zero || specifiers.minus || specifiers.width < 1) flag = 1;
  for (int i = 1; i <= 2; i++) {
    if ((number1 < 0 || specifiers.plus || specifiers.space) && flag == 1) {
      if (number1 < 0)
        *str = '-';
      else if (specifiers.plus && number1 > -1)
        *str = '+';
      else if (specifiers.space && number1 > -1)
        *str = ' ';
      if (number1 < 0 || specifiers.plus || specifiers.space) {
        str++;
        result++;
        if (specifiers.precision != -1) specifiers.precision += 1;
      }
      flag = 0;
    }
    if (specifiers.width && specifiers.minus != 1) {
      specifiers.width -= count_num + precision + 1;
      if (precision == 0) specifiers.width++;
      if (buff_num < 0 || specifiers.plus || specifiers.space)
        specifiers.width--;
      int n = width_to_str(str, specifiers);
      result += n;
      str += n;
      specifiers.width = 0;
      if (specifiers.zero == 0) flag = 1;
    } else {
      if (number1 < 0) number1 *= -1;
      int n = s21_sprintf(str, "%d", (int)number1);
      result += n;
      str += n;
      long double number2 = (number1 - (int)number1);
      if (specifiers.precision != -1 || specifiers.precision_count == 0) {
        *str = '.';
        str++;
        result++;
        if (number2 < 0) number2 *= -1;
        for (int i = 0; i < precision; i++) {
          number2 *= 10;
          if (i == precision - 1 && (int)(number2 * 10) % 10 > 5) number2++;
          s21_sprintf(str, "%d", (int)number2);
          result++;
          str++;
          number2 -= (int)number2;
        }
      }
      if (specifiers.width == 0) i++;
      specifiers.minus -= 1;
    }
  }
  return result;
}

int for_unsigned_int(char *str, va_list argc, Specifiers specifiers) {
  unsigned long int number = 0;
  if (specifiers.l) {
    number = (unsigned long int)va_arg(argc, unsigned long int);
  }
  if (specifiers.h) {
    number = (unsigned short int)va_arg(argc, unsigned int);
  }
  if (!specifiers.l && !specifiers.h) {
    number = va_arg(argc, unsigned int);
  }
  int result = 0, count = 0;
  unsigned int buff_num = number;
  if (number != 0) {
    while (buff_num != 0) {
      buff_num /= 10;
      count++;
    }
  } else
    count++;
  for (int i = 1; i <= 2; i++) {
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= count;
      if (specifiers.precision > -1)
        specifiers.width -= specifiers.precision - count;
      int n = width_to_str(str, specifiers);
      result += n;
      str += n;
      specifiers.width = 0;
    } else {
      if (specifiers.precision > 0 && !specifiers.f) {
        int m = precision_for_int(str, count, specifiers);
        result += m;
        str += m;
      }
      for (int del = pow(10, count - 1); del != 0; del /= 10) {
        int num = number / del;
        *str = num + 48;
        str++;
        result++;
        number = number % del;
        if (specifiers.width == 0) i++;
        specifiers.minus -= 1;
      }
    }
  }
  return result;
}

int for_o(char *str, va_list argc, Specifiers specifiers) {
  int result = 0, len = 0;
  unsigned int value = (unsigned int)va_arg(argc, unsigned int);
  unsigned int temp = value;
  do {
    len++;
    temp /= 8;
  } while (temp != 0);
  char *buffer = (char *)calloc((len + 1), sizeof(char));
  int flag = 0;
  if (specifiers.zero || specifiers.minus || specifiers.width < 1) flag = 1;
  for (int j = 1; j <= 2; j++) {
    if (specifiers.notation > 0 && flag == 1) {
      *str = '0';
      str++;
      result++;
      flag = 0;
    }
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= len;
      if (specifiers.notation) specifiers.width--;
      if (specifiers.precision > -1)
        specifiers.width -= specifiers.precision - len;
      int n = width_to_str(str, specifiers);
      result += n;
      str += n;
      specifiers.width = 0;
      if (specifiers.zero == 0) flag = 1;
    } else {
      if (specifiers.precision_count > 0) {
        int n = precision_for_int(str, len, specifiers);
        result += n;
        str += n;
      }
      for (int i = len - 1; i >= 0; --i) {
        int digit = value % 8;
        buffer[i] = '0' + digit;
        value /= 8;
      }
      if (specifiers.width == 0) j++;
      specifiers.minus -= 1;
      s21_strcat(str, buffer);
      str += len;
    }
  }
  free(buffer);
  return len + result;
}

int for_xX(char *str, va_list argc, Specifiers specifiers) {
  int result = 0, len = 0, flag = 0;
  unsigned int value = (unsigned int)va_arg(argc, unsigned int);
  unsigned int temp = value;
  if (specifiers.zero || specifiers.minus || specifiers.width < 1) flag = 1;
  do {
    len++;
    temp /= 16;
  } while (temp != 0);
  char *buffer = (char *)calloc((len + 1), sizeof(char));
  for (int j = 1; j <= 2; j++) {
    if (specifiers.notation > 0 && flag == 1) {
      if (specifiers.x)
        s21_strcat(str, "0x");
      else
        s21_strcat(str, "0X");
      str += 2;
      result += 2;
      flag = 0;
    }
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= len;
      if (specifiers.notation > 0) specifiers.width -= 2;
      if (specifiers.precision > -1)
        specifiers.width -= specifiers.precision - len;
      int n = width_to_str(str, specifiers);
      result += n;
      str += n;
      specifiers.width = 0;
      if (specifiers.zero == 0) flag = 1;
    } else {
      if (specifiers.precision_count > 0 && !specifiers.f) {
        int n = precision_for_int(str, len, specifiers);
        result += n;
        str += n;
      }
      for (int i = len - 1; i >= 0; --i) {
        int digit = value % 16;
        uppercase(buffer, specifiers, digit, i);
        value /= 16;
      }
      if (specifiers.width == 0) j++;
      specifiers.minus -= 1;
      s21_strcat(str, buffer);
      str += len;
    }
  }
  free(buffer);
  return len + result;
}

int for_p(char *str, va_list argc, Specifiers specifiers) {
  int result = 0;
  int len = 0;
  unsigned long long value =
      (unsigned long long)va_arg(argc, unsigned long long);
  unsigned long long temp = value;
  do {
    len++;
    temp /= 16;
  } while (temp != 0);
  char *buffer = (char *)calloc((len + 3), sizeof(char));
  for (int j = 1; j <= 2; j++) {
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= len + 2;
      result += width_to_str(str, specifiers);
      str += result;
      specifiers.width = 0;
    } else {
      buffer[0] = '0';
      buffer[1] = 'x';
      for (int i = len + 1; i >= 2; i--) {
        int digit = value % 16;
        if (digit < 10) {
          buffer[i] = '0' + digit;
        } else {
          buffer[i] = 'a' + digit - 10;
        }
        value /= 16;
      }
      specifiers.minus -= 1;
      s21_strcat(str, buffer);
      str += len;
      if (specifiers.width == 0) j++;
    }
  }
  free(buffer);
  return len + result + 2;
}

void uppercase(char *buffer, Specifiers specifiers, int digit, int i) {
  if (digit < 10) {
    buffer[i] = '0' + digit;
  } else {
    if (specifiers.X) {
      buffer[i] = 'A' + digit - 10;
    } else {
      buffer[i] = 'a' + digit - 10;
    }
  }
}

int for_e(char *str, va_list argc, Specifiers specifiers) {
  int result = 0, exponent = 0, len = 0;
  double number = (double)va_arg(argc, double);
  char buffer[10000] = {0};
  int flag = 0;
  if (specifiers.precision == -1) specifiers.precision = 6;
  if (number != number) {
    if (specifiers.e)
      result = s21_sprintf(buffer, "nan");
    else
      result = s21_sprintf(buffer, "NAN");
    flag = 1;
  } else if (number != 0) {
    exponent = floor(log10(fabs(number)));
    number /= pow(10, exponent);
  }
  if (flag != 1) {
    if (S21_POS_INF == number) {
      if (specifiers.e)
        result = s21_sprintf(buffer, "nan");
      else
        result = s21_sprintf(buffer, "NAN");
      flag = 1;
    } else if (specifiers.e)
      len = s21_sprintf(buffer, "%.*fe%+03d", specifiers.precision,
                        fabs(number), exponent);
    else
      len = s21_sprintf(buffer, "%.*fE%+03d", specifiers.precision,
                        fabs(number), exponent);
  }

  result += e_num_to_str(str, specifiers, number, len, buffer);
  return result;
}

int e_num_to_str(char *str, Specifiers specifiers, double number, int len,
                 char *buffer) {
  int result = 0, flag = 0;
  if (specifiers.zero || specifiers.minus || specifiers.width < 1) flag = 1;
  for (int i = 1; i <= 2; i++) {
    if ((number < 0 || specifiers.plus || specifiers.space) && flag == 1) {
      if (number < 0)
        *str = '-';
      else if (specifiers.plus)
        *str = '+';
      else if (specifiers.space)
        *str = ' ';
      if (number < 0 || specifiers.plus || specifiers.space) {
        str++;
        result++;
      }
      flag = 0;
    }
    if (specifiers.width > 0 && specifiers.minus != 1) {
      specifiers.width -= len;
      if (number < 0 || specifiers.plus || specifiers.space) specifiers.width--;
      int n = width_to_str(str, specifiers);
      result += n;
      str += n;
      specifiers.width = 0;
      if (specifiers.zero == 0) flag = 1;
    } else {
      result += s21_sprintf(str, "%s", buffer);
      str += len;
      if (specifiers.width == 0) i++;
      specifiers.minus -= 1;
    }
  }
  return result;
}

int width_to_str(char *str, Specifiers specifiers) {
  int result = 0;
  for (; specifiers.width > 0; specifiers.width -= 1) {
    if (specifiers.zero)
      *str = '0';
    else
      *str = ' ';
    str++;
    result++;
  }
  return result;
}

int precision_for_int(char *str, int count_num, Specifiers specifiers) {
  int result = 0;
  specifiers.precision -= count_num;
  while (specifiers.precision > 0) {
    *str = '0';
    str++;
    result++;
    --specifiers.precision;
  }
  return result;
}