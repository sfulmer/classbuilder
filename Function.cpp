#include "Function.h"

using namespace net::draconia::classbuilder::model;

QList<Argument> &Function::getArgumentsInternal() const
{
    return(const_cast<QList<Argument> &>(mLstArguments));
}

void Function::setClass(Class *ptrClass)
{
    mPtrClass = ptrClass;

    setChanged(true);
    notifyObservers("Class");
}

Function::Function(const QString &sAccess)
    :   Observable()
    ,   msAccess(sAccess)
{ }

Function::Function(Class *ptrClass, const QString &sName, const QList<Argument> &lstArguments, const QString &sReturnType, const bool bConstant, const bool bReturnConstant, const bool bStatic, const bool bVirtual, const bool bPure, const QString &sAccess)
    :   Observable()
    ,   mbConstant(bConstant)
    ,   mbPure(bPure)
    ,   mbReturnConstant(bReturnConstant)
    ,   mbStatic(bStatic)
    ,   mbVirtual(bVirtual)
    ,   mPtrClass(ptrClass)
    ,   msAccess(sAccess)
    ,   msName(sName)
    ,   msReturnType(sReturnType)
{
    addArguments(lstArguments);
}

Function::Function(const Function &refCopy)
    :   Function(refCopy.getClass(), refCopy.getName(), refCopy.getArguments(), refCopy.getReturnType(), refCopy.isConstant(), refCopy.isReturnConstant(), refCopy.isStatic(), refCopy.isVirtual(), refCopy.isPure(), refCopy.getAccess())
{ }

Function::Function(Function &&refMove)
    :   Function(refMove.getClass(), refMove.getName(), refMove.getArguments(), refMove.getReturnType(), refMove.isConstant(), refMove.isReturnConstant(), refMove.isStatic(), refMove.isVirtual(), refMove.isPure(), refMove.getAccess())
{ }

Function::~Function()
{ }

void Function::addArgument(const QString &sName, const bool bConstant, const QString &sDataType, const int iPointerLevel, const int iReferenceLevel, const QString &sDefault, const int iDefaultAddressOfLevel, const int iDefaultDereferenceLevel, const bool bDefaultLiteral)
{
    getArgumentsInternal().append(Argument(sName, bConstant, sDataType, iPointerLevel, iReferenceLevel, sDefault, iDefaultAddressOfLevel, iDefaultDereferenceLevel, bDefaultLiteral));

    setChanged(true);
    notifyObservers("Arguments");
}

void Function::addArgument(const Argument objArgument)
{
    getArgumentsInternal().append(objArgument);

    setChanged(true);
    notifyObservers("Arguments");
}

void Function::addArguments(const QList<Argument> &lstArguments)
{
    for(const Argument &arg :lstArguments)
        getArgumentsInternal().append(arg);

    setChanged(true);
    notifyObservers("Arguments");
}

void Function::clearArguments()
{
    getArgumentsInternal().clear();

    setChanged(true);
    notifyObservers("Arguments");
}

const QString &Function::getAccess() const
{
    return(msAccess);
}

const QList<Argument> &Function::getArguments() const
{
    return(getArgumentsInternal());
}

const QString &Function::getBody() const
{
    return(msBody);
}

Class *Function::getClass() const
{
    return(mPtrClass);
}

const QString &Function::getName() const
{
    return(msName);
}

const QString &Function::getReturnType() const
{
    return(msReturnType);
}

bool Function::isConstant() const
{
    return(mbConstant);
}

bool Function::isPure() const
{
    return(mbPure);
}

bool Function::isReturnConstant() const
{
    return(mbReturnConstant);
}

bool Function::isStatic() const
{
    return(mbStatic);
}

bool Function::isVirtual() const
{
    return(mbVirtual);
}

void Function::removeArgument(const Argument &refArgument)
{
    getArgumentsInternal().removeOne(refArgument);

    setChanged(true);
    notifyObservers("Arguments");
}

