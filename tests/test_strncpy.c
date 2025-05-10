#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strncpy_normal) {
  int n = 15;
  char dest[30];
  char *str = "Hello, World!";
  ck_assert_str_eq(s21_strncpy(dest, str, n), strncpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_strncpy_unicode) {
  int n = 50;
  char dest[200] = {0};
  char *str =
      "Пельмени — блюдо русской кухни из пресного теста с начинкой из "
      "рублёного мяса, употребляемое в варёном виде.";
  ck_assert_str_eq(s21_strncpy(dest, str, n), strncpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_strncpy_nOver) {
  int n = 50;
  char dest[50];
  char *str = "Hello, World!";
  ck_assert_str_eq(s21_strncpy(dest, str, n), strncpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_strncpy_embeddedNull) {
  int n = 50;
  char dest[50];
  char str[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                'W', 'o', 'r', 'l', 'd', '!'};
  ck_assert_str_eq(s21_strncpy(dest, str, n), strncpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_strncpy_longString) {
  int n = 15;
  char dest[120] = {0};
  char *str =
      "This is a test string exactly 100 characters long, including "
      "spaces and punctuation, world!";
  ck_assert_str_eq(s21_strncpy(dest, str, n), strncpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_strncpy_destNull) {
  int n = 15;
  char *dest = S21_NULL;
  char *str =
      "This is a test string exactly 100 characters long, including "
      "spaces and punctuation, world!";
  ck_assert_ptr_eq(s21_strncpy(dest, str, n), S21_NULL);
}
END_TEST

START_TEST(test_s21_strncpy_strNull) {
  int n = 15;
  char dest[120];
  char *str = S21_NULL;
  ck_assert_ptr_eq(s21_strncpy(dest, str, n), S21_NULL);
}
END_TEST

START_TEST(test_s21_strncpy_allZero) {
  int n = 0;
  char *dest = S21_NULL;
  char *str = S21_NULL;
  ck_assert_ptr_eq(s21_strncpy(dest, str, n), S21_NULL);
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc_normalString = tcase_create("Core");

  tcase_add_test(tc_normalString, test_s21_strncpy_normal);
  tcase_add_test(tc_normalString, test_s21_strncpy_longString);
  tcase_add_test(tc_normalString, test_s21_strncpy_destNull);
  tcase_add_test(tc_normalString, test_s21_strncpy_strNull);
  tcase_add_test(tc_normalString, test_s21_strncpy_allZero);
  tcase_add_test(tc_normalString, test_s21_strncpy_unicode);
  tcase_add_test(tc_normalString, test_s21_strncpy_nOver);
  tcase_add_test(tc_normalString, test_s21_strncpy_embeddedNull);

  suite_add_tcase(s, tc_normalString);

  return s;
}