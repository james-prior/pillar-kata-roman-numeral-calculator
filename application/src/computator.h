#if !defined(COMPUTATOR_H)
#define COMPUTATOR_H

// TEST_MAIN is defined by compiler for testing.
#if defined(TEST_MAIN)
#define MAIN_FUNCTION testable_main
int testable_main(int argc, char *argv[]);
#else
#define MAIN_FUNCTION main
#endif

char *meat(int argc, char *argv[]);
#endif
