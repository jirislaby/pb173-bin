#include <stdio.h>

#include "lib.h"

void my_lib_function(void)
{
	printf("Called %s\n", __func__);
}
