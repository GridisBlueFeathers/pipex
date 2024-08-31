#include "pipex.h"
#include "libunit/test.h"
#include "libunit/assert.h"
#include "libunit/group.h"

void test_args_check_quotes_0()
{
	int res = args_check_quotes("");
	int exp = 1;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_args_check_quotes_1()
{
	int res = args_check_quotes("\"\"");
	int exp = 1;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_args_check_quotes_2()
{
	int res = args_check_quotes("''");
	int exp = 1;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_args_check_quotes_3()
{
	int res = args_check_quotes("\"'\"");
	int exp = 1;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_args_check_quotes_4()
{
	int res = args_check_quotes("'\"'");
	int exp = 1;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_args_check_quotes_5()
{
	int res = args_check_quotes("\"'\"'");
	int exp = 0;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_args_check_quotes_6()
{
	int res = args_check_quotes("'\"'\"");
	int exp = 0;
	t_assert_data data = { .res = &res, .exp = &exp};
	assert(INT_EQUAL, &data);
}

void test_empty_string()
{
	int res = args_count("");
	int exp = 0;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_one_word_no_spaces_no_quotes_string()
{
	int res = args_count("hello");
	int exp = 1;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_two_words_no_quotes_string()
{
	int res = args_count("hello there");
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_two_words_one_double_quotes_string()
{
	int res = args_count("hello \"there\"");
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_4()
{
	int res = args_count("hello \"there you\"");
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_5()
{
	int res = args_count("hello \"there\"you");
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_6()
{
	int res = args_count("hello \"there \"you");
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_7()
{
	int res = args_count("hello \"there \"you there");
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_8()
{
	int res = args_count("hello \"there \"you \"there\"");
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_9()
{
	int res = args_count("hello \"there \"you \"there you\"");
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_10()
{
	int res = args_count("hello hello\"there \"you \"there you\"");
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

int main()
{
	test(&test_args_check_quotes_0, "args_check_quotes(\"\")");
	test(&test_args_check_quotes_1, "args_check_quotes(\"\\\"\\\"\")");
	test(&test_args_check_quotes_2, "args_check_quotes(\"''\")");
	test(&test_args_check_quotes_3, "args_check_quotes(\"\\\"'\\\"\")");
	test(&test_args_check_quotes_4, "args_check_quotes(\"'\\\"'\")");
	test(&test_args_check_quotes_5, "args_check_quotes(\"\\\"'\\\"'\")");
	test(&test_args_check_quotes_6, "args_check_quotes(\"'\\\"'\\\"\")");
	test(&test_empty_string, "args_count(\"\")");
	test(&test_one_word_no_spaces_no_quotes_string, "args_count(\"hello\")");
	test(&test_two_words_no_quotes_string, "args_count(\"hello there\")");
	test(&test_two_words_one_double_quotes_string, "args_count(\"hello \"there\"\")");
	test(&test_case_4, "args_count(\"hello \"there you\"\")");
	test(&test_case_5, "args_count(\"hello \"there\"you\")");
	test(&test_case_6, "args_count(\"hello \"there \"you\")");
	test(&test_case_7, "args_count(\"hello \"there \"you there\")");
	test(&test_case_8, "args_count(\"hello \"there \"you \"there\"\")");
	test(&test_case_9, "args_count(\"hello \"there \"you \"there you\"\")");
	test(&test_case_10, "args_count(\"hello hello\"there \"you \"there you\"\")");
}
