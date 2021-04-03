#pragma once

#include "Request.h";

class OfflineSession : public Request {
public:
	OfflineSession(int id, Date dd, float price, char* subj, std::string url) : Request(id, dd, price, subj) {
		m_url = url;
	}
	OfflineSession(const Request request);
	OfflineSession(const OfflineSession& offline_session);
	friend ostream& operator<<(ostream& output, const Request& r);
	friend istream& operator>>(istream& input, Request& r);
private:
	std::string m_url;
};