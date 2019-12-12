
#include "Human.h"
#include <iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;



int main()
{
		
	Person::Gender male;
	male = Person::Gender::male;

	Person::Gender female;
	female = Person::Gender::female;

  
	try
	{
		vector<Person>Family(100);
		My_SmartPtr<Person> Adam(new Person( "Adam", male));//
		My_SmartPtr<Person>Eva(new Person("Eva", female));

		cout << (*Adam).GetID();

		
		My_SmartPtr<Person>John(new Person("John", Eva.GetPtr(), Adam.GetPtr(), male));
		My_SmartPtr<Person>Kate(new Person("Kate", Eva.GetPtr(), Adam.GetPtr(), female));

		My_SmartPtr<Person>Jim(new Person("Jim", Kate.GetPtr(), John.GetPtr(), male));
		My_SmartPtr<Person>Sarah(new Person("Sarah", Kate.GetPtr(), John.GetPtr(), female));

		My_SmartPtr<Person>Jake(new Person("Jake", Sarah.GetPtr(), Jim.GetPtr(), male));
		My_SmartPtr<Person>Zoey(new Person("Zoey", Sarah.GetPtr(), Jim.GetPtr(), female));
		My_SmartPtr<Person>Liz(new Person("Liz", Sarah.GetPtr(), Jim.GetPtr(), female));

		My_SmartPtr<Person>Ann(new Person("Kate", Zoey.GetPtr(), Jake.GetPtr(), female));
		My_SmartPtr<Person>Ken(new Person("Ken", Zoey.GetPtr(), Jake.GetPtr(), male));
		My_SmartPtr<Person>Margo(new Person(((*Liz).GiveBirth("Margo", female))));

		My_SmartPtr<Person>Ronnie(new Person("Ronnie", Margo.GetPtr(), Jake.GetPtr(), male));
		My_SmartPtr<Person>Alex(new Person("Alex", Margo.GetPtr(), Jake.GetPtr(), male));
		My_SmartPtr<Person>Jenifer(new Person("Jenifer", Margo.GetPtr(), Jake.GetPtr(), female));
		My_SmartPtr<Person>Nicole(new Person("Nicole", Margo.GetPtr(), Jake.GetPtr(), female));

		My_SmartPtr<Person>Tedd(new Person("Tedd", Jenifer.GetPtr(), Alex.GetPtr(), male));
		My_SmartPtr<Person>Nora(new Person("Nora", Nicole.GetPtr(), Ronnie.GetPtr(), female));

		My_SmartPtr<Person>Jeremy(new Person("Jeremy", Nora.GetPtr(), Tedd.GetPtr(), male));
		My_SmartPtr<Person>Richard(new Person("Richard", Nora.GetPtr(), Tedd.GetPtr(), female));

		My_SmartPtr<Person> FirstChild(new Person((*Eva).GiveBirth(John.GetPtr(), "Igor",male)));//??
	
		//My_SmartPtr<Person>Err(new Person("Error", male));
		//cout << *Err;

		/**My_SmartPtr<Person>Err2(new Person("Michael",Kate.GetPtr(),Adam.GetPtr(), male));
		cout<<(*Err2).GiveBirth("Don't matter what name", male);*/

		set<Person>Rodoslovnaya = {*Eva,*John,
			*Kate,*FirstChild,*Jim,*Sarah,*Jake,*Zoey,*Liz,*Ann,*Ken,*Margo };
		Rodoslovnaya.insert((*Adam));
		Rodoslovnaya.insert((*Ronnie));
		Rodoslovnaya.insert(*Alex);
		Rodoslovnaya.insert(*Jenifer);
		Rodoslovnaya.insert(*Nicole);
		Rodoslovnaya.insert(*Tedd);
		Rodoslovnaya.insert(*Nora);
		Rodoslovnaya.insert(*Jeremy);
		Rodoslovnaya.insert(*Richard);

		cout << "All poeple from oldest to youngest: "<<endl;
		for(const auto& el:Rodoslovnaya)
		{
			cout<<"№"<<el.GetID ()<<"\t" << el << endl;;
		
		}

		pair<string, Person>Peson_pair("Adam",(*Adam));
		/*string name;
		cout << "Welcome to our supersecret database!" << endl;
		cout << "Enter the name of person for archieving his description:" << endl;
		cin >> name;
		
		auto it=Rodoslovnaya.find(name)*/

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


