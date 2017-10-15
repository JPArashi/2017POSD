#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Variable : public Term{
public:
  Variable(string s):_symbol(s){}
  string symbol() const
	{ 
		return _symbol; 
	}
  string value() const 
  {
    if(_vectorPointer == -1)
      return symbol();
    else
      return _value[_vectorPointer]->value(); 
  }
  bool match( Term & term ){
    Variable * pv = dynamic_cast<Variable *>(&term);
    if (pv){
      if(_vectorPointer!=-1 && pv->_vectorPointer!=-1){
        return false;
      }else if(_vectorPointer!=-1){
        pv->_vectorPointer = _vectorPointer;
        return true;
      }else if(pv->_vectorPointer!=-1){
        _vectorPointer = pv->_vectorPointer;
        return true;
      }else{
        _value.push_back(NULL);
        pv->_vectorPointer = _vectorPointer = _value.size()-1;
        return true;
      }
    }else if(_vectorPointer == -1){
      _value.push_back(&term);
      _vectorPointer = _value.size()-1;
      return true;
    }else if(_value[_vectorPointer] == NULL){
      _value[_vectorPointer] = &term;
    }
    return false;
  }

private:
  string _symbol;
  bool _assignable = true;
  static vector<Term *> _value;
  int _vectorPointer = -1;
};

vector<Term *> Variable::_value;

#endif
