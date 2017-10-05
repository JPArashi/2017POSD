#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
class Atom;
class Number;
using std::string;

class Variable{
public:
  Variable(string s):_symbol(s), _value(s){}
  string const _symbol;
  string value(){
    return _value;
  }
  bool match( Atom atom );
  bool match( Number n );

private:
  bool _assignable = true;
  string _value;  
};

#endif
