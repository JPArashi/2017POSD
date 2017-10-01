#include "atom.h"
#include "variable.h"
#include "number.h"

bool Number::match( Number n ){
    return value() == n.value();
}
bool Number::match( Atom a ){
    return false;
}
bool Number::match( Variable &v ){
    return v.match(*this);
}