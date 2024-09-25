#include "ValueField.h"
#include "ValueFunction.h"
#include "ValueLiteral.h"
#include "Variable.h"

using namespace net::draconia::classbuilder::model;

Variable::Variable(const QString &sName, Class *ptrDataType, const int iPointerLevel, const int iReferenceLevel, const bool bConstant, Value *ptrValue)
    :   Object(sName, ptrDataType, iPointerLevel, iReferenceLevel)
    ,   mbConstant(bConstant)
    ,   mPtrValue(ptrValue)
{ }

Variable::Variable(const Variable &refCopy)
    :   Object(refCopy)
    ,   mbConstant(refCopy.isConstant())
    ,   mPtrValue(refCopy.getValue())
{ }

Variable::Variable(Variable &&refMove)
    :   Object(refMove)
    ,   mbConstant(refMove.isConstant())
    ,   mPtrValue(refMove.getValue())
{ }

Variable::~Variable()
{ }

Value *Variable::getValue() const
{
    return(const_cast<Value *>(mPtrValue));
}

bool Variable::isConstant() const
{
    return(mbConstant);
}

void Variable::setConstant(const bool bConstant)
{
    mbConstant = bConstant;

    setChanged(true);
    notifyObservers("Constant");
}

void Variable::setValue(Object *ptrObject, Field *ptrField, const int iPointerLevel, const int iReferenceLevel)
{
    mPtrValue = new ValueField(ptrObject, ptrField, iPointerLevel, iReferenceLevel);

    setChanged(true);
    notifyObservers("Value");
}

void Variable::setValue(Object *ptrObject, Function *ptrFunction, const int iPointerLevel, const int iReferenceLevel, const QList<Value *> &lstArguments)
{
    mPtrValue = new ValueFunction(ptrObject, ptrFunction, iPointerLevel, iReferenceLevel, lstArguments);

    setChanged(true);
    notifyObservers("Value");
}

void Variable::setValue(const QString &sValue)
{
    mPtrValue = new ValueLiteral(sValue);

    setChanged(true);
    notifyObservers("Value");
}

void Variable::setValue(Value *ptrValue)
{
    mPtrValue = ptrValue;

    setChanged(true);
    notifyObservers("Value");
}

const QString Variable::toString() const
{
    return(getAlteredName() + QString(" = ") + getValue()->toString());
}

Variable &Variable::operator=(const Variable &refCopy)
{
    Object::operator=(refCopy);
    setConstant(refCopy.isConstant());
    setValue(refCopy.getValue());

    return(*this);
}

Variable &Variable::operator=(Variable &&refMove)
{
    Object::operator=(refMove);
    setConstant(refMove.isConstant());
    setValue(refMove.getValue());

    return(*this);
}

bool Variable::operator==(const Variable &refOther) const
{
    return  (   Object::operator==(refOther)
            &&  (isConstant() == refOther.isConstant())
            &&  (getValue() == refOther.getValue()));
}

bool Variable::operator!=(const Variable &refOther) const
{
    return(!operator==(refOther));
}
