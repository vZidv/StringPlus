#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_memcpy_normal) {
  int n = 14;
  char dest[30];
  char *str = "Hello, World!";
  ck_assert_str_eq(s21_memcpy(dest, str, n), memcpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_memcpy_unicode) {
  int n = 50;
  char dest[300] = {0};
  char *str =
      "Макароны по-флотски — классическое блюдо русской кухни, которое "
      "сочетает простоту, быстроту готовки и сытность.";
  ck_assert_str_eq(s21_memcpy(dest, str, n), memcpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_memcpy_embeddedNull) {
  int n = 13;
  char dest[50];
  char str[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                'W', 'o', 'r', 'l', 'd', '!'};
  ck_assert_str_eq(s21_memcpy(dest, str, n), memcpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_memcpy_longString) {
  int n = 92;
  char dest[120];
  char *str =
      "This is a test string exactly 100 characters long, including "
      "spaces and punctuation, world!";
  ck_assert_str_eq(s21_memcpy(dest, str, n), memcpy(dest, str, n));
}
END_TEST

START_TEST(test_s21_memcpy_destNull) {
  int n = 15;
  char *dest = S21_NULL;
  char *str =
      "This is a test string exactly 100 characters long, including "
      "spaces and punctuation, world!";
  ck_assert_ptr_eq(s21_memcpy(dest, str, n), S21_NULL);
}
END_TEST

START_TEST(test_s21_smemcpy_strNull) {
  int n = 15;
  char dest[120];
  char *str = S21_NULL;
  ck_assert_ptr_eq(s21_memcpy(dest, str, n), S21_NULL);
}
END_TEST

START_TEST(test_s21_memcpy_allZero) {
  int n = 0;
  char *dest = S21_NULL;
  char *str = S21_NULL;
  ck_assert_ptr_eq(s21_memcpy(dest, str, n), S21_NULL);
}
END_TEST

START_TEST(test_s21_memcpy_empty_strings) {
  char dest[50] = {0};
  char *str = "";
  int n = 0;
  ck_assert_str_eq(s21_memcpy(dest, str, n), memcpy(dest, str, n));
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcpy_normal);
  tcase_add_test(tc_core, test_s21_memcpy_unicode);
  tcase_add_test(tc_core, test_s21_memcpy_embeddedNull);
  tcase_add_test(tc_core, test_s21_memcpy_longString);
  tcase_add_test(tc_core, test_s21_memcpy_destNull);
  tcase_add_test(tc_core, test_s21_smemcpy_strNull);
  tcase_add_test(tc_core, test_s21_memcpy_allZero);
  tcase_add_test(tc_core, test_s21_memcpy_empty_strings);

  suite_add_tcase(s, tc_core);
  return s;
}