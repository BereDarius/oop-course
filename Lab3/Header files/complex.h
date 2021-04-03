//
// Created by Darius on 3/11/2021.
//

#ifndef LAB3_COMPLEX_H
#define LAB3_COMPLEX_H

#endif //LAB3_COMPLEX_H

typedef struct {
    float real, imag;
} complex;

complex create(float real, float imag);
complex read();

void display(complex c);
void display(complex* c);

complex add(complex c1, complex c2);
complex add(complex c1, complex* c2);
complex add(complex* c1, complex c2);
complex add(complex* c1, complex* c2);

complex subtract(complex c1, complex c2);
complex subtract(complex* c1, complex c2);
complex subtract(complex c1, complex* c2);
complex subtract(complex* c1, complex* c2);

complex multiply(complex c1, complex c2);
complex multiply(complex* c1, complex c2);
complex multiply(complex c1, complex* c2);
complex multiply(complex* c1, complex* c2);

bool equal(complex c1, complex c2);
bool equal(complex* c1, complex c2);
bool equal(complex c1, complex* c2);
bool equal(complex* c1, complex* c2);

complex conjugate(complex c);
complex conjugate(complex* c);

void multiply(complex* c, float s);

double magnitude(complex c);
double magnitude(complex* c);

double phase(complex c);
double phase(complex* c);

void toPolar(complex c, float *r, float* theta);
void toPolar(complex* c, float *r, float* theta);

complex divide(complex c1, complex c2);
complex divide(complex c1, complex* c2);
complex divide(complex* c1, complex c2);
complex divide(complex* c1, complex* c2);