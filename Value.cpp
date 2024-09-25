#include "Value.h"

using namespace net::draconia::classbuilder::model;

Value::Value(const Value &refCopy)
    :   Observable(refCopy)
{ }

Value::Value(Value &&refMove)
    :   Observable(refMove)
{ }

Value::~Value()
{ }

Value &Value::operator=(const Value &refCopy)
{
    Observable::operator=(refCopy);

    return(*this);
}

Value &Value::operator=(Value &&refMove)
{
    Observable::operator=(refMove);

    return(*this);
}

bool Value::operator==(const Value &refOther) const
{
    return(Observable::operator==(refOther));
}

bool Value::operator!=(const Value &refOther) const
{
    return(!operator==(refOther));
}
