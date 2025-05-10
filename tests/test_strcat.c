#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strcat_normal) {
  char dest[50] = "Hello";
  char str[] = ", World!";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_normal_encode) {
  char dest[50] = "Камень и";
  char str[] = " БУЛЫЖНИК!";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_n_zero) {
  char dest[50] = "Hello";
  char str[] = ", World!";
  ck_assert_str_eq(s21_strncat(dest, str, 0), strncat(dest, str, 0));
}
END_TEST

START_TEST(test_s21_strcat_n_big) {
  char dest[100000] = "Hello";
  char str[] = ", World!";
  ck_assert_str_eq(s21_strncat(dest, str, 10000), strncat(dest, str, 10000));
}
END_TEST

START_TEST(test_s21_strcat_long_dest) {
  char dest[100] =
      "This is a test string exactly 100 characters long, "
      "including spaces and punctuation";
  char str[] = ", World!";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_long_str) {
  char dest[100] = "This is a test ";
  char str[] =
      "string exactly 100 characters long, including spaces and "
      "punctuation, World!";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_empty_dest) {
  char dest[100] = "";
  char str[] =
      "string exactly 100 characters long, including spaces and "
      "punctuation, World!";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_empty_str) {
  char dest[100] = "This is a test ";
  char str[] = "";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_charEFO_str) {
  char dest[100] = "This is a test ";
  char str[] = "\0";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_charEFO_dest) {
  char dest[100] = "\0";
  char str[] =
      "string exactly 100 characters long, including spaces and "
      "punctuation, World!";
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_embedded_null) {
  char dest[50] = "Hello";
  char str[] = {' ', 'W', 'o', 'r', 'l', 'd', '\0', '!', '\0'};
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

START_TEST(test_s21_strcat_null_dest) {
  char *dest = NULL;
  char str[] = ", World!";
  ck_assert_ptr_eq(s21_strncat(dest, str, 8), NULL);
}
END_TEST

START_TEST(test_s21_strcat_null_str) {
  char dest[50] = "Hello";
  char *str = NULL;
  ck_assert_ptr_eq(s21_strncat(dest, str, 8), NULL);
}
END_TEST

START_TEST(test_s21_strcat_embedded_null_2) {
  char dest[50] = "Hello";
  char str[] = {' ', '\0', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
  ck_assert_str_eq(s21_strncat(dest, str, 8), strncat(dest, str, 8));
}
END_TEST

Suite *s21_strcat_suite(void) {
  Suite *s = suite_create("s21_strcat");

  TCase *tc_normalString = tcase_create("Normal_String");
  tcase_add_test(tc_normalString, test_s21_strcat_normal);
  tcase_add_test(tc_normalString, test_s21_strcat_long_dest);
  tcase_add_test(tc_normalString, test_s21_strcat_long_str);
  tcase_add_test(tc_normalString, test_s21_strcat_empty_dest);
  tcase_add_test(tc_normalString, test_s21_strcat_empty_str);
  tcase_add_test(tc_normalString, test_s21_strcat_charEFO_dest);
  tcase_add_test(tc_normalString, test_s21_strcat_charEFO_str);
  tcase_add_test(tc_normalString, test_s21_strcat_n_zero);
  tcase_add_test(tc_normalString, test_s21_strcat_n_big);
  tcase_add_test(tc_normalString, test_s21_strcat_normal_encode);
  tcase_add_test(tc_normalString, test_s21_strcat_embedded_null);
  tcase_add_test(tc_normalString, test_s21_strcat_null_dest);
  tcase_add_test(tc_normalString, test_s21_strcat_null_str);
  tcase_add_test(tc_normalString, test_s21_strcat_embedded_null_2);

  suite_add_tcase(s, tc_normalString);

  return s;
}