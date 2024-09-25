#include "Parent.h"

using namespace net::draconia::classbuilder::model;

QString Parent::toString() const
{
    return(getAccess().toLower() + QString(" ") + getParentClass()->getName());
}

Parent::Parent(Class *ptrParentClass, const QString &sAccess)
    :   Observable()
    ,   mPtrParentClass(ptrParentClass)
    ,   msAccess(sAccess)
{ }

Parent::Parent(const Parent &refCopy)
    :   Parent(refCopy.getParentClass(), refCopy.getAccess())
{ }

Parent::Parent(Parent &&refMove)
    :   Parent(refMove.getParentClass(), refMove.getAccess())
{ }

Parent::~Parent()
{ }

const QString &Parent::getAccess() const
{
    return(msAccess);
}

Class *Parent::getParentClass() const
{
    return(mPtrParentClass);
}

void Parent::setAccess(const QString &sAccess)
{
    msAccess = sAccess;

    setChanged(true);
    notifyObservers("Access");
}

void Parent::setParentClass(Class *ptrParentClass)
{
    mPtrParentClass = ptrParentClass;

    setChanged(true);
    notifyObservers("ParentClass");
}

Parent &Parent::operator=(const Parent &refCopy)
{
    setParentClass(refCopy.getParentClass());
    setAccess(refCopy.getAccess());

    return(*this);
}

Parent &Parent::operator=(Parent &&refMove)
{
    setParentClass(refMove.getParentClass());
    setAccess(refMove.getAccess());

    return(*this);
}

bool Parent::operator==(const Parent &refOther) const
{
    if(getParentClass() == nullptr)
        if(refOther.getParentClass() == nullptr)
            return(getAccess() == refOther.getAccess());
        else if((getParentClass() == nullptr) && (refOther.getParentClass() != nullptr))
            return(false);
        else
            {
            Class &cls1 = *(getParentClass());
            Class &cls2 = *(refOther.getParentClass());

            return((cls1 == cls2) && (getAccess() == refOther.getAccess()));
            }
}

bool Parent::operator!=(const Parent &refOther) const
{
    return(!operator==(refOther));
}

Parent::operator const QString() const
{
    return(toString());w
}
