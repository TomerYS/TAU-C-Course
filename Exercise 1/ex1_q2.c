#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int num, reversed = 0;
	int sign = 1;

	printf("Enter a number to reverse: ");
	scanf("%d", &num);
	if (num == 0) {
		printf("Reverse of number is: 0");
		return 0;
	}
	if (num < 0) {
		sign = -1;
		num = -num;
	}
	while (num > 0) {
		reversed = reversed * 10 + (num % 10);
		num = num / 10;
	}
	reversed = reversed * sign;
	
	printf("Reverse of number is: %d", reversed);

	return 0;
}