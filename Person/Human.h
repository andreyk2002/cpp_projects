#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<exception>
#include<memory>


using namespace std;


class Person
{
public:


	bool operator<(const Person& a)const;
	enum class Gender { male, female };

	Person(const char*, Gender);
	Person(const char*, Person*, Person*, Gender);
	virtual ~Person();


	string GetGender() const;//??
	const char* GetName()const;
	const char* GetMotherName()const;
	const char* GetFatherName()const;
	int GetID()const;

	void SetName(const char*);

	Person GiveBirth(Person*, const char*, Gender g);
	Person GiveBirth(const char*, Gender g);

	Person(const Person&);//copy constructor


	Person& operator =(const Person&);
	friend ostream& operator<<(ostream&, const Person&);

	
private:
	void Erase() const;
	void Clone(const Person&);

	char* name;
	static int next_ID;
	const int ID = 0;
	Gender gender;
	Person* mother;
	Person* father;

	void SetGender(Gender);
	void SetMother(Person*);
	void SetFather(Person*);

	
};

class Person_exception : public exception {
public:
	Person_exception(const char* const message)
		: exception(message) {}
	Person_exception(const Person_exception& right)

		: exception(right) {}

};

template<typename T>

class My_SmartPtr: public shared_ptr<T>//??
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
inline My_SmartPtr<T>::My_SmartPtr(T* ptr)//privte constr
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







