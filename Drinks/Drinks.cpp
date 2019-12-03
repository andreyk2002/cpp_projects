
#include <iostream>
//#include"BottledDrink.h"
#include"AlcDrinks.h"
#include"NonAlcDrinks.h"

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{

		std::cout << "Alcoholic" << std::endl;
		Beer Lidskoe(0.7, "Lidskoe", 3.2, Beer::Engridient::wheat);

		Lidskoe.SetVolume(0.3);
		std::cout << Lidskoe;

		Vine byxlo(1.0, "Domashnee", 14.5);
		std::cout << byxlo;

		Brandy Armeniak(1.0, "Armenia", 40.0);
		std::cout << Armeniak;
	}

	catch (std::exception & ex)
	{
		std::cout << ex.what();

	}

	catch (...)
	{

		std::cout << "A system exception was called";
	}

	try 
	{
		std::cout << "Non-alcoholic" << std::endl;
		MineralWater Minskaya(2.0, "Минская",true, "Blue");
		std::cout << Minskaya;

		Lemonade Lem(1.2, "Laim", true, 40);
		std::cout << Lem;

		Milk milk(1.0, "Брест-литовск", 66);
		std::cout << milk;

	}
	catch (std::exception & ex)
	{
		std::cout << ex.what();

	}

	catch (...)
	{

		std::cout << "A system exception was called";
	}

	system("pause");
	return 0;
} 

