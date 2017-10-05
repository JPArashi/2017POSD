#ifndef NUMBER_H
#define NUMBER_H

#include <string>
class Atom;
class Variable;
using std::string;

class Number{
public:
	Number(int i)
	{
		_symbol = std::to_string(i);
		_value = std::to_string(i);
	}
	string value(){ return _value; }
	string symbol(){ return _symbol; }
	bool match( Number n );
    bool match( Atom a );
    bool match( Variable &v );
private:
	string _symbol;
	string _value;
};

#endif
