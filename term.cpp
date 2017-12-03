#include "term.h"
#include "iterator.h"

Atom &Term::name()
{
    return *new Atom("");
}

Iterator<Term *> *Term::createIterator()
{
    return new NullIterator<Term *>(this);
}

Iterator<Term *> *Term::createDFSIterator()
{
    return new NullIterator<Term *>(this);
}

Iterator<Term *> *Term::createBFSIterator()
{
    return new NullIterator<Term *>(this);
}