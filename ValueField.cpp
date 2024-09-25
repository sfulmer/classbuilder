#include "ValueField.h"

using namespace net::draconia::classbuilder::model;

ValueField::ValueField(Object *ptrObject, Field *ptrField, const int iPointerLevel, const int iReferenceLevel)
    :   Value()
    ,   mPtrField(ptrField)
    ,   miPointerLevel(iPointerLevel)
    ,   miReferenceLevel(iReferenceLevel)
    ,   mPtrObject(ptrObject)
{ }

ValueField::ValueField(const ValueField &refCopy)
    :   ValueField(refCopy.getObject(), refCopy.getField(), refCopy.getPointerLevel(), refCopy.getReferenceLevel())
{ }

ValueField::ValueField(ValueField &&refMove)
    :   ValueField(refMove.getObject(), refMove.getField(), refMove.getPointerLevel(), refMove.getReferenceLevel())
{ }

ValueField::~ValueField()
{ }

Field *ValueField::getField() const
{
    return(mPtrField);
}

Object *ValueField::getObject() const
{
    return(mPtrObject);
}

int ValueField::getPointerLevel() const
{
    return(miPointerLevel);
}

int ValueField::getReferenceLevel() const
{
    return(miReferenceLevel);
}

void ValueField::setField(Field *ptrField)
{
    mPtrField = ptrField;

    setChanged(true);
    notifyObservers("Field");
}

void ValueField::setObject(Object *ptrObject)
{
    mPtrObject = ptrObject;

    setChanged(true);
    notifyObservers("Object");
}

void ValueField::setPointerLevel(const int iPointerLevel)
{
    miPointerLevel = iPointerLevel;

    setChanged(true);
    notifyObservers("PointerLevel");
}

void ValueField::setReferenceLevel(const int iReferenceLevel)
{
    miReferenceLevel = iReferenceLevel;

    setChanged(true);
    notifyObservers("RefereneLevel");
}

const QString ValueField::toString() const
{
    QString str = "";

    for(unsigned uiLength = getPointerLevel(), uiLoop = 0;uiLoop < uiLength; uiLoop++)
        str += "*";
    for(unsigned uiLength = getReferenceLevel(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        str += "&";

    if(getField()->isStatic())
        str += getField()->getClass()->getName() + QString("::") + getField()->getName();
    else
        str += getObject()->getName() + "." + getField()->getName();

    return(str);
}

ValueField &ValueField::operator=(const ValueField &refCopy)
{
    setField(refCopy.getField());
    setObject(refCopy.getObject());
    setPointerLevel(refCopy.getPointerLevel());
    setReferenceLevel(refCopy.getReferenceLevel());

    return(*this);
}

ValueField &ValueField::operator=(ValueField &&refMove)
{
    setField(refMove.getField());
    setObject(refMove.getObject());
    setPointerLevel(refMove.getPointerLevel());
    setReferenceLevel(refMove.getReferenceLevel());

    return(*this);
}

bool ValueField::operator==(const ValueField &refOther) const
{
    return  (   (getField()== refOther.getField())
            &&  (getObject() == refOther.getObject())
            &&  (getPointerLevel() == refOther.getPointerLevel())
            &&  (getReferenceLevel() == refOther.getReferenceLevel()));
}

bool ValueField::operator!=(const ValueField &refOther) const
{
    return(!operator==(refOther));
}
