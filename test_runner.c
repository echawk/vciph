#include "munit/munit.h"
#include "reverse_string.h"
#include "vigenere.h"


static MunitResult
test_reverse_string(const MunitParameter params[], void* data) {
    char *string_1 = "revengemybabymegnever";
    (void) params;
    (void) data;
    munit_assert_string_equal(reverse_string(string_1), string_1);

    return MUNIT_OK;
}

static MunitResult
test_vigenere(const MunitParameter params[], void* data) {
    char *key_1 = "KEY";
    char *key_2 = "LONGERKEY";
    char *plain_message_1 = "SHORTMESSAGE";
    char *crypt_key_1_message_1 = "CLMBXKOWQKKC";
    char *plain_message_2 = "MUCHMUCHLONGERMESSAGE";

    char *string_1 = "abcdefghijklmnopqrstuvwxyz";
    munit_assert_int(0, ==, getIndexOfChar(string_1, 'a'));
    munit_assert_int(25, ==, getIndexOfChar(string_1, 'z'));

    munit_assert_string_equal(translate_string(key_1, plain_message_1, 'e'), crypt_key_1_message_1);

    return MUNIT_OK;
}

static MunitTest
test_suite_tests[] = {
    { (char*) "Reverse String Header", test_reverse_string, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { (char*) "Vigenere Header",             test_vigenere, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
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
