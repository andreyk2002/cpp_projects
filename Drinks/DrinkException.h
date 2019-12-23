#pragma once
#include<exception>

class DrinkException : public std::exception
{
public:
	DrinkException(const char* const message)
		: exception(message) {}
	DrinkException(const DrinkException& right)

		: exception(right) {}

};