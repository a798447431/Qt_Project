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

void SingleTon::set_rowList(QString str) {
    this->rowList.append(str);
}

QString SingleTon::get_rowList(int i) {
    return this->rowList.at(i);
}

int SingleTon::rowList_size() {
    return this->rowList.size();
}

void SingleTon::remove_rowList() {
    this->rowList.clear();
}
