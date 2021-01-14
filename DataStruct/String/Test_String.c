#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char* str1 = "ABC";
	char str2[7] = "ABC";
	char str2_1[] = {'A', 'B', 'C', NULL};

	int num[] = { 1, 2, 3 };

	char* str3 = "GHIKKE";
	printf("str2: %s\n", strcpy(str2, str3));
	


	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str2_1: %s\n", str2_1);
	printf("str3: %s\n", str3);
	
	printf("sizeof(str1): %d\n", sizeof(str1));
	printf("sizeof(str2): %d\n", sizeof(str2));
	return 0;
}