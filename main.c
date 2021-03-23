#include <string.h>
#include <math.h>

int StrCmp(char* s1, char* s2) {
	while (*s1 && *s2 && *s1++==*s2++);
	return *--s2 - *--s1;
}
int str2int(char* str) {
	int num = 0;
	while(*str) 
		num = num*10 + *str++ - '0';  
	return num;
}
char* int2str(char* str, int num) {
	int len = 0; 
	while ((int)(num / pow(10, len))) 
		len++;
	for (int i = 0; i <= len; i++)
		str[i] =  i != len ? (int)(num / pow(10, len-1 - i)) % 10 + '0' : 0;
	return str;
}
int isPalindrom(char* str) {
	int len = strlen(str);
	for (int i = 0; i <= len / 2; i++)
		if (str[i] != str[len - 1 - i])
			return 0;
	return 1;
}
