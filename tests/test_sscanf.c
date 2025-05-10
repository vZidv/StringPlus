#include <check.h>
#include <stdio.h>
#include <wchar.h>

#include "../src/s21_string.h"

START_TEST(test_s21_sscanf_specificator_c_normal) {
  char *str = "Aboba";
  char *format = "%c";
  char a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_c_with_width) {
  char *str = "Aboba";
  char *format = "%3c";
  char a[5] = {0};
  char b[5] = {0};

  int result1 = s21_sscanf(str, format, a);
  int result2 = sscanf(str, format, b);

  ck_assert_str_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_c_mod_l) {
  char *str = "Aboba";
  char *format = "%lc";
  wchar_t a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_s_normal) {
  char *str = "Aboba";
  char *format = "%s";

  char buffer1[50];
  char buffer2[50];

  int result1 = s21_sscanf(str, format, buffer1);
  int result2 = sscanf(str, format, buffer2);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_s_with_width) {
  char *str = "Aboba";
  char *format = "%4s";

  char buffer1[50];
  char buffer2[50];

  int result1 = s21_sscanf(str, format, buffer1);
  int result2 = sscanf(str, format, buffer2);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_s_mod_l) {
  char *str = "Aboba";
  char *format = "%ls";

  wchar_t buffer1[50];
  wchar_t buffer2[50];

  int result1 = s21_sscanf(str, format, buffer1);
  int result2 = sscanf(str, format, buffer2);

  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_normal) {
  char *str = "123";
  char *format = "%d";

  int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_with_width) {
  char *str = "12345";
  char *format = "%3d";

  int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_mod_h) {
  char *str = "12345";
  char *format = "%hd";

  short a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_mod_l) {
  char *str = "12345";
  char *format = "%ld";

  long int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_mod_L) {
  char *str = "12345";
  char *format = "%Ld";

  long long a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_num_zero) {
  char *str = "0";
  char *format = "%d";

  int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_with_sign_plus) {
  char *str = "+123";
  char *format = "%d";

  int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_d_with_sign_minus) {
  char *str = "-123";
  char *format = "%d";

  int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_f_normal) {
  char *str = "123.456";
  char *format = "%f";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_f_with_width) {
  char *str = "123.456";
  char *format = "%4f";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_f_mod_L) {
  char *str = "123.456";
  char *format = "%Lf";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_f_mod_l) {
  char *str = "123.456";
  char *format = "%lf";

  double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_f_num_zero) {
  char *str = "0.0";
  char *format = "%f";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_u_normal) {
  char *str = "123456";
  char *format = "%u";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_u_with_width) {
  char *str = "123456";
  char *format = "%3u";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_u_mod_h) {
  char *str = "123456";
  char *format = "%hu";

  unsigned short a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_u_mod_l) {
  char *str = "123456";
  char *format = "%lu";

  unsigned long int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_u_mod_L) {
  char *str = "123456";
  char *format = "%Lu";

  unsigned long long a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_u_num_zero) {
  char *str = "0";
  char *format = "%u";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_normal_decimal) {
  char *str = "12.02456";
  char *format = "%g";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_with_width_decimal) {
  char *str = "12.02456";
  char *format = "%4g";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_mod_L_decimal) {
  char *str = "12.02456";
  char *format = "%Lg";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_mod_l_decimal) {
  char *str = "12.02456";
  char *format = "%lg";

  double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_num_zero_decimal) {
  char *str = "12.02456";
  char *format = "%g";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_normal_Exponetial) {
  char *str = "3.36E+5";
  char *format = "%g";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_with_width_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%3g";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_mod_L_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%Lg";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_mod_l_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%lg";

  double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_g_num_zero_Exponetial) {
  char *str = "0.0";
  char *format = "%g";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_normal_decimal) {
  char *str = "12.02456";
  char *format = "%G";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_with_width_decimal) {
  char *str = "12.02456";
  char *format = "%4G";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_mod_L_decimal) {
  char *str = "12.02456";
  char *format = "%LG";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_mod_l_decimal) {
  char *str = "12.02456";
  char *format = "%LG";

  double long a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_num_zero_decimal) {
  char *str = "0.0";
  char *format = "%G";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_normal_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%G";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_with_width_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%3G";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_mod_L_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%LG";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_mod_l_Exponetial) {
  char *str = "3.36e+5";
  char *format = "%lG";

  double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_G_num_zero_Exponetial) {
  char *str = "0.0";
  char *format = "%G";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_float_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_x_normal) {
  char *str = "12B";
  char *format = "%x";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_x_with_width) {
  char *str = "12B";
  char *format = "%2x";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_x_mod_h) {
  char *str = "12B";
  char *format = "%hx";

  unsigned short a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_x_mod_l) {
  char *str = "12B";
  char *format = "%lx";

  unsigned long int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_x_num_zero) {
  char *str = "0";
  char *format = "%x";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_X_normal) {
  char *str = "12B";
  char *format = "%X";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_X_with_width) {
  char *str = "12B";
  char *format = "%2X";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_X_mod_h) {
  char *str = "12B";
  char *format = "%hX";

  unsigned short a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_X_mod_l) {
  char *str = "12B";
  char *format = "%lX";

  unsigned long int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_X_num_zero) {
  char *str = "0";
  char *format = "%X";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_o_normal) {
  char *str = "255";
  char *format = "%o";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_o_mod_h) {
  char *str = "255";
  char *format = "%ho";

  short a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_o_mod_l) {
  char *str = "255";
  char *format = "%lo";

  unsigned long int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_o_with_width) {
  char *str = "255";
  char *format = "%2o";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_o_num_zero) {
  char *str = "0";
  char *format = "%o";

  unsigned int a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_uint_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_p_normal) {
  const char *input = "0x7ffee4b5c9a4";

  void *original, *custom;

  int res1 = sscanf(input, "%p", &original);
  int res2 = s21_sscanf(input, "%p", &custom);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(original, custom);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_p_normal_big_X) {
  const char *input = "0X7ffee4b5c9a4";

  void *original, *custom;

  int res1 = sscanf(input, "%p", &original);
  int res2 = s21_sscanf(input, "%p", &custom);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(original, custom);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_p_with_width) {
  const char *input = "0x7ffee4b5c9a4";

  void *original, *custom;

  int res1 = sscanf(input, "%4p", &original);
  int res2 = s21_sscanf(input, "%4p", &custom);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(original, custom);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_e_normal) {
  char *str = "5.000032e+7";
  char *format = "%e";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_e_normal_minus) {
  char *str = "5.000032e-7";
  char *format = "%e";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_e_with_width) {
  char *str = "5.000032e+7";
  char *format = "%4e";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_e_mod_L) {
  char *str = "5.000032e+7";
  char *format = "%Le";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_e_mod_l) {
  char *str = "5.000032e+7";
  char *format = "%le";

  double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_e_num_zero) {
  char *str = "0";
  char *format = "%e";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_E_normal) {
  char *str = "5.000032e+7";
  char *format = "%E";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_E_normal_minus) {
  char *str = "5.000032e-7";
  char *format = "%E";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_E_with_width) {
  char *str = "5.000032e+7";
  char *format = "%4E";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_E_mod_L) {
  char *str = "5.000032e+7";
  char *format = "%LE";

  long double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_E_mod_l) {
  char *str = "5.000032e+7";
  char *format = "%lE";

  double a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_sscanf_specificator_E_num_zero) {
  char *str = "0";
  char *format = "%E";

  float a, b;

  int result1 = s21_sscanf(str, format, &a);
  int result2 = sscanf(str, format, &b);

  ck_assert_double_eq(a, b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite *s21_sscanf_suite(void) {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sscanf_specificator_c_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_c_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_c_mod_l);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_s_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_s_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_s_mod_l);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_mod_h);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_mod_L);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_num_zero);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_with_sign_plus);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_d_with_sign_minus);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_f_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_f_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_f_mod_L);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_f_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_f_num_zero);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_u_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_u_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_u_mod_h);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_u_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_u_mod_L);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_u_num_zero);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_normal_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_with_width_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_mod_L_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_mod_l_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_num_zero_decimal);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_normal_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_with_width_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_mod_L_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_mod_l_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_g_num_zero_Exponetial);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_normal_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_with_width_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_mod_L_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_mod_l_decimal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_num_zero_decimal);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_normal_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_with_width_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_mod_L_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_mod_l_Exponetial);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_G_num_zero_Exponetial);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_x_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_x_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_x_mod_h);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_x_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_x_num_zero);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_X_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_X_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_X_mod_h);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_X_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_X_num_zero);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_o_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_o_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_o_mod_h);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_o_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_o_num_zero);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_p_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_p_normal_big_X);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_p_with_width);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_e_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_e_normal_minus);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_e_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_e_mod_L);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_e_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_e_num_zero);

  tcase_add_test(tc_core, test_s21_sscanf_specificator_E_normal);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_E_normal_minus);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_E_with_width);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_E_mod_L);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_E_mod_l);
  tcase_add_test(tc_core, test_s21_sscanf_specificator_E_num_zero);

  suite_add_tcase(s, tc_core);

  return s;
}