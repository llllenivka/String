#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

// memchr
// memcmp
// memcpy
// memset
// strncat
// strchr
// strncmp
// strncpy
// strcspn
// stderror
// strlen
// strpbrk
// strrchr
// strstr

/*---------------------memchr---------------------*/
START_TEST(test_s21_memchr) {
  char str1[] = "youth forgives everything";
  int c1 = 'y';
  s21_size_t n1 = strlen(str1);

  char str2[] = "youth forgives everything";
  int c2 = 'g';
  s21_size_t n2 = strlen(str2);

  char str3[] = "youth forgives everything";
  int c3 = 'r';
  s21_size_t n3 = strlen(str3);

  char str4[] = "youth forgives everything";
  int c4 = 'p';
  s21_size_t n4 = strlen(str4);

  char str5[] = "youth forgives everything";
  int c5 = '!';
  s21_size_t n5 = strlen(str5);

  char str6[] = "";
  int c6 = 'y';
  s21_size_t n6 = strlen(str6);

  ck_assert_ptr_eq(s21_memchr(str1, c1, n1), memchr(str1, c1, n1));
  ck_assert_ptr_eq(s21_memchr(str2, c2, n2), memchr(str2, c2, n2));
  ck_assert_ptr_eq(s21_memchr(str3, c3, n3), memchr(str3, c3, n3));
  ck_assert_ptr_eq(s21_memchr(str4, c4, n4), memchr(str4, c4, n4));
  ck_assert_ptr_eq(s21_memchr(str5, c5, n5), memchr(str5, c5, n5));
  ck_assert_ptr_eq(s21_memchr(str6, c6, n6), memchr(str6, c6, n6));
}
END_TEST;

Suite *s21_memchr_test() {
  Suite *result;
  TCase *tc_memchr;

  result = suite_create("s21_memchr");
  tc_memchr = tcase_create("s21_memchr");

  tcase_add_test(tc_memchr, test_s21_memchr);
  suite_add_tcase(result, tc_memchr);

  return result;
}

/*---------------------memcmp---------------------*/
START_TEST(test_s21_memcmp) {
  char *t1_str_1 = "Haski";
  char *str_12 = "Haski";
  s21_size_t n_1 = 5;

  char *t2_str_1 = "Haski";
  char *str_2 = "HaskI";
  s21_size_t n_2 = 5;

  char *t3_str_1 = "Haski";
  char *str_3 = "1ask0";
  s21_size_t n_3 = 5;

  char *t4_str_1 = "Haski";
  char *str_4 = "Wolf";
  s21_size_t n_4 = 4;

  char *t5_str_1 = "Haski";
  char *str_5 = "1ask0";
  s21_size_t n_5 = 3;

  char *t6_str_1 = "Haski";
  char *str_6 = "Ha";
  s21_size_t n_6 = 2;

  ck_assert_int_eq(s21_memcmp(t1_str_1, str_12, n_1),
                   memcmp(t1_str_1, str_12, n_1));
  ck_assert_int_eq(s21_memcmp(t2_str_1, str_2, n_2),
                   memcmp(t2_str_1, str_2, n_2));
  ck_assert_int_eq(s21_memcmp(t3_str_1, str_3, n_3),
                   memcmp(t3_str_1, str_3, n_3));
  ck_assert_int_eq(s21_memcmp(t4_str_1, str_4, n_4),
                   memcmp(t4_str_1, str_4, n_4));
  ck_assert_int_eq(s21_memcmp(t5_str_1, str_5, n_5),
                   memcmp(t5_str_1, str_5, n_5));
  ck_assert_int_eq(s21_memcmp(t6_str_1, str_6, n_6),
                   memcmp(t6_str_1, str_6, n_6));
}
END_TEST;

Suite *s21_memcmp_test() {
  Suite *result;
  TCase *tc_memcmp;

  result = suite_create("s21_memcmp");
  tc_memcmp = tcase_create("s21_memcmp");

  tcase_add_test(tc_memcmp, test_s21_memcmp);
  suite_add_tcase(result, tc_memcmp);

  return result;
}

/*---------------------memcpy---------------------*/
START_TEST(test_s21_memcpy) {
  char dest[10000] = "";

  char _str1[] = "Haski";
  s21_size_t _n_1 = 5;

  char _str2[] = "HASKI";
  s21_size_t _n_2 = 3;

  char _str3[] = "12345";
  s21_size_t _n_3 = 11;

  char _str4[] = ".";
  s21_size_t _n_4 = 3;

  char _str5[] = "H A S K I";
  s21_size_t _n_5 = 9;

  ck_assert_mem_eq(s21_memcpy(dest, _str1, _n_1), memcpy(dest, _str1, _n_1),
                   _n_1);
  ck_assert_mem_eq(s21_memcpy(dest, _str2, _n_2), memcpy(dest, _str2, _n_2),
                   _n_2);
  ck_assert_mem_eq(s21_memcpy(dest, _str3, _n_3), memcpy(dest, _str3, _n_3),
                   _n_3);
  ck_assert_mem_eq(s21_memcpy(dest, _str4, _n_4), memcpy(dest, _str4, _n_4),
                   _n_4);
  ck_assert_mem_eq(s21_memcpy(dest, _str5, _n_5), memcpy(dest, _str5, _n_5),
                   _n_5);
}
END_TEST;

Suite *s21_memcpy_test() {
  Suite *result;
  TCase *tc_memcpy;

  result = suite_create("s21_memcpy");
  tc_memcpy = tcase_create("s21_memcpy");

  tcase_add_test(tc_memcpy, test_s21_memcpy);
  suite_add_tcase(result, tc_memcpy);

  return result;
}

/*---------------------memset---------------------*/
START_TEST(test_s21_memset) {
  char str__1[] = "youth forgives everything";
  int c = 'F';
  s21_size_t n__1 = 8;
  char str__2[] = "0000000000000000000000000";
  int c2 = '7';
  s21_size_t n__2 = 8;
  char str__3[] = "";
  int c3 = '!';
  s21_size_t n__3 = 1;

  ck_assert_mem_eq(s21_memset(str__1, c, n__1), memset(str__1, c, n__1), 30);
  ck_assert_mem_eq(s21_memset(str__2, c2, n__2), memset(str__2, c2, n__2), 30);
  ck_assert_mem_eq(s21_memset(str__3, c3, n__3), memset(str__3, c3, n__3), 30);
}
END_TEST

