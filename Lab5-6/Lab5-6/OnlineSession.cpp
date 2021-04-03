#include "OnlineSession.h"

void OnlineSession::display(std::ostream& os) {
	Request::display(os);
	os << " time: " << this->m_time;
}