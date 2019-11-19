
#include <iostream>
#include "Deque.h"

void Deque::Erase()
{
	while (Pop_back())
		size = 0;
}

void Deque::Clone(const Deque& D)
{
	DequeItem* tmp;
	*tmp= D.left;
	

	for (unsigned i = 0; i < D.size; i++)
	{
		Push_back(tmp->info);
		tmp = tmp->next;
	}

}

Deque::Deque(const Deque& D)
{
	size = 0;
	Clone(D);
}

Deque::~Deque()
{
	Erase();
}

Deque& Deque::operator=(const Deque& D)
{
	if (this != &D) {
		Erase();
		Clone(D);
	}
	return *this;
}

void Deque::Push_back(Infotype Ainfo)
{
	DequeItem *tmp = new DequeItem(Ainfo);
	if (size > 0)
	{
		right->next = tmp;
		tmp->previous = right;
	}
	else
		left = tmp;
	right = tmp;
	size++;
}

void Deque::Push_front(Infotype Ainfo)
{
	DequeItem* tmp = new DequeItem(Ainfo);
	if (size > 0)
	{
		left->previous = tmp;
		tmp->next = left;

	}
	else
		right = tmp;
	left = tmp;
	size++;
}

bool Deque::Pop_back()
{
	if(size==0)
		return false;
	DequeItem* tmp = right;
	right = right->previous;
	delete tmp;
	size--;

	if (size == 0)
		left = nullptr;
	return true;
}

bool Deque::Pop_front()
{
	if(size==0)
		return false;

	DequeItem* tmp = left;
	left = left->next;
	delete tmp;
	size--;

	if (size == 0)
		right = nullptr;
	return true;

}

/*Infotype Deque::GetFirst() const
{
	return Infotype();
}

Infotype Deque::GetLast() const
{
	return Infotype();
}

bool Deque::IsEmpty() const
{
	return false;
}*/

unsigned Deque::GetSize() const
{
	return size;
}

Infotype Deque::operator[](unsigned k) const
{
	if((k<0)||(k>=size))
		throw exception
		("Impossible to execute	operator[]: invalid index");
	if (k <= size / 2)
	{
		DequeItem* tmp = left;
		for (unsigned i = 0; i < k; i++)
			tmp = tmp->next;
		return tmp->info;
	}
	else
	{
		DequeItem* tmp = right;
		for (unsigned i = 0; i < (size - k); i++)
			tmp = tmp->previous;
		return tmp->info;
	}
	const Infotype& Deque::getByIndex(unsigned k) const
	{
		if ((k < 0) || (k >= size))
			throw exception
			("Impossible to execute operator[]: invalid index");
		DequeItem * tmp = front;
		for (unsigned i = 0; i < k; i++)
			tmp = tmp->next;
		return tmp->info;
	}
	InfoType& LQueue::operator [] (unsigned k)
	{
		return (InfoType&)GetByIndex(k);
	}
}



void Deque::Sort()
{
}

ostream& Deque::Print(ostream& s )
{
	for (unsigned i = 0; i < size; i++)
		s << "element  №" << i << " = " << *this->[i] << "\n";
	return s;


ostream& Deque::PrintReverse(ostream&s)
{
	// TODO: вставьте здесь оператор return
}

ostream &operator<<( ostream &s,const Deque &D)
{
	
		for (unsigned i = 0; i < D.size; i++)
			s << "element  №" << i << " = " << D[i] << "\n";
		s << endl;

		for (unsigned i = D.size - 1; i >= 0; i--)
			s << "element  №" << i << " = " << D[i] << "\n";

		return s;
	
}




