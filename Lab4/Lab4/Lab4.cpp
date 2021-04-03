#include "Complex.h"
#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main() {
	Complex a, b{10, 20};
	cin >> a;
	Complex c = a + b;

	Complex* e = new Complex;
	cin >> *e;
	(*e).add(a);

	DynamicArray arr1;

	arr1.addLast(a);
	arr1.addLast(b);
	arr1.addLast(c);
	arr1.addLast(*e);

	cout << arr1 << endl;

	delete e;

	system("pause");
}