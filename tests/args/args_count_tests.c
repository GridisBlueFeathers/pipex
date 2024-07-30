#include "pipex.h"
#include "libunit/test.h"
#include "libunit/assert.h"

void test_empty_string()
{
	int res = args_count("", ' ');
	int exp = 0;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_one_word_no_spaces_no_quotes_string()
{
	int res = args_count("hello", ' ');
	int exp = 1;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_two_words_no_quotes_string()
{
	int res = args_count("hello there", ' ');
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_two_words_one_double_quotes_string()
{
	int res = args_count("hello \"there\"", ' ');
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_4()
{
	int res = args_count("hello \"there you\"", ' ');
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_5()
{
	int res = args_count("hello \"there\"you", ' ');
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_6()
{
	int res = args_count("hello \"there \"you", ' ');
	int exp = 2;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_7()
{
	int res = args_count("hello \"there \"you there", ' ');
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_8()
{
	int res = args_count("hello \"there \"you \"there\"", ' ');
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

void test_case_9()
{
	int res = args_count("hello \"there \"you \"there you\"", ' ');
	int exp = 3;
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(INT_EQUAL, &data);
}

int main()
{
	test(&test_empty_string, "\"\" ' '");
	test(&test_one_word_no_spaces_no_quotes_string, "\"hello\" ' '");
	test(&test_two_words_no_quotes_string, "\"hello there\" ' '");
	test(&test_two_words_one_double_quotes_string, "\"hello \"there\"\" ' '");
	test(&test_case_4, "\"hello \"there you\"\" ' '");
	test(&test_case_5, "\"hello \"there\"you\" ' '");
	test(&test_case_6, "\"hello \"there \"you\" ' '");
	test(&test_case_7, "\"hello \"there \"you there\" ' '");
	test(&test_case_8, "\"hello \"there \"you \"there\"\" ' '");
	test(&test_case_9, "\"hello \"there \"you \"there you\"\" ' '");
}
