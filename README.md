# String

The **String** project is an implementation of the standard `string.h` library in the C programming language with additional support for `sprintf` functions and special functions for string processing.

## Contents

1. [Library Features](#library-features)
    - [Basic string.h functions](#basic-stringh-functions)
    - [Sprintf Functions](#sprintf-functions)
    - [Special string handling functions](#special-string-handling-functions)
2. [Requirements](#requirements)
3. [Build](#build)
4. [Use](#use)
5. [Testing](#testing)

## Library Features

#### Basic string.h functions

The library includes implementations of functions from the standard `string.h` such as:

| № | Function | Description |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| 4 | void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| 5 | char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| 6	| char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| 7 | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| 8 | char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| 9 | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| 10 | char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives. |
| 11 | size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| 12 | char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| 13 | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| 14 | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| 15 | char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |

- All basic `string.h` functions are supported.
- Source, header and assembly files are located in the `src/` directory.


### sprintf functions

The library includes an implementation of `sprintf` functions with formatting support:

| Function | Function | Description |
| --------- | -------- |
| `sprintf` | formats a string according to a template and writes the result to `str`. | |

Supported specifiers for `sprintf`:

| No. | Specifier | sprintf output | sscanf output |
| --- | --- | --- | --- |
| 1 | c | Character | Character |
| 2 | d | Signed decimal integer | Signed decimal integer |
| 3 | i | Signed decimal integer | Signed integer (may be decimal, octal or hexadecimal) |
| 4 | e | Scientific notation (mantissa/exponent) using e character (the output of the numbers must match up to e-6) | Decimal floating point or scientific notation (mantissa/exponent) |
| 5 | E | Scientific notation (mantissa/exponent) using E character | Decimal floating point or scientific notation (mantissa/exponent) |
| 6 | f | Decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 7 | o | Unsigned octal | Unsigned octal |
| 8 | s | String of characters | String of characters |
| 9 | u | Unsigned decimal integer | Unsigned decimal integer |
| 10 | x | Unsigned hexadecimal integer | Unsigned hexadecimal integer (any letters) |
| 11 | X | Unsigned hexadecimal integer (capital letters) | Unsigned hexadecimal integer (any letters) |
| 12 | p | Pointer address | Pointer address |
| 13 | n | Number of characters printed until %n occurs | Number of characters scanned until %n occurs |
| 14 | % | Character % | Character % |

Supported flags for `sprintf`:

| No. | Flags | Description |
| --- | --- | --- |
| 1 | - | Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
| 2 | + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| 3 | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4 | # | Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed. |
| 5 | 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |

Supported Width for `sprintf`:

| No. |	Width | Description |
| --- | --- | --- |
| 1	| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| 2 | * | In sprintf the * sign means, that the width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. In sscanf the * sign placed after % and before the format specifier reads data of the specified type, but suppresses their assignment. |

Supported Precision for `sprintf`:

| No. |	.precision | Description |
| --- | --- | --- |
| 1	| .number | For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers − this is the number of digits to be printed after the decimal point. For g and G specifiers − This is the maximum number of significant digits to be printed. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified for specifiers e, E, f, g and G, the default one is 6. When no precision is specified for all other kind of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| 2	| .* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

Supported Length for `sprintf`:

| No. |	Length | Description |
| --- | --- | --- |
| 1 | h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X). |
| 2 | l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s. |
| 3 | L | The argument is interpreted as a long double (only applies to floating point specifiers − e, E, f, g and G). |

The `sprintf` functions support partial and full formatting, including specifiers, flags, width and precision.

### Special string handling functions

Additional functions for string processing, inspired by the `String` class in C#:

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *to_upper(const char *str) | Returns a copy of string (str) converted to uppercase. In case of any error, return NULL |
| 2 | void *to_lower(const char *str) | Returns a copy of string (str) converted to lowercase. In case of any error, return NULL |
| 3 | void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL |
| 4 | void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL |

- Special functions help extend string processing capabilities by adding convenient conversion and modification methods.

## Requirements

Program Requirements:
- Language: C (standard C11)
- Compiler: GCC (GNU Compiler Collection)
- Build system: Makefile

## Build

1. Cloning the repository:

```bash
git clone https://github.com/llllenivka/String.git
cd s21_string_plus
```

2. Build the library using the Makefile:

```bash
make all
```

3. To clean up all compiled files:

```bash
make clean
```

4. To create a coverage report:

```bash
make gcov_report
```

## Use

Example usage of s21_string:

```c
#include “s21_string.h”
int main() {
    char str[100];
    s21_sprintf(str, “Example number: %d”, 42);
    printf(“%s\n”, str);
    char *upper = s21_to_upper(“example”);
    printf(“Upper case: %s\n”, upper);
    free(upper);
    return 0;
}
```

## Testing
Run tests for the library using the command:
```bash
make test
```
The tests check the implementation of each function in s21_string, comparing the results with the original string.h library.