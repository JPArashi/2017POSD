#ifndef TERM_H
#define TERM_H

#include <string>

using std::string;
class Struct;
class Variable;
class List;
class Iterator;

class Term
{
public:
  virtual string symbol() const = 0;

  virtual string value() const { return symbol(); }

  virtual bool match(Term &term) = 0;

  virtual Struct *getStruct() { return NULL; }
  virtual Variable *getVariable() { return NULL; }
  virtual List *getList() { return NULL; }
  virtual Iterator *createIterator();
};

#endif
