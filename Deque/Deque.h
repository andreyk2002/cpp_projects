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

template<typename Infotype>




class Deque
{
private:
	struct DequeItem
	{
		Infotype info;
		DequeItem* next;
		DequeItem* previous;

		template<typename Infotype>
		DequeItem(Infotype Ainfo) : info(Ainfo), next(nullptr),
			previous(nullptr) {};
		template<>
		DequeItem(const char* AInfo) : next(nullptr), previous(nullptr)
		{
			info = new char[strlen(AInfo) + 1];
			strcpy((char*)info, AInfo);
		}
		

	};
	
	DequeItem* left, * right;
	unsigned size;

	void Erase();
	void Clone(const Deque&);
	void Push_back(Infotype Ainfo,bool Erase);

	void* PtrByIndex(unsigned k) const;

	
	

public:

	


	Deque() :left(nullptr), right(nullptr), size(0) {};
	Deque(const Deque&);
	virtual ~Deque();
	Deque& operator=(const Deque&);

	void Push_back(Infotype Ainfo);
	void Push_front(Infotype Ainfo);
	bool Pop_back();
	bool Pop_front();

	void SetByIndex(Infotype ,unsigned ) const;
	Infotype GetByIndex(unsigned k) const;
	
	//Infotype GetLast() const;
	//bool IsEmpty()const;
	unsigned GetSize()const;
	Infotype& operator[](unsigned);
	Infotype  operator[](unsigned) const;

	

	

	void Sort();

	//friend ostream& operator << (ostream&, const Deque&);
	ostream& Print(ostream&);
	ostream& PrintReverse(ostream&);
	
	
};






































