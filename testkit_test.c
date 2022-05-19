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
		strcpy(ret + (strlen(str) * i), str);
	}
	return ret;
}


int main() {

	test_numeq(test_func, "test func 1", 11, 2, 3, 6);
	test_numeq(test_func, "test func 2", 12, 2, 3, 7);
	test_numeq(test_func, "test func 3", 13, 2, 3, 8);
	test_numeq(test_func, "test func 4", 14, 2, 3, 9);
	test_numeq(test_func, "test func 5", 15, 2, 3, 10);
	test_numeq(test_func, "test func 6", 16, 2, 3, 11);
	test_numeq(test_func, "test func 7", 17, 2, 3, 12);
	test_numeq(test_func, "test func 7", 17, 2, 3, 12);
	test_streq(conc, "conc eq 1", "hello, world!", "hello, ", "world!");
	test_streq(rep, "rep eq 1", "hello, hello, hello, ", "hello, ", 3);
	test_strlen(rep, "rep len 1", 21, "hello, ", 3);
	//level1
	result();

	return 0;
}

