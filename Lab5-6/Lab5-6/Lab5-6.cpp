#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Request.h";
#include <string.h>

using namespace std;

int main()
{
	char* subj = new char[100];
	strcpy(subj, "matematica");
	Request r1(1, { 4, 1, 2021 }, 20.5, subj, UNPAYED);
}
