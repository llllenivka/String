#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_COUNT_ER_L 1
#define MAX_COUNT_ER_L 134

#define MIN_COUNT_ER 1
#define MAX_COUNT_ER 106

#define s21_NULL ((void *)0)
#define S21_POS_INF (1.0 / 0.0)
typedef unsigned long s21_size_t;

typedef struct {
  int c;
  int d;
  int f;
  int s;
  int u;
  int h;
  int l;
  int o;
  int x;
  int X;
  int p;
  int e;
  int E;
  int L;
  int zero;
  int spec_count;
  int plus;
  int minus;
  int width;
  int width_count;
  int dot;
  int precision;
  int precision_count;
  int notation;
  int space;
} Specifiers;

int s21_sprintf(char *str, const char *format, ...);
int spec_in_format(char *str, const char *format, va_list argc, int *count);
Specifiers precision_in_format(const char *format, Specifiers specifiers,
                               char numbers[24], va_list argc);
Specifiers width_in_format(const char *format, Specifiers specifiers,
                           char numbers[24], va_list argc);
Specifiers read_spec(const char *format, Specifiers specifiers);
int input_to_str(char *str, va_list argc, Specifiers specifiers);

int for_char(char *str, va_list argc, Specifiers specifiers);
int for_str(char *str, va_list argc, Specifiers specifiers);
int for_int(char *str, va_list argc, Specifiers specifiers);
int int_num_to_str(char *str, Specifiers specifiers, long int number,
                   long int count);
int for_float(char *str, va_list argc, Specifiers specifiers);
int float_num_to_str(char *str, Specifiers specifiers, double number1,
                     int count_num, int precision);
int for_unsigned_int(char *str, va_list argc, Specifiers specifiers);
int for_o(char *str, va_list argc, Specifiers specifiers);
int for_xX(char *str, va_list argc, Specifiers specifiers);
void uppercase(char *buffer, Specifiers specifiers, int digit, int i);
int for_p(char *str, va_list argc, Specifiers specifiers);
int for_e(char *str, va_list argc, Specifiers specifiers);
int e_num_to_str(char *str, Specifiers specifiers, double number, int len,
                 char *buffer);

int width_to_str(char *str, Specifiers specifiers);
int precision_for_int(char *str, int count_num, Specifiers specifiers);

/*--------------ФУНКЦИИ--------------*/

void *s21_memchr(const void *str, int c,
                 s21_size_t n);  // Выполняет поиск первого вхождения символа c
                                 // (беззнаковый тип) в первых n байтах строки,
                                 // на которую указывает аргумент str.
int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n);  //Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src,
                 size_t n);  // Копирует n символов из src в dest.
void *s21_memset(
    void *str, int c,
    s21_size_t n);  //Копирует символ c (беззнаковый тип) в первые n
                    //символов строки, на которую указывает аргумент str.
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(
    const char *str,
    int c);  //Выполняет поиск первого вхождения символа c (беззнаковый
             //тип) в строке, на которую указывает аргумент str.
int s21_strncmp(const char *str1, const char *str2,
                size_t n);  // Сравнивает не более первых n байтов str1 и str2.
char *s21_strncpy(char *dest, const char *src,
                  size_t n);  //Копирует до n символов из строки, на которую
                              //указывает src, в dest. (куда, откуда).
size_t s21_strcspn(
    const char *str1,
    const char
        *str2);  //Вычисляет длину начального сегмента str1, который состоит из
                 //символов, не входящих в str2. (где искать, что искать)
char *s21_strerror(int errnum);  //  ошибки
size_t s21_strlen(const char *str);  // Вычисляет длину строки str, не включая
                                     // завершающий нулевой символ.
char *s21_strpbrk(
    const char *str1,
    const char *str2);  //Находит первый символ в строке str1, который
                        //соответствует любому символу, указанному в str2.
char *s21_strrchr(
    const char *str,
    int c);  //Выполняет поиск последнего вхождения символа c (беззнаковый тип)
             //в строке, на которую указывает аргумент str.
char *s21_strstr(
    const char *haystack,
    const char *needle);  //Находит первое вхождение всей строки needle
                          //(не включая завершающий нулевой символ),
                          //которая появляется в строке haystack.
char *s21_strtok(char *str, const char *delim);  //Разбивает строку str на ряд
                                                 //токенов, разделенных delim.

/*--------------ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ--------------*/
void *s21_to_upper(const char *str);  //Возвращает копию строки (str),
                                      //преобразованной в верхний регистр.
void *s21_to_lower(const char *str);  //Возвращает копию строки (str),
                                      //преобразованной в нижний регистр.
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

/*---------------------функция для error---------------------*/
char *s21_strcpy(char *dst, const char *src);

/*---------------------функция для спецификатора-------------*/
char *s21_strcat(char *destination, const char *append);

#endif
