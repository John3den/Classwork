#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>

void writeInputIntoArray(int arr[]) {
	int x = 0;
	for (int i = 0; i < N; i++) {
		scanf("%i", &x);
		arr[i] = x;
	}
	return 0;
}

void findAndPrintMax(int arr[]) {
	int max = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	printf("Max element is %i\n", max);
	return 0;
}

void findAndPrintMin(int arr[]) {
	int min = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	printf("Min element is %i\n", min);
	return 0;
}

void determineSortingOrder(int arr[]) {
	int risingOrderFlag = 1;
	int descendingOrderFlag = 1;
	int equalityflag = 1;
	int x = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] == x)
			continue;
		if (arr[i] > x)
			descendingOrderFlag = 0;
		else
			risingOrderFlag = 0;
		equalityflag = 0;
		x = arr[i];
	}
	if (equalityflag)
		printf("Numbers are equal UWU");
	else if (risingOrderFlag)
		printf("ascending order");
	else if (descendingOrderFlag)
		printf("descending order");
	else
		printf("no order");
	printf("\n");
	return 0;
}

void eraseMultiplicatives(int arr[], int x) {
	int p = x + x;
	while (p < N) {
		arr[p] = -1;
		p += x;
	}
}

int main() {
	int arr[N];
	writeInputIntoArray(arr);
	findAndPrintMax(arr);
	findAndPrintMin(arr);
	determineSortingOrder(arr);
	return 0;
}
