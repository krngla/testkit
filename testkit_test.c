#include "p_testkit.h"
#include "p_tools.h"
#include <stdbool.h>
int test_func(int a, int b, int c) {
	return a + b + c;
}

char * conc(char * a, char * b) {
	char * ret = malloc( strlen(a) + strlen(b) + 1);
	strcpy(ret, a);
	strcpy(ret + strlen(a), b);
	return ret;
}

char * rep(char * str, int n) {

	char * ret = malloc( strlen(str) * n);
	for (int i = 0; i < n; i++) {
		strcpy(ret + (strlen(str) * i), str + 1);
	}
	return ret;
}


int main() {

	test_numeq(test_func, 11, 2, 3, 6);
	test_numeq(test_func, 12, 2, 3, 7);
	test_numeq(test_func, 13, 2, 3, 8);
	test_numeq(test_func, 14, 2, 3, 9);
	test_numeq(test_func, 15, 2, 3, 10);
	test_numeq(test_func, 16, 2, 3, 11);
	test_numeq(test_func, 17, 2, 3, 12);
	test_streq(conc, "hello, world!", "hello, ", "world!");
	//test_streq(conc, "hello, world!", "hello,", "world!");
	test_streq(rep, "hello, hello, hello, ", "hello, ", 3);
	test_strlen(rep, 22, "hello, ", (unsigned long int)3);
	printf("%s\n", rep("hello, ", 3));
	//level1
	result;



	return 0;
}

