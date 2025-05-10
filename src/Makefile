INCLUDE_DIR = include
FUNCTION_DIR = functions
TEST_DIR = ../tests
LIB_DIR = lib
LIB = s21_string.a
CLANG_FORMAT_CONFIG = ../materials/linters/.clang-format

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -I ./$(INCLUDE_DIR)
LDFLAGS = -lcheck -lm -lrt -lpthread -lsubunit

SRCS = $(wildcard $(FUNCTION_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TETS_OBJS =$(TEST_SRCS:.c=.o)
TEST_TARGET = $(TEST_DIR)/test_runner


.PHONY: all clean test_build s21_string.a gcov_report rebuild test format

all: s21_string.a test_build

rebuild: clean all
	@echo "Project has been rebuild."

s21_string.a: $(OBJS)
	ar rcs $@ $^
	rm -f $(FUNCTION_DIR)/*.o

test_build: $(TETS_OBJS)
	$(CC) $(CFLAGS) $(TETS_OBJS) -o $(TEST_TARGET) s21_string.a $(LDFLAGS)
	rm -rf $(TETS_OBJS)
	
test: test_build
	./$(TEST_TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(LIB) $(OBJS) $(TEST_DIR)/test_runner $(TETS_OBJS) *.html *.css $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno $(FUNCTION_DIR)/*.gcda $(FUNCTION_DIR)/*.gcno

gcov_report: CFLAGS += --coverage
gcov_report: LDFLAGS += --coverage
gcov_report: clean s21_string.a test_build
	./$(TEST_TARGET)
	gcovr -r . --html --html-details -o coverage.html \
		--object-directory=functions \
		--exclude tests/ \
		--gcov-ignore-errors=no_working_dir_found
