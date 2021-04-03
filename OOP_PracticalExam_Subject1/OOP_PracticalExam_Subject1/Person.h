#pragma once
#include <string>
#include <ostream>

using namespace std;

class Person {
protected:
	const int id;
	string first_name;
	string last_name;
public:
	Person(int id, string fn, string ln) : id(id), first_name(fn), last_name(ln) {};
	Person(Person& p) : id(p.id), first_name(p.first_name), last_name(p.last_name) {};
	~Person() = default;
	friend ostream& operator<<(ostream& os, Person& p);
};