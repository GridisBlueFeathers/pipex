#include "pipex.h"
#include "libunit/test.h"
#include "libunit/assert.h"
#include "libunit/libunit.h"

void test_case_0()
{
	char **res = args_split("hello");
	char *exp[] = {"hello", NULL};
	t_assert_data data;
	data.exp = &exp;
	data.res = &res;
	assert(STR_ARR_EQUAL, &data);
}

int main()
{
	start_up(NULL);
	test(&test_case_0, "\"hello\"");
	teardown(NULL);
}
