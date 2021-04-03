#include "dynamic_array.h"
#include <iostream>

using namespace std;

DynamicArray* create(unsigned int initial_capacity)
{
	DynamicArray* result = new DynamicArray;
	result->len = 0;
	result->cap = initial_capacity;
	result->data = new void*[initial_capacity];
	return result;
}

void insert(DynamicArray* a, void* elem)
{
	if (a->len == a->cap)
	{
		a->cap = a->cap * 2;
		void** new_data = new void*[a->cap];
		for (int i = 0; i < a->len; i++)
		{
			new_data[i] = a->data[i];
		}
		delete[] a->data;
		a->data = nullptr;
		a->data = new_data;
	}
	a->data[a->len++] = elem;
}

void deleteLast(DynamicArray* a)
{
	a->len--;
}

void display(DynamicArray* a, void (*displayElement)(void*))
{
	for (int i = 0; i < a->len; i++)
	{
		displayElement(a->data[i]);
	}
	cout << endl;
}

void release(DynamicArray* a)
{
	delete[] a->data;
	delete a;
	a = nullptr;
}

int search(DynamicArray* a, bool(*condition)(void*))
{
	for (int i = 0; i < a->len; i++) 
	{
		if (condition(a->data[i])) 
		{
			return i;
		}
	}
	return -1;
}
