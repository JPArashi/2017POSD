#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Variable : public Term{
public:
  Variable(string s):_symbol(s){}

  string symbol() const
  { 
		return _symbol; 
  }
  
  string value() const 
  {
    if(_value)
      return _value->value();
    else
      return symbol(); 
  }

  bool match( Term & term )
  {
    if(&term == this)
    {
      return true;
    }
    if(!_value)
    {
      _value = &term;
      return true;
    }
    else
    {
      return _value->match(term);
    }
  }

private:
  string _symbol;
  bool _assignable = true;
  Term * _value = NULL;
  int _vectorPointer = -1;
};

#endif
