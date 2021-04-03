#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_most_frequent_digit(unsigned long long number) {
	
	int* histogram = (int*)malloc(sizeof(int) * 10);
	memset(histogram, 0, 10*sizeof(int));	

	if (0 == number) {
		free(histogram);
		return 0;
	}

	while (number != 0) {
		histogram[number % 10]++;
		number /= 10;
	}

	int max_occurences = 0;
	int most_freq_digit = -1;
	for(int i = 0; i < 10; i++)
		if (max_occurences < histogram[i]) {
			most_freq_digit = i;
			max_occurences = histogram[i];
		}

	free(histogram);

	return most_freq_digit;
}

int main() {
	
	unsigned long long num1 = 9650472222445L;
	unsigned long long num2 = 111111111110023L;
	unsigned long long num3 = 88822233300L;
	unsigned long long num4 = 0L;

	
	printf("The most frequent digit in the number %llu is %d\n", num1, get_most_frequent_digit(num1));
	printf("The most frequent digit in the number %llu is %d\n", num2, get_most_frequent_digit(num2));
	printf("The most frequent digit in the number %llu is %d\n", num3, get_most_frequent_digit(num3));
	printf("The most frequent digit in the number %llu is %d\n", num4, get_most_frequent_digit(num4));

	return 0;
}