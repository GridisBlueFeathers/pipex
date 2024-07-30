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

int main()
{
	test(&test_empty_string, "Empty string, \"\" ' '");

}
