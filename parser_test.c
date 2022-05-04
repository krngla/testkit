#include "p_parser.h"
#include "p_tools.h"
#include <stdbool.h>
int testcount = 0;
int n_failed = 0;
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define WHT "\x1B[37m"
#define RST "\x1B[0m"


int num_condition(int result, int expected) { 
	return result == expected;
}
int str_condition(char * result, char * expected) {
	return (0 == strcmp(result, expected));
}
#define eq_condition "=="
#define neq_condition "!="

#define teststate(result, condition, expected, variables, testid, printformat) do {\
	printf("Test %4i ", testid);\
	if (condition(result, expected)) {\
		printf(GRN "Passed\n" RST);\
	}\
	else {\
		printf(RED "Failed\t" RST);\
		printf(printformat " =/= " printformat "\t input: %s\n", expected, result, variables);\
		n_failed++;\
		exit(-1);\
	}\
} while (0)


void t_teststate(int state, int testid) {
	printf("Test %4i %s", testid, ((state) ? GRN "Passed\n" RST: RED "Failed\n" RST));
	(state) ? n_failed : n_failed++;
}



#define test_numeq(funct, expected, ...) teststate(funct(__VA_ARGS__), num_condition, expected, #__VA_ARGS__, ++testcount, "%i")
#define test_streq(funct, expected, ...) teststate(funct(__VA_ARGS__), str_condition, expected, #__VA_ARGS__, ++testcount, "%s")

#define result ((n_failed == 0) ? printf(GRN "All tests passed\n" RST) : printf(RED "Tests failed: %i\n" RST, n_failed))

int test_func(int a, int b, int c) {
	return a + b + c;
}

char * conc(char * a, char * b) {
	char * ret = malloc( strlen(a) + strlen(b) + 1);
	strcpy(ret, a);
	strcpy(ret + strlen(a), b);
	return ret;
}

const char g_file[] = "abcdefghijklmnopqrstuvwxyz";
char * ch = (char*)g_file;
char * check = (char*)g_file;
int t_getch() {
	return *ch++;
}

int main() {
	int ch;
	while ((ch = t_getch()) != '\0') {
		assert(ch == *check++);
		printf("%c", (char)ch);
	}
	printf("\n");
	test_numeq(test_func, 11, 2, 3, 6);
	test_numeq(test_func, 12, 2, 3, 7);
	test_numeq(test_func, 13, 2, 3, 8);
	test_numeq(test_func, 14, 2, 3, 9);
	test_numeq(test_func, 15, 2, 3, 10);
	test_numeq(test_func, 16, 2, 3, 11);
	test_numeq(test_func, 17, 2, 3, 12);
	test_streq(conc, "hello, world!", "hello, ", "world!");
	test_streq(conc, "hello, world!", "hello,", "world!");
	//level1
	result;



	return 0;
}

