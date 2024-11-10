
#include "s21_string.h"
// memchr
// memcpy
// memset
// memcmp
// strchr
// ctrncmp
// strncpy
// strlen
// strcspn
// strerror

//подвинуть strlen
void *s21_memchr(const void *str, int c,
                 s21_size_t n) {  // Выполняет поиск первого вхождения символа c
                                  // (беззнаковый тип) в первых n байтах строки,
                                  // на которую указывает аргумент str.
  const unsigned char *s = str;
  unsigned char sym = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    if (s[i] == sym) {
      return (void *)(s + i);
    }
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n) {  // Сравнивает первые n байтов str1 и str2
  char *b1 = (char *)str1;
  char *b2 = (char *)str2;

  int result = 0;

  for (s21_size_t i = 0; i < n && result == 0; i++) {
    if (b1[i] != b2[i]) {
      if (b1[i] > b2[i])
        result = b1[i] - b2[i];
      else
        result = b1[i] - b2[i];
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src,
                 size_t n) {  //Копирует n символов из src в dest.
  char *d = (char *)dest;
  const char *s = (char *)src;
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

void *s21_memset(
    void *str, int c,
    s21_size_t n) {  //Копирует символ c (беззнаковый тип) в первые n
                     //символов строки, на которую указывает аргумент str.
  unsigned char *s = str;
  unsigned char sym = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    s[i] = sym;
  }
  return str;
}

char *s21_strncat(
    char *dest, const char *src,
    s21_size_t n) {  //Добавляет строку, на которую указывает src, в конец
                     //строки, на которую указывает dest, длиной до n символов.
  s21_size_t l = s21_strlen(dest);
  // size_t m = s21_strlen(src);
  for (s21_size_t i = 0; i < n; i++) {
    dest[l + i] = src[i];
  }
  dest[l + n] = '\0';
  return dest;
}

char *s21_strchr(
    const char *str,
    int c) {  // Выполняет поиск первого вхождения символа c (беззнаковый
              // тип) в строке, на которую указывает аргумент str.
  char *p_str = NULL;
  while (*str != '\0' && *str != (char)c) {
    str++;
  }
  if (*str != '\0') p_str = (char *)str;

  return p_str;
  ;
}

int s21_strncmp(const char *str1, const char *str2,
                size_t n) {  // Сравнивает не более первых n байтов str1 и str2.
  const char *s1 = str1;
  const char *s2 = str2;
  int result = 0;
  for (size_t i = 0; i < n; i++) {
    if (s1[i] != s2[i] || (s1[i] == '\0' || s2[i] == '\0')) {
      result = s1[i] - s2[i];
      break;
    }
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src,
                  size_t n) {  //Копирует до n символов из строки, на которую
                               //указывает src, в dest. (куда, откуда)
  char *d = dest;
  const char *s = src;
  size_t i = 0;
  // int result = 0;
  for (i = 0; i < n && s[i] != '\0'; i++) {
    d[i] = s[i];
  }
  for (; i < n; i++) {
    d[i] = '\0';
  }
  return d;
}

size_t s21_strcspn(
    const char *str1,
    const char
        *str2) {  //Вычисляет длину начального сегмента str1, который состоит из
                  //символов, не входящих в str2. (где искать, что искать)

  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  // size_t c1 = 0;
  // size_t c2 = strlen(s1);
  int res = 0;
  int stop_break = 0;
  for (int i = 0; s1[i] != '\0'; i++) {
    for (int jk = 0; s2[jk] != '\0'; jk++) {
      if (s1[i] == s2[jk]) stop_break = 1;
    }
    if (stop_break == 1) break;
    res++;
  }
  return res;
}

char *s21_strerror(int errnum) {
#ifdef __APPLE__
#define MIN_COUNT_ER 1
#define MAX_COUNT_ER 106
  const char *all_errors[] = {"Undefined error: 0",
                              "Operation not permitted",
                              "No such file or directory",
                              "No such process",
                              "Interrupted system call",
                              "Input/output error",
                              "Device not configured",
                              "Argument list too long",
                              "Exec format error",
                              "Bad file descriptor",
                              "No child processes",
                              "Resource deadlock avoided",
                              "Cannot allocate memory",
                              "Permission denied",
                              "Bad address",
                              "Block device required",
                              "Resource busy",
                              "File exists",
                              "Cross-device link",
                              "Operation not supported by device",
                              "Not a directory",
                              "Is a directory",
                              "Invalid argument",
                              "Too many open files in system",
                              "Too many open files",
                              "Inappropriate ioctl for device",
                              "Text file busy",
                              "File too large",
                              "No space left on device",
                              "Illegal seek",
                              "Read-only file system",
                              "Too many links",
                              "Broken pipe",
                              "Numerical argument out of domain",
                              "Result too large",
                              "Resource temporarily unavailable",
                              "Operation now in progress",
                              "Operation already in progress",
                              "Socket operation on non-socket",
                              "Destination address required",
                              "Message too long",
                              "Protocol wrong type for socket",
                              "Protocol not available",
                              "Protocol not supported",
                              "Socket type not supported",
                              "Operation not supported",
                              "Protocol family not supported",
                              "Address family not supported by protocol family",
                              "Address already in use",
                              "Can't assign requested address",
                              "Network is down",
                              "Network is unreachable",
                              "Network dropped connection on reset",
                              "Software caused connection abort",
                              "Connection reset by peer",
                              "No buffer space available",
                              "Socket is already connected",
                              "Socket is not connected",
                              "Can't send after socket shutdown",
                              "Too many references: can't splice",
                              "Operation timed out",
                              "Connection refused",
                              "Too many levels of symbolic links",
                              "File name too long",
                              "Host is down",
                              "No route to host",
                              "Directory not empty",
                              "Too many processes",
                              "Too many users",
                              "Disc quota exceeded",
                              "Stale NFS file handle",
                              "Too many levels of remote in path",
                              "RPC struct is bad",
                              "RPC version wrong",
                              "RPC prog. not avail",
                              "Program version wrong",
                              "Bad procedure for program",
                              "No locks available",
                              "Function not implemented",
                              "Inappropriate file type or format",
                              "Authentication error",
                              "Need authenticator",
                              "Device power is off",
                              "Device error",
                              "Value too large to be stored in data type",
                              "Bad executable (or shared library)",
                              "Bad CPU type in executable",
                              "Shared library version mismatch",
                              "Malformed Mach-o file",
                              "Operation canceled",
                              "Identifier removed",
                              "No message of desired type",
                              "Illegal byte sequence",
                              "Attribute not found",
                              "Bad message",
                              "EMULTIHOP (Reserved)",
                              "No message available on STREAM",
                              "ENOLINK (Reserved)",
                              "No STREAM resources",
                              "Not a STREAM",
                              "Protocol error",
                              "STREAM ioctl timeout",
                              "Operation not supported on socket",
                              "Policy not found",
                              "State not recoverable",
                              "Previous owner died",
                              "Interface output queue is full"};
#elif defined __linux__

  const char *all_errorsL[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error"};

#endif
  char *error = 0;
  static char ret_mas[110];

#ifdef __APPLE__
  if ((errnum >= MIN_COUNT_ER && errnum <= MAX_COUNT_ER) || errnum == 0) {
    error = (char *)all_errors[errnum];
  } else if (errnum > MAX_COUNT_ER || errnum <= MIN_COUNT_ER) {
    s21_sprintf(ret_mas, "Unknown error: %d", errnum);
    error = ret_mas;
  }
#elif defined __linux__
  if ((errnum >= MIN_COUNT_ER_L && errnum <= MAX_COUNT_ER_L) || errnum == 0) {
    error = (char *)all_errorsL[errnum];
  } else if (errnum > MAX_COUNT_ER_L || errnum <= MIN_COUNT_ER_L) {
    s21_sprintf(ret_mas, "Unknown error %d", errnum);
    error = ret_mas;
  }
#endif
  return error;
}

size_t s21_strlen(const char *str) {
  size_t i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *ch = s21_NULL;
  int f = 0;
  s21_size_t l = s21_strlen(str1);
  s21_size_t m = s21_strlen(str2);
  for (s21_size_t i = 0; i < m; i++) {
    for (s21_size_t j = 0; j < l; j++) {
      if (str1[j] == str2[i] && f == 0) {
        ch = (char *)&str1[j];
        f = 1;
      }
    }
  }
  return ch;
}

char *s21_strrchr(const char *str, int c) {
  char *ch = s21_NULL;
  s21_size_t l = s21_strlen(str);
  for (s21_size_t i = 0; i < l; i++) {
    if (str[i] == c) {
      ch = (char *)&str[i];
    }
  }
  return ch;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t size_needle_length = s21_strlen(needle);
  char copy_let_needle[1] = {0};
  const char *ptr = haystack;
  s21_strncpy(copy_let_needle, needle,
              1);  //копируем в новый массив 1 символ needle
  s21_size_t count_match = 0;
  char *match = s21_strpbrk(
      ptr, copy_let_needle);  // передвинули массив на совпадение в haystack

  int flag = 0;  //нашел соответствие полное - выйди из цикла ниже

  while (match != s21_NULL && flag != 1) {
    if (match != s21_NULL && *ptr != '\0') {  //если есть совпадения
      for (s21_size_t i = 0; i < size_needle_length || match[i] != '\0'; i++) {
        if (match[i] == needle[i]) count_match++;
      }
      if (count_match == size_needle_length) {
        ptr = match;  //если совпадения есть полностью всего needle
        flag = 1;
      } else {
        ptr = match;
        ptr++;
        count_match = 0;
        match = s21_strpbrk(ptr, copy_let_needle);
      }
    }
  }
  if (!match || *ptr == '\0' || *haystack == '\0') ptr = s21_NULL;
  if (*needle == '\0') ptr = haystack;

  return (char *)ptr;
}

char *s21_strtok(char *str, const char *delim) {
  static int count_call;
  static char *ptr_pass_tok = s21_NULL;
  static int orig_str_length;

  if (str != s21_NULL && count_call == 0)
    orig_str_length = s21_strlen(
        str);  //подсчет символов в оригинальной строке при первом вызове
  if ((orig_str_length <= 0) || (str == s21_NULL && count_call == 0) ||
      (str == s21_NULL && delim == s21_NULL))
    str = s21_NULL;
  else {
    orig_str_length -= 1;  //вычитаем последний зануленный делимер
    if (count_call == 0) ptr_pass_tok = str;  //если первый вызов
    if (count_call != 0 && *ptr_pass_tok != '\0') {
      str = ptr_pass_tok;  //если вызов не первый
    }
    s21_size_t tok_length =
        s21_strcspn(str, delim);  //находим кол-во символов до делимера
    while (tok_length == 0) {  //несколько delim подряд
      ptr_pass_tok = ptr_pass_tok + 1;
      str = str + 1;
      orig_str_length--;
      tok_length = s21_strcspn(str, delim);
    }
    for (s21_size_t i = 0; i < s21_strlen(delim);
         i++) {  //последний delim подряд
      if (*ptr_pass_tok == delim[i]) {
        ptr_pass_tok = ptr_pass_tok + 1;
        str = str + 1;
        orig_str_length--;
      }
    }
    ptr_pass_tok = ptr_pass_tok + tok_length;  //переход до делимера
    str[tok_length] = '\0';                    //зануляем делимер
    ptr_pass_tok = ptr_pass_tok + 1;  //шаг на следующий символ
    count_call++;
    orig_str_length -= tok_length;
  }
  return str;
}
/*--------------ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ--------------*/
void *s21_to_upper(const char *str) {
  char *s = (char *)str;
  char *copy = calloc(1000, sizeof(char *));
  s21_strcpy(copy, s);
  if (*s != '\0') {
    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] >= 97 && s[i] <= 122) {
        copy[i] = s[i] - 32;
      }
    }
  } else if (*s == '\0') {
    copy = "";
  } else {
    copy = s21_NULL;
  }
  return copy;
}

void *s21_to_lower(const char *str) {
  char *s = (char *)str;
  char *copy = calloc(1000, sizeof(char *));
  s21_strcpy(copy, s);
  if (*s != '\0') {
    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] >= 65 && s[i] <= 90) {
        copy[i] = s[i] + 32;
      }
    }
  } else if (*s == '\0')
    copy = "";
  else
    copy = s21_NULL;
  return copy;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t l = s21_strlen(src);
  s21_size_t m = s21_strlen(str);
  char *res = calloc(1000, sizeof(char *));
  char *r = (char *)src;
  s21_size_t index = 0;
  if (*src != '\0' && *str != '\0' && l > start_index) {
    for (s21_size_t i = 0; i < l; i++) {
      if (i == start_index) {
        for (s21_size_t j = 0; j < m; j++) {
          res[index] = str[j];
          index++;
        }
      }
      res[index] = r[i];
      index++;
    }
    res[index] = '\0';
  } else
    res = s21_NULL;
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t l = s21_strlen(src);
  s21_size_t m = s21_strlen(trim_chars);
  char *new = calloc(1000, sizeof(char *));
  char *r = (char *)src;
  s21_sprintf(new, "%s", src);
  s21_size_t index = 0;
  int flag = 1;
  if (*src != '\0' && *trim_chars != '\0') {
    for (s21_size_t i = 0; i < l; i++) {
      int flag_2 = 0;
      for (s21_size_t j = 0; j < m; j++) {
        if (r[i] == trim_chars[j] && flag && flag_2 < 1) {
          index++;
          flag_2++;
        }
      }
      if (flag_2 == 0) flag = 0;
    }
    if (index > 0) {
      for (s21_size_t i = 0; i < l - index; i++) {
        new[i] = r[i + index];
      }
      new[l - index] = '\0';
    }
    r = (char *)new;
    flag = 1;
    for (s21_size_t i = l - index - 1; i > 0; i--) {
      int flag_2 = 0;
      for (s21_size_t j = 0; j < m; j++) {
        if (r[i] == trim_chars[j] && flag) {
          flag_2++;
          new[i] = '\0';
        }
      }
      if (flag_2 == 0) flag = 0;
    }
  } else
    new = s21_NULL;
  return new;
}

/*---------------------функция для error---------------------*/
char *s21_strcpy(char *dst, const char *src) {
  dst[50] = '0';
  s21_size_t length_src = s21_strlen(src);
  s21_size_t i = 0;

  for (i = 0; i < length_src; i++) {  // strlen = 9?
    dst[i] = src[i];
  }
  for (; i < sizeof(dst) / sizeof(dst); i++) {
    dst[i] = '\0';
  }

  return (char *)dst;
}

// /*---------------------функция для спецификатора---------------------*/
char *s21_strcat(char *destination, const char *append) {
  char *dest = destination;
  char *app = (char *)append;
  while (*dest != '\0') {
    dest++;
  }
  while (*app != '\0') {
    *dest = *app;
    app++;
    dest++;
  }
  return destination;
}

// int main() {
//   char *df = "haski";
//   char *df1 = "has";

//   printf("%p", s21_insert(df, df1,3));
// }