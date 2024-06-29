CC=gcc
FLAGS=-std=c11 -Werror -Wall -Wextra
ASAN:=#-fsanitize=address
OBJ_DIR=./objs
TEST_OBJ_DIR=./tests/objs
C_FILES=$(shell find s21_*.c)
H_FILES=$(shell find s21_*.h)
TEST_C_FILES=$(shell find tests/s21_*.c)
TEST_H_FILES=$(shell find tests/s21_*.h)
OBJ_FILES=$(addprefix $(OBJ_DIR)/, $(notdir $(C_FILES:.c=.o)))
TEST_OBJ_FILES=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_C_FILES:.c=.o)))
TST_LIBS=$(shell pkg-config --cflags --libs check) #-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
TARGET=s21_string.a
MK:=mkdir -p

all: test s21_string.a gcov_report

$(TARGET): $(OBJ_FILES)
	ar rc $(TARGET) $(OBJ_FILES)
	ranlib $(TARGET)

$(OBJ_FILES): $(C_FILES)
	@$(MK) $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

test: $(TARGET) $(TEST_OBJ_FILES) $(TEST_OBJ_DIR)/main.o 
	$(CC) $(FLAGS) $(TEST_OBJ_FILES) $(TEST_OBJ_DIR)/main.o -o test $(TST_LIBS) -L. $(TARGET)

$(TEST_OBJ_FILES): $(TEST_C_FILES)
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(TEST_OBJ_DIR)/main.o: main.c 
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(FLAGS) main.c -c -o $(TEST_OBJ_DIR)/main.o

	
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

clean_with_tests:
	rm -rf $(TARGET)
	rm -rf actual_output.txt
	rm -rf expected_output.txt
	rm -rf valgrind_results

rebuild: clean s21_cat