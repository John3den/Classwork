#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>

void display(int arr[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(arr[i][j]<10) printf(" %i ", arr[i][j]);
			else  		 printf("%i ", arr[i][j]);
		}
		printf("\n");
	}
}

void fillRow(int arr[N][N], int row) {
	for (int i = 0; i < N; i++) 
	{
		arr[row][i] = row * N + i;
	}
}

void fillRowReverse(int arr[N][N], int row) {
	for (int i = 0; i < N; i++)
	{
		arr[row][i] = (row + 1) * N - i - 1;
	}
}

void drawSerpantine(int arr[N][N]) {
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0) fillRow(arr, i);
		else 		fillRowReverse(arr, i);
	}
}

int main() {
	int arr[N][N];

	drawSerpantine(arr);
	display(arr);

	return 0;
}
