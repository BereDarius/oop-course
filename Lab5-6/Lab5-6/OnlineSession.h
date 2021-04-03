#pragma once

#include "Request.h";

class OnlineSession : public Request {
public:
	OnlineSession(int id, Date dd, float price, char* subj, std::string url, int time) : Request(id, dd, price, subj) {
		m_url = url;
		m_time = time;
	}
	OnlineSession(const Request request);
	OnlineSession(const OnlineSession& offline_session);
	friend ostream& operator<<(ostream& output, const Request& r);
	friend istream& operator>>(istream& input, Request& r);
private:
	std::string m_url; // nu mai trebuie RULE OF THREE
	int m_time;
};