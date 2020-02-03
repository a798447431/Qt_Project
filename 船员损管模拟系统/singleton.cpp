#include "singleton.h"

SingleTon *SingleTon::m_pInstance = NULL;

SingleTon *SingleTon::GetInstance() { //生成单例模式对象
    if (m_pInstance == NULL) {
        m_pInstance = new SingleTon();
        atexit(Release);
    }
    return m_pInstance;
}

void SingleTon::Release() { //删除单例模式
    if (m_pInstance) {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

SingleTon::SingleTon() //单例模式的构造函数，构造时清空map和字符串信息
{
    clear_map();
    this->now_info = nullptr;
}

