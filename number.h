#ifndef NUMBER_H
#define NUMBER_H

#include <string>
class Atom;
class Variable;
using std::string;

class Number{
public:
	Number(int i):_symbol(i), _value(i){}
	int value(){ return _value; }
	int symbol(){ return _symbol; }
	bool match( Number n );
    bool match( Atom a );
    bool match( Variable &v );
private:
	int const _symbol;
	int _value;
};

#endif
