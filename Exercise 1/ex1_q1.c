#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int userInput;
	printf("Input: n = ");
	scanf("%d", &userInput);
	if (userInput == 0) {
		printf("Output: ");
		return 0;
	}
	printf("Output: ");
	for (int i = 1; i < userInput; i++) {
		if (userInput % i == 0) {
			printf("%d ", i);
		}
	}
	printf("%d", userInput);
	
	return 0;
}