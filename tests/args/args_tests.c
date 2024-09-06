#include "pipex.h"
#include "libunit/test.h"
#include "libunit/assert.h"
#include "libunit/group.h"
#include "libunit/libunit.h"

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
	int check_res;
	check_res = 1;
	int fun_res = args_count("", &check_res);
	int fun_exp = 0;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_one_word_no_spaces_no_quotes_string()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello", &check_res);
	int fun_exp = 1;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_two_words_no_quotes_string()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello there", &check_res);
	int fun_exp = 2;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_two_words_one_double_quotes_string()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there\"", &check_res);
	int fun_exp = 2;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_4()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there you\"", &check_res);
	int fun_exp = 2;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_5()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there\"you", &check_res);
	int fun_exp = 2;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_6()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there \"you", &check_res);
	int fun_exp = 2;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_7()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there \"you there", &check_res);
	int fun_exp = 3;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_8()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there \"you \"there\"", &check_res);
	int fun_exp = 3;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_9()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello \"there \"you \"there you\"", &check_res);
	int fun_exp = 3;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

void test_case_10()
{
	int check_res;
	check_res = 1;
	int fun_res = args_count("hello hello\"there \"you \"there you\"", &check_res);
	int fun_exp = 3;

	t_assert_data data;
	data.exp = &fun_exp;
	data.res = &fun_res;
	assert(INT_EQUAL, &data);

	int check_exp = 1;
	t_assert_data data2;
	data2.exp = &check_exp;
	data2.res = &check_res;
	assert(INT_EQUAL, &data2);
}

int main()
{
	start_up(NULL);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"\")", &test_args_check_quotes_0);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"\\\"\\\"\")", &test_args_check_quotes_1);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"''\")", &test_args_check_quotes_2);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"\\\"'\\\"\")", &test_args_check_quotes_3);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"'\\\"'\")", &test_args_check_quotes_4);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"\\\"'\\\"'\")", &test_args_check_quotes_5);
	group_add_test("args_check_quotes(char *s)", "args_check_quotes(\"'\\\"'\\\"\")", &test_args_check_quotes_6);
	group_add_test("args_count(char *s)", "args_count(\"\")", &test_empty_string);
	group_add_test("args_count(char *s)", "args_count(\"hello\")", &test_one_word_no_spaces_no_quotes_string);
	group_add_test("args_count(char *s)", "args_count(\"hello there\")", &test_two_words_no_quotes_string);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there\"\")", &test_two_words_one_double_quotes_string);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there you\"\")", &test_case_4);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there\"you\")", &test_case_5);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there \"you\")", &test_case_6);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there \"you there\")", &test_case_7);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there \"you \"there\"\")", &test_case_8);
	group_add_test("args_count(char *s)", "args_count(\"hello \"there \"you \"there you\"\")", &test_case_9);
	group_add_test("args_count(char *s)", "args_count(\"hello hello\"there \"you \"there you\"\")", &test_case_10);
	teardown(NULL);
}
