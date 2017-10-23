#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <vector>
using std::vector;

class List : public Term {
public:
  string symbol() const
  {
    string ret = "[";
    
    return ret + "]";
  }
  string value() const{};
  bool match(Term & term)
  {
    return NULL;
  }

public:
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  Term * head() const
  {
    return NULL;
  }
  List * tail() const
  {
    return NULL;
  }

private:
  vector<Term *> _elements;

};

#endif
