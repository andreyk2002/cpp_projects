#pragma once
#include<iostream>
#include<cmath>
#include<exception>
//#define DEBUG

using namespace std;

class BrCash
{
		
	private:
		int pounds;
		int shillings;
		float pences;
		static void CheckPeAndSh(int& po, int& sh, float& pe);

	public:
		BrCash();
		BrCash(int pounds, int shillings, float pences);
		virtual ~BrCash();

		void SetPounds(int p);
		void SetShillings(int s);
		void SetPences(float pe);
		ostream& GetPounds(ostream&);
		ostream& GetShillings(ostream&);
		ostream& GetPences(ostream&);
		

		BrCash operator - () const;
		BrCash& operator += (int a);
		BrCash& operator -= (int a);
		BrCash operator +(const BrCash&)const;
		BrCash operator -(const BrCash&)const;
		bool operator ==(const BrCash&)const;
		bool operator !=(const BrCash&)const;
		bool operator >(const BrCash&)const;
		bool operator <(const BrCash&)const; 
		bool operator >=(const BrCash&)const;
		bool operator <=(const BrCash&)const;


		friend ostream& operator<< (ostream&, const BrCash&);
	
};

class my_exception_constr : public exception {
public:
	my_exception_constr(const char* const message)
		: exception(message) {}
	my_exception_constr(const my_exception_constr& right)

		: exception(right) {}

};



#ifdef DEBUG



	template<typename T>

	class Sp
	{
	public:
		Sp(T* ptr);

		~Sp();

		T& operator*();
	
	private:
		T *ptr;

	};

	template<typename T>
	inline Sp<T>::Sp(T* ptr)
	{
		this->ptr = ptr;
	#ifdef DEBUG
		cout << "constructor" << endl;
	#endif // DEBUG

	
	}

	template<typename T>
	inline Sp<T>::~Sp()
	{
		delete ptr;
	#ifdef DEBUG
		cout << "destructor" << endl;
	#endif // DEBUG

	
	}

	template<typename T>
	inline T& Sp<T>::operator*()
	{
		return *ptr;
	}
#endif // DEBUG

