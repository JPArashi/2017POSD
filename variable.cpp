#include "atom.h"
#include "variable.h"
#include "number.h"

#include <iostream>

bool Variable::match( Atom atom ){
    bool ret = _assignable || _value == atom.value();
    if(_assignable){
        _value = atom.value();
        _assignable = false;
    }
    return ret;
}

bool Variable::match( Number n ){
    bool ret = _assignable || _value == n.value();
    if(_assignable){
        _value = n.value() ;
        _assignable = false;
    }
    return ret;
}
