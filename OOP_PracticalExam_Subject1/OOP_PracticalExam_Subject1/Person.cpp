#include "Person.h";

ostream& operator<<(ostream& os, Person& p)
{
	os << "id: " << p.id << " first name: " << p.first_name << " last name: " << p.last_name;
	return os;
}

Person::Person(Person& p) {

}
