#include <stdio.h>
#include <stdlib.h>

float* compute_average(int* arr, int sz) {
	float avg = 0;
	
	for (int i = 0; i < sz; i++)
		avg += arr[i];
	avg /= sz;

	float* avg_return = &avg;

	return avg_return;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	float* average;
	*average = *compute_average(arr, 5);
	printf("The average of the array is %f\n", *average);
	return 0;
}