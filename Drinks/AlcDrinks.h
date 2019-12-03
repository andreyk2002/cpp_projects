#pragma once
#include "BottledDrink.h"
class Beer :public AlcDrink
{

public:
	enum class Engridient{barley,wheat,ginger};
	virtual ~Beer();
	Beer(double Vol,const std::string &aname, double Str, Engridient en);
	std::string GetEngridient() const ;

	friend std::ostream& operator<<(std::ostream&, const Beer&);


protected:
	void AbstractMethod() const override {};
	Engridient engridient;
};


////////////////////////////////////////////////////////
class Vine: public AlcDrink
{
public:
	enum class Category{chernila,standart,premium,SupremeLuxurySuperElite};
	virtual ~Vine();
	Vine(double Vol, const std::string& aname, double Str, Category category, unsigned short year);
	Vine(double Vol, const std::string& aname, double Str, Category category);
	Vine(double Vol, const std::string& aname, double Str);

	std::string GetCategory() const;
	std::string GetYear()const;

	friend std::ostream& operator<<(std::ostream&, const Vine&);
	
protected:
	void AbstractMethod() const override {};
	Category category;
	unsigned short int year;

};

////////////////////////////////////////////////////////

class Brandy :public AlcDrink
{
protected:
	unsigned short int stars;
	std::string country;

	void AbstractMethod() const override {};
public:
	virtual ~Brandy();
	Brandy(double Vol, const std::string& aname, double Str, const std::string &country, unsigned short int stars);
	Brandy(double Vol, const std::string& aname, double Str, const std::string &country);
	Brandy(double Vol, const std::string& aname, double Str);

	std::string GetCountry()const;
	std::string GetStars()const;

	friend std::ostream& operator<<(std::ostream&, const Brandy&);
};