Suite *s21_memset_test() {
  Suite *result;
  TCase *tc_memset;

  result = suite_create("s21_memset");
  tc_memset = tcase_create("s21_memset");

  tcase_add_test(tc_memset, test_s21_memset);
  suite_add_tcase(result, tc_memset);

  return result;
}

/*---------------------strncat---------------------*/
START_TEST(test_s21_strncat) {
  char dest1[600] = "";
  char str___1[50] = "youth forgives everything\n";
  char str___2[50] = "I'l be back\n";
  char str___3[50] = "!\n";
  char str___4[50] = "\n";
  char str___5[50] = " ";

  ck_assert_ptr_eq(s21_strncat(dest1, str___1, 26),
                   strncat(dest1, str___1, 26));
  ck_assert_ptr_eq(s21_strncat(dest1, str___2, 12),
                   strncat(dest1, str___2, 12));
  ck_assert_ptr_eq(s21_strncat(dest1, str___3, 2), strncat(dest1, str___3, 2));
  ck_assert_ptr_eq(s21_strncat(dest1, str___4, 1), strncat(dest1, str___4, 1));
  ck_assert_ptr_eq(s21_strncat(dest1, str___5, 1), strncat(dest1, str___5, 1));
}
END_TEST;

Suite *s21_strncat_test() {
  Suite *result;
  TCase *tc_strncat;

  result = suite_create("s21_strncat");
  tc_strncat = tcase_create("s21_strncat");

  tcase_add_test(tc_strncat, test_s21_strncat);
  suite_add_tcase(result, tc_strncat);

  return result;
}

/*---------------------strchr---------------------*/
START_TEST(test_s21_strchr) {
  char str___1[100] = "we are the champions!";
  int c1 = 'w';
  int c2 = 't';
  int c3 = 'e';

  char str___2[100] = "";
  int c4 = '!';

  ck_assert_ptr_eq(s21_strchr(str___1, c1), strchr(str___1, c1));
  ck_assert_ptr_eq(s21_strchr(str___1, c2), strchr(str___1, c2));
  ck_assert_ptr_eq(s21_strchr(str___1, c3), strchr(str___1, c3));

  ck_assert_ptr_eq(s21_strchr(str___2, c4), strchr(str___2, c4));
}
END_TEST;

Suite *s21_strchr_test() {
  Suite *result;
  TCase *tc_strchr;

  result = suite_create("s21_strchr");
  tc_strchr = tcase_create("s21_strchr");

  tcase_add_test(tc_strchr, test_s21_strchr);
  suite_add_tcase(result, tc_strchr);

  return result;
}

/*---------------------strncmp----------------------*/
START_TEST(test_s21_strncmp) {
  char str1__[100] = "haski";

  char str2__[100] = "HASKI";
  s21_size_t n__1 = 5;

  char str3__[100] = "1";
  s21_size_t n__2 = 1;

  char str4__[100] = "!!!";
  s21_size_t n__3 = 15;

  char str5__[100] = "has";
  s21_size_t n__4 = 3;

  char str6__[100] = "";
  s21_size_t n__5 = 3;

  ck_assert_int_eq(s21_strncmp(str1__, str2__, n__1),
                   strncmp(str1__, str2__, n__1));
  ck_assert_int_eq(s21_strncmp(str1__, str3__, n__2),
                   strncmp(str1__, str3__, n__2));
  ck_assert_int_eq(s21_strncmp(str1__, str4__, n__3),
                   strncmp(str1__, str4__, n__3));
  ck_assert_int_eq(s21_strncmp(str1__, str5__, n__4),
                   strncmp(str1__, str5__, n__4));
  ck_assert_int_eq(s21_strncmp(str1__, str6__, n__5),
                   strncmp(str1__, str6__, n__5));
}
END_TEST;

Suite *s21_strncmp_test() {
  Suite *result;
  TCase *tc_strncmp;

  result = suite_create("s21_strncmp");
  tc_strncmp = tcase_create("s21_strncmp");

  tcase_add_test(tc_strncmp, test_s21_strncmp);
  suite_add_tcase(result, tc_strncmp);

  return result;
}

/*---------------------strncpy----------------------*/
START_TEST(test_s21_strncpy) {
  char dest1[600] = "";
  char str___1[50] = "youth forgives everything\n";
  s21_size_t n1 = 26;

  char str___2[50] = "!_!\n";
  s21_size_t n2 = 4;

  char str___3[50] = "\n";
  s21_size_t n3 = 1;

  char str___4[50] = "";
  s21_size_t n4 = 0;

  ck_assert_ptr_eq(s21_strncpy(dest1, str___1, n1),
                   strncpy(dest1, str___1, n1));
  ck_assert_ptr_eq(s21_strncpy(dest1, str___2, n2),
                   strncpy(dest1, str___2, n2));
  ck_assert_ptr_eq(s21_strncpy(dest1, str___3, n3),
                   strncpy(dest1, str___3, n3));
  ck_assert_ptr_eq(s21_strncpy(dest1, str___4, n4),
                   strncpy(dest1, str___4, n4));
}
END_TEST;

Suite *s21_strncpy_test() {
  Suite *result;
  TCase *tc_strncpy;

  result = suite_create("s21_strncpy");
  tc_strncpy = tcase_create("s21_strncpy");

  tcase_add_test(tc_strncpy, test_s21_strncpy);
  suite_add_tcase(result, tc_strncpy);

  return result;
}

/*---------------------strcspn----------------------*/
START_TEST(test_s21_strcspn) {
  char str___1[50] = "youth forgives everything";
  char str___11[50] = "e";

  char str___2[50] = " e123";
  char str___3[50] = "youthYOUTH";
  char str___4[50] = "";
  char str___5[50] = "UDSGDKDGKDGDKGUDGIU";

  ck_assert_int_eq(s21_strcspn(str___1, str___11), strcspn(str___1, str___11));
  ck_assert_int_eq(s21_strcspn(str___2, str___11), strcspn(str___2, str___11));
  ck_assert_int_eq(s21_strcspn(str___3, str___11), strcspn(str___3, str___11));
  ck_assert_int_eq(s21_strcspn(str___4, str___11), strcspn(str___4, str___11));
  ck_assert_int_eq(s21_strcspn(str___5, str___11), strcspn(str___5, str___11));
}
END_TEST;

