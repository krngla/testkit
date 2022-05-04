#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include "p_tools.h"


int v_testkit_n_failed = 0;
int v_testkit_next_testid = 0;

int num_condition(int result, int expected) { 
	return result == expected;
}

int str_condition(char * result, char * expected) {
	int ret = (0 == strcmp(result, expected));
	free(result);
	return ret;
}

int str_len_condition(unsigned long int result, unsigned long int expected) {
	return result == expected;
}

