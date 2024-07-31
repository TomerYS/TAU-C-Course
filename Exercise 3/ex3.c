#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int q_1(char arr[]);

int q_2(char arr[], int k);

int q_3(char arr[]);

int q_4(char arr[]);

int array_helper(char arr[], int arr_int[]);


int main()
{
	printf("\n\n");
	int q_num = 0, n = 0, res = 0, k = 0;
	char arr[MAX_SIZE];

	printf("Which question would you like to check?: ");
	scanf("%d", &q_num);
	printf("Please enter the input array: ");
	scanf("%s", arr);
	switch (q_num)
	{
	case 1:
		res = q_1(arr);
		printf("Result = %d", res);
		break;
	case 2:
		printf("Please enter k: ");
		scanf("%d", &k);
		res = q_2(arr, k);
		printf("Result = %d", res);
		break;
	case 3:
		res = q_3(arr);
		printf("Result = %d", res);
		break;
	case 4:
		res = q_4(arr);
		printf("Result = %d", res);
		break;
	default:
		printf("%d is an invalid input", q_num);
	}
	return 0;
}

int array_helper(char arr[], int arr_int[]) {
	int num = 0, i = 0, j = 0, sign = 1;
	while (arr[i] != '\0') {
		if (arr[i] == '-') {
			sign = -1;
		}
		else if (arr[i] == ',') {
			arr_int[j++] = num * sign;
			num = 0;
			sign = 1;
		}
		else {
			num = num * 10 + (arr[i] - '0');
		}
		i++;
	}
	arr_int[j] = num * sign;
	return j + 1;
}

int q_1(char arr[]) {
	int arr_int[MAX_SIZE] = { 0 };
	int arr_int_len = array_helper(arr, arr_int);

	int max_value = -99999;
	int max_len = 0;
	int left = 0, right = 0, sum = 0;

	while (right < arr_int_len) {
		sum += arr_int[right];
		if (sum > max_value) {
			max_len = right - left + 1;
			max_value = sum;
		}
		right++;
		if (sum < 0) {
			left = right;
			sum = 0;
		}
	}
	return max_len;
}

int q_2(char arr[], int k) {
	int arr_int[MAX_SIZE];
	int i, n = array_helper(arr, arr_int);

	int minSwaps = MAX_SIZE, countLessEqualK = 0;

	for (i = 0; i < n; i++) {
		if (arr_int[i] <= k) {
			countLessEqualK++;
		}
	}

	if (countLessEqualK == 0) return 0;

	int currentOverK = 0;

	for (i = 0; i < countLessEqualK; i++) {
		if (arr_int[i] > k) {
			currentOverK++;
		}
	}
	minSwaps = currentOverK;

	for (i = countLessEqualK; i < n; i++) {
		if (arr_int[i - countLessEqualK] > k) {
			currentOverK--;
		}
		if (arr_int[i] > k) {
			currentOverK++;
		}
		if (currentOverK < minSwaps) {
			minSwaps = currentOverK;
		}
	}

	return minSwaps;
}





int q_3(char arr[]) {
	int arr_int[MAX_SIZE];
	int n = array_helper(arr, arr_int);
	char seen[MAX_SIZE] = { 0 };

	for (int i = 0; i < n; i++) {
		int value = arr_int[i];

		if (value >= n) {
			continue;
		}

		if (seen[value]) {
			return 1;
		}
		seen[value] = 1;
	}

	return -1;
}



int q_4(char arr[]) {
	int arr_int[MAX_SIZE];
	int left_max[MAX_SIZE];
	int right_max[MAX_SIZE];
	int n = array_helper(arr, arr_int);
	int water_trapped = 0;

	left_max[0] = arr_int[0];
	for (int i = 1; i < n; i++) {
		if (arr_int[i] > left_max[i - 1]) {
			left_max[i] = arr_int[i];
		}
		else {
			left_max[i] = left_max[i - 1];
		}
	}

	right_max[n - 1] = arr_int[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (arr_int[i] > right_max[i + 1]) {
			right_max[i] = arr_int[i];
		}
		else {
			right_max[i] = right_max[i + 1];
		}
	}

	for (int i = 0; i < n; i++) {
		int min_height;
		if (left_max[i] < right_max[i]) {
			min_height = left_max[i];
		}
		else {
			min_height = right_max[i];
		}
		if (min_height > arr_int[i]) {
			water_trapped += min_height - arr_int[i];
		}
	}

	return water_trapped;
}
