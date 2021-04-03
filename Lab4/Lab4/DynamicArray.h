#pragma once
#include "Complex.h"
#include <ostream>

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const DynamicArray& a);
	~DynamicArray();
	DynamicArray& operator=(const DynamicArray& a);
	void addLast(const Complex c);
	DynamicArray& operator+(const Complex c);
	Complex& operator[](int i);
	friend ostream& operator<<(ostream& os, const DynamicArray& a);
private:
	int m_length;
	int m_capacity;
	Complex* m_arr;
};

