# String

Проект **String** представляет собой реализацию стандартной библиотеки `string.h` на языке программирования C с дополнительной поддержкой функций `sprintf` и специальных функций для обработки строк.

## Оглавление

1. [Особенности библиотеки](#особенности-библиотеки)
    - [Основные функции string.h](#основные-функции-stringh)
    - [Функции sprintf](#функции-sprintf)
    - [Специальные функции обработки строк](#специальные-функции-обработки-строк)
2. [Требования](#требования)
3. [Сборка](#сборка)
4. [Использование](#использование)
5. [Тестирование](#тестирование)

## Особенности библиотеки

### Основные функции string.h

Библиотека включает реализацию функций из стандартной `string.h`, таких как:

| № | Функция                           | Описание |
| --- | -------------------------------- | -------- |
| 1   | `memchr(const void *str, int c, size_t n)` | Поиск первого вхождения символа `c` в первых `n` байтах строки `str`. |
| 2   | `memcmp(const void *str1, const void *str2, size_t n)` | Сравнение первых `n` байтов `str1` и `str2`. |
| 3   | `memcpy(void *dest, const void *src, size_t n)` | Копирование `n` байтов из `src` в `dest`. |
| ... | ...                              | ... |
| 15  | `strtok(char *str, const char *delim)` | Разбивает строку `str` на токены, разделенные `delim`. |

- Поддерживаются все основные функции `string.h`.
- Исходные, заголовочные и сборочные файлы располагаются в директории `src/`.

### Функции sprintf

Библиотека включает реализацию функций `sprintf` с поддержкой форматирования:

| Функция   | Описание |
| --------- | -------- |
| `sprintf` | Форматирует строку по шаблону и записывает результат в `str`. |

Поддерживаемые спецификаторы для `sprintf`:

| № | Спецификатор | Описание |
| --- | ----------- | -------- |
| 1   | `%c`        | Символ |
| 2   | `%d`        | Знаковое десятичное целое число |
| 3   | `%f`        | Число с плавающей точкой |
| 4   | `%s`        | Строка символов |
| ... | ...         | ... |

Функции `sprintf` поддерживают частичное и полное форматирование, включая спецификаторы, флаги, ширину и точность.

### Специальные функции обработки строк

Дополнительные функции для обработки строк, вдохновленные классом `String` в C#:

| Функция                     | Описание |
| --------------------------- | -------- |
| `to_upper(const char *str)` | Преобразует строку `str` в верхний регистр. |
| `to_lower(const char *str)` | Преобразует строку `str` в нижний регистр. |
| `insert(const char *src, const char *str, size_t start_index)` | Вставляет строку `str` в `src` на позицию `start_index`. |
| `trim(const char *src, const char *trim_chars)` | Удаляет указанные символы `trim_chars` в начале и конце строки `src`. |

- Специальные функции помогают расширить возможности обработки строк, добавляя удобные методы преобразования и модификации.

## Требования

Требования к программе:
- Язык: C (стандарт C11)
- Компилятор: GCC (GNU Compiler Collection)
- Система сборки: Makefile

## Сборка

1. Клонирование репозитория:

```bash
git clone https://github.com/username/s21_string_plus.git
cd s21_string_plus
```

2. Сборка библиотеки с помощью Makefile:

```bash
make all
```

3. Для очистки всех скомпилированных файлов:

```bash
make clean
```

4. Для создания отчета покрытия:

```bash
make gcov_report
```

## Использование

Пример использования s21_string:
```c
#include "s21_string.h"

int main() {
    char str[100];
    s21_sprintf(str, "Пример числа: %d", 42);
    printf("%s\n", str);

    char *upper = s21_to_upper("пример");
    printf("Верхний регистр: %s\n", upper);
    free(upper);

    return 0;
}
```
## Тестирование

Запуск тестов для библиотеки осуществляется командой:

```bash
make test
```
Тесты проверяют реализацию каждой функции в s21_string, сравнивая результаты с оригинальной библиотекой string.h.