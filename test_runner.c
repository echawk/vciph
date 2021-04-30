#include "munit/munit.h"
#include "reverse_string.h"
#include "vigenere.h"


static MunitResult
test_compare(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    char *string_1 = "revengemybabymegnever";
    munit_assert_string_equal(reverse_string(string_1), string_1);


    return MUNIT_OK;
}






static MunitTest
test_suite_tests[] = {
    { (char*) "Reverse String", test_compare, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};



static const MunitSuite
test_suite = {
    (char*) "",
    test_suite_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};


int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {

    return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
