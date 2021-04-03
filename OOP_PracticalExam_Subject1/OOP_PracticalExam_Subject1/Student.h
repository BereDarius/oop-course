#pragma once
#include "Person.h";

class Student : public Person {
private:
	const int enrollment_number;
public:
	Student(int id, string fn, string ln, int en) : Person(id, fn, ln), enrollment_number(en) {};
	Student(Student& s);
	~Student() = default;
	friend ostream& operator<<(ostream& os, Student s);
};