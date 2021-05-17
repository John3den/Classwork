#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

	int isPrime(int x)
	{
		for (int i = 2; i < x; i++)
		{
			if (x % i == 0) return 0;
		}
		return 1;
	}

	int normalOrder(int x)
	{
		printf("\nTASK 1:\n");
		printf("--------------------------------------\n");

		for (int i = 0; i <= x; i++)
		{
			printf("%i ", i);
		}

		printf("\n--------------------------------------\n\n");
	}

	int reverseOrder(int x)
	{
		printf("TASK 2:\n");
		printf("--------------------------------------\n");

		for (int i = 0; i <= x; i++)
		{
			printf("%i ", x - i);
		}

		printf("\n--------------------------------------\n\n");
	}

	int checkmateOrder(int x)
	{
		printf("TASK 3:\n");
		printf("--------------------------------------\n");

		for (int i = 0; i <= x; i++)
		{
			if (i % 2 == 0) printf("%i ", i/2);
			else            printf("%i ", x - i/2);
		}

		printf("\n--------------------------------------\n\n");
	}

	int sumTable(int x, int y)
	{
		printf("TASK 4:\n");
		printf("--------------------------------------\n");

		for (int i = 0; i <= y; i++)
		{
			for (int j = 0; j <= x; j++)
			{
				printf("%i ", i + j);
			}
			if (i != y)printf("\n");
		}

		printf("\n--------------------------------------\n\n");
	}

	int fibonacciNumbers(int x)
	{
		printf("TASK 5:\n");
		printf("--------------------------------------\n");

		int x1 = 0, x2 = 1, sum = 0;
		for (int i = 0; i <= x; i++)
		{
			sum = x1 + x2;
			printf("%i ", sum);
			x1 = x2;
			x2 = sum;
		}

		printf("\n--------------------------------------\n\n");
	}

	int primeNumbers(int x)
	{
		printf("TASK 6:\n");
		printf("--------------------------------------\n");

		int x1 = 2;
		for (int i = 0; i < x; i++)
		{
			while (!isPrime(x1)) x1++;
			printf("%i ", x1);
			x1++;
		}

		printf("\n--------------------------------------\n\n");
	}


	int main()
	{
		int x = 0, y = 0;
		printf("Enter x and y:\n");
		scanf("%i%i", &x, &y);


		normalOrder(x);
		reverseOrder(x);
		checkmateOrder(x);
		sumTable(x, y);
		fibonacciNumbers(x);
		primeNumbers(x);

		return 0;
	}
