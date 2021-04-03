#pragma once

#include <string>
#include <ostream>
#include <istream>

using namespace std;

struct Date {
	int month, day, year;
};

typedef enum {
	UNPAYED,
	PENDING_COMPLETION,
	COMPLETED
};

class Request {
public:
	Request(int id, Date dd, float price, char* subj) {
		m_id = id;
		m_dueDate = dd;
		m_price = price;
		strcpy(m_subject, subj);
		m_status = UNPAYED;
	}
	Request(const Request& other);
	Request& operator=(const Request& other);
	~Request();
	friend ostream& operator<<(ostream& output, const Request& r);
	friend istream& operator>>(istream& input, Request& r);
protected:
	Date m_dueDate;
	float m_price;
	char* m_subject; // clasa cu date alocate dinamic: RULE OF THREE: constructor de copiere, destructor si operator=
	int m_status; // 0 - unpayed, 1 - pending completion, 2 - completed
private:
	int m_id;
};