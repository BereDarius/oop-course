#include "OfflineSession.h"

void OfflineSession::display(std::ostream& os) {
	Request::display(os);
	os << " url: " << this->m_url;
}