#ifndef ATOM_H
#define ATOM_H

#include <string>
// #include "number.h"
// #include "variable.h"
class Number;
class Variable;

using std::string;

class Atom {
public:
  Atom (string s):_symbol(s) {}
  bool operator ==(Atom a);
  string _symbol;
  bool match( Number n );
  bool match( Atom a );
  bool match( Variable &v );
};

#endif
