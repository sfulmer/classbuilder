#include "ValueLiteral.h"

using namespace net::draconia::classbuilder::model;

ValueLiteral::ValueLiteral(const QString &sValue)
    :   Value()
    ,   msValue(sValue)
{ }

ValueLiteral::ValueLiteral(const ValueLiteral &refCopy)
    :   ValueLiteral(refCopy.getValue())
{ }

ValueLiteral::ValueLiteral(ValueLiteral &&refMove)
    :   ValueLiteral(refMove.getValue())
{ }

ValueLiteral::~ValueLiteral()
{ }

const QString &ValueLiteral::getValue() const
{
    return(msValue);
}

void ValueLiteral::setValue(const QString &sValue)
{
    msValue = sValue;

    setChanged(true);
    notifyObservers("Value");
}

const QString ValueLiteral::toString() const
{
    return(getValue());
}

ValueLiteral &ValueLiteral::operator=(const ValueLiteral &refCopy)
{
    Value::operator=(refCopy);
    setValue(refCopy.getValue());

    return(*this);
}

ValueLiteral &ValueLiteral::operator=(ValueLiteral &&refMove)
{
    Value::operator=(refMove);
    setValue(refMove.getValue());

    return(*this);
}

bool ValueLiteral::operator==(const ValueLiteral &refOther) const
{
    return(Value::operator==(refOther) & (getValue() == refOther.getValue()));
}

bool ValueLiteral::operator!=(const ValueLiteral &refOther) const
{
    return(!operator==(refOther));
}
