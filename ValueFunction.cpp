#include <QtAlgorithms>
#include "ValueFunction.h"

using namespace net::draconia::classbuilder::model;

QList<Value *> ValueFunction::getValuesInternal() const
{
    return(mLstValues);
}

void ValueFunction::setValues(const QList<Value *> lstValues)
{
    mLstValues = lstValues;

    setChanged(true);
    notifyObservers("Values");
}

ValueFunction::ValueFunction(Object *ptrObject, Function *ptrFunction, const int iPointerLevel, const int iReferenceLevel, const QList<Value *> &lstValues)
    :   Value()
    ,   mPtrFunction(ptrFunction)
    ,   miPointerLevel(iPointerLevel)
    ,   miReferenceLevel(iReferenceLevel)
    ,   mPtrObject(ptrObject)
    ,   mLstValues(lstValues)
{ }

ValueFunction::ValueFunction(const ValueFunction &refCopy)
    :   ValueFunction(refCopy.getObject(), refCopy.getFunction(), refCopy.getPointerLevel(), refCopy.getReferenceLevel())
{ }

ValueFunction::ValueFunction(ValueFunction &&refMove)
    :   ValueFunction(refMove.getObject(), refMove.getFunction(), refMove.getPointerLevel(), refMove.getReferenceLevel())
{ }

ValueFunction::~ValueFunction()
{ }

void ValueFunction::addValue(const Value *ptrValue)
{
    getValuesInternal().append(const_cast<Value *>(ptrValue));

    setChanged(true);
    notifyObservers("Values");
}

void ValueFunction::addValues(const QList<Value *> lstValues)
{
    getValuesInternal().append(lstValues);

    setChanged(true);
    notifyObservers("Values");
}

void ValueFunction::clearValues()
{
    qDeleteAll(getValuesInternal());
    getValuesInternal().clear();

    setChanged(true);
    notifyObservers("Values");
}

Function *ValueFunction::getFunction() const
{
    return(mPtrFunction);
}

Object *ValueFunction::getObject() const
{
    return(mPtrObject);
}

int ValueFunction::getPointerLevel() const
{
    return(miPointerLevel);
}

int ValueFunction::getReferenceLevel() const
{
    return(miReferenceLevel);
}

void ValueFunction::removeValue(const Value *ptrValue)
{
    int iIndex = getValuesInternal().indexOf(const_cast<Value *>(ptrValue));

    delete getValuesInternal()[iIndex];
    getValuesInternal().removeOne(ptrValue);

    setChanged(true);
    notifyObservers("Values");
}

void ValueFunction::removeValues(const QList<Value *> lstValues)
{
    for(const Value *ptr : lstValues)
        removeValue(ptr);

    setChanged(true);
    notifyObservers("Values");
}

void ValueFunction::setFunction(Function *ptrFunction)
{
    mPtrFunction = ptrFunction;

    setChanged(true);
    notifyObservers("Function");
}

void ValueFunction::setObject(Object *ptrObject)
{
    mPtrObject = ptrObject;

    setChanged(true);
    notifyObservers("Object");
}

void ValueFunction::setPointerLevel(const int iPointerLevel)
{
    miPointerLevel = iPointerLevel;

    setChanged(true);
    notifyObservers("PointerLevel");
}

void ValueFunction::setReferenceLevel(const int iReferenceLevel)
{
    miReferenceLevel = iReferenceLevel;

    setChanged(true);
    notifyObservers("RefereneLevel");
}

const QString ValueFunction::toString() const
{
    QString str = "";

    for(unsigned uiLength = getPointerLevel(), uiLoop = 0;uiLoop < uiLength; uiLoop++)
        str += "*";
    for(unsigned uiLength = getReferenceLevel(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        str += "&";

    if(getFunction()->isStatic())
        str += getObject()->getClass()->getName() + QString("::") + getFunction()->getName();
    else
        str += getObject()->getName() + QString(".") + getFunction()->getName();

    str += "(";

    for(unsigned uiLength = getValuesInternal().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        {
        str += getValuesInternal()[uiLoop]->toString();

        if(uiLoop < (uiLength - 1))
            str += ", ";
        }

    str += ")";

    return(str);
}

ValueFunction &ValueFunction::operator=(const ValueFunction &refCopy)
{
    Value::operator=(refCopy);

    setFunction(refCopy.getFunction());
    setObject(refCopy.getObject());
    setPointerLevel(refCopy.getPointerLevel());
    setReferenceLevel(refCopy.getReferenceLevel());

    return(*this);
}

ValueFunction &ValueFunction::operator=(ValueFunction &&refMove)
{
    Value::operator=(refMove);

    setFunction(refMove.getFunction());
    setObject(refMove.getObject());
    setPointerLevel(refMove.getPointerLevel());
    setReferenceLevel(refMove.getReferenceLevel());

    return(*this);
}

bool ValueFunction::operator==(const ValueFunction &refOther) const
{
    return  (   Value::operator==(refOther)
            &&  (getFunction()== refOther.getFunction())
            &&  (getObject() == refOther.getObject())
            &&  (getPointerLevel() == refOther.getPointerLevel())
            &&  (getReferenceLevel() == refOther.getReferenceLevel()));
}

bool ValueFunction::operator!=(const ValueFunction &refOther) const
{
    return(!operator==(refOther));
}
