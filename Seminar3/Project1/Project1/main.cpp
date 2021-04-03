#include "dynamic_array.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void printInt(void* elem) {
	int* a = (int*) elem;
	cout << *a << " ";
}

bool isEven(void* elem) {
	return *((int*) elem) % 2 == 0;
}

bool isNegative(void* elem) {
	return *((int*)elem) < 0;
}

int main()
{
	DynamicArray* test = create(10);
	display(test, printInt);
	
	for (int i = 0; i < 200; i++)
	{
		int* val = new int;
		*val = rand() % 20;
		insert(test, (void*)val);
		if (i % 10 == 0)
		{
			display(test, printInt);
		}
	}

	cout << search(test, isEven) << endl;
	cout << search(test, isNegative) << endl;

	release(test);
	return 0;
}