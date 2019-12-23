#pragma once
#include "BottledDrink.h"
class MineralWater : public NonAlcDrink
{
protected:
	std::string CapColor;

	void AbstractMethod() const override {};
public:
	std::string GetColor()const;
	std::string GetDrinkName()const override;

	MineralWater(double Vol,const std::string &aname, bool isCarb, const std::string &CapCol);
	MineralWater(double Vol, const std::string &aname, const std::string &CapCol);

	friend std::ostream& operator<<(std::ostream&, const MineralWater&);
};

////////////////////////////////////////////////////////////////////////////////////////////


class Lemonade : public NonAlcDrink
{
protected:
	void AbstractMethod() const override {};
	unsigned short int SugarContent;

public:
	std::string GetSugar()const;
	std::string GetDrinkName()const override;

	virtual ~Lemonade();
	Lemonade(double Vol, const std::string &aname, bool isCarb, unsigned short int SugarCont);
	Lemonade(double Vol, const std::string &aname, unsigned short int SugarCont);

	friend std::ostream& operator<<(std::ostream&, const Lemonade&);

};

////////////////////////////////////////////////////////////////////////////////////////////////


class Milk :public NonAlcDrink
{
protected:
	void AbstractMethod() const override {};

	unsigned short int FatContent;

public:

	std::string GetFat()const;
	std::string GetDrinkName()const override;
	virtual ~Milk();
	Milk(double Vol, const std::string &aname, unsigned short int FatCont);

	friend std::ostream& operator<<(std::ostream&, const Milk&);

	   	 
};