Suite *s21_strcspn_test() {
  Suite *result;
  TCase *tc_strcspn;

  result = suite_create("s21_strcspn");
  tc_strcspn = tcase_create("s21_strcspn");

  tcase_add_test(tc_strcspn, test_s21_strcspn);
  suite_add_tcase(result, tc_strcspn);

  return result;
}

/*---------------------strerror----------------------*/
START_TEST(test_s21_strerror) {
  int a = 0;
  int b = 1;
  int c = 17;
  int d = 96;
  int e = 4673262;

  ck_assert_str_eq(s21_strerror(a), strerror(a));
  ck_assert_str_eq(s21_strerror(a), strerror(a));
  ck_assert_str_eq(s21_strerror(b), strerror(b));
  ck_assert_str_eq(s21_strerror(c), strerror(c));
  ck_assert_str_eq(s21_strerror(d), strerror(d));
  ck_assert_str_eq(s21_strerror(e), strerror(e));
}

Suite *s21_strerror_test() {
  Suite *result;
  TCase *tc_strerror;

  result = suite_create("s21_strerror");
  tc_strerror = tcase_create("s21_strerror");

  tcase_add_test(tc_strerror, test_s21_strerror);
  suite_add_tcase(result, tc_strerror);

  return result;
}

/*---------------------strlen----------------------*/
START_TEST(test_s21_strlen) {
  char test[100] = " ";
  char test1[100] = "123";
  char test2[100] = "1 2 3 ";
  char test3[100] = "1 \0 3 ";
  char test4[100] = "и жили они долго и счастливо";
  char test5[100] = "";

  ck_assert_int_eq(s21_strlen(test), strlen(test));
  ck_assert_int_eq(s21_strlen(test1), strlen(test1));
  ck_assert_int_eq(s21_strlen(test2), strlen(test2));
  ck_assert_int_eq(s21_strlen(test3), strlen(test3));
  ck_assert_int_eq(s21_strlen(test4), strlen(test4));
  ck_assert_int_eq(s21_strlen(test5), strlen(test5));
}
END_TEST

Suite *s21_strlen_test() {
  Suite *result;
  TCase *tc_strlen;

  result = suite_create("s21_strlen");
  tc_strlen = tcase_create("s21_strlen");

  tcase_add_test(tc_strlen, test_s21_strlen);
  suite_add_tcase(result, tc_strlen);
  return result;
}

/*---------------------strpbrk----------------------*/
START_TEST(test_s21_strpbrk) {
  char test[100] = "123";
  char test_char[100] = "456";

  char test1[100] = "";
  char test_char1[100] = "";

  char test2[100] = "1234567890";
  char test_char2[100] = "26";

  char test3[100] = "и жили они жолгл и счастливо";
  char test_char3[100] = "жили";

  char test4[100] = " ";
  char test_char4[100] = " ";

  ck_assert_ptr_eq(s21_strpbrk(test, test_char), strpbrk(test, test_char));
  ck_assert_ptr_eq(s21_strpbrk(test1, test_char1), strpbrk(test1, test_char1));
  ck_assert_ptr_eq(s21_strpbrk(test2, test_char2), strpbrk(test2, test_char2));
  ck_assert_ptr_eq(s21_strpbrk(test3, test_char3), strpbrk(test3, test_char3));
  ck_assert_ptr_eq(s21_strpbrk(test4, test_char4), strpbrk(test4, test_char4));
}
END_TEST

Suite *s21_strpbrk_test() {
  Suite *result;
  TCase *tc_strpbrk;

  result = suite_create("s21_strpbrk");
  tc_strpbrk = tcase_create("s21_strpbrk");

  tcase_add_test(tc_strpbrk, test_s21_strpbrk);
  suite_add_tcase(result, tc_strpbrk);
  return result;
}

/*---------------------strrchr----------------------*/
START_TEST(test_s21_strrchr) {
  char test[100] = "123456";
  int ch = '5';

  char test1[100] = "";
  int ch1 = '5';

  char test2[100] = "123457890";
  int ch2 = '6';

  char test3[100] = "november december";
  int ch3 = 'e';

  char test4[100] = " ";
  int ch4 = '0';

  ck_assert_ptr_eq(s21_strrchr(test, ch), strrchr(test, ch));
  ck_assert_ptr_eq(s21_strrchr(test1, ch1), strrchr(test1, ch1));
  ck_assert_ptr_eq(s21_strrchr(test2, ch2), strrchr(test2, ch2));
  ck_assert_ptr_eq(s21_strrchr(test3, ch3), strrchr(test3, ch3));
  ck_assert_ptr_eq(s21_strrchr(test4, ch4), strrchr(test4, ch4));
}
END_TEST

Suite *s21_strrchr_test() {
  Suite *result;
  TCase *tc_strrchr;

  result = suite_create("s21_strrchr");
  tc_strrchr = tcase_create("s21_strrchr");

  tcase_add_test(tc_strrchr, test_s21_strrchr);
  suite_add_tcase(result, tc_strrchr);
  return result;
}

/*---------------------strstr----------------------*/
START_TEST(test_s21_strstr) {
  char str_1[50] = "kabachok lotos pony tor";
  char str_2[10] = "pony";
  char str_3[10] = "pony";
  char str_4[10] = "oreo";
  char str_5[10] = "j";
  char str_6[] = "";
  char str_7[] = "";
  char str_8[] = "";
  char str_9[] = "";
  char str_10[10] = "pony";

  ck_assert_pstr_eq(s21_strstr(str_1, str_2), strstr(str_1, str_2));
  ck_assert_pstr_eq(s21_strstr(str_1, str_3), strstr(str_1, str_3));
  ck_assert_pstr_eq(s21_strstr(str_1, str_4), strstr(str_1, str_4));
  ck_assert_pstr_eq(s21_strstr(str_1, str_5), strstr(str_1, str_5));
  ck_assert_pstr_eq(s21_strstr(str_6, str_7), strstr(str_6, str_7));
  ck_assert_pstr_eq(s21_strstr(str_1, str_8), strstr(str_1, str_8));
  ck_assert_pstr_eq(s21_strstr(str_9, str_10), strstr(str_9, str_10));
}
END_TEST

