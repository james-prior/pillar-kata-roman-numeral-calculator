#if !defined(COMPUTATOR_H)
#define COMPUTATOR_H

// TEST_MAIN is defined by compiler for testing.
#if defined(TEST_MAIN)
#define MAIN_FUNCTION testable_main
#else
#define MAIN_FUNCTION main
#endif

struct main_return_struct {
    char *stdout;
    int exit_status;
};

struct main_return_struct *kinda_main(int argc, char *argv[]);
#endif
