

#include "Fraction.h"



void Fraction::SetNom(long nom)
{
	nomerator = nom;
}

void Fraction::SetDenom(long denom)
{
	if (denom == 0)
	{
		throw runtime_error("Critical error:division by zero\n");
	}
	denominator = denom;
}

long Fraction::GetNom() const
{
	return nomerator;
}

long Fraction::GetDenom() const
{
	return denominator;
}

Fraction::Fraction()
{
	SetNom(0);
	SetDenom(1);
}



Fraction::Fraction(long nomerator, long denominator)
{
	if (nomerator == 0)
	{
		Fraction();
	}
	if (denominator == 0)
	{
		//throw runtime_error("Critical error:division by zero\n");
		SetDenom(denominator);
	}
	ToSimple(nomerator, denominator);
	ToPositiveD(nomerator, denominator);
	
	SetNom(nomerator);
	SetDenom(denominator);
	
}

Fraction::~Fraction(void)
{

}

long Fraction::NOD(long a, long b)
{
	
	while (b != 0)
	{
		long temp;
		temp = b;
		b= a % b;
		a = temp;

	}
	return a;
}

void Fraction::ToSimple(long &a,long &b)
{
	long res = NOD(abs(a), abs(b));
	b /= res;
	a /= res;
}


void Fraction::ToPositiveD(long &a, long &b)
{
	if (b < 0)
	{
		a=-a;
		b=-b;
	}
	
}





Fraction Fraction::operator-() const
{
	
	return Fraction(-nomerator, denominator);
}

Fraction Fraction::operator+(const Fraction& f) const
{
	long nom, den;
	nom = nomerator * f.denominator + f.nomerator * denominator;
	den = denominator * f.denominator;
	
	return Fraction(nom,den);
}

Fraction Fraction::operator-(const Fraction& f) const
{
	long nom, den;
	nom = nomerator * f.denominator - f.nomerator * denominator;
	den = denominator * f.denominator;
	return Fraction(nom,den);
}

Fraction Fraction::operator*(const Fraction& f) const
{

	return Fraction(nomerator*f.nomerator,denominator*f.denominator);
}

Fraction Fraction::operator/(const Fraction& f) const
{
	return Fraction(nomerator * f.denominator, denominator * f.nomerator);
}

Fraction Fraction::operator+(const long& l) const
{
	return Fraction(nomerator+l*denominator,denominator);
}

Fraction Fraction::operator-(const long& l) const
{
	return  Fraction(nomerator - l * denominator, denominator);
}

Fraction Fraction::operator*(const long& l) const
{
	return  Fraction(nomerator * l , denominator);
}

Fraction Fraction::operator/(const long& l) const
{
	return Fraction(nomerator , denominator*l);
}

bool Fraction::operator==(const Fraction& f) const
{
	return (nomerator==f.nomerator&& denominator==f.denominator);
}

bool Fraction::operator!=(const Fraction& f) const
{
	return (!this->operator==(f));;
}

bool Fraction::operator>(const Fraction& f) const
{
	if (this->nomerator * f.denominator - this->denominator * f.nomerator > 0) //??
		return true;
	return false;
	
}

bool Fraction::operator<(const Fraction& f) const
{
	return !(this->operator==(f)||this->operator>(f));
}

bool Fraction::operator>=(const Fraction& f) const
{
	return (this->operator==(f) || this->operator>(f));
}

bool Fraction::operator<=(const Fraction& f) const
{
	return !(this->operator>(f));
}

Fraction::operator double()const
{
	double n = nomerator;
	double d = denominator;

	return n/d;
}

Fraction operator+(const long& l, const Fraction& f)
{
	return Fraction(l*f.denominator+f.nomerator,f.denominator);
}

Fraction operator-(const long& l, const Fraction& f)
{
	return Fraction(l * f.denominator - f.nomerator, f.denominator);
}

Fraction operator*(const long& l, const Fraction& f)
{
	return Fraction(l * f.nomerator, f.denominator);
}

Fraction operator/(const long& l, const Fraction&  f)
{
	return Fraction(l * f.denominator , f.nomerator);
}

ostream& operator<<(ostream& s, const Fraction& f)
{
	
		s << f.nomerator << "/" << f.denominator << endl;
		return s;
	

}
