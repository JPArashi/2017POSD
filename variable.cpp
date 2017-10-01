#include "atom.h"
#include "variable.h"
#include "number.h"

#include <iostream>

bool Variable::match( Atom atom ){
    bool ret = _assignable || (_type == "string" && _svalue == atom._symbol);
    if(_assignable){
        _type = "string";
        _svalue = atom._symbol;
        _assignable = false;
    }
    return ret;
}

bool Variable::match( Number n ){
    bool ret = _assignable || (_type == "int" && _ivalue == n.value());
    if(_assignable){
        _type = "int";
        _ivalue = n.value() ;
        _assignable = false;
    }
    return ret;
}