Suite *s21_strstr_test() {
  Suite *result;
  TCase *tc_strstr;

  result = suite_create("s21_strstr");
  tc_strstr = tcase_create("s21_strstr");

  tcase_add_test(tc_strstr, test_s21_strstr);
  suite_add_tcase(result, tc_strstr);

  return result;
}

/*---------------------strtok----------------------*/
START_TEST(test_s21_strtok_1) {
  char str_1[100] = "kabachok,/.lotos.pony, tor";
  char str_3[100] = "kabachok,/.lotos.pony, tor";

  char *str_2 = "., /";

  char *res_1 = s21_strtok(str_1, str_2);
  char *res_2 = strtok(str_3, str_2);
  ck_assert_pstr_eq(res_1, res_2);

  while (res_1 != s21_NULL) {
    res_1 = s21_strtok(s21_NULL, str_2);
    res_2 = strtok(s21_NULL, str_2);
    ck_assert_pstr_eq(res_1, res_2);
    ;
  }
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str_1[100] = "kabachok/lotos.pony,tor";
  char str_3[100] = "kabachok/lotos.pony,tor";

  char *str_2 = "., /";

  char *res_1 = s21_strtok(str_1, str_2);
  char *res_2 = strtok(str_3, str_2);
  ck_assert_pstr_eq(res_1, res_2);

  while (res_1 != s21_NULL) {
    res_1 = s21_strtok(s21_NULL, str_2);
    res_2 = strtok(s21_NULL, str_2);
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str_1[100] = "kabachok/lotos.pony,tor";
  char str_3[100] = "kabachok/lotos.pony,tor";

  char *str_2 = "";

  char *res_1 = s21_strtok(str_1, str_2);
  char *res_2 = strtok(str_3, str_2);
  ck_assert_pstr_eq(res_1, res_2);

  while (res_1 != s21_NULL) {
    res_1 = s21_strtok(s21_NULL, str_2);
    res_2 = strtok(s21_NULL, str_2);
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

Suite *s21_strtok_test() {
  Suite *result;
  TCase *tc_strtok;

  result = suite_create("s21_strtok");
  tc_strtok = tcase_create("s21_strtok");

  tcase_add_test(tc_strtok, test_s21_strtok_1);
  tcase_add_test(tc_strtok, test_s21_strtok_2);
  tcase_add_test(tc_strtok, test_s21_strtok_5);

  suite_add_tcase(result, tc_strtok);

  return result;
}

// /*----------------------------ДОПОЛНИТЕЛЬНЫЕ
// ФУНКЦИИ----------------------------*/

/*---------------------to upper----------------------*/
START_TEST(test_s21_to_upper1) {
  char *str1 = "haski";
  char *str2 = "HASKI";
  char *upper1 = s21_to_upper(str1);
  ck_assert_str_eq(upper1, str2);
  free(upper1);
}
END_TEST
START_TEST(test_s21_to_upper2) {
  char *str4 = "youth forgives EVERYTHING";
  char *str6 = "YOUTH FORGIVES EVERYTHING";
  char *upper2 = s21_to_upper(str4);
  ck_assert_str_eq(upper2, str6);
  free(upper2);
}
END_TEST

START_TEST(test_s21_to_upper3) {
  char *str3 = "YOUTH FORGIVES EVERYTHING";
  char *str5 = "yoUth FoRgIvEs EvErYtHiNg";
  char *upper3 = s21_to_upper(str5);

  ck_assert_str_eq(upper3, str3);
  free(upper3);
}
END_TEST
START_TEST(test_s21_to_upper4) {
  char *str7 = "hhH123))4!00y@mato tenzo))";
  char *str8 = "HHH123))4!00Y@MATO TENZO))";
  char *upper4 = s21_to_upper(str7);
  ck_assert_str_eq(upper4, str8);
  free(upper4);
}
END_TEST

Suite *s21_to_upper_test() {
  Suite *result;
  TCase *tc_to_upper;

  result = suite_create("s21_to_upper");
  tc_to_upper = tcase_create("s21_to_upper");

  tcase_add_test(tc_to_upper, test_s21_to_upper1);
  tcase_add_test(tc_to_upper, test_s21_to_upper2);
  tcase_add_test(tc_to_upper, test_s21_to_upper3);
  tcase_add_test(tc_to_upper, test_s21_to_upper4);
  suite_add_tcase(result, tc_to_upper);

  return result;
}

/*---------------------lower----------------------*/
START_TEST(test_s21_to_lower1) {
  char *str2 = "haski";
  char *str1 = "HASKI";
  char *lower1 = s21_to_lower(str1);
  ck_assert_str_eq(lower1, str2);
  free(lower1);
}
END_TEST
START_TEST(test_s21_to_lower2) {
  char *str6 = "youth forgives everything";
  char *str4 = "YOUTH FORGIVES EVERYTHING";
  char *lower2 = s21_to_lower(str4);
  ck_assert_str_eq(lower2, str6);
  free(lower2);
}
END_TEST

START_TEST(test_s21_to_lower3) {
  char *str5 = "youth forgives everything";
  char *str3 = "YOUTH FORGIVES EVERYTHING";
  char *lower3 = s21_to_lower(str3);

  ck_assert_str_eq(lower3, str5);
  free(lower3);
}
END_TEST
START_TEST(test_s21_to_lower4) {
  char *str8 = "hhh123))4!00y@mato tenzo))";
  char *str7 = "HHH123))4!00Y@MATO TENZO))";
  char *lower4 = s21_to_lower(str7);
  ck_assert_str_eq(lower4, str8);
  free(lower4);
}
END_TEST

Suite *s21_to_lower_test() {
  Suite *result;
  TCase *tc_to_lower;

  result = suite_create("s21_to_lower");
  tc_to_lower = tcase_create("s21_to_lower");

  tcase_add_test(tc_to_lower, test_s21_to_lower1);
  tcase_add_test(tc_to_lower, test_s21_to_lower2);
  tcase_add_test(tc_to_lower, test_s21_to_lower3);
  tcase_add_test(tc_to_lower, test_s21_to_lower4);
  suite_add_tcase(result, tc_to_lower);

  return result;
}

/*---------------------insert----------------------*/
START_TEST(test_s21_insert) {
  char test[100] = "123678";
  char test_char[100] = "45";
  char *res1 = s21_insert(test, test_char, 3);

  char test1[100] = "12  12";
  char test_char1[100] = "45";
  char *res2 = s21_insert(test1, test_char1, 3);

  char test2[100] = "123678";
  char test_char2[100] = " 45";
  char *res3 = s21_insert(test2, test_char2, 3);

  char test4[100] = "Has Has ";
  char test_char4[100] = " ";
  char *res4 = s21_insert(test4, test_char4, 4);

  ck_assert_str_eq(res1, "12345678");
  free(res1);
  ck_assert_str_eq(res2, "12 45 12");
  free(res2);
  ck_assert_str_eq(res3, "123 45678");
  free(res3);
  ck_assert_str_eq(res4, "Has  Has ");
  free(res4);
}
END_TEST

Suite *s21_insert_test() {
  Suite *result;
  TCase *tc_insert;

  result = suite_create("s21_insert");
  tc_insert = tcase_create("s21_insert");

  tcase_add_test(tc_insert, test_s21_insert);
  suite_add_tcase(result, tc_insert);
  return result;
}
/*---------------------trim----------------------*/
START_TEST(test_s21_trim1) {
  char test[100] = "12345678";
  char test_char[100] = "12578";
  char *res1 = s21_trim(test, test_char);
  ck_assert_str_eq(res1, "3456");
  free(res1);
}
END_TEST
START_TEST(test_s21_trim2) {
  char test1[100] = "abcdefg";
  char test_char1[100] = "cfg";
  char *res2 = s21_trim(test1, test_char1);
  ck_assert_str_eq(res2, "abcde");
  free(res2);
}
END_TEST
START_TEST(test_s21_trim3) {
  char test2[100] = "123678";
  char test_char2[100] = "1527";
  char *res3 = s21_trim(test2, test_char2);
  ck_assert_str_eq(res3, "3678");
  free(res3);
}
END_TEST
START_TEST(test_s21_trim4) {
  char test3[100] = " 1278";
  char test_char3[100] = " 2";
  char *res4 = s21_trim(test3, test_char3);
  ck_assert_str_eq(res4, "1278");
  free(res4);
}
END_TEST
START_TEST(test_s21_trim5) {
  char test4[100] = "12345678";
  char test_char4[100] = "12";
  char *res5 = s21_trim(test4, test_char4);
  ck_assert_str_eq(res5, "345678");
  free(res5);
}
END_TEST

Suite *s21_trim_test() {
  Suite *result;
  TCase *tc_trim;

  result = suite_create("s21_trim");
  tc_trim = tcase_create("s21_trim");

  tcase_add_test(tc_trim, test_s21_trim1);
  tcase_add_test(tc_trim, test_s21_trim2);
  tcase_add_test(tc_trim, test_s21_trim3);
  tcase_add_test(tc_trim, test_s21_trim4);
  tcase_add_test(tc_trim, test_s21_trim5);

  suite_add_tcase(result, tc_trim);
  return result;
}

/*---------------------функция для error---------------------*/
START_TEST(test_s21_strcpy) {
  char str1[] = "Yamato Tenzo";
  char str2[] = " ";
  char str3[] = "1234567787";
  char str4[] = "@$^&***&*&*";

  ck_assert_ptr_eq(s21_strcpy(str1, str2), strcpy(str1, str2));
  ck_assert_ptr_eq(s21_strcpy(str3, str2), strcpy(str3, str2));
  ck_assert_ptr_eq(s21_strcpy(str4, str2), strcpy(str4, str2));
}
END_TEST

Suite *s21_strcpy_test() {
  Suite *result;
  TCase *tc_strspy;

  result = suite_create("s21_strcpy");
  tc_strspy = tcase_create("strspy");

  tcase_add_test(tc_strspy, test_s21_strcpy);
  suite_add_tcase(result, tc_strspy);
  return result;
}

/*---------------------функция для strcat---------------------*/
START_TEST(test_s21_strcat) {
  char str1[10000] = "Yamato Tenzo";
  char str2[100000] = " ";
  char str3[1000] = "1234567787";
  char str4[1000] = "@$^&***&*&*";

  ck_assert_ptr_eq(s21_strcat(str1, str2), strcat(str1, str2));
  ck_assert_ptr_eq(s21_strcat(str3, str2), strcat(str3, str2));
  ck_assert_ptr_eq(s21_strcat(str4, str2), strcat(str4, str2));
}
END_TEST

Suite *s21_strcat_test() {
  Suite *result;
  TCase *tc_strcat;

  result = suite_create("s21_strcat");
  tc_strcat = tcase_create("strcat");

  tcase_add_test(tc_strcat, test_s21_strcat);
  suite_add_tcase(result, tc_strcat);
  return result;
}

/*-------------------------------------------------------------*/
/*---------------------функция для sprintf---------------------*/
/*-------------------------------------------------------------*/

START_TEST(test_sprintf) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};

  sprintf(array_orig, "SPDOSPDOPD ==-=-099 832744       ui");
  s21_sprintf(array_s21, "SPDOSPDOPD ==-=-099 832744       ui");
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_() {
  Suite *result;
  TCase *tc_sprintf;

  result = suite_create("\033[32mSPRINTF\033[0m");
  tc_sprintf = tcase_create("s21_sprintf");

  tcase_add_test(tc_sprintf, test_sprintf);
  suite_add_tcase(result, tc_sprintf);

  return result;
}

/*------------------ spec d -----------------------*/

START_TEST(test_sprintf_d_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%d %d", x, y);
  s21_sprintf(array_s21, "%d %d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%+d %+d", x, y);
  s21_sprintf(array_s21, "%+d %+d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%*d %*d", 10, x, 12, y);
  s21_sprintf(array_s21, "%*d %*d", 10, x, 12, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%.*d %.*d", 10, x, 12, y);
  s21_sprintf(array_s21, "%.*d %.*d", 10, x, 12, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%12.10d %8.6d", x, y);
  s21_sprintf(array_s21, "%12.10d %8.6d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;
  int wight = 12;
  int precision = 10;
  sprintf(array_orig, "%*.*d %*.*d", wight, precision, x, wight, precision, y);
  s21_sprintf(array_s21, "%*.*d %*.*d", wight, precision, x, wight, precision,
              y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;
  int wight = 12;
  int precision = 10;
  sprintf(array_orig, "%-*.*d %-*.*d", wight, precision, x, wight, precision,
          y);
  s21_sprintf(array_s21, "%-*.*d %-*.*d", wight, precision, x, wight, precision,
              y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_8) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;
  sprintf(array_orig, "%hd %hd", x, y);
  s21_sprintf(array_s21, "%hd %hd", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_9) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  long int x = 12345;
  long int y = -678;
  sprintf(array_orig, "%ld %ld", x, y);
  s21_sprintf(array_s21, "%ld %ld", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_10) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  long int x = 12345;
  int y = -678;
  sprintf(array_orig, "%-*ld %.*hd", 15, x, 6, y);
  s21_sprintf(array_s21, "%-*ld %.*hd", 15, x, 6, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_11) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  long int x = 12345;
  int y = 0;
  sprintf(array_orig, "%-*ld %.*hd", 15, x, 6, y);
  s21_sprintf(array_s21, "%-*ld %.*hd", 15, x, 6, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_12) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%012d %8.6d", x, y);
  s21_sprintf(array_s21, "%012d %8.6d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_13) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%+d %+d", x, y);
  s21_sprintf(array_s21, "%+d %+d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_14) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "%+015d %+09d", x, y);
  s21_sprintf(array_s21, "%+015d %+09d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_15) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "% 15d % 9d", x, y);
  s21_sprintf(array_s21, "% 15d % 9d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_d_16) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 12345;
  int y = -678;

  sprintf(array_orig, "% 015d % 09d", x, y);
  s21_sprintf(array_s21, "% 015d % 09d", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_d() {
  Suite *result;
  TCase *tc_sprintf_d;

  result = suite_create("\033[32mSPRINTF_D\033[0m");
  tc_sprintf_d = tcase_create("s21_sprintf_d");

  tcase_add_test(tc_sprintf_d, test_sprintf_d_1);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_2);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_3);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_4);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_5);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_6);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_7);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_8);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_9);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_10);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_11);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_12);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_13);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_14);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_15);
  tcase_add_test(tc_sprintf_d, test_sprintf_d_16);
  suite_add_tcase(result, tc_sprintf_d);

  return result;
}

