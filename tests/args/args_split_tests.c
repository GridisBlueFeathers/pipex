#include "pipex.h"
#include "libft/libft.h"
#include "libunit/test.h"
#include "libunit/assert.h"
#include "libunit/libunit.h"

void test_case_0()
{
	char **res = args_split("hello");
	ft_putstrarr_fd(res, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	char *exp[] = {"hello", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	assert(STR_ARR_EQUAL, &data);
}

void test_case_1()
{
	char **res = args_split("hello there");
	ft_putstrarr_fd(res, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	char *exp[] = {"hello", "there", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	assert(STR_ARR_EQUAL, &data);
}

void test_case_2()
{
	char **res = args_split("hello \"there\"");
	ft_putstrarr_fd(res, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	char *exp[] = {"hello", "there", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	assert(STR_ARR_EQUAL, &data);
}

void test_case_3()
{
	char **res = args_split("hello \"hey hey\"");
	ft_putstrarr_fd(res, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	char *exp[] = {"hello", "hey hey", NULL};
	t_assert_data data;
	data.exp = exp;
	data.res = res;
	assert(STR_ARR_EQUAL, &data);
}

int main()
{
	start_up(NULL);
	test(&test_case_0, "args_split(\"hello\")");
	test(&test_case_1, "args_split(\"hello there\")");
	test(&test_case_2, "args_split(\"hello \"there\"\")");
	test(&test_case_3, "args_split(\"hello \"hey hey\"\")");
	teardown(NULL);
}
