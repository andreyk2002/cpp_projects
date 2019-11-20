//#define DEBUG
#include <Windows.h>
#include <iostream>
#include"BrCash.h"
#include<memory>



using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//BrCash* Money;
	//BrCash* Money2;
	int pounds1, pounds2, shillings1, shillings2;
	float pences1, pences2;
	cout << "Pounds(1)=" << endl;
	cin >> pounds1;
	cout << "Pounds(2)=" << endl;
	cin >> pounds2;
	cout << "Shillings(1)=" << endl;
	cin >> shillings1;
	cout << "Shillings(2)=" << endl;
	cin >> shillings2;
	cout << "Pences(1)=" << endl;
	cin >> pences1;
	cout << "Pences(2)=" << endl;
	cin >> pences2;
	try
	{
		cout << "Проверяем конструктор по умолчанию:" << endl;
		shared_ptr<BrCash>Money (new BrCash());
		cout << *Money << endl;

	}
	catch (my_exception_constr & ex)
	{

		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

		
	}

	try
	{
		if (pounds1 < 0 || pounds2 < 0 || shillings1 < 0)
			throw my_exception_constr("First input can't be negtive!");
		else if (shillings2 < 0 || pences1 < 0 || pences2 < 0)
			throw my_exception_constr("First input can't be negtive!");

	}
	catch (my_exception_constr & ex)
	{

		cout << ex.what() << endl;

		return 1;


	}



	try
	{
		cout << "унарный минус(первого): ";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
	  // (*Money).GetPences(cout);
		cout << -(*Money) << endl;
	}
	catch (my_exception_constr & ex)
	{

		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

	}
	try
	{
		cout << "cумма: ";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		shared_ptr<BrCash>Money2(new BrCash(pounds2, shillings2, pences2));
		cout << (*Money) + (*Money2) << endl;
		//cash2.GetPences();

	}
	catch (my_exception_constr & ex)
	{

		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

	}

	catch (runtime_error & err)
	{
		
		cout << err.what() << endl;

	}


	try
	{
		cout << " разность:";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		shared_ptr<BrCash>Money2(new BrCash(pounds2, shillings2, pences2));
		//(*Money2).GetPounds(cout);
		//*Money= (*Money - *Money2)
		cout << *Money - *Money2 << endl;

	}
	catch (my_exception_constr & ex)//все ошибки выбрасываются в конструкторе
	{

		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

	}
	
	try
	{
		cout << "+=: ";
		int n;
		cout << "Введите число:";
		cin >> n;

		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		
		((*Money) += n) += n;
		cout << *Money;

	}


	catch (my_exception_constr & ex)
	{

		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

	}

	catch (runtime_error & err)
	{

		cout << err.what() << endl;

	}


	try
	{
		cout << "-=: ";
		int n;
		cout << "Введите число:";
		cin >> n;

		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		
		((*Money) -= n) -= n;
		cout << *Money << endl;

	}

	catch (my_exception_constr & ex)
	{

		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

	}

	catch (runtime_error & err)
	{

		cout << err.what() << endl;

	}


	try
	{
		cout << "== ";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		shared_ptr<BrCash>Money2(new BrCash(pounds2, shillings2, pences2));
		cout << (*Money == *Money2) << endl;

		cout << "=! ";
		cout << (*Money != *Money2) << endl;

		cout << "> ";
		cout << (*Money > * Money2) << endl;

		cout << ">=";
		cout << (*Money >= *Money2) << endl;

		cout << "<";
		cout << (*Money < *Money2) << endl;

		cout << "<=";
		cout << (*Money <= *Money2) << endl;


	}
	catch (my_exception_constr & ex)//все ошибки выбрасываются в конструкторе
	{
		cout << ex.what() << endl;

	}

	return 0;
}

