#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strncmp_normal) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  int n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_short_n) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  int n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_long_n) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  int n = 30;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_empty_str2) {
  char str1[30] = "Hello, world!";
  char str2[30] = "";
  int n = 13;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_empty_str) {
  char *str1 = "";
  char *str2 = "Hello, world!";
  int n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_all_empty) {
  char *str1 = "";
  char *str2 = "";
  int n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_unicode) {
  char *str1 =
      "Карл IV Люксембургский (14 мая 1316 — 29 ноября 1378) — король "
      "Германии, король Чехии, император Священной Римской империи.";
  char *str2 =
      "Карл IV Люксембургский (14 мая 1316 — 29 ноября 1378) — король "
      "Германии, король Чехии, император Священной Римской империи.";
  int n = 70;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_embeddedNull) {
  char str1[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                 'W', 'o', 'r', 'l', 'd', '!'};
  char str2[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                 'W', 'o', 'r', 'l', 'd', '!'};
  int n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_notNormal) {
  char *str1 = "Hello, world!";
  char *str2 = "Rock and Stone!";
  int n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

START_TEST(test_s21_strncmp_str2_EFO) {
  char *str1 = "Hello, world!";
  char *str2 = "\0";
  int n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

START_TEST(test_s21_strncmp_str1_EFO) {
  char *str1 = "\0";
  char *str2 = "Hello, world!";
  int n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

Suite *s21_strncmp_suite(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncmp_normal);
  tcase_add_test(tc_core, test_s21_strncmp_short_n);
  tcase_add_test(tc_core, test_s21_strncmp_long_n);
  tcase_add_test(tc_core, test_s21_strncmp_empty_str2);
  tcase_add_test(tc_core, test_s21_strncmp_empty_str);
  tcase_add_test(tc_core, test_s21_strncmp_all_empty);
  tcase_add_test(tc_core, test_s21_strncmp_unicode);
  tcase_add_test(tc_core, test_s21_strncmp_embeddedNull);
  tcase_add_test(tc_core, test_s21_strncmp_notNormal);
  tcase_add_test(tc_core, test_s21_strncmp_str2_EFO);
  tcase_add_test(tc_core, test_s21_strncmp_str1_EFO);

  suite_add_tcase(s, tc_core);
  return s;
}