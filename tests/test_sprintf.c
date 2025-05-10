#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/s21_string.h"

START_TEST(test_s21_sprintf_specificator_d_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 13464;
  const char *format = "Super mega test %d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = 'c';
  const char *format = "Super mega %cool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_s_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char *s = "It's me Mario.";
  const char *format = "Omg who is that? %s";
  ck_assert_int_eq(s21_sprintf(buffer1, format, s),
                   sprintf(buffer2, format, s));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.23345;
  const char *format = "Super mega number %f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_normal_plus) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = +1643.23345;
  const char *format = "Super mega number %f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_decimal_zero) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.0;
  const char *format = "Super mega number %f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_u_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 888555355;
  const char *format = "Super mega number %u";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_g_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double u = 1234.004345;
  const char *format = "Super mega number %g";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_G_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double u = 1234.004345;
  const char *format = "Super mega number %G";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double u = 12.0004345;
  const char *format = "Super mega number %e";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double u = 12.0004345;
  const char *format = "Super mega number %E";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 255;
  const char *format = "Super mega number %x";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 255;
  const char *format = "Super mega number %X Super mega number";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 255;
  const char *format = "Super mega number %o Super mega number";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *u = S21_NULL;
  const char *format = "Super mega number %p Super mega number";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_procent_normal) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = '%';
  const char *format = "Super mega %%ool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 13464;
  const char *format = "Super mega test %12d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 13464;
  const char *format = "Super mega test %-12d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 13464;
  const char *format = "Super mega test %-                 12d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 13464;
  const char *format = "Super mega test %-12.8d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 13464;
  const char *format = "Super mega test %.d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = 'c';
  const char *format = "Super mega %12cool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = 'c';
  const char *format = "Super mega %-12cool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = 'c';
  const char *format = "Super mega %-                        12cool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = 'c';
  const char *format = "Super mega %12.23cool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char c = 'c';
  const char *format = "Super mega %.cool";
  ck_assert_int_eq(s21_sprintf(buffer1, format, c),
                   sprintf(buffer2, format, c));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_s_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char *s = "It's me Mario.";
  const char *format = "Omg who is that? %19s";
  ck_assert_int_eq(s21_sprintf(buffer1, format, s),
                   sprintf(buffer2, format, s));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_s_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char *s = "It's me Mario.";
  const char *format = "Omg who is that? %-19s";
  ck_assert_int_eq(s21_sprintf(buffer1, format, s),
                   sprintf(buffer2, format, s));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_s_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char *s = "It's me Mario.";
  const char *format = "Omg who is that? %-                      19s";
  ck_assert_int_eq(s21_sprintf(buffer1, format, s),
                   sprintf(buffer2, format, s));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_s_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char *s = "It's me Mario.";
  const char *format = "Omg who is that? %10.23s";
  ck_assert_int_eq(s21_sprintf(buffer1, format, s),
                   sprintf(buffer2, format, s));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_s_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char *s = "It's me Mario.";
  const char *format = "Omg who is that? %.s";
  ck_assert_int_eq(s21_sprintf(buffer1, format, s),
                   sprintf(buffer2, format, s));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.23345;
  const char *format = "Super mega number %22f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.23345;
  const char *format = "Super mega number %-22f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.23345;
  const char *format = "Super mega number %-                       22f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.23345;
  const char *format = "Super mega number %10.12f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double f = 1643.23345;
  const char *format = "Super mega number %.f";
  ck_assert_int_eq(s21_sprintf(buffer1, format, f),
                   sprintf(buffer2, format, f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_u_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 888555355;
  const char *format = "Super mega number %22u";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_u_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 888555355;
  const char *format = "Super mega number %-22u";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_u_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 888555355;
  const char *format = "Super mega number %-                   22u";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_u_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 888555355;
  const char *format = "Super mega number %22.33u";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_u_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int u = 888555355;
  const char *format = "Super mega number %.u";
  ck_assert_int_eq(s21_sprintf(buffer1, format, u),
                   sprintf(buffer2, format, u));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_g_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %12g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_g_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %-12g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_g_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %-                 12g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_g_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %-12.8g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_g_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %.g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_G_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %.G. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_G_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %12G. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_G_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %-12g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_G_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %-                 12G. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_G_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.00345;
  const char *format = "Super mega test %-12.8g. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %.e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %12e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %-12e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %-                 12e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %-12.8e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_nan) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = nan("");
  const char *format = "Super mega test %-12.8e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_nan) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = nan("");
  const char *format = "Super mega test %-12.8E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_e_with_infinity) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = INFINITY;
  const char *format = "Super mega test %-12.8e. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %12E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_infinity) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = INFINITY;
  const char *format = "Super mega test %-12.8E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %-12E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %-                 12E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %-12.8E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_E_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  double n = 56.0000045;
  const char *format = "Super mega test %.E. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %12x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-12x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-                 12x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-12.8x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %.x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %12X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-12X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-                 12X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-12.8X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %.X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %12o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-12o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-                 12o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %-12.8o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 56;
  const char *format = "Super mega test %.o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_alignment_right) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %12p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_alignment_left) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %-12p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_alignment_left_more_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %-                 12p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %-12.8p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_empty_width_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %.p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_dinamic_width) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char n = 'g';
  const char *format = "Super mega test %*.c. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, 1, n),
                   sprintf(buffer2, format, 1, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_dinamic_width) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 678;
  const char *format = "Super mega test %*.d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, 3, n),
                   sprintf(buffer2, format, 3, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_dinamic_width) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 233;
  const char *format = "Super mega test %*.x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_dinamic_width) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 233;
  const char *format = "Super mega test %*.X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_dinamic_width) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 233;
  const char *format = "Super mega test %*.o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_dinamic_width) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %*.p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_c_with_dinamic_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  char n = 'g';
  const char *format = "Super mega test %.*c. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_with_dinamic_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int n = 678;
  const char *format = "Super mega test %.*d. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_with_dinamic_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 233;
  const char *format = "Super mega test %.*x. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_with_dinamic_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 233;
  const char *format = "Super mega test %.*X. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_with_dinamic_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  unsigned int n = 233;
  const char *format = "Super mega test %.*o. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_p_with_dinamic_accuracy) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};

  int *n = S21_NULL;
  const char *format = "Super mega test %.*p. Yes yes.";
  ck_assert_int_eq(s21_sprintf(buffer1, format, n),
                   sprintf(buffer2, format, n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_plus_positive) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  int n = 12345;
  ck_assert_int_eq(s21_sprintf(buffer1, "Number: %+d", n),
                   sprintf(buffer2, "Number: %+d", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_plus_negative) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  int n = -12345;
  ck_assert_int_eq(s21_sprintf(buffer1, "Number: %+d", n),
                   sprintf(buffer2, "Number: %+d", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_plus) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  double f = 123.456;
  ck_assert_int_eq(s21_sprintf(buffer1, "Value: %+f", f),
                   sprintf(buffer2, "Value: %+f", f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  int n = 12345;
  ck_assert_int_eq(s21_sprintf(buffer1, "Number: % d", n),
                   sprintf(buffer2, "Number: % d", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_space) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  double f = 123.456;
  ck_assert_int_eq(s21_sprintf(buffer1, "Value: % f", f),
                   sprintf(buffer2, "Value: % f", f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_hash) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  unsigned int n = 255;
  ck_assert_int_eq(s21_sprintf(buffer1, "Hex: %#x", n),
                   sprintf(buffer2, "Hex: %#x", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_X_hash) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  unsigned int n = 255;
  ck_assert_int_eq(s21_sprintf(buffer1, "Hex: %#X", n),
                   sprintf(buffer2, "Hex: %#X", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_o_hash) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  unsigned int n = 63;
  ck_assert_int_eq(s21_sprintf(buffer1, "Octal: %#o", n),
                   sprintf(buffer2, "Octal: %#o", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_hash) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  double f = 123.0;
  ck_assert_int_eq(s21_sprintf(buffer1, "Value: %#.0f", f),
                   sprintf(buffer2, "Value: %#.0f", f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_zero_pad) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  int n = 42;
  ck_assert_int_eq(s21_sprintf(buffer1, "Number: %010d", n),
                   sprintf(buffer2, "Number: %010d", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_f_zero_pad) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  double f = 123.456;
  ck_assert_int_eq(s21_sprintf(buffer1, "Value: %015f", f),
                   sprintf(buffer2, "Value: %015f", f));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_d_plus_zero) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  int n = 42;
  ck_assert_int_eq(s21_sprintf(buffer1, "Number: %+010d", n),
                   sprintf(buffer2, "Number: %+010d", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_specificator_x_hash_zero) {
  char buffer1[1024] = {0};
  char buffer2[1024] = {0};
  unsigned int n = 255;
  ck_assert_int_eq(s21_sprintf(buffer1, "Hex: %#010x", n),
                   sprintf(buffer2, "Hex: %#010x", n));
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_c_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_s_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_u_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_g_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_G_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_e_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_E_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_X_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_o_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_p_normal);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_procent_normal);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_c_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_s_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_u_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_g_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_G_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_e_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_E_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_X_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_o_with_alignment_right);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_p_with_alignment_right);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_c_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_s_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_u_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_g_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_G_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_e_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_E_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_X_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_o_with_alignment_left);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_p_with_alignment_left);

  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_d_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_c_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_s_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_f_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_u_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_g_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_G_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_e_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_E_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_x_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_X_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_o_with_alignment_left_more_space);
  tcase_add_test(
      tc_core, test_s21_sprintf_specificator_p_with_alignment_left_more_space);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_c_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_s_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_u_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_g_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_G_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_e_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_E_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_X_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_o_with_width_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_p_with_width_accuracy);

  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_d_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_c_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_s_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_f_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_u_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_g_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_G_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_e_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_E_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_x_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_X_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_o_with_empty_width_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_p_with_empty_width_accuracy);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_c_with_dinamic_width);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_with_dinamic_width);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_with_dinamic_width);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_X_with_dinamic_width);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_o_with_dinamic_width);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_p_with_dinamic_width);

  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_c_with_dinamic_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_d_with_dinamic_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_x_with_dinamic_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_X_with_dinamic_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_o_with_dinamic_accuracy);
  tcase_add_test(tc_core,
                 test_s21_sprintf_specificator_p_with_dinamic_accuracy);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_plus_positive);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_plus_negative);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_plus);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_space);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_space);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_hash);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_X_hash);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_o_hash);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_hash);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_zero_pad);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_zero_pad);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_d_plus_zero);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_x_hash_zero);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_normal_plus);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_f_decimal_zero);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_e_with_nan);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_E_with_nan);

  tcase_add_test(tc_core, test_s21_sprintf_specificator_e_with_infinity);
  tcase_add_test(tc_core, test_s21_sprintf_specificator_E_with_infinity);

  suite_add_tcase(s, tc_core);

  return s;
}