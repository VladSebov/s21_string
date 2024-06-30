#Variables for gcc:
CC=gcc
FLAGS=-std=c11 -Werror -Wall -Wextra
ASAN=-g -fsanitize=address
#Our static library
TARGET=s21_string.a
TEST_TARGET=tests.a
#Directories for .o files
SRC_DIR=./
OBJ_DIR=./objs
TEST_OBJ_DIR=./tests_objs
#Variables for compiling .o files used in s21_string.a 
C_FILES=$(shell find s21_*.c)
OBJ_FILES=$(addprefix $(OBJ_DIR)/, $(notdir $(C_FILES:.c=.o)))
#Variables for compiling .o files used in unit-testing
TEST_C_FILES=$(shell find tests/s21_*.c)
TEST_OBJ_FILES=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_C_FILES:.c=.o)))
TEST_LIBS=$(shell pkg-config --cflags --libs check) #-pthread -lcheck_pic -pthread -lrt -lm -lsubunit

all: test

s21_string.a: $(OBJ_FILES)
	ar rc $(TARGET) $(OBJ_FILES)
	ranlib $(TARGET)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(ASAN) -o $@ -c $<

test: $(TARGET) $(TEST_OBJ_FILES) $(TEST_OBJ_DIR)/main.o
	$(CC) $(FLAGS) $(ASAN) $(TEST_OBJ_FILES) $(TEST_OBJ_DIR)/main.o -o test $(TEST_LIBS) -L. $(TARGET)

$(TEST_OBJ_DIR)/%.o: tests/%.c
	mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(ASAN) $(FLAGS) -o $@ -c $<

#$(TEST_OBJ_DIR)/s21_strlen_tests.o: tests/s21_strlen_tests.c
#	mkdir -p $(TEST_OBJ_DIR)
#	$(CC) $(ASAN) $(FLAGS) -o $@ -c $<


$(TEST_OBJ_DIR)/main.o: main.c 
	mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(ASAN) $(FLAGS) main.c -c -o $(TEST_OBJ_DIR)/main.o

run_test: test
	./test

test_leaks: test
	valgrind --tool=memcheck --leak-check=yes ./test


gcov_report:



style:
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i tests/*.c
	clang-format -i tests/*.h

check:
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n tests/*.c
	clang-format -n tests/*.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJ_DIR)
	rm -rf test 