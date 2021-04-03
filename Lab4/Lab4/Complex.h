#pragma once

#include <ostream>
#include <istream>

using namespace std;

class Complex
{
public:
	Complex();
	Complex(float real, float imaginar);
	Complex add(Complex);
	Complex operator+(Complex c);
	friend ostream& operator<<(ostream& os, const Complex& c);
	friend istream& operator>>(istream& is, Complex& c);
	float getReal();
	float getImaginary();
private:
	float m_real, m_imaginar;
};