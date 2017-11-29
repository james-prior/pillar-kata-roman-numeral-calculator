tests/check_computator: src/computator.h src/computator.c tests/check_computator.c
	cc -DTEST_MAIN tests/check_computator.c src/computator.c -o tests/check_computator -lcheck -lm -lpthread -lsubunit -lrt

check: tests/check_computator
	tests/check_computator 

src/computator: src/computator.h src/computator.c
	cc src/computator.c -o src/computator

