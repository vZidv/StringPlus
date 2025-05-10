#include <check.h>
#include <stdlib.h>

#include "../src/s21_string.h"

START_TEST(test_s21_to_lower_normal) {
  const char *input = "Hello, world!";
  char *expected = "HELLO, WORLD!";

  char *result = s21_to_upper(input);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_empty) {
  const char *input = "";
  char *expected = "";

  char *result = s21_to_upper(input);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_only_space) {
  const char *input = "        ";
  char *expected = "        ";

  char *result = s21_to_upper(input);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_mix) {
  const char *input = "Hello1234FFFFf";
  char *expected = "HELLO1234FFFFF";

  char *result = s21_to_upper(input);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_null) {
  char *result = s21_to_upper(NULL);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_to_lower_non_letters) {
  const char *input = "1234!@#$";
  char *expected = "1234!@#$";

  char *result = s21_to_upper(input);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_were_upper) {
  const char *input = "ABOBA";
  char *expected = "ABOBA";

  char *result = s21_to_upper(input);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_lower_normal);
  tcase_add_test(tc_core, test_s21_to_lower_empty);
  tcase_add_test(tc_core, test_s21_to_lower_only_space);
  tcase_add_test(tc_core, test_s21_to_lower_mix);
  tcase_add_test(tc_core, test_s21_to_lower_null);
  tcase_add_test(tc_core, test_s21_to_lower_non_letters);
  tcase_add_test(tc_core, test_s21_to_upper_were_upper);

  suite_add_tcase(s, tc_core);

  return s;
}