
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

	catch (Fraction_exception & ex)
	{
		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
		
	}
	catch (...)
	{
		cout << "������� ��������� ����������" << endl;


	}
	
	
	try
	{
		shared_ptr<Fraction>a(new Fraction(nom1, den1));
		shared_ptr<Fraction>b(new Fraction(nom2, den2));

			

		cout << (*a);

		/*cout << "����� ������: " << *a + *b << endl;

		cout << "�������� ������: " << *a - *b << endl;


		cout << "������� �����: " << -(*a) << endl;

		cout << "������������ ������: " << (*a) *(* b) << endl;

		cout << "������� ������: " << (*a) /( *b) << endl;
	
	
		cout << "��������� ����� �� �����: " << (*a) * numb << endl;

		cout << "������� ����� �� �����: " << (*a) / numb << endl;

		cout << "�������� ����� � ������: " << (*a) + numb << endl;

		cout << "�������� ����� � ������: " << (*a) - numb << endl;

	
		cout << "�������� ����� � ������ " << numb - (*a) << endl;


		cout << "����� ����� � ������ " << numb + (*a) << endl;


		cout << "������� ����� �� ����� " << numb / (*a) << endl;


		cout << "��������� ����� �� ����� " << numb * (*a) << endl;
				
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

		cout << "�������� ���������� ����:" << double(*a) << ";";
		cout << double(*b) << endl;
		*/
	}
	catch (Fraction_exception & ex)
	{
		cout << ex.what() << endl;
#ifdef DEBUG
		return 1;
#endif // DEBUG
	}
	
	/*catch (my_exception_action & ex)
	{
		cout << ex.what() << endl;
	}*/

	catch (...)
	{
		cout << "������� ��������� ����������" << endl;
	

	}
	system("pause");

	return 0;
}