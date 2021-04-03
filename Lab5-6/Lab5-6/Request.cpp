#include "Request.h"
#include "..\..\..\..\Downloads\Request.h"
#define _CRT_SECURE_NO_WARNINGS


int Request::getId()
{
	return this->m_id;
}

void Request::display(std::ostream& os)
{
	os << "id: " << this->m_id << " subject: " << this->m_subject;
}

Request::Request()
{
}

Request::Request(int id, Date dd, float price, const char* subj, Status st) {
	this->m_id = id;
	this->m_dueDate = dd;
	this->m_price = price;
	this->m_subject = new char[strlen(subj)+1];
	strcpy(this->m_subject, subj);
	this->m_status = st;
}
Request::Request(const Request& other) {
	this->m_id = other.m_id;
	this->m_dueDate = other.m_dueDate;
	this->m_price = other.m_price;
	this->m_subject = other.m_subject;
	this->m_status = other.m_status;
}

Request& Request::operator=(const Request& other) {
	this->m_id = other.m_id;
	this->m_dueDate = other.m_dueDate;
	this->m_price = other.m_price;
	this->m_subject = other.m_subject;
	this->m_status = other.m_status;
	return *this;
}

Request::~Request()
{
}

std::ostream& operator<<(std::ostream& os, Request& R)
{
	R.display(os);
	return os;
}
