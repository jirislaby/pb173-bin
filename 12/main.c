#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

static void leave_me_alone(void)
{
	void *ptr = malloc(100);
	printf("%s: allocated 100B at %p\n", __func__, ptr);
}

int main()
{
	leave_me_alone();

	my_lib_function();

	return 0;
}
