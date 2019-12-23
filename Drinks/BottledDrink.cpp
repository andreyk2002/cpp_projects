#include "BottledDrink.h"

namespace My_str 
{

	std::string to_string(double num)
	{
		std::string res = std::to_string(num);
		int size = res.length();
		int i = size - 1;
		for (; i >= 0; i--)
		{
			if (res[i] == '0')
				res.erase(i);
			else
				break;
		}
		if (res[i] == '.')
			res.erase(i);
		return res;
	}
}
std::string BottledDrink::GetVolume()const
{
	return My_str::to_string(Volume)+"L";
}

void BottledDrink::SetVolume(double volume)
{
	if (volume > BottleVolume)
	   throw DrinkException("Volume bigger than max!");
	Volume = volume;
}

BottledDrink& BottledDrink::operator=(const BottledDrink& B)
{
	if (this != &B)
	{				
		DrinkName = B.DrinkName;
		Volume = B.Volume;
		BottleVolume = B.BottleVolume;
		
	}
	return *this;
}

std::string BottledDrink::GetDrinkName()const
{
	return DrinkName;
}

void BottledDrink::SetName(const std::string &name)
{
	DrinkName = name;
}

std::string BottledDrink::GetMaxVolume()const
{
	return My_str::to_string(BottleVolume)+"L";
}

BottledDrink::~BottledDrink()
{ 
	
}

BottledDrink::BottledDrink(double vol, const std::string &aname)
{
	BottleVolume = vol;
	SetVolume(vol);
	SetName(aname);
	
}

////////////////////////////////////////////


std::string AlcDrink::GetStrongh()const
{
	return My_str::to_string(Strongth)+"%";
}

AlcDrink::~AlcDrink()
{
}

AlcDrink::AlcDrink(double vol, const std::string &aname ,double Strongth):BottledDrink(vol,aname)
{
	
	SetStrongth(Strongth);
	
}

void AlcDrink::SetStrongth(double str)
{
	if (str < 0)
		throw DrinkException("Strongth can't be negtive!");
	if(str>96)
		throw DrinkException("Strongth can't be bigger than 96!");
	Strongth = str;
}


std::string NonAlcDrink::GetCarb()const
{
	if (isCarbonated)
		return "carbonated";
	return "non-carbonated";
}

NonAlcDrink::~NonAlcDrink()
{

}

NonAlcDrink::NonAlcDrink(double vol,const std::string &aname, bool isCarb) :BottledDrink(vol, aname)

{
	isCarbonated = isCarb;
}


