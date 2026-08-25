#include "exercise_1_1.h"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}


void test_print_hello_world(void) {
    print_hello_world();
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_print_hello_world);

    return UNITY_END();
}