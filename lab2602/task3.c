#define _CRT_SECURE_NO_WARNINGS
#define N 10000
#include <stdio.h>

void display(int arr[]) {
	printf("Prime numbers less than %i: ", N);
	for (int i = 2; i < N; i++)
	{
		if (arr[i] == 1) printf("%i ", i);
	}
}

void fillArray(int arr[]) {
	for (int i = 0; i < N; i++)
	{
		arr[i] = 1;
	}
}

void eraseMultiplicatives(int arr[], int x) {
	int p = x + x;
	while (p < N) 
	{
		arr[p] = -1;
		p += x;
	}
}


void EratosthenesSieve(int arr[]) {
	for (int i = 2; i < N; i++)
	{
		if (arr[i] == 1) eraseMultiplicatives(arr, i);
	}
}

int main() {
	int arr[N];

	fillArray(arr);
	EratosthenesSieve(arr);
	display(arr);

	return 0;
}
