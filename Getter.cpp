#include "Getter.h"

using namespace net::draconia::classbuilder::model;

Getter::Getter(const QString &sAccess)
    :   Function(sAccess)
{ }

Getter::Getter(const QString &sField, const QString &sReturnType, const bool bConstant, const bool bReturnConstant, const bool bStatic, const bool bVirtual, const bool bPure, const QString &sAccess)
    :   Function(QString("get") + sField[0].toUpper() + QStringRef(&sField, 0, sField.length() - 1), QList<Argument>(), sReturnType, bConstant, bReturnConstant, bStatic, bVirtual, bPure, sAccess)
{ }

Getter::Getter(const Getter &refCopy)
    :   Getter(refCopy.getField(), refCopy.getReturnType(), refCopy.isConstant(), refCopy.isReturnConstant(), refCopy.isStatic(), refCopy.isVirtual(), refCopy.isPure(), refCopy.getAccess())
{ }

Getter::Getter(Getter &&refMove)
    :   Getter(refMove.getField(), refMove.getReturnType(), refMove.isConstant(), refMove.isReturnConstant(), refMove.isStatic(), refMove.isVirtual(), refMove.isPure(), refMove.getAccess())
{ }

Getter::~Getter()
{ }

const QString &Getter::getAccess() const
{
    return(Function::getAccess());
}

const QString &Getter::getField() const
{
    return(msField);
}

const QString &Getter::getReturnType() const
{
    return(Function::getReturnType());
}

bool Getter::isConstant() const
{
    return(Function::isConstant());
}

bool Getter::isPure() const
{
    return(Function::isPure());
}

bool Getter::isReturnConstant() const
{
    return(Function::isReturnConstant());
}

bool Getter::isStatic() const
{
    return(Function::isStatic());
}

bool Getter::isVirtual() const
{
    return(Function::isVirtual());
}

void Getter::setAccess(const QString &sAccess)
{
    Function::setAccess(sAccess);
}

void Getter::setConstant(const bool bConstant)
{
    Function::setConstant(bConstant);
}

void Getter::setField(const QString &sField)
{
    msField = sField;

    setChanged(true);
    notifyObservers("Field");
}

void Getter::setPure(const bool bPure)
{
    Function::setPure(bPure);
}

void Getter::setReturnConstant(const bool bReturnConstant)
{
    Function::setReturnConstant(bReturnConstant);
}

void Getter::setReturnType(const QString &sReturnType)
{
    Function::setReturnType(sReturnType);
}

void Getter::setStatic(const bool bStatic)
{
    Function::setStatic(bStatic);
}

void Getter::setVirtual(const bool bVirtual)
{
    Function::setVirtual(bVirtual);
}

Getter &Getter::operator=(const Getter &refCopy)
{
    Function::operator=(refCopy);
    setField(refCopy.getField());

    return(*this);
}

Getter &Getter::operator=(Getter &&refMove)
{
    Function::operator=(refMove);
    setField(refMove.getField());

    return(*this);
}

bool Getter::operator==(const Getter &refOther)
{
    return(Function::operator==(refOther) && (getField() == refOther.getField()));
}

bool Getter::operator!=(const Getter &refOther)
{
    return(!operator==(refOther));
}

Getter::operator const QString() const
{
    return(toString());
}
