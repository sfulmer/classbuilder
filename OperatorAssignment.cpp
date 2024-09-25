#include "OperatorAssignment.h"


using namespace net::draconia::classbuilder::model;

void OperatorAssignment::setClass(Class *ptrClass)
{
    mPtrClass = ptrClass;

    setChanged(true);
    notifyObservers("Class");
}

const QString OperatorAssignment::toString() const
{
    OperatorAssignment  copy(getClass(), isStatic(), isVirtual(), isPure(), getAccess())
            ,           move(getClass(), isStatic(), isVirtual(), isPure(), getAccess());
    QList<OperatorAssignment> lstOperatorAssignments;
    QString  str = "";

    copy.addArgument("refCopy", true, getClass()->getName(), 0, 1);
    move.addArgument("refMove", false, getClass()->getName(), 0, 2);

    for(const OperatorAssignment &arg : {copy, move})
        lstOperatorAssignments.append(arg);

    for(unsigned uiLength = lstOperatorAssignments.length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        {
        str += lstOperatorAssignments[uiLoop];

        if(uiLoop < (uiLength - 1))
            str += QString("\n");
        }

    return(str);
}

OperatorAssignment::OperatorAssignment(Class *ptrClass, const bool bStatic, const bool bVirtual, const bool bPure, const QString &sAccess)
    :   Operator("operator=", QList<Argument>(), ptrClass->getName(), false, false, bStatic, bVirtual, bPure, sAccess);
    ,   mPtrClass(ptrClass)
{ }

OperatorAssignment::OperatorAssignment(const OperatorAssignment &refCopy)
    :   Operator(refCopy)
    ,   mPtrClass(refCopy.getClass())
{ }

OperatorAssignment::OperatorAssignment(OperatorAssignment &&refMove)
    :   Operator(refMove)
    ,   mPtrClass(refMove.getClass())
{ }

OperatorAssignment::~OperatorAssignment()
{ }

const QString &OperatorAssignment::getAccess() const
{
    return(Operator::getAccess());
}

const QList<Argument> &OperatorAssignment::getArguments() const
{
    return(Operator::getArguments());
}

Class *OperatorAssignment::getClass() const
{
    return(mPtrClass);
}

const QString &OperatorAssignment::getName() const
{
    return(Operator::getName());
}

const QString &OperatorAssignment::getReturnType() const
{
    return(Operator::getReturnType());
}

bool OperatorAssignment::isConstant() const
{
    return(Operator::isConstant());
}

bool OperatorAssignment::isPure() const
{
    return(Operator::isPure());
}

bool OperatorAssignment::isReturnConstant() const
{
    return(Operator::isReturnConstant()_;)
}

bool OperatorAssignment::isStatic() const
{
    return(Operator::isStatic());
}

bool OperatorAssignment::isVirtual() const
{
    return(Operator::isVirtual());
}

void OperatorAssignment::setAccess(const QString &sAccess)
{
    Operator::setAccess(sAccess);
}

void OperatorAssignment::setPure(const bool bPure)
{
    Operator::setPure(bPure);
}

void OperatorAssignment::setStatic(const bool bStatic)
{
    Operator::setStatic(bStatic);
}

void OperatorAssignment::setVirtual(const bool bVirtual)
{
    Operator::setVirtual(bVirtual);
}

OperatorAssignment &OperatorAssignment::operator=(const OperatorAssignment &refCopy)
{
    Operator::operator=(refCopy);
    setClass(refCopy.getClass());

    return(*this);
}

OperatorAssignment &OperatorAssignment::operator=(OperatorAssignment &&refMove)
{
    Operator::operator=(refMove);
    setClass(refMove.getClass());

    return(*this);
}

bool OperatorAssignment::operator==(const OperatorAssignment &refOther) const
{
    return  (   Operator::operator==(refOther)
            &&  (getClass() == refOther.getClass()));
}

bool OperatorAssignment::operator!=(const OperatorAssignment &refOther) const
{
    return(!operator==(refOther));
}

OperatorAssignment::operator const QString() const
{
    return(toString());
}
