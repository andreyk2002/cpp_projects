

#include "Fraction.h"



void Fraction::SetNom(long nom)
{
	SetNom(nom, true);
}

void Fraction::SetDenom(long denom)
{
	if (denom == 0)
	{
		throw Fraction_exception("Critical error:division by zero(c)\n");
	}
	denominator = denom;
	Reduce();
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
		
	SetNom(nomerator,false);
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



void Fraction::Reduce()
{
	if (denominator < 0)
	{
		nomerator = -nomerator;
		denominator = -denominator;
	}

	long res = NOD(abs(nomerator), abs(denominator));
	denominator /= res;
	nomerator /= res;
	
}

void Fraction::SetNom(long nom, bool ShouldReduce)
{
	if (ShouldReduce)
	{
		nomerator = nom;
		Reduce();
	}
	else
		nomerator = nom;
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