void Function::removeArguments(const QList<Argument> lstArguments)
{
    for(const Argument &arg : lstArguments)
        getArgumentsInternal().append(arg);

    setChanged(true);
    notifyObservers("Arguments");
}

void Function::setAccess(const QString &sAccess)
{
    msAccess = sAccess;

    setChanged(true);
    notifyObservers("Access");
}

void Function::setBody(const QString &sBody)
{
    msBody = sBody;

    setChanged(true);
    notifyObservers("Body");
}

void Function::setConstant(const bool bConstant)
{
    mbConstant = bConstant;

    setChanged(true);
    notifyObservers("Constant");
}

void Function::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers("Name");
}

void Function::setPure(const bool bPure)
{
    mbPure = bPure;

    setChanged(true);
    notifyObservers("Pure");
}

void Function::setReturnConstant(const bool bReturnConstant)
{
    mbReturnConstant = bReturnConstant;

    setChanged(true);
    notifyObservers("ReturnConstant");
}

void Function::setReturnType(const QString &sReturnType)
{
    msReturnType = sReturnType;

   setChanged(true);
   notifyObservers("ReturnType");
}

void Function::setStatic(const bool bStatic)
{
    mbStatic = bStatic;

    setChanged(true);
    notifyObservers("Static");
}

void Function::setVirtual(const bool bVirtual)
{
    mbVirtual = bVirtual;

    setChanged(true);
    notifyObservers("Virtual");
}

const QString Function::toCPPString() const
{
    QString str = "";

    if(!isPure())
        {
        if(isReturnConstant())
            str += "const" + QString(" ") + getReturnType();

        str += QString(" ") + getClass()->getName() + "::" + getName() + "(";

        for(unsigned uiLength = getArguments().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
            {
            str += getArguments()[uiLoop].toCPPString();

            if(uiLoop < (uiLength - 1))
                str += ", ";
            }

        str += ")";

        if(!getBody().isEmpty())
            str += "\n{\n" + getBody() + "\n}";
        else
            str += "\n{ }";
        }

    return(str);
}

const QString Function::toHString() const
{
    QString str;

    if(isVirtual())
        str += "virtual";
    else if(isStatic())
        str += "static";
    str += " ";

    if(isReturnConstant())
        str += "const" + QString(" ") + getReturnType();
    str += QString(" ") + getClass()->getName() + "(";

    for(unsigned uiLength = getArguments().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
        {
        str += getArguments()[uiLoop].toCPPString();

        if(uiLoop < (uiLength - 1))
            str += ", ";
        }

    str += ")";

    if(isPure())
        str += " = 0";

    str += ";";

    return(str);
}

Function &Function::operator=(const Function &refCopy)
{
    setAccess(refCopy.getAccess());
    setConstant(refCopy.isConstant());
    setName(refCopy.getName());
    setPure(refCopy.isPure());
    setReturnConstant(refCopy.isReturnConstant());
    setReturnType(refCopy.getReturnType());
    setStatic(refCopy.isStatic());
    setVirtual(refCopy.isVirtual());

    return(*this);
}

Function &Function::operator=(Function &&refMove)
{
    setAccess(refMove.getAccess());
    setConstant(refMove.isConstant());
    setName(refMove.getName());
    setPure(refMove.isPure());
    setReturnConstant(refMove.isReturnConstant());
    setReturnType(refMove.getReturnType());
    setStatic(refMove.isStatic());
    setVirtual(refMove.isVirtual());

    return(*this);
}

bool Function::operator==(const Function &refOther) const
{
    return  (   (getAccess() == refOther.getAccess())
            &&  (isConstant() == refOther.isConstant())
            &&  (getName() == refOther.getName())
            &&  (isPure() == refOther.isPure())
            &&  (isReturnConstant() == refOther.isReturnConstant())
            &&  (getReturnType() == refOther.getReturnType())
            &&  (isStatic() == refOther.isStatic())
            &&  (isVirtual() == refOther.isVirtual()));
}

bool Function::operator!=(const Function &refOther) const
{
    return(!operator==(refOther));
}

Function::operator const QString() const
{
    return(toString());
}
