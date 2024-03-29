#include "BrCash.h"
#include<iostream>
#include<cmath>
#include<exception>
#include<string>

using namespace std;

BrCash::BrCash()
{
	pounds = 0;
	shillings = 0;
	pences = 0;

}
BrCash::BrCash(int pounds, int shillings, float pences)
{
		SetPounds(pounds);
		SetShillings(shillings);
		SetPences(pences);
		
}

BrCash::~BrCash()
{

}

void BrCash::SetPounds(int p)
{
	if (abs(p) > 1000000000)
		throw my_exception_constr("wrong anount of money(bigger than max)(c)");
	pounds = p;
}

void BrCash::SetShillings(int s)
{
	if(s>20)
		throw my_exception_constr("wrong anount of money(1)(c)");
	shillings = s;
}

void BrCash::SetPences(float pe)
{
	float ep = pe - floor(pe);
	if (abs(ep - 0.5) != 0 && ep != 0)
	     throw my_exception_constr("wrong input of money(pences err)(c)");
	else if(pe>12)
		throw my_exception_constr("wrong anount of money(1)(c)");
	pences = pe;
}

ostream& BrCash::GetPounds(ostream& s)
{

	s << pounds << " po."<<endl;

	return s;
}

ostream& BrCash::GetShillings(ostream& s)
{

	s << shillings << " sh."<<endl;

	return s;
}

ostream& BrCash::GetPences(ostream&s)
{
	
	s<< pences << " pe." << endl;

	return s;
}
void BrCash::CheckPeAndSh(int &po, int &sh, float &pe)
{
	if (abs(po) > 1000000000)
		throw runtime_error("wrong anount of money(bigger than max)");
	while (pe <=-12)
	{
		sh--;
		pe += 12;

	}
	while (sh <= -20)
	{

		po--;
		sh += 20;
	}
	while (pe >= 12)
	{
		sh++;
		pe -= 12;

	}
	while (sh >= 20)
	{
		po++;
		sh -= 20;
	}
	
}
BrCash BrCash::operator-() const
{
	return BrCash(-pounds,-shillings,-pences);
}
BrCash &BrCash::operator+=(int a)
{
	pounds += a;
	pences += a;
	shillings += a;
	CheckPeAndSh(pounds,shillings,pences);
	return *this;
}
BrCash &BrCash::operator-=(int a)
{
	pounds -= a;
	pences -= a;
	shillings -= a;
	CheckPeAndSh(pounds, shillings, pences);
	
	return *this;
}
BrCash BrCash::operator+(const BrCash& p) const
{
	int po = pounds + p.pounds;
	int sh = shillings + p.shillings;
	float pe = pences + p.pences;
	
	CheckPeAndSh(po, sh, pe);
	BrCash result(po, sh, pe);
	return result ;
}
BrCash BrCash::operator-(const BrCash& p) const
{
	
	BrCash result(pounds - p.pounds, shillings - p.shillings, pences - p.pences);
	
	return result;
}
bool BrCash::operator==(const BrCash& p) const
{
	return (pounds == p.pounds && shillings == p.shillings && pences == p.pences);
}
bool BrCash::operator!=(const BrCash& p) const
{
	return !(this->operator==(p));
}
bool BrCash::operator>(const BrCash& p ) const
{
	if (pounds > p.pounds)
		return true;
	else if (pounds < p.pounds)
		return false;
	else
	{
		if (shillings > p.shillings)
			return true;
		else if (shillings < p.shillings)
			return false;
		else
		{
			if (pences > p.pences)
				return true;
			else 
				return false;
		
		
		}
	
	
	}
	
}
bool BrCash::operator<(const BrCash& p) const
{
	return !(this->operator > (p)||this->operator==(p));
}
bool BrCash::operator>=(const BrCash& p) const
{
	return (this->operator>(p)||this->operator==(p));
}
bool BrCash::operator<=(const BrCash& p) const
{
	return !(this->operator>(p));
}
ostream& operator<< (ostream& s, const BrCash& p)
{

	s << p.pounds << "pd." << "; " << p.shillings << "sh." << "; " << p.pences << "p." << endl;
	return s;
}




