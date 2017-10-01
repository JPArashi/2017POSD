#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
class Atom;
class Number;
// #include "atom.h"
// #include "number.h"
using std::string;

class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string svalue(){ 
    return _type == "string"? _svalue: ""; 
  }
  int ivalue(){ 
    return _type == "int"? _ivalue: 0; 
  }
  bool match( Atom atom );
  bool match( Number n );

private:
  bool _assignable = true;
  string _svalue;  
  int _ivalue;
  string _type;
};

#endif
