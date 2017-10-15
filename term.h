#ifndef TERM_H
#define TERM_H

#include <string>

using std::string;


class Term{
public:
  virtual string symbol() const= 0;

  virtual string avalue() const{
    return symbol();
  };

  virtual bool match(Term & term) {
    return avalue() == term.avalue();
  }
};

#endif
