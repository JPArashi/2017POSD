#ifndef NODE_H
#define NODE_H
#include "term.h"
#include "vector"
using std::vector;

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
    
    string getResult(){
        string result;
        if (payload == SEMICOLON)
        {
            string leftResult = left->getResult();
            string rightResult = right->getResult();
            if(leftResult == "false." &&
               rightResult == "false."){
                return string("false.");
            }
            else{
                if(leftResult != "true." &&
                   leftResult != "false."){
                    result = leftResult;
                }
                if(rightResult != "true." &&
                   rightResult != "false." &&
                   rightResult != ""){
                    if(result != "")
                        result = result.substr(0, result.size()-1) + "; ";
                    result += rightResult;
                }
                if(leftResult == "true." &&
                   rightResult == "true.")
                    result == "true.";
                return result;
            }
            
        }
        else if (payload == COMMA){
            string leftResult = left->getResult();
            string rightResult = right->getResult();
            if(leftResult == "false." ||
               rightResult == "false."){
                return string("false.");
            }
            else if(leftResult == "true." &&
                    rightResult == "true."){
                    return string("true.");
            }
            else{
                if(leftResult != "true."){
                    result = leftResult;
                }
                if(rightResult != "true." &&
                   rightResult != ""){
                    if(result != "")
                        result = result.substr(0, result.size()-1) + ", ";
                    result += rightResult;
                }
                return result;
            }
        }
        else if (payload == EQUALITY)
        {
            if(evaluate() == false){
                return string("false.");
            }
            else{
                if(left->term->symbol() == right->term->symbol()){
                    return string("true.");
                }
                if(left->term->getVariable() && !checkVariableInTable(left->term)){
                    variableTable.push_back(left->term);
                    result = left->term->symbol() + " = " + left->term->value() + ".";
                }
                if(right->term->getVariable() && !checkVariableInTable(right->term)){
                    variableTable.push_back(right->term);
                    result += right->term->symbol() + " = " + right->term->value() + ".";
                }
                return result;
            }
        }
    }

    bool checkVariableInTable(Term *term){
        for (int i = 0; i < (int) variableTable.size(); i++){
            if(variableTable[i] == term)
                return true;
        }
        return false;
    }

    string operatorsEnumToString(Operators op){
        if(op == SEMICOLON){
            return ";";
        }else if(op == COMMA){
            return ",";
        }else if(op == EQUALITY){
            return "=";
        }
    }

    Operators payload;
    Term *term;
    Node *left;
    Node *right;
    
    static vector<Term *> variableTable;
};
#endif