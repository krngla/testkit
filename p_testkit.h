#pragma once
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include "p_tools.h"
//Useful tools
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define WHT "\x1B[37m"
#define RST "\x1B[0m"


int num_condition(int result, int expected);
int str_condition(char * result, char * expected);
long unsigned int str_len_condition(unsigned long int, unsigned long int len);
extern int v_testkit_n_failed;
extern int v_testkit_next_testid;

#define teststate(result,func_name, condition, expected, variables, testid, printformat) do {\
	printf("Test %4i %-15s ", testid, func_name);\
	if (condition(result, expected)) {\
		printf(GRN "Passed\n" RST);\
	}\
	else {\
		printf(RED "Failed\t" RST);\
		printf(printformat " =/= " printformat "\t input: %s\n", expected, result, variables);\
		v_testkit_n_failed++;\
	}\
} while (0)

#define test_numeq(funct, expected, ...) teststate(funct(__VA_ARGS__), #funct, num_condition, expected, #__VA_ARGS__, ++v_testkit_next_testid, "%i")
#define test_streq(funct, expected, ...) teststate(funct(__VA_ARGS__), #funct, str_condition, expected, #__VA_ARGS__, ++v_testkit_next_testid, "%s")
#define test_strlen(funct, expected, ...) teststate(strlen(funct(__VA_ARGS__)), #funct, str_len_condition, (long unsigned int)expected, #__VA_ARGS__, ++v_testkit_next_testid, "%lu")

#define result ((v_testkit_n_failed == 0) ? printf(GRN "All tests passed\n" RST) : printf(RED "Tests failed: %i\n" RST, v_testkit_n_failed))
