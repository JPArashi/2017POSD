#ifndef NODE_H
#define NODE_H
#include "term.h"

class iterator;

enum Operators
{
    SEMICOLON,
    COMMA,
    EQUALITY,
    TERM
};

class Node
{
  public:
    Node(Operators op) : payload(op), term(0), left(0), right(0) {}
    Node(Operators op, Term *t, Node *l, Node *r) : payload(op), term(t), left(l), right(r) {}

    bool evaluate()
    {
        if (payload == SEMICOLON)
        {
            bool lResult = left->evaluate();
            bool rResult = right->evaluate();
            return lResult || rResult;
        }
        else if (payload == COMMA)
        {
            return left->evaluate() && right->evaluate();
        }
        else if (payload == EQUALITY)
        {
            return left->term->match(*(right->term));
        }
        else if (!payload)
        {
            return false;
        }
    }

    Iterator *createDFSIterator();
    Iterator *createBFSIterator();

    Operators payload;
    Term *term;
    Node *left;
    Node *right;
};

#endif