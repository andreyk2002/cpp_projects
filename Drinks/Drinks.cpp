
#include <iostream>
//#include"BottledDrink.h"
#include"AlcDrinks.h"
#include"NonAlcDrinks.h"

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BottledDrink* B[6] = { nullptr };

	
	try
	{
		
		
		std::cout << "Alcoholic" << std::endl;
		Beer Lidskoe(0.7, "Lidskoe", 3.2, Beer::Engridient::wheat);
		std::cout << Lidskoe.GetDrinkName();
		B[0]= &Lidskoe;


		//std::cout << Lidskoe.GetDrinkName();
		Lidskoe.SetVolume(0.3);
		std::cout << Lidskoe;

		Vine byxlo(1.0, "Domashnee", 14.5);
		std::cout << byxlo;
		B[1] = &byxlo;

		Brandy Armeniak(1.0, "Armenia", 40.0);
		std::cout << Armeniak;

		B[2] = &Armeniak;


		std::cout << "Non-alcoholic" << std::endl;
		MineralWater Minskaya(2.0, "Минская", true, "Blue");
		std::cout << Minskaya;
		B[3] = &Minskaya;

		Lemonade Lem(1.2, "Laim", true, 40);
		std::cout << Lem;
		B[4] = &Lem;

		Milk milk(1.0, "Брест-литовск", 66);
		std::cout << milk;
		B[5] = &milk;

		for (int i = 0; i < 6; i++)
		{
			std::cout << "Name: " << (*B[i]).GetDrinkName();
			std::cout << "; Max volume/volume:" << (B[i])->GetMaxVolume() << "/" << (B[i])->GetVolume() << std::endl;


		}

	}

	catch (DrinkException & ex)
	{
		std::cout << ex.what()<<std::endl;

	}

	catch (...)
	{

		std::cout << "A system exception was called"<<std::endl;
	}

	

		
	system("pause");
	return 0;
} 

