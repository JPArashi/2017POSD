#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include <string>
using std::string;

class Number : public Term{
public:
	Number (double d):_symbol(std::to_string(d)) {}
	string symbol() const
	{ 
		return _symbol; 
	}
private:
	string _symbol;
};

#endif
