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

	static void ToSimple(long& a, long& b);

	static void ToPositiveD(long& a, long& b);


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

