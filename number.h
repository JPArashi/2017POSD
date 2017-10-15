#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include <string>
using std::string;

class Number : public Term{
public:
	Number (double d)
	{
		string temp = std::to_string(d);
		for(int i = temp.size()-1; i>=0; i--){
			if(temp[i]=='0' || temp[i]=='.')
				temp.pop_back();
			else
				break;
		}
		_symbol = temp;
	}
	string symbol() const
	{ 
		return _symbol; 
	}
private:
	string _symbol;
};

#endif
