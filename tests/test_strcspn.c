#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strcspn_normal) {
  char *str = "Hello, world!";
  char *reject = " ,!";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_unicode) {
  char *str =
      "Дуэйн Дуглас Джонсон — американский киноактёр, предприниматель, "
      "музыкант, певец, рестлер.";
  char *reject = ",";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_str_empty) {
  char *str = "";
  char *reject = " ,!";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_reject_empty) {
  char *str = "Hello, world!";
  char *reject = "";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_str_long) {
  char *str =
      "This is a test string exactly 100 characters long, including "
      "spaces and punctuation! Enjoy coding :)";
  char *reject = ":";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_reject_EFO) {
  char *str = "Hello, world!";
  char *reject = "\0";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_reject_embeddedNull) {
  char str[] = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'};
  char *reject = "d";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_multiple_same_chars) {
  char *str = "aaaabbbbcccc";
  char *reject = "b";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_delimiters_at_start_and_end) {
  char *str = " ,!Hello, world!,! ";
  char *reject = " ,!";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_no_matches) {
  char *str = "Hello, world!";
  char *reject = "xyz";
  ck_assert_uint_eq(s21_strcspn(str, reject), strcspn(str, reject));
}
END_TEST

START_TEST(test_s21_strcspn_str_null) {
  char *str = S21_NULL;
  char *reject = "xyz";
  ck_assert_uint_eq(s21_strcspn(str, reject), 0);
}
END_TEST

START_TEST(test_s21_strcspn_reject_null) {
  char *str = "Hello, world!";
  char *reject = S21_NULL;
  ck_assert_uint_eq(s21_strcspn(str, reject), 0);
}
END_TEST

START_TEST(test_s21_strcspn_all_null) {
  char *str = S21_NULL;
  char *reject = S21_NULL;
  ck_assert_uint_eq(s21_strcspn(str, reject), 0);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn_normal);
  tcase_add_test(tc_core, test_s21_strcspn_unicode);
  tcase_add_test(tc_core, test_s21_strcspn_str_empty);
  tcase_add_test(tc_core, test_s21_strcspn_reject_empty);
  tcase_add_test(tc_core, test_s21_strcspn_str_long);
  tcase_add_test(tc_core, test_s21_strcspn_reject_EFO);
  tcase_add_test(tc_core, test_s21_strcspn_reject_embeddedNull);
  tcase_add_test(tc_core, test_s21_strcspn_multiple_same_chars);
  tcase_add_test(tc_core, test_s21_strcspn_delimiters_at_start_and_end);
  tcase_add_test(tc_core, test_s21_strcspn_no_matches);
  tcase_add_test(tc_core, test_s21_strcspn_str_null);
  tcase_add_test(tc_core, test_s21_strcspn_reject_null);
  tcase_add_test(tc_core, test_s21_strcspn_all_null);

  suite_add_tcase(s, tc_core);

  return s;
}