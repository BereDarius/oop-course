//
// Created by Darius on 3/11/2021.
//

#include "../Header files/complex.h"
#include <iostream>
#include <cmath>

using namespace std;

complex create(float real, float imag) {

    complex c;
    c.real = real;
    c.imag = imag;
/*
complex* pc = new complex;
pc->imag = imag;
pc->real = real;
*/
    return c;
}

complex read() {
    float real;
    float imag;
    complex result;
    cout << "Please enter the real part of the complex number: ";
    cin >> real;
    cout << endl;
    cout << "Please enter the imaginary part of the complex number: ";
    cin >> imag;
    cout << endl;
    result = create(real, imag);
    return result;
}

void display(complex c) {
    cout << c.real << " + " << c.imag << "i" << endl;
}

void display(complex* c) {
    cout << c->real << " + " << c->imag << "i" << endl;
}

complex add(complex c1, complex c2) {
    c1.real = c1.real + c2.real;
    c1.imag = c1.imag + c2.imag;
    return c1;
}

complex add(complex* c1, complex c2) {
    c1->real = c1->real + c2.real;
    c1->imag = c1->imag + c2.imag;
    return *c1;
}

complex add(complex c1, complex* c2) {
    c1.real = c1.real + c2->real;
    c1.imag = c1.imag + c2->imag;
    return c1;
}

complex add(complex* c1, complex* c2) {
    c1->real = c1->real + c2->real;
    c1->imag = c1->imag + c2->imag;
    return *c1;
}

complex subtract(complex c1, complex c2) {
    c1.real = c1.real - c2.real;
    c1.imag = c1.imag - c2.imag;
    return c1;
}

complex subtract(complex* c1, complex c2) {
    c1->real = c1->real - c2.real;
    c1->imag = c1->imag - c2.imag;
    return *c1;
}

complex subtract(complex c1, complex* c2) {
    c1.real = c1.real - c2->real;
    c1.imag = c1.imag - c2->imag;
    return c1;
}

complex subtract(complex* c1, complex* c2) {
    c1->real = c1->real - c2->real;
    c1->imag = c1->imag - c2->imag;
    return *c1;
}

bool equal(complex c1, complex c2) {
    return (c1.real == c2.real && c1.imag == c2.imag);
}

bool equal(complex* c1, complex c2) {
    return (c1->real == c2.real && c1->imag == c2.imag);
}

bool equal(complex c1, complex* c2) {
    return (c1.real == c2->real && c1.imag == c2->imag);
}

bool equal(complex* c1, complex* c2) {
    return (c1->real == c2->real && c1->imag == c2->imag);
}

complex conjugate(complex c) {
    c.imag = -c.imag;
    return c;
}

complex conjugate(complex* c) {
    c->imag = -c->imag;
    return *c;
}

void multiply(complex* c, float s) {
    c->real = s * c->real;
    c->imag = s * c->imag;
}

double magnitude(complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

double magnitude(complex* c) {
    return sqrt(c->real * c->real + c->imag * c->imag);
}

double phase(complex c) {
    return atan(c.imag / c.real);
}

double phase(complex* c) {
    return atan(c->imag / c->real);
}

void toPolar(complex c, float *r, float *theta) {
    *r = float(magnitude(c));
    *theta = float(phase(c));
}

complex divide(complex c1, complex c2) {
    complex conj = conjugate(c2);
    multiply(&c1, c2.real * c2.real - c2.imag * c2.imag);
    multiply(&conj, c2.real * c2.real - c2.imag * c2.imag);
    c1 = add(c1, conj);
}

complex divide(complex c1, complex* c2) {
    complex conj = conjugate(c2);
    multiply(&c1, c2->real * c2->real - c2->imag * c2->imag);
    multiply(&conj, c2->real * c2->real - c2->imag * c2->imag);
    c1 = add(c1, conj);
}

complex divide(complex* c1, complex c2) {
    complex conj = conjugate(c2);
    multiply(c1, c2.real * c2.real - c2.imag * c2.imag);
    multiply(&conj, c2.real * c2.real - c2.imag * c2.imag);
    complex res = add(c1, conj);
    c1 = &res;
}

complex divide(complex* c1, complex* c2) {
    complex conj = conjugate(c2);
    multiply(c1, c2->real * c2->real - c2->imag * c2->imag);
    multiply(&conj, c2->real * c2->real - c2->imag * c2->imag);
    complex res = add(c1, conj);
    c1 = &res;
}