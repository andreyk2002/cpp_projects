
#include <iostream>
#include "Deque.h"
#include"HelpClasses.cpp"

using namespace std;

namespace str
{
	int string_comp(const void* a, const void* b)
	{
		return strcmp(*(char**)a, *(char**)b);

	}



}

template<typename Infotype>
void Deque<Infotype>::Erase()
{
	while (Pop_back());
	size = 0;
}

template<typename Infotype>
void Deque<Infotype>::Clone(const Deque& D)
{
	try
	{
		DequeItem* tmp;
		tmp = D.left;


		for (unsigned i = 0; i < D.size; i++)
		{
			Push_back(tmp->info);
			tmp = tmp->next;
		}
	}

	catch (...)
	{
		cout << "System exception!" << endl;

		Erase();

	}

}



template<typename Infotype>
void* Deque<Infotype>::PtrByIndex(unsigned k) const
{
	if (k >= size)
		throw My_Deque_exception("Impossible to obtDequeItem * tmp = front;");
	if (k <= size / 2)
	{
		DequeItem* tmp = left;
		for (unsigned i = 0; i < k; i++)
			tmp = tmp->next;
		return tmp;
	}
	else
	{
		DequeItem* tmp = right;
		for (unsigned i = 0; i < (size - k - 1); i++)
			tmp = tmp->previous;
		return tmp;
	}

}



template<typename Infotype>
Deque<Infotype>::Deque(const Deque& D)
{
	size = 0;
	Clone(D);
}

template<typename Infotype>
Deque<Infotype>::~Deque()
{
	Erase();
}

template<typename Infotype>
Deque<Infotype>& Deque<Infotype>::operator=(const Deque& D)
{
	if (this != &D)
	{
		Erase();
		Clone(D);
	}
	return *this;
}

template<typename Infotype>
void Deque<Infotype>::Push_back(Infotype Ainfo)
{
	try
	{
		DequeItem* tmp = new DequeItem(Ainfo);
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
	catch (...)
	{
		Erase();
		throw My_Deque_exception("Build errors ocurred");

	}
	    
	

}

template<typename Infotype>
void Deque<Infotype>::Push_front(Infotype Ainfo)
{
	try
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
	catch (...)
	{
		Erase();
		throw My_Deque_exception("Build errors ocurred");

	}

}


template<typename Infotype>
bool Deque<Infotype>::Pop_back()
{
	if (size == 0)
		return false;
	DequeItem* tmp = right;
	right = right->previous;
	delete tmp;
	size--;

	if (size == 0)
		left = nullptr;
	return true;
}

template<>
bool Deque<const char*>::Pop_back()
{
	if (size == 0)
		return false;
	DequeItem* tmp = right;
	right = right->previous;
	delete[]tmp->info;
	delete tmp;
	size--;

	if (size == 0)
		left = nullptr;
	return true;
}

template<typename Infotype>
bool Deque<Infotype>::Pop_front()
{
	if (size == 0)
		return false;

	DequeItem* tmp = left;
	left = left->next;
	delete tmp;
	size--;

	if (size == 0)
		right = nullptr;
	return true;

}

template<>
bool Deque<const char*>::Pop_front()
{


	if (size == 0)
		return false;

	DequeItem* tmp = left;
	left = left->next;
	delete[]tmp->info;
	delete tmp;
	size--;

	if (size == 0)
		right = nullptr;
	return true;

}

template<typename Infotype>
Infotype Deque<Infotype>::GetByIndex(unsigned k)const
{
	return  (static_cast<DequeItem*>(PtrByIndex(k)))->info;//((DequeItem*)PtrByIndex(k))->info; ;
}

template<typename Infotype>
void Deque<Infotype>::SetByIndex(Infotype Ainfo, unsigned k)const
{
	(static_cast<DequeItem*>(PtrByIndex(k)))->info = Ainfo;
}



template<typename Infotype>
unsigned Deque<Infotype>::GetSize() const
{
	return size;
}

template<typename Infotype>
Infotype Deque<Infotype>:: operator[](unsigned k) const
{
	return (*this).GetByIndex(k);
}




template <typename InfoType>
InfoType& Deque<InfoType> ::operator[](unsigned k)
{
	if (typeid(InfoType) == typeid(const char*))
	{
		throw My_Deque_exception("Using of operator[] is prohibited; use SetByIndex or GetByIndex instead");
	}
	return (InfoType&)(static_cast<DequeItem*>(PtrByIndex(k)))->info;
}



template<typename Infotype>
void Deque<Infotype>::Sort()
{
	Infotype* sorter = new Infotype[size];
	for (unsigned i = 0; i < size; i++)
	{
		sorter[i] = (this->GetByIndex(i));
	}
	if (typeid(Infotype) == typeid(const char*))
		qsort(sorter, size, sizeof(char**), str::string_comp);
	else
		sort(sorter, sorter + size);

	for (unsigned i = 0; i < size; i++)
	{
		this->SetByIndex(sorter[i], i);
	}
	delete[]sorter;;
}


template<typename Infotype>
ostream& Deque<Infotype>::Print(ostream& s)
{
	DequeItem* tmp = left;
	for (unsigned i = 0; i < size; i++)
	{
		s << "element  №" << i << " = " << (*tmp).info << "\n";
		tmp = tmp->next;
	}
	s << "\n";
	return s;

}


template<typename Infotype>
ostream& Deque<Infotype>::PrintReverse(ostream& s)
{

	DequeItem* tmp = right;
	for (int i = size - 1; i >= 0; i--)
	{
		s << "element  №" << i << " = " << (*tmp).info << "\n";
		tmp = tmp->previous;
	}
	s << "\n";
	return s;


}





