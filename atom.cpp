#include "atom.h"
#include "variable.h"
#include "number.h"

bool Atom::operator==(Atom a){
    return _symbol == a._symbol;
}
bool Atom::match( Number n ){
    return false;
}
bool Atom::match( Atom a ){
    return _symbol == a._symbol;
}
bool Atom::match( Variable &v ){
    return v.match(*this);
}