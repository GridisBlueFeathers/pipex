#include "pipex.h"
#include "libft/libft.h"
#include "libunit/test.h"
#include "libunit/assert.h"
#include "libunit/libunit.h"
#include "libunit/group.h"

void test_case_0()
{
	char **res = args_split("hello");
	char *exp[] = {"hello", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

void test_case_1()
{
	char **res = args_split("hello there");
	char *exp[] = {"hello", "there", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

void test_case_2()
{
	char **res = args_split("hello \"there\"");
	char *exp[] = {"hello", "there", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

void test_case_3()
{
	char **res = args_split("hello \"hey hey\"");
	char *exp[] = {"hello", "hey hey", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

void test_case_4()
{
	char **res = args_split("hello hey\"hey hey\"");
	char *exp[] = {"hello", "heyhey hey", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

void test_case_5()
{
	char **res = args_split("hello hey\"hey hey\"hey");
	char *exp[] = {"hello", "heyhey heyhey", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

void test_case_6()
{
	char **res = args_split("hello hey\"hey \\\"hey\"hey");
	char *exp[] = {"hello", "heyhey \"heyhey", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	data.fn_failed = 0;
	if (!res)
		data.fn_failed = 1;
	assert(STR_ARR_EQUAL, &data);
	ft_free(STR_ARR, &res);
}

int main()
{
	start_up(NULL);
	group_add_test("args_split(char *args)",  "args_split(\"hello\")", &test_case_0);
	group_add_test("args_split(char *args)",  "args_split(\"hello there\")", &test_case_1);
	group_add_test("args_split(char *args)",  "args_split(\"hello \"there\"\")", &test_case_2);
	group_add_test("args_split(char *args)",  "args_split(\"hello \"hey hey\"\")", &test_case_3);
	group_add_test("args_split(char *args)",  "args_split(\"hello hey\"hey hey\"\")", &test_case_4);
	group_add_test("args_split(char *args)",  "args_split(\"hello hey\"hey hey\"hey\")", &test_case_5);
	group_add_test("args_split(char *args)",  "args_split(\"hello hey\"hey \\\"hey\"hey\")", &test_case_6);
	teardown(NULL);
}
