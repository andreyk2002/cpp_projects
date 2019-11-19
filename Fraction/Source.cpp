
#include "Fraction.h"
//#define DEBUG


using namespace std;

int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Fraction *n;
	//Fraction *a;
	//Fraction* b;
	long numb;
	long nom1, nom2, den1, den2;
	cout << "Введите числитель и знаменатель первой дроби:";
	cin >> nom1 >> den1;
	cout << "Введите числитель и знаменатель второй дроби:";
	cin >> nom2 >> den2;

	cout << "Введите число:";
	cin >> numb;


	try
	{
		shared_ptr<Fraction>n(new Fraction());
		cout << "Checking default constructor..." << endl;
		cout << *n;
		
	}

	catch (runtime_error & err)
	{
		cout << err.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
		
	}
	
	
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		shared_ptr<Fraction>b(new Fraction(nom2, den2));
	}
	catch (runtime_error & err)
	{
		cout << err.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG

		

	}
   
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		shared_ptr<Fraction>b(new Fraction(nom2, den2));

		cout << "Сумма дробей: " << *a + *b << endl;

		cout << "Разность дробей: " << *a - *b << endl;


		cout << "Унарный минус: " << -(*a) << endl;

		cout << "Произведение дробей: " << (*a) *(* b) << endl;

		cout << "Частное дробей: " << (*a) /( *b) << endl;
				
	}
	
	catch (runtime_error & error)
	{
		cout << error.what() << endl;
#ifdef DEBUG
			return 1;
#endif // DEBUG
	}
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
				
		cout << "Умножение дроби на число: " << (*a) * numb << endl;

		cout << "Деление дроби на число: " << (*a) / numb << endl;

		cout << "Сложение дроби с числом: " << (*a) + numb << endl;

		cout << "Разность дроби с числом: " << (*a) - numb << endl;

		
	}
	catch (runtime_error & error)
	{
		cout << error.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
	}


	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		

		cout << "Разность числа с дробью " << numb - (*a) << endl;


		cout << "Сумма числа с дробью " << numb + (*a) << endl;


		cout << "Деление числа на дробь " << numb / (*a) << endl;


		cout << "Умножение числа на дробь " << numb * (*a) << endl;

		
	}
	catch (runtime_error & error)
	{
		cout << error.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
	}

	cout << "Операции сравнения: \n";
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		shared_ptr<Fraction>b(new Fraction(nom2, den2));

		if (*a > *b)
			cout << "Первая дробь больше \n ";
		if (*a < *b)
			cout << "Первая дробь меньше \n ";
		if (*a == *b)
			cout << "Дроби равны\n";
		if (*a != *b)
			cout << "Дроби не равны\n";
		if (*a >= *b)
			cout << "Первая дробь больше либо равна второй\n";
		if (*a <= *b)
			cout << "Первая дробь меньше либо равна второй\n";

	}
	catch (runtime_error & error)
	{
		cout << error.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
	}
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		shared_ptr<Fraction>b(new Fraction(nom2, den2));
		cout << "Операции приведения типа:" << double(*a) <<";";
		cout << double(*b)<<endl;
	}
	catch (runtime_error & error)
	{
		cout << error.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
	}
	
	system("pause");

	return 0;
}