#include "AlcDrinks.h"

Beer::~Beer()
{

}

Beer::Beer(double Vol, const std::string &aname, double Str, Engridient en) :AlcDrink(Vol, aname, Str)
{
	engridient = en;
}

std::string Beer::GetEngridient()const
{
	switch (engridient)
	{
	case Beer::Engridient::barley:
		return "barley";
	
	case Beer::Engridient::wheat:
		return "wheat";
	
	case Beer::Engridient::ginger:
		return "ginger";
	
	}

}

std::ostream& operator<<(std::ostream& s, const Beer &B)//?
{
	s << "Beer name: " << B.DrinkName << "; Volume/MaxVolume: " << B.GetVolume() << "/" << B.GetMaxVolume();
	s << "; Strongth: " << B.GetStrongh() << "; Main engridient:" << B.GetEngridient() << std::endl;

	return s;
}

std::ostream& operator<<(std::ostream& s, const Vine &V)
{
	s << "Vine name: " << V.DrinkName << "; Volume/MaxVolume: " << V.GetVolume() << "/" << V.GetMaxVolume();
	s << "; Strongth: " << V.GetStrongh() << ";" << V.GetYear() << "; Category:" << V.GetCategory() << std::endl;

	return s;
}

std::ostream& operator<<(std::ostream& s, const Brandy &Br)
{
	s << "Brandy name: " << Br.DrinkName << "; Volume/MaxVolume: " << Br.GetVolume() << "/" << Br.GetMaxVolume();
	s << "; Strongth: " << Br.GetStrongh() << "; " << Br.GetCountry() << "; " << Br.GetStars() << std::endl;

	return s;
	
}

//////////////////////////////////////////////////////

Vine::~Vine()
{
}

Vine::Vine(double Vol, const std::string &aname, double Str, Category category, unsigned short year) :AlcDrink(Vol, aname, Str)
{
	this->category = category;
	this->year = year;
}

Vine::Vine(double Vol, const std::string &aname, double Str, Category category) :Vine(Vol, aname, Str, category, 2019)
{
}

Vine::Vine(double Vol, const std::string& aname, double Str) : Vine(Vol, aname, Str, Category::chernila, 2019)
{

}

std::string Vine::GetCategory()const
{
	switch (category)
	{
	case Vine::Category::chernila:
		return "chernila"; 
		
	case Vine::Category::standart:
	   return "standart";
		
	case Vine::Category::premium:
		return "premium";
		
	case Vine::Category::SupremeLuxurySuperElite:
		return"SupremeLuxurySuperElite";
		
	
	}
}

std::string Vine::GetYear() const
{
	return " Bottled in " + std::to_string(year);
}


////////////////////////////////////////////////

Brandy::~Brandy()
{
}

Brandy::Brandy(double Vol,const std::string &aname, double Str, const std::string &country, unsigned short int stars):AlcDrink(Vol, aname, Str)
{
	this->country = country;
	this->stars = stars;
}

Brandy::Brandy(double Vol, const std::string &aname, double Str, const std::string &country):Brandy(Vol,aname,Str,country,3)
{
}

Brandy::Brandy(double Vol, const std::string &aname, double Str):Brandy(Vol,aname,Str,"Belarus")
{
}

std::string Brandy::GetCountry() const
{
	return "Country: "+country;
}

std::string Brandy::GetStars() const
{
	return "Extract:"+std::to_string(stars)+" stars";
}
