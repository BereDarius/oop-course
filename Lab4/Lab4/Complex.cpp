#include "Complex.h"

Complex::Complex() :m_real{ 0 }, m_imaginar{ 0 } {}

Complex::Complex(float real, float imaginar) : m_real{ real }, m_imaginar{ imaginar } {}

Complex Complex::add(Complex c) {
	Complex result{
		m_real + c.m_real,
		m_imaginar + c.m_imaginar
	};
	return result;
}

Complex Complex::operator+(Complex c)
{
	return this->add(c);
}

float Complex::getReal()
{
	return m_real;
}

float Complex::getImaginary()
{
	return m_imaginar;
}

ostream& operator<<(ostream& os, const Complex& c) {
	os << c.m_real << "+" << c.m_imaginar << "i" << endl;
	return os;
}

istream& operator>>(istream& is, Complex& c) {
	is >> c.m_real >> c.m_imaginar;
	return is;
}