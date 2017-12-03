#include "term.h"
#include "iterator.h"

Iterator * Term::createIterator(){
  return new NullIterator(this);
}