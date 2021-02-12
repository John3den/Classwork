#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <stdio.h>
int x,y;
int main() {
	scanf("%d%d", &x, &y);
	if ((ll)(x)+(ll)(y) == x+y)
		printf("x+y=%d\n", x + y);
	else 
		printf("numbers are too big, Mason!\n");
	printf("x*y=%d\n", x * y);
	if (y != 0)
	{
		printf("x/y=%d\n", x / y);
		printf("x%%y=%d\n", x % y);
	}
	else
	{
		printf("Division by zero!\n");
	}
	printf("x-y=%d\n", x - y);
	printf("x>=y=%d\n", x >= y);
	printf("x<=y=%d\n", x <= y);
	printf("x>y=%d\n", x > y);
	printf("x<y=%d\n", x < y);
	printf("x==y=%d\n", x == y);
	printf("x!=y=%d\n", x != y);
	printf("x's address is %i\n",&x);
	return 0;
}
