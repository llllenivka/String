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
| --- | -------------------------------- | -------- |
| 1 | `memchr(const void *str, int c, size_t n)` | Finds the first occurrence of the character `c` in the first `n` bytes of the string `str`. | |
| 2 | `memcmp(const void *str1, const void *str2, size_t n)` | Comparing the first `n` bytes of `str1` and `str2`. | |
| 3 | `memcpy(void *dest, const void *src, size_t n)` | Copy `n` bytes from `rc` to `dest`. | .
| ... | ...                              | ... |
| 15 | `strtok(char *str, const char *delim)` | Splits the string `str` into tokens separated by `delim`. | |

- All basic `string.h` functions are supported.
- Source, header and assembly files are located in the `src/` directory.


### sprintf functions

The library includes an implementation of `sprintf` functions with formatting support:

| Function | Function | Description |
| --------- | -------- |
| `sprintf` | formats a string according to a template and writes the result to `str`. | |

Supported specifiers for `sprintf`:

| No. | Specifier | Description |
| --- | ----------- | -------- |
| 1 | `%c` | Symbol |
| 2 | `%d` | A signed decimal integer |
| 3 | `%f` | A floating point number |
| 4 | `%s` | Character string |
| ... | ...         | ... |

The `sprintf` functions support partial and full formatting, including specifiers, flags, width and precision.