/*------------------ spec c -----------------------*/

START_TEST(test_sprintf_c_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char sym = '*';
  sprintf(array_orig, "%c", sym);
  s21_sprintf(array_s21, "%c", sym);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_c_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char sym = '*';
  sprintf(array_orig, "%10c", sym);
  s21_sprintf(array_s21, "%10c", sym);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_c_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char sym = '*';
  sprintf(array_orig, "%-*c", 5, sym);
  s21_sprintf(array_s21, "%-*c", 5, sym);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_c() {
  Suite *result;
  TCase *tc_sprintf_c;

  result = suite_create("\033[32mSPRINTF_C\033[0m");
  tc_sprintf_c = tcase_create("s21_sprintf_c");

  tcase_add_test(tc_sprintf_c, test_sprintf_c_1);
  tcase_add_test(tc_sprintf_c, test_sprintf_c_2);
  tcase_add_test(tc_sprintf_c, test_sprintf_c_3);

  suite_add_tcase(result, tc_sprintf_c);

  return result;
}

/*------------------ spec s -----------------------*/

START_TEST(test_sprintf_s_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "i wanna be hokage!";
  sprintf(array_orig, "%s", str);
  s21_sprintf(array_s21, "%s", str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_s_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "i wanna be hokage!";
  sprintf(array_orig, "%*s", 10, str);
  s21_sprintf(array_s21, "%*s", 10, str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_s_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "i wanna be hokage!";
  sprintf(array_orig, "%.*s", 10, str);
  s21_sprintf(array_s21, "%.*s", 10, str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_s_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "i wanna be hokage!";
  sprintf(array_orig, "%12.*s", 10, str);
  s21_sprintf(array_s21, "%12.*s", 10, str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_s_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "i wanna be hokage!";
  sprintf(array_orig, "%-12.*s", 10, str);
  s21_sprintf(array_s21, "%-12.*s", 10, str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_s_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "";
  sprintf(array_orig, "%s", str);
  s21_sprintf(array_s21, "%s", str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_s_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  char str[] = "";
  sprintf(array_orig, "%10.5s", str);
  s21_sprintf(array_s21, "%10.5s", str);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_s() {
  Suite *result;
  TCase *tc_sprintf_s;

  result = suite_create("\033[32mSPRINTF_S\033[0m");
  tc_sprintf_s = tcase_create("sprintf_s");

  tcase_add_test(tc_sprintf_s, test_sprintf_s_1);
  tcase_add_test(tc_sprintf_s, test_sprintf_s_2);
  tcase_add_test(tc_sprintf_s, test_sprintf_s_3);
  tcase_add_test(tc_sprintf_s, test_sprintf_s_4);
  tcase_add_test(tc_sprintf_s, test_sprintf_s_5);
  tcase_add_test(tc_sprintf_s, test_sprintf_s_6);
  tcase_add_test(tc_sprintf_s, test_sprintf_s_7);

  suite_add_tcase(result, tc_sprintf_s);

  return result;
}

/*------------------ spec f -----------------------*/

START_TEST(test_sprintf_f_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%f %f", x, y);
  s21_sprintf(array_s21, "%f %f", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%*f %*f", 10, x, 5, y);
  s21_sprintf(array_s21, "%*f %*f", 10, x, 5, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%.*f %.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "%.*f %.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%15.*f %9.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "%15.*f %9.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%-15.*f %-9.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "%-15.*f %-9.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%+15.*f %+9.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "%+15.*f %+9.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%-+15.*f %-+9.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "%-+15.*f %-+9.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_8) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 0.2345;
  float y = -678.9123;

  sprintf(array_orig, "%+015.*f %+09.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "%+015.*f %+09.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_f_9) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 0.2345;
  float y = -678.9123;

  sprintf(array_orig, "% 015.*f % 09.*f", 10, x, 3, y);
  s21_sprintf(array_s21, "% 015.*f % 09.*f", 10, x, 3, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_f() {
  Suite *result;
  TCase *tc_sprintf_f;

  result = suite_create("\033[32mSPRINTF_F\033[0m");
  tc_sprintf_f = tcase_create("sprintf_f");

  tcase_add_test(tc_sprintf_f, test_sprintf_f_1);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_2);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_3);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_4);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_5);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_6);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_7);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_8);
  tcase_add_test(tc_sprintf_f, test_sprintf_f_9);

  suite_add_tcase(result, tc_sprintf_f);

  return result;
}

/*------------------ spec u -----------------------*/

START_TEST(test_sprintf_u_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%u %u", x, y);
  s21_sprintf(array_s21, "%u %u", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_u_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%*u %*u", 10, x, 8, y);
  s21_sprintf(array_s21, "%*u %*u", 10, x, 8, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_u_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%.*u %.*u", 10, x, 8, y);
  s21_sprintf(array_s21, "%.*u %.*u", 10, x, 8, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_u_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 0;
  int y = -1234;

  sprintf(array_orig, "%13.*u %6.*u", 10, x, 8, y);
  s21_sprintf(array_s21, "%13.*u %6.*u", 10, x, 8, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_u_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%-13.*u %-6.*u", 10, x, 8, y);
  s21_sprintf(array_s21, "%-13.*u %-6.*u", 10, x, 8, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_u_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  long int x = 123;
  int y = -1234;

  sprintf(array_orig, "%lu %hu", x, y);
  s21_sprintf(array_s21, "%lu %hu", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_u() {
  Suite *result;
  TCase *tc_sprintf_u;

  result = suite_create("\033[32mSPRINTF_U\033[0m");
  tc_sprintf_u = tcase_create("sprintf_u");

  tcase_add_test(tc_sprintf_u, test_sprintf_u_1);
  tcase_add_test(tc_sprintf_u, test_sprintf_u_2);
  tcase_add_test(tc_sprintf_u, test_sprintf_u_3);
  tcase_add_test(tc_sprintf_u, test_sprintf_u_4);
  tcase_add_test(tc_sprintf_u, test_sprintf_u_5);
  tcase_add_test(tc_sprintf_u, test_sprintf_u_6);

  suite_add_tcase(result, tc_sprintf_u);

  return result;
}

/*------------------ spec o -----------------------*/

START_TEST(test_sprintf_o_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%o %o", x, y);
  s21_sprintf(array_s21, "%o %o", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_o_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%0*o %0*o", 11, x, 10, y);
  s21_sprintf(array_s21, "%0*o %0*o", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_o_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%*.12o %*.12o", 11, x, 10, y);
  s21_sprintf(array_s21, "%*.12o %*.12o", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_o_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-*.12o %*.12o", 11, x, 10, y);
  s21_sprintf(array_s21, "%-*.12o %*.12o", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_o_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%#12o %#12o", x, y);
  s21_sprintf(array_s21, "%#12o %#12o", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_o_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-#12o %-#12o", x, y);
  s21_sprintf(array_s21, "%-#12o %-#12o", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_o_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%#012o %#012o", x, y);
  s21_sprintf(array_s21, "%#012o %#012o", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_o() {
  Suite *result;
  TCase *tc_sprintf_o;

  result = suite_create("\033[32mSPRINTF_O\033[0m");
  tc_sprintf_o = tcase_create("sprintf_o");

  tcase_add_test(tc_sprintf_o, test_sprintf_o_1);
  tcase_add_test(tc_sprintf_o, test_sprintf_o_2);
  tcase_add_test(tc_sprintf_o, test_sprintf_o_3);
  tcase_add_test(tc_sprintf_o, test_sprintf_o_4);
  tcase_add_test(tc_sprintf_o, test_sprintf_o_5);
  tcase_add_test(tc_sprintf_o, test_sprintf_o_6);
  tcase_add_test(tc_sprintf_o, test_sprintf_o_7);

  suite_add_tcase(result, tc_sprintf_o);

  return result;
}

/*------------------ spec x -----------------------*/

START_TEST(test_sprintf_x_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%x %x", x, y);
  s21_sprintf(array_s21, "%x %x", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_x_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%0*x %0*x", 11, x, 10, y);
  s21_sprintf(array_s21, "%0*x %0*x", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_x_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%*.12x %*.12x", 11, x, 10, y);
  s21_sprintf(array_s21, "%*.12x %*.12x", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_x_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-*.12x %*.12x", 11, x, 10, y);
  s21_sprintf(array_s21, "%-*.12x %*.12x", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_x_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%#12x %#12x", x, y);
  s21_sprintf(array_s21, "%#12x %#12x", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_x_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-#12x %-#12x", x, y);
  s21_sprintf(array_s21, "%-#12x %-#12x", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_x_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%#012x %#012x", x, y);
  s21_sprintf(array_s21, "%#012x %#012x", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_x() {
  Suite *result;
  TCase *tc_sprintf_x;

  result = suite_create("\033[32mSPRINTF_x\033[0m");
  tc_sprintf_x = tcase_create("sprintf_x");

  tcase_add_test(tc_sprintf_x, test_sprintf_x_1);
  tcase_add_test(tc_sprintf_x, test_sprintf_x_2);
  tcase_add_test(tc_sprintf_x, test_sprintf_x_3);
  tcase_add_test(tc_sprintf_x, test_sprintf_x_4);
  tcase_add_test(tc_sprintf_x, test_sprintf_x_5);
  tcase_add_test(tc_sprintf_x, test_sprintf_x_6);
  tcase_add_test(tc_sprintf_x, test_sprintf_x_7);

  suite_add_tcase(result, tc_sprintf_x);

  return result;
}

/*------------------ spec X -----------------------*/

START_TEST(test_sprintf_X_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = -1234;

  sprintf(array_orig, "%X %X", x, y);
  s21_sprintf(array_s21, "%X %X", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_X_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%0*X %0*X", 11, x, 10, y);
  s21_sprintf(array_s21, "%0*X %0*X", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_X_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%*.12X %*.12X", 11, x, 10, y);
  s21_sprintf(array_s21, "%*.12X %*.12X", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_X_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-*.12X %*.12X", 11, x, 10, y);
  s21_sprintf(array_s21, "%-*.12X %*.12X", 11, x, 10, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_X_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%#12x %#12x", x, y);
  s21_sprintf(array_s21, "%#12x %#12x", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_X_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-#12x %-#12x", x, y);
  s21_sprintf(array_s21, "%-#12x %-#12x", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_X_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%#012X %#012X", x, y);
  s21_sprintf(array_s21, "%#012X %#012X", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_X() {
  Suite *result;
  TCase *tc_sprintf_X;

  result = suite_create("\033[32mSPRINTF_X\033[0m");
  tc_sprintf_X = tcase_create("sprintf_X");

  tcase_add_test(tc_sprintf_X, test_sprintf_X_1);
  tcase_add_test(tc_sprintf_X, test_sprintf_X_2);
  tcase_add_test(tc_sprintf_X, test_sprintf_X_3);
  tcase_add_test(tc_sprintf_X, test_sprintf_X_4);
  tcase_add_test(tc_sprintf_X, test_sprintf_X_5);
  tcase_add_test(tc_sprintf_X, test_sprintf_X_6);
  tcase_add_test(tc_sprintf_X, test_sprintf_X_7);

  suite_add_tcase(result, tc_sprintf_X);

  return result;
}

/*------------------ spec p -----------------------*/

START_TEST(test_sprintf_p_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%p %p", &x, &y);
  s21_sprintf(array_s21, "%p %p", &x, &y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_p_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%*p %*p", 11, &x, 4, &y);
  s21_sprintf(array_s21, "%*p %*p", 11, &x, 4, &y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_p_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  int x = 123;
  int y = 1234;

  sprintf(array_orig, "%-*p %-*p", 11, &x, 4, &y);
  s21_sprintf(array_s21, "%-*p %-*p", 11, &x, 4, &y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_p() {
  Suite *result;
  TCase *tc_sprintf_p;

  result = suite_create("\033[32mSPRINTF_p\033[0m");
  tc_sprintf_p = tcase_create("sprintf_p");

  tcase_add_test(tc_sprintf_p, test_sprintf_p_1);
  tcase_add_test(tc_sprintf_p, test_sprintf_p_2);
  tcase_add_test(tc_sprintf_p, test_sprintf_p_3);

  suite_add_tcase(result, tc_sprintf_p);

  return result;
}

/*------------------ spec e -----------------------*/

START_TEST(test_sprintf_e_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%e %e", x, y);
  s21_sprintf(array_s21, "%e %e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 0.0 / 0.0;

  sprintf(array_orig, "%e", x);
  s21_sprintf(array_s21, "%e", x);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%.1e %.1e", x, y);
  s21_sprintf(array_s21, "%.1e %.1e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%15e %15e", x, y);
  s21_sprintf(array_s21, "%15e %15e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%-15e %-15e", x, y);
  s21_sprintf(array_s21, "%-15e %-15e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%+-15e %+-15e", x, y);
  s21_sprintf(array_s21, "%+-15e %+-15e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%05e %05e", x, y);
  s21_sprintf(array_s21, "%05e %05e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_e_8) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "% 5e % 5e", x, y);
  s21_sprintf(array_s21, "% 5e % 5e", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_e() {
  Suite *result;
  TCase *tc_sprintf_e;

  result = suite_create("\033[32mSPRINTF_e\033[0m");
  tc_sprintf_e = tcase_create("sprintf_e");

  tcase_add_test(tc_sprintf_e, test_sprintf_e_1);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_2);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_3);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_4);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_5);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_6);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_7);
  tcase_add_test(tc_sprintf_e, test_sprintf_e_8);

  suite_add_tcase(result, tc_sprintf_e);

  return result;
}

/*------------------ spec E -----------------------*/

START_TEST(test_sprintf_E_1) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%E %E", x, y);
  s21_sprintf(array_s21, "%E %E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_2) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 0.0 / 0.0;

  sprintf(array_orig, "%E", x);
  s21_sprintf(array_s21, "%E", x);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_4) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%15E %15E", x, y);
  s21_sprintf(array_s21, "%15E %15E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_5) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%-15E %-15E", x, y);
  s21_sprintf(array_s21, "%-15E %-15E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_6) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%+-15E %+-15E", x, y);
  s21_sprintf(array_s21, "%+-15E %+-15E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_3) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%.1E %.1E", x, y);
  s21_sprintf(array_s21, "%.1E %.1E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_7) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "%05E %05E", x, y);
  s21_sprintf(array_s21, "%05E %05E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

START_TEST(test_sprintf_E_8) {
  char array_s21[1000] = {0};
  char array_orig[1000] = {0};
  float x = 1.2345;
  float y = -678.9123;

  sprintf(array_orig, "% 5E % 5E", x, y);
  s21_sprintf(array_s21, "% 5E % 5E", x, y);
  ck_assert_str_eq(array_s21, array_orig);
}
END_TEST

Suite *s21_sprintf_E() {
  Suite *result;
  TCase *tc_sprintf_E;

  result = suite_create("\033[32mSPRINTF_E\033[0m");
  tc_sprintf_E = tcase_create("sprintf_E");

  tcase_add_test(tc_sprintf_E, test_sprintf_E_1);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_2);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_3);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_4);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_5);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_6);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_7);
  tcase_add_test(tc_sprintf_E, test_sprintf_E_8);

  suite_add_tcase(result, tc_sprintf_E);

  return result;
}

int main() {
  Suite *result;
  int failed = 0;
  SRunner *runner;

  result = s21_memchr_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_memcmp_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_memcpy_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_memset_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strncat_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strchr_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strncmp_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strncpy_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strcspn_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  // error will be here

  result = s21_strlen_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strpbrk_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strrchr_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strstr_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strtok_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_to_upper_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_to_lower_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_insert_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_trim_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strcpy_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strcat_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_strerror_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  /*-------------------------------------------------------------*/
  /*---------------------тесты для sprintf---------------------*/
  /*-------------------------------------------------------------*/

  result = s21_sprintf_();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_d();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_c();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_s();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_f();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_u();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_o();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_x();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_X();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_p();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_e();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sprintf_E();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}