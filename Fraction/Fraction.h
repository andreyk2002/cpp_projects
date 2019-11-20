#pragma once
#include<memory>
#include <iostream>
#include<exception>
#include<cmath>
#include <Windows.h>

using namespace std;
class Fraction
{
private:
	long nomerator;
	long denominator;
	static long NOD(long a, long b);

	

	void Reduce();

	void SetNom(long nom, bool ShouldReduce);


public:
	void SetNom(long nom);
	void SetDenom(long denom);
	long GetNom()const;
	long GetDenom()const;

	Fraction();
	//Fraction(long nomerator);
	Fraction(long nomerator, long denominator);
	virtual ~Fraction(void);

		
	

	
	Fraction operator - () const;

	Fraction operator +(const Fraction&)const;

	Fraction operator -(const Fraction&)const;

	Fraction operator *(const Fraction&)const;

	Fraction operator /(const Fraction&)const;

	Fraction operator +(const long&)const;

	Fraction operator -(const long&)const;

	Fraction operator *(const long&)const;

	Fraction operator /(const long&)const;

	

	bool operator ==(const Fraction&)const;
	bool operator !=(const Fraction&)const;
	bool operator >(const Fraction&)const;
	bool operator <(const Fraction&)const;
	bool operator >=(const Fraction&)const;
	bool operator <=(const Fraction&)const;

	
    operator double ()const;
	

	friend Fraction operator + (const long&, const Fraction&);
	friend Fraction operator - (const long&, const Fraction&);
	friend Fraction operator * (const long&, const Fraction&);
	friend Fraction operator / (const long&, const Fraction&);
	friend ostream& operator<< (ostream&, const Fraction&);

};

class Fraction_exception : public exception {
public:
	Fraction_exception(const char* const message)
		: exception(message) {}
	Fraction_exception(const Fraction_exception& right)

		: exception(right) {}

};

/*class my_exception_action : public exception {
public:
	my_exception_action(const char* const message)
		: exception(message) {}
	my_exception_action(const my_exception_action& right)

		: exception(right) {}

};*/



