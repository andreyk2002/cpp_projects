
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
	cout << "������� ��������� � ����������� ������ �����:";
	cin >> nom1 >> den1;
	cout << "������� ��������� � ����������� ������ �����:";
	cin >> nom2 >> den2;

	cout << "������� �����:";
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

		cout << "����� ������: " << *a + *b << endl;

		cout << "�������� ������: " << *a - *b << endl;


		cout << "������� �����: " << -(*a) << endl;

		cout << "������������ ������: " << (*a) *(* b) << endl;

		cout << "������� ������: " << (*a) /( *b) << endl;
				
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
				
		cout << "��������� ����� �� �����: " << (*a) * numb << endl;

		cout << "������� ����� �� �����: " << (*a) / numb << endl;

		cout << "�������� ����� � ������: " << (*a) + numb << endl;

		cout << "�������� ����� � ������: " << (*a) - numb << endl;

		
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
		

		cout << "�������� ����� � ������ " << numb - (*a) << endl;


		cout << "����� ����� � ������ " << numb + (*a) << endl;


		cout << "������� ����� �� ����� " << numb / (*a) << endl;


		cout << "��������� ����� �� ����� " << numb * (*a) << endl;

		
	}
	catch (runtime_error & error)
	{
		cout << error.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
	}

	cout << "�������� ���������: \n";
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		shared_ptr<Fraction>b(new Fraction(nom2, den2));

		if (*a > *b)
			cout << "������ ����� ������ \n ";
		if (*a < *b)
			cout << "������ ����� ������ \n ";
		if (*a == *b)
			cout << "����� �����\n";
		if (*a != *b)
			cout << "����� �� �����\n";
		if (*a >= *b)
			cout << "������ ����� ������ ���� ����� ������\n";
		if (*a <= *b)
			cout << "������ ����� ������ ���� ����� ������\n";

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
		cout << "�������� ���������� ����:" << double(*a) <<";";
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