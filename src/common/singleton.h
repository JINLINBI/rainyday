#pragma once
/************************************************************************
singleton模式类模板
1:延迟创建类实例    2:double check    3:互斥访问    4:模板
************************************************************************/
#include <thread>
#include <mutex>


template<class T>
class CSingleton {
private:
    static T* m_instance;
    CSingleton(void);

public:
    static T* get(void);
    static void close(void);

private:
    static std::mutex m_mutex;
};

//模板类static变量
template<class T>
T*  CSingleton<T>::m_instance = nullptr;

template<class T>
std::mutex CSingleton<T>::m_mutex;

//模板类方法实现
template<class T>
CSingleton<T>::CSingleton(void) {
}

template<class T>
T*  CSingleton<T>::get(void) {
    if (m_instance == nullptr) {
        std::lock_guard<std::mutex> lockGuard(m_mutex);
        if (m_instance == nullptr) {
            m_instance = new T;
        }
    }
    return m_instance;
}

template<class T>
void CSingleton<T>::close(void) {
    if (m_instance) {
        delete m_instance;
        m_instance = nullptr;
    }
}