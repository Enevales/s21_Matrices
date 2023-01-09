CC = gcc
CFLAGS = -Wall -Wextra -Werror #-std=c11 -pedantic
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -lgcov --coverage
PREF_SRC = ./lib/
PREF_TEST = ./tests/
SOURCES =  $(wildcard $(PREF_SRC)*.c)
OBJECTS = $(patsubst $(PREF_SRC)%.c, %.o, $(SOURCES))
TESTS = $(wildcard $(PREF_TEST)*.c)
UNAME:=$(shell uname -s)
LIB = s21_matrix.a

ifeq ($(UNAME),Linux)
	LDLIBS = -lcheck `pkg-config --cflags --libs check`
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDLIBS = -lcheck
	OPEN_CM=open
endif

all: clean $(LIB)

test: $(TESTS) $(PREF_TEST)s21_tests.h
	$(CC) $(CFLAGS) $(OBJECTS) $^ -o ./a.out $(LDLIBS) -L. $(LIB)
	exec ./a.out


$(LIB): $(OBJECTS)
	ar rcs $(LIB) $^
	ranlib $(LIB)

%.o : $(PREF_SRC)%.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@


gcov_report:
	$(CC) $(GCOVFLAGS) $(LCOVFLAGS) $(SOURCES) $(TESTS) -o report.out $(LDLIBS)
	./report.out
	gcov -f $(SOURCES) 
	lcov -t "gcov_report" --no-external -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	$(OPEN_CM) ./report/index-sort-f.html

# 	# gcovr --html-details  report.html
# 	# $(OPEN_CM) report.html


clang:
	cppcheck $(SOURCES) $(TESTS) *.h *.c
	cp ../materials/linters/.clang-format .clang-format
	# clang-format -i lib/*.c
	clang-format -n lib/*.c
	rm -rf .clang-format

valgrind: test
	valgrind -s --leak-check=full --show-leak-kinds=all  ./a.out

leaks:
		CK_FORK=no leaks --atExit -- ./a.out

clean:
	rm -rf $(LIB)
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov
	find . -name '*.o' -name '*.out' -type f -delete
	rm -rf ./report/*.png ./report/*.html ./report/*.css 
	rm -rf ./report/lib/*.html ./report/tests/*.html
	find . -name '*.gcno' -type f -delete
	find . -name '*.gcda' -type f -delete
	find . -name '*.info' -type f -delete
	rm -rf test
	rm -rf *.html 
	rm -rf *.css
