#include "Operator.h"

using namespace net::draconia::classbuilder::model;

Operator::Operator(const QString &sName, const QList<Argument> &lstArguments, const QString &sReturnType, const bool bConstant, const bool bReturnConstant, const bool bStatic, const bool bVirtual, const bool bPure, const QString &sAccess)
    :   Function(sName, lstArguments, sReturnType, bConstant, bReturnConstant, bStatic, bVirtual, bPure, sAccess)
{ }

Operator::Operator(const QString &sAccess)
    :   Function(sAccess)
{ }

Operator::Operator(const Operator &refCopy)
    :   Function(refCopy)
{ }

Operator::Operator(Operator &&refMove)
    :   Function(refMove)
{ }

const QString &Operator::getAccess() const
{
    return(Function::getAccess());
}

const QList<Argument> &Operator::getArguments() const
{
    return(Function::getArguments());
}

const QString &Operator::getName() const
{
    return(Function::getName());
}

const QString &Operator::getReturnType() const
{
    return(Function::getReturnType());
}

bool Operator::isConstant() const
{
    return(Function::isConstant());
}

bool Operator::isPure() const
{
    return(Function::isPure());
}

bool Operator::isReturnConstant() const
{
    return(Function::isReturnConstant());
}

bool Operator::isStatic() const
{
    return(Function::isStatic());
}

bool Operator::isVirtual() const
{
    return(Function::isVirtual());
}

void Operator::setAccess(const QString &sAccess)
{
    Function::setAccess(sAccess);
}

void Operator::setPure(const bool bPure)
{
    Function::setPure(bPure);
}

void Operator::setStatic(const bool bStatic)
{
    Function::setStatic(bStatic);
}

void Operator::setVirtual(const bool bVirtual)
{
    Function::setVirtual(bVirtual);
}

Operator &Operator::operator=(const Operator &refCopy)
{
    Function::operator=(refCopy);

    return(*this);
}

Operator &Operator::operator=(Operator &&refMove)
{
    Function::operator=(refMove);

    return(*this);
}

bool Operator::operator==(const Operator &refOther) const
{
    return(Function::operator==(refOther));
}

bool Operator::operator!=(const Operator &refOther) const
{
    return(!operator==(refOther));
}

Operator::operator const QString() const
{
    return(toString());
}
