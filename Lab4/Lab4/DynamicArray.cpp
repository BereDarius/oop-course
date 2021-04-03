#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	m_length = 0;
	m_capacity = 20;
	m_arr = new Complex[20];
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	m_length = a.m_length;
	m_capacity = a.m_capacity;
	m_arr = new Complex[m_capacity];
	for (int i = 0; i < m_length; i++) {
		m_arr[i] = a.m_arr[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] m_arr;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& a)
{
	m_length = a.m_length;
	m_capacity = a.m_capacity;
	m_arr = new Complex[m_capacity];
	for (int i = 0; i < m_length; i++) {
		m_arr[i] = a.m_arr[i];
	}
	return *this;
}

void DynamicArray::addLast(const Complex c)
{
	if (m_length == m_capacity) {
		m_capacity *= 2;
	}
	Complex* aux_arr = new Complex[m_capacity];
	for (int i = 0; i < m_length; i++) {
		m_arr[i] = aux_arr[i];
	}
	m_arr[m_length] = c;
	delete[] aux_arr;
}

DynamicArray& DynamicArray::operator+(const Complex c)
{
	this->addLast(c);
	return *this;
}

Complex& DynamicArray::operator[](int i)
{
	if (i >=0 && i < m_length) {
		return m_arr[i];
	}
	else {
		throw exception();
	}
}

ostream& operator<<(ostream& os, const DynamicArray& a)
{
	for (int i = 0; i < a.m_length; i++) {
		os << a.m_arr[i].getReal() << "+" << a.m_arr[i].getImaginary() << "i" << endl;
	}
	return os;
}
