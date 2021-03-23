#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <intrin.h>
#define N 256

int StrCmp(char* s1, char* s2) {
	while (*s1++ && *s2++);
	return *--s2 - *--s1;
}
int str2int(char* str) {
	int num = 0;
	while(*str) num = num*10 + *str++ - '0';  
	return num;
}
char* int2str(char* str, int num) {
	int len = 0; 
	int numcpy = num;
	while (numcpy != 0)
	{
		numcpy /= 10;
		len++;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		str[i] = num % 10;
	}
	return str;
}
int isPalindrom(char* str) {
	int len = strlen(str);
	for (int i = 0; i <= len / 2; i++)
		if (str[i] != str[len - 1 - i])
			return 0;
	return 1;
}
int main() {
	int a = 11111;
	printf("%i",);
	return 0;
}