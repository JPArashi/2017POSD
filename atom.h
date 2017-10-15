#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Atom : public Term{
public:
  Atom (string s):_symbol(s) {}

  string symbol() const
  {
    return _symbol;
  }

  string _symbol;

  bool match(Term & term) 
  {
    return value() == term.value();
  }

  bool match(Variable & var) 
  {
    return var.match(*this);
  }
};


#endif
