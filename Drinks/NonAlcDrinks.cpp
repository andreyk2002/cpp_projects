#include "NonAlcDrinks.h"

std::string MineralWater::GetColor() const
{
	return CapColor;
}

std::string MineralWater::GetDrinkName() const
{
	return "Water " + DrinkName;
}

MineralWater::MineralWater(double Vol, const std::string &aname, bool isCarb,const std::string &CapCol):NonAlcDrink(Vol,aname,isCarb)
{
	this->CapColor = CapCol;
}

MineralWater::MineralWater(double Vol, const std::string &aname,const std::string &CapCol):MineralWater(Vol,aname,false,CapCol)
{
}

std::ostream& operator<<(std::ostream& s, const MineralWater &Mw)
{
	s << "Water name: " <<Mw.DrinkName << "; Volume/MaxVolume: " << Mw.GetVolume() << "/" << Mw.GetMaxVolume();
	s << "; Type: " << Mw.GetCarb() << "; Cap color:" << Mw.CapColor << std::endl;

	return s;
}

std::ostream& operator<<(std::ostream& s, const Lemonade &L)
{
	s << "Water name: " << L.DrinkName << "; Volume/MaxVolume: " << L.GetVolume() << "/" << L.GetMaxVolume();
	s << "; Type: " << L.GetCarb() << "; Sugar constistance:" << L.GetSugar() << std::endl;

	return s;
}

std::ostream& operator<<(std::ostream& s, const Milk &M)
{
	s << "Water name: " << M.DrinkName << "; Volume/MaxVolume: " << M.GetVolume() << "/" << M.GetMaxVolume();
	s << "; Type: " << M.GetCarb() << "; Fat consistance:" << M.GetFat() << std::endl;

	return s;
}

std::string Lemonade::GetSugar() const
{
	return std::to_string(SugarContent)+"%";
}

std::string Lemonade::GetDrinkName() const
{
	return "Lemonade " + DrinkName;
}

Lemonade::~Lemonade()
{
}

Lemonade::Lemonade(double Vol, const std::string &aname, bool isCarb, unsigned short int SugarCont) :NonAlcDrink(Vol, aname, isCarb)
{
	if (SugarCont > 100||SugarCont<0)
		throw std::exception("Wrong consistance of sugar");
	SugarContent = SugarCont;
}

Lemonade::Lemonade(double Vol, const std::string &aname, unsigned short int SugarCont):Lemonade(Vol,aname,false, SugarCont)
{
}

std::string Milk::GetFat() const
{
	return std::to_string(FatContent) + "%";
}

std::string Milk::GetDrinkName() const
{
	return "Milk " + DrinkName;
}

Milk::~Milk()
{
}

Milk::Milk(double Vol, const std::string &aname, unsigned short int FatCont) :NonAlcDrink(Vol, aname, false)
{
	if (FatCont > 100||FatCont<0)
		throw std::exception("Wrong consistance of fat");
	FatContent = FatCont;
}
