#include "Constructor.h"

using namespace net::draconia::classbuilder::model;

Constructor::Constructor(Class *ptrClass, const QList<Argument> lstArguments, const QString &sAccess)
    :   Function(ptrClass, "", lstArguments, "", false, false, false, false, false, "", sAccess)
{ }

Constructor::Constructor(Class *ptrClass, const QList<Argument> &lstArguments, const QString &sBody, const QString &sAccess)
:   Function(ptrClass, "", lstArguments, "", false, false, false, false, false, sBody, sAccess)
{ }

Constructor::Constructor(const Constructor &refCopy)
    :   Function(refCopy)
{ }

Constructor::Constructor(Constructor &&refMove)
    :   Function(refMove)
{ }

Constructor::~Constructor()
{ }

void Constructor::addArgument(const Argument &refArgument)
{
    Function::addArgument(refArgument);
}

void Constructor::addArguments(const QList<Argument> &lstArguments)
{
    Function::addArguments(lstArguments);
}

void Constructor::clearArguments()
{
    Function::clearArguments();
}

const QString &Constructor::getAccess() const
{
    return(Function::getAccess());
}

const QList<Argument> &Constructor::getArguments() const
{
    return(Function::getArguments());
}

const QString &Constructor::getBody() const
{
    return(Function::getBody());
}

Class *Constructor::getClass() const
{
    return(Function::getClass());
}

void Constructor::removeArgument(const Argument &refArgument)
{
    Function::removeArgument(refArgument);
}

void Constructor::removeArguments(const QList<Argument> lstArguments)
{
    Function::removeArguments(lstArguments);
}

void Constructor::setAccess(const QString &sAccess)
{
    Function::setAccess(sAccess);
}

void Constructor::setBody(const QString &sBody)
{
    Function::setBody(sBody);
}

void Constructor::setClass(Class *ptrClass)
{
    Function::setClass(ptrClass);
}

const QString Constructor::toCPPString() const
{
    QString str;

    str = getClass()->getName() + "::" + getClass()->getName();
    str += "(";

    for(unsigned uiLength = getArguments().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        {
        str += getArguments()[uiLoop].toCPPString();

        if(uiLoop < (uiLength - 1))
            str += ", ";
        }

    str += ")";

    if  (   (!getClass()->getParents().empty())
        &&  (!getClass()->getFields().empty()))
        {
        str += "\t:\t";

        for(unsigned uiLength = getClass()->getParents().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
            {
             str += getClass()->getParents()[uiLoop].getn

            }
        }

    return(str);
}

const QString Constructor::toHString() const
{
    QString str;

    str = getClass()->getName() + "(";

    for(unsigned uiLength = getArguments().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        {
        str += getArguments()[uiLoop].toHString();

        if(uiLoop < (uiLength - 1))
            str += ", ";
        }

    str += ");";

    return(str);
}

Constructor &Constructor::operator=(const Constructor &refCopy)
{
    Function::operator=(refCopy);

    return(*this);
}

Constructor &Constructor::operator=(Constructor &&refMove)
{
    Function::operator=(refMove);

    return(*this);
}

bool Constructor::operator==(const Constructor &refOther) const
{
    return(Function::operator==(refOther));
}

bool Constructor::operator!=(const Constructor &refOther) const
{
    return(!operator==(refOther));
}
