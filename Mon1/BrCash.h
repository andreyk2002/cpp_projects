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
		string GetPounds()const;
		string GetShillings()const;
		string GetPences()const;
		

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

