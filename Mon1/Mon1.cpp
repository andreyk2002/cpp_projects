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
	cout << "Pences(1)=" << endl;
	cin >> pences2;
	try
	{
		cout << "Проверяем конструктор по умолчанию:" << endl;
		shared_ptr<BrCash>Money (new BrCash());
		cout << *Money << endl;

	}
	catch (runtime_error & err)
	{

		cout << err.what() << endl;
		return 1;

	}

	try
	{
		if (pounds1 < 0 || pounds2 < 0 || shillings1 < 0)
			throw runtime_error("First input can't be negtive!");
		else if (shillings2 < 0 || pences1 < 0 || pences2 < 0)
			throw runtime_error("First input can't be negtive!");

	}
	catch (runtime_error & err)
	{
		cout << err.what() << endl;
		return 1;

	}



	try
	{
		cout << "унарный минус(первого): ";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		cout << -(*Money) << endl;
	}
	catch (runtime_error & err)//все ошибки выбрасываются в конструкторе
	{

		cout << err.what() << endl;

	}
	try
	{
		cout << "cумма: ";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		shared_ptr<BrCash>Money2(new BrCash(pounds2, shillings2, pences2));
		cout << (*Money) + (*Money2) << endl;
		//cash2.GetPences();

	}

	catch (runtime_error & err)//конструктор
	{


		cout << err.what() << endl;

	}


	try
	{
		cout << " разность:";
		shared_ptr<BrCash>Money(new BrCash(pounds1, shillings1, pences1));
		shared_ptr<BrCash>Money2(new BrCash(pounds2, shillings2, pences2));
		//*Money= (*Money - *Money2)
		cout << *Money - *Money2 << endl;

	}
	catch (runtime_error & err)//все ошибки выбрасываются в конструкторе
	{

		cout << err.what() << endl;

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
	catch (runtime_error & err)//все ошибки выбрасываются в конструкторе
	{
		cout << err.what() << endl;

	}

	return 0;
}

