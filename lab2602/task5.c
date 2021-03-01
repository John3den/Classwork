#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>

void fillArray(int arr[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = -1;
		}
	}
}

void display(int arr[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			if (arr[j][i] < 10) printf(" %i ", arr[j][i]);
			else  		    printf( "%i ", arr[j][i]);

		}
		printf("\n");
	}
	
}

int checkForth(int coordinateSystem[N][N], int X, int Y, int dirX, int dirY) {
	if (X + dirX >= N || Y + dirY >= N) 		      return 0;
	else if (coordinateSystem[X + dirX][Y + dirY] != -1)  return 0;
	else 						      return 1;
}

void drawALine(int coordinateSystem[N][N], int *X ,int *Y, int *counter, int dirX, int dirY) {
	while (checkForth(coordinateSystem,*X,*Y,dirX,dirY))
	{
		*X += dirX;
		*Y += dirY;
		coordinateSystem[*X][*Y] = (*counter)++;
	}
}

//directions: 1 = right; 2 = down; 3 = left; 4 = up;
void changeDirectionClockwise(int* dirX,int* dirY,int* direction) {
	switch (*direction)
	{
	case 1: *dirX =  1; *dirY =  0; break;
	case 2: *dirX =  0; *dirY =  1; break;
	case 3: *dirX = -1; *dirY =  0; break;
	case 4: *dirX =  0; *dirY = -1; break;
	}
	*direction = *direction % 4 + 1;
}

void drawSpiral(int arr[N][N]) 
{
	int counter = 0;
	int direction = 1;
	int dirX=0, dirY=0;
	int x = -1, y = 0; // стартовая точка вне спирали
	while (counter<N*N)
	{
		changeDirectionClockwise(&dirX, &dirY, &direction);
		drawALine(arr, &x, &y, &counter, dirX, dirY);
	}
}

int main() {
	int arr[N][N];

	fillArray(arr);
	drawSpiral(arr);
	display(arr);

	return 0;
}
