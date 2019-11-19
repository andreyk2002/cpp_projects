#pragma once

#include<iostream>
#include<string.h>
#include<Windows.h>
#include<memory>
#include<exception>
#include<algorithm>

using namespace std;

//template<typename T>
typedef Infotype;

class Deque
{
private:
	struct DequeItem
	{
		Infotype info;
		DequeItem* previous;
		DequeItem* next;

		DequeItem(Infotype Ainfo) : info(Ainfo), next(nullptr),
			previous(nullptr) {}

	};
	DequeItem* left, * right;
	unsigned size;

	void Erase();
	void Clone(const Deque&);

public:

	Deque() :left(nullptr), right(nullptr), size(0) {};
	Deque(const Deque&);
	virtual ~Deque();
	Deque& operator=(const Deque&);

	void Push_back(Infotype Ainfo);
	void Push_front(Infotype Ainfo);
	bool Pop_back();
	bool Pop_front();
	//Infotype GetFirst() const;
	//Infotype GetLast() const;
	//bool IsEmpty()const;
	unsigned GetSize()const;

	Infotype operator[](unsigned) const;

	Infotype operator[](unsigned) const;

	const Infotype& getByIndex(unsigned k) const;

	void Sort();

	friend ostream& operator << (ostream&, const Deque&);
	ostream& Print(ostream&);
	ostream& PrintReverse(ostream&);
	
	
};

