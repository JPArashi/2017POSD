#ifndef ATOM_H
#define ATOM_H

#include <string>
class Number;
class Variable;

using std::string;

class Atom {
public:
  Atom (string s):_symbol(s), _value(s) {}
  bool operator ==(Atom a);
  string symbol(){
    return _symbol;
  }
  string value(){
    return _symbol;
  }
  bool match( Number n );
  bool match( Atom a );
  bool match( Variable &v );
private:
  string _symbol;
  string _value;
};

#endif
