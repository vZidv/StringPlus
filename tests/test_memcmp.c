#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_memcmp_normal) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  int n = 13;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_short_n) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_empty_str2) {
  char *str1 = "Hello, world!";
  char *str2 = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_empty_str) {
  char *str1 = "";
  char *str2 = "Hello, world!";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_all_empty) {
  char *str1 = "";
  char *str2 = "";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_unicode) {
  char *str1 =
      "Сигизмунд 1 Старый (1 января 1467, Краков, Польша — 1 апреля "
      "1548, там же) — король Польши и великий князь Литовский, "
      "правивший обширными владениями в течение 42 лет (1506–1548).";
  char *str2 =
      "Сигизмунд 1 Старый (1 января 1467, Краков, Польша — 1 апреля "
      "1548, там же) — король Польши и великий князь Литовский, "
      "правивший обширными владениями в течение 42 лет (1506–1548).";
  int n = 70;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_embeddedNull) {
  char str1[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                 'W', 'o', 'r', 'l', 'd', '!'};
  char str2[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                 'W', 'o', 'r', 'l', 'd', '!'};
  int n = 13;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_notNormal) {
  char *str1 = "Hello, world!";
  char *str2 = "Rock and Stone!";
  int n = 13;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(test_s21_memcmp_str2_EFO) {
  char *str1 = "Hello, world!";
  char *str2 = "\0";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(test_s21_memcmp_str1_EFO) {
  char *str1 = "\0";
  char *str2 = "Hello, world!";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(test_s21_memcmp_multiple_same_chars) {
  char str1[] = "aaaabbbbcccc";
  char str2[] = "aaaabbbbcccc";
  int n = 12;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_char_not_found) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world?";
  int n = 13;
  ck_assert_int_ne(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(test_s21_memcmp_embedded_null_2) {
  char str1[] = {'H', 'e', '\0', 'l', 'o'};
  char str2[] = {'H', 'e', '\0', 'l', 'o'};
  int n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_delimiters_at_start_and_end) {
  char str1[] = " ,!Hello, world!,! ";
  char str2[] = " ,!Hello, world!,! ";
  int n = 20;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memcmp_normal);
  tcase_add_test(tc_core, test_s21_memcmp_short_n);
  tcase_add_test(tc_core, test_s21_memcmp_empty_str2);
  tcase_add_test(tc_core, test_s21_memcmp_empty_str);
  tcase_add_test(tc_core, test_s21_memcmp_all_empty);
  tcase_add_test(tc_core, test_s21_memcmp_unicode);
  tcase_add_test(tc_core, test_s21_memcmp_embeddedNull);
  tcase_add_test(tc_core, test_s21_memcmp_notNormal);
  tcase_add_test(tc_core, test_s21_memcmp_str2_EFO);
  tcase_add_test(tc_core, test_s21_memcmp_str1_EFO);
  tcase_add_test(tc_core, test_s21_memcmp_multiple_same_chars);
  tcase_add_test(tc_core, test_s21_memcmp_char_not_found);
  tcase_add_test(tc_core, test_s21_memcmp_embedded_null_2);
  tcase_add_test(tc_core, test_s21_memcmp_delimiters_at_start_and_end);

  suite_add_tcase(s, tc_core);

  return s;
}
