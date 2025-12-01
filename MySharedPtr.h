#pragma once


template<typename T>
class MySharedPtr {
private:
    T* ptr;
    size_t* refCount;

public:
    // 생성자
    explicit MySharedPtr(T* p = nullptr) : ptr(p), refCount(new size_t(1)) {}

    // 복사 생성자
    MySharedPtr(const MySharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        /* TODO */
    }

    // 대입 연산자
    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();
            /* TODO */
        }
        return *this;
    }

    // 소멸자
    ~MySharedPtr() { release(); }

    // 참조 해제
    void release() {
        /* TODO */
    }

    // 접근 연산자
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // 참조 카운트 확인
    size_t use_count() const { return *refCount; }

    // get() 기능
    T* get() const { return ptr; }

    // reset() 기능
    void reset(T* p = nullptr) {
        release();
        ptr = p;
        refCount = new size_t(1);
    }
};
