#include <stdio.h>
#include <stdlib.h>

int* compute_digit_frequency(int number) {
	const int num_digits = 9;
	int histogram[num_digits];
	
	for (int i = 0; i < 9; i++)
		histogram[i] = 0;

	while (number != 0) {
		histogram[number % 10]++;
		number /= 10;
	}

	int* ret_hist = histogram;
	return ret_hist;
}

int main() {
	
	int* hist1 = compute_digit_frequency(0);
	int* hist2 = compute_digit_frequency(3420);
	int* hist3 = compute_digit_frequency(2420);
	int* hist4 = compute_digit_frequency(2311);
	delete hist1;
	delete[] hist2;
	delete hist3;
	delete[] hist4;
	return 0;
}