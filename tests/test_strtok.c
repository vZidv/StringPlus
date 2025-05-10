#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strtok_normal) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";

  char *delim = " ,!";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_unicode) {
  char str1[] =
      "Хидэо Кодзима — японский геймдизайнер, геймдиректор, "
      "сценарист, продюсер и актёр.";
  char str2[] =
      "Хидэо Кодзима — японский геймдизайнер, геймдиректор, "
      "сценарист, продюсер и актёр.";

  char *delim = ",";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_not_contain_delim) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";

  char *delim = "?";

  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_s21_strtok_embeddedNull) {
  char str1[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                 'W', 'o', 'r', 'l', 'd', '!'};
  char str2[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                 'W', 'o', 'r', 'l', 'd', '!'};

  char *delim = " ,!";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_empty_string) {
  char str1[] = "";
  char str2[] = "";
  char *delim = " ,!";
  ck_assert_ptr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_s21_strtok_only_delimiters) {
  char str1[] = " ,!";
  char str2[] = " ,!";
  char *delim = " ,!";
  ck_assert_ptr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_s21_strtok_long_string) {
  char str1[200] =
      "This is a very long string with multiple delimiters like "
      "spaces, commas, and exclamation marks!";
  char str2[200] =
      "This is a very long string with multiple delimiters like "
      "spaces, commas, and exclamation marks!";
  char *delim = " ,!";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_strtok_normal);
  tcase_add_test(tc_core, test_s21_strtok_unicode);
  tcase_add_test(tc_core, test_s21_strtok_not_contain_delim);
  tcase_add_test(tc_core, test_s21_strtok_embeddedNull);
  tcase_add_test(tc_core, test_s21_strtok_empty_string);
  tcase_add_test(tc_core, test_s21_strtok_only_delimiters);
  tcase_add_test(tc_core, test_s21_strtok_long_string);

  suite_add_tcase(s, tc_core);
  return s;
}