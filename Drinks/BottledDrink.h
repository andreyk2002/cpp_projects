#pragma once
#include<iostream>
#include<string>
#include<exception>
#include<Windows.h>



//using namespace std;

class BottledDrink
{
protected:
	std::string DrinkName;
	double Volume;
	double BottleVolume;
	virtual void AbstractMethod() const = 0;
	static std::string My_to_string(double num) ;

public:
	std::string GetVolume()const;
	void SetVolume(double volume);

	std::string GetDrinkName()const;
	void SetName(const std:: string &name);

	std::string GetMaxVolume()const;

	virtual ~BottledDrink();
	BottledDrink(double vol, const std::string &aname);

};

class AlcDrink: public BottledDrink
{

public:
	std::string GetStrongh()const;
	virtual ~AlcDrink();
	AlcDrink(double vol, const std::string &aname,double Strongth);

protected:
	 double Strongth;
	 void SetStrongth(double str);
	

};

class NonAlcDrink : public BottledDrink
{
public:
	std::string GetCarb()const;
	virtual ~NonAlcDrink();
	NonAlcDrink(double vol, const std::string &aname, bool isCarb);

protected:
	bool isCarbonated;
};
