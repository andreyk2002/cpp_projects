
#include "Human.h"
#include <iostream>

using namespace std;


int main()
{
	
	
	//char s[200];
	//cout << "Enter your hero name:";
	//cin.getline(s, 200);
	Person::Gender male;
	male = Person::Gender::male;

	Person::Gender female;
	female = Person::Gender::female;

	

	try
	{
		My_SmartPtr<Person> Adam(new Person( "Adam", male));//вывод енума,оформление мэйна,конструкторы
		My_SmartPtr<Person>Eva(new Person("Eva", female));//геттеры для родителей

		cout << *Adam;
		cout << *Eva;
		//cout << (*Adam).GetID() << endl;
		

		My_SmartPtr<Person>Sb(new Person("John",Eva.GetPtr(),Adam.GetPtr(),male));
		My_SmartPtr<Person>Kate(new Person("Kate", Eva.GetPtr(), Adam.GetPtr(), female));

		cout << *Sb;

		Person FirstChild=(*Eva).GiveBirth(Sb.GetPtr(), "Igor",male);//??
		cout << FirstChild;

		cout << (*Kate).GiveBirth("Daniel", male);
		//My_SmartPtr<Person>Err(new Person("Error", male));
		//cout << *Err;
	}
	
	catch (Person_exception & ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{

		cout << "A system exception was called" << endl;
	}

	system("pause");
	return 0;
}


