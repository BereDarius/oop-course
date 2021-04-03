#include <iostream>
#include "Header files/complex.h"
#include <iostream>

using namespace std;

int main() {
    complex c1;
    complex* c2 = new complex;

    c1 = read();

    c2->real = 3.0;
    c2->imag = 4.0;

    display(c1);
    display(c2);

    display(add(c1, c2));
    display(add(c2, c2));
    display(add(c2, c1));
    display(add(c1, c1));

    display(subtract(c1, c2));
    display(subtract(c2, c2));
    display(subtract(c2, c1));
    display(subtract(c1, c1));

    display(multiply(c1, c2));
    display(multiply(c2, c2));
    display(multiply(c2, c1));
    display(multiply(c1, c1));

    cout << equal(c1, c2) << endl;
    cout << equal(c2, c2) << endl;
    cout << equal(c1, c1) << endl;
    cout << equal(c2, c1) << endl;

    cout << magnitude(c2) << endl;

    cout << phase(c2) << endl;

    float r1;
    float r2;
    float theta1;
    float theta2;

    toPolar(c1, &r1, &theta1);
    toPolar(c2, &r2, &theta2);

    cout << r1 << ", " << theta1 << endl;
    cout << r2 << ", " << theta2 << endl;

    display(divide(c1, c2));
    display(divide(c1, c1));
    display(divide(c2, c2));
    display(divide(c2, c1));

    delete c2;
    return 0;
}
