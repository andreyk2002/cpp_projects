#include "Human.h"

#pragma warning(disable:4996)

void Person::Erase()
{
	delete[]name;
}

void Person::Clone(const Person& p)
{
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	mother = p.mother;
	father = p.father;
	gender = p.gender;
}


void Person::SetMother(Person* m)
{
	if (m != NULL && m->gender == Gender::male)
	{
		throw Person_exception
		("Wrong gender for mother!");
	}
	mother = m;

}

void Person::SetFather(Person* f)
{
	if (f != NULL && f->gender == Gender::female)
	{
		throw Person_exception
		("Wrong gender for father!");
	}

	father = f;
}


Person::Person(const char* aname, Gender g) : ID(++next_ID)
{
	if (ID > 2)
		throw Person_exception("What about mother?");
	SetFather(NULL);
	SetMother(NULL);
	SetGender(g);
	SetName(aname);
	
}
Person::Person(const char* aname, Person* mother, Person* father, Gender g)
	:ID(++next_ID)
{	
	SetFather(father);
	SetMother(mother);
	SetGender(g);
	SetName(aname);
}
Person::~Person()
{
	Erase();


}
void Person::SetGender(Gender gen)
{
	gender = gen;
}
string Person::GetGender()
{
	if (gender == Gender::male)
	{
		return "male";
	}
	return "female";
}

const char* Person::GetName()const
{

	return name;

}

const char* Person::GetMotherName() const
{
	if (mother == NULL)
		throw Person_exception("Good try,man");
	return (*mother).name;
}

const char* Person::GetFatherName() const
{
	if (father == NULL)
		throw Person_exception("Father is unknown");
	return (*father).name;
}

void Person::SetName(const char* aname)
{
	if (aname == NULL)
		throw Person_exception("Invalid parametr {NULL}");
	if (aname[0] == '\0')
		throw Person_exception("Invalid name length!(empty)");
	name = new char[strlen(aname) + 1];
	strcpy(name, aname);
}



Person Person::GiveBirth (Person *father,const char*name,Gender g)
{
	//srand(time(NULL));

	if ((*father).gender == Gender::female)
		throw Person_exception("Woman can't be a father of a child!");
	if (this->gender == Gender::male)
		throw Person_exception("Man can't be a mother of a child");
	// int xy = rand() % 2;

	//Gender g;
	//xy == 1 ? g = Gender::male : g = Gender::female;

	Person child(name, this, father, g);
	return child;
}

Person Person::GiveBirth(const char* aname, Gender g)
{
	if (this->gender == Gender::male)
		throw Person_exception("Man can't be a mother of a child");
	Person child(aname, this, NULL, g);
	return child;

}


Person::Person(const Person& d) :ID(++next_ID)
{
	Clone(d);
}

int Person::GetID()
{
	return ID;
}
Person& Person::operator=(const Person& p)
{
	if (this != &p)
	{
		Erase();
		Clone(p);
	}
	return *this;
}
int Person::next_ID = 0;

ostream& operator<<(ostream& s,  Person p)//??
{
	if (p.mother == NULL)
	{
		s << "Name:" << p.name << endl;
		s << "This person doesn't have a mother!"<<endl;
		s << "Gender:" << p.GetGender() << endl<<endl;
	}
	else if(p.father == NULL)
	{
	s << "Name:" << p.name << endl;
	s << "Gender:" <<p.GetGender() << endl;
	s << "Mother Name: " << p.GetMotherName() << endl<<endl;
	}
	else
	{
		s << "Name:" << p.name << endl;
		s << "Gender:" <<p.GetGender() << endl;
		s << "Mother Name: " << p.GetMotherName() <<"; ";
		s << "Father Name: " << p.GetFatherName() << endl<<endl;
	}
	return s;
}
