#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>

// NOTE: Since <math.h> is included, you can use sqrt() to calculate the square-root of a number.

int q_1(int res_decimal);

double q_2(int n);

double q_3(int n);

int main()
{
	int q_num = 0, n = 0, res_decimal = 0;
	double res;

	printf("Which question would you like to check?: ");
	scanf("%d", &q_num);
	printf("Please enter a number: ");
	scanf("%d", &n);
	switch (q_num)
	{
	case 1:
		res_decimal = q_1(n);
		printf("Result = %d", res_decimal);
		break;
	case 2:
		res = q_2(n);
		printf("Result = %lf", res);
		break;
	case 3:
		res = q_3(n);
		printf("Result = %lf", res);
		break;
	default:
		printf("%d is an invalid input", q_num);
	}
	return 0;
}

int q_1(int res_decimal)
{
	// HERE: define the function accordingly
}

double q_2(int n)
{
	// HERE: define the function accordingly
}

double q_3(int n)
{
	// HERE: define the function accordingly
}