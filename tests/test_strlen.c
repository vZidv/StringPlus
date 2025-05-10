#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strlen_normalString) {
  const char *str = "Hello, World!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_unicodeString) {
  const char *str = "Латиница Латиница. ПРОВЕРКААА";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_embeddedNull) {
  const char str[] = {'H', 'e', 'l', 'l', 'o', '\0',
                      'W', 'o', 'r', 'l', 'd', '\0'};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_longString) {
  const char *str =
      "This is a test string exactly 100 characters long, "
      "including spaces and punctuation! Enjoy coding :)";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_emptyString) {
  const char *str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_emptyStringSpace) {
  const char *str = "   ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s = suite_create("s21_strlen");

  TCase *tc_normalString = tcase_create("Normal_String");
  tcase_add_test(tc_normalString, test_s21_strlen_normalString);
  tcase_add_test(tc_normalString, test_s21_strlen_longString);
  tcase_add_test(tc_normalString, test_s21_strlen_unicodeString);
  tcase_add_test(tc_normalString, test_s21_strlen_embeddedNull);

  TCase *tc_emptyString = tcase_create("Empty_String");
  tcase_add_test(tc_emptyString, test_s21_strlen_emptyString);
  tcase_add_test(tc_emptyString, test_s21_strlen_emptyStringSpace);

  suite_add_tcase(s, tc_normalString);
  suite_add_tcase(s, tc_emptyString);

  return s;
}