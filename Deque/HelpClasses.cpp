#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<string.h>
#include<Windows.h>
#include<memory>
#include<exception>
#include<algorithm>
#include<vector>

using namespace std;


class My_Deque_exception : public runtime_error {
public:
	My_Deque_exception(const char* const message)
		: runtime_error(message) {}
	My_Deque_exception(const My_Deque_exception& right)

		: runtime_error(right) {}

};

template<typename T>

class My_SmartPtr : public shared_ptr<T>//??
{
public:
	My_SmartPtr(T* ptr);

	~My_SmartPtr();

	T& operator*();

	T* GetPtr()const;

private:
	T* ptr;

};

template<typename T>
inline My_SmartPtr<T>::My_SmartPtr(T* ptr)
{
	this->ptr = ptr;

}

template<typename T>
inline My_SmartPtr<T>::~My_SmartPtr()
{
	delete ptr;

}

template<typename T>
inline T& My_SmartPtr<T>::operator*()
{
	return *ptr;
}

template<typename T>
inline T* My_SmartPtr<T>::GetPtr() const
{
	return ptr;
}

