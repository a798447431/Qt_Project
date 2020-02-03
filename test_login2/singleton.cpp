#include "singleton.h"

SingleTon *SingleTon::m_pInstance = NULL;

SingleTon *SingleTon::GetInstance() {
    if (m_pInstance == NULL) {
        m_pInstance = new SingleTon();
        atexit(Release);
    }
    return m_pInstance;
}

void SingleTon::Release() {
    if (m_pInstance) {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

SingleTon::SingleTon()
{
    this->now_info = "";
}
