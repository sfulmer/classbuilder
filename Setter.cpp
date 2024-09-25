#include "Setter.h"

using namespace net::draconia::classbuilder::model;

Setter::Setter(const QString &sAccess)
    :Function(sAccess)
{ }

Setter::Setter(const QString &sField, const QString &sDataType, const QString &sDefault, const bool bConstantArg, const bool bStatic, const bool bVirtual, const bool bPure, const QString &sAccess)
    :   Function(QString("set") + sField[0].toUpper() + QStringRef(&sField, 1, sField.length() - 1).toString(), QList<Argument>(), "void", false, false, bStatic, bVirtual, bPure, sAccess)
    ,   mbConstantArg(bConstantArg)
    ,   msDataType(sDataType)
    ,   msDefault(sDefault)
{
    if(sDataType.trimmed().toLower() == "void")
        BadArgumentTypeException().raise();
    else
        {
        QString sName = "m";
        QStringList lstDataTypes;

        if(isStatic())
            sName += "s";

        lstDataTypes = getDataType().split(" ");

        for(const QString &sDataTypePart : lstDataTypes)
            if(sDataTypePart.toLower() == "unsigned")
                sName += "u";
            else if(sDataTypePart.toLower() == "long")
                sName += "l";
            else if(sDataTypePart.toLower() == "int")
                sName += "i";
            else  if(sDataTypePart.toLower() == "short")
                sName += "sh";
            else if(sDataTypePart.toLower() == "char")
                sName += "ch";
            else if(sDataTypePart.toLower().contains("string"))
                sName += "s";
            else
                sName += "obj";

        Argument arg(sName, mbConstantArg, sDataType, sDefault);

        addArgument(arg);
        }
}

Setter::Setter(const Setter &refCopy)
    :   Setter(refCopy.getField(), refCopy.getDataType(), refCopy.getDefault(), refCopy.isConstantArgument(), refCopy.isStatic(), refCopy.isVirtual(), refCopy.isPure(), refCopy.getAccess())
{ }

Setter::Setter(Setter &&refMove)
    :   Setter(refMove.getField(), refMove.getDataType(), refMove.getDefault(), refMove.isConstantArgument(), refMove.isStatic(), refMove.isVirtual(), refMove.isPure(), refMove.getAccess())
{ }

Setter::~Setter()
{ }

const QString &Setter::getAccess() const
{
    return(Function::getAccess());
}

const QString &Setter::getDataType() const
{
    return(msDataType);
}

const QString &Setter::getField() const
{
    return(msField);
}

bool Setter::isConstantArgument() const
{
    return(mbConstantArg);
}

bool Setter::isPure() const
{
    return(Function::isPure());
}

bool Setter::isStatic() const
{
    return(Function::isStatic());
}

bool Setter::isVirtual() const
{
    return(Function::isVirtual());
}

void Setter::setAccess(const QString &sAccess)
{
    Function::setAccess(sAccess);
}

void Setter::setConstant(const bool bConstant)
{
    Function::setConstant(bConstant);
}


void Setter::setConstantArg(const bool bConstantArg)
{
    mbConstantArg = bConstantArg;

    setChanged(true);
    notifyObservers("ConstantArg");
}

void Setter::setDataType(const QString &sDataType)
{
    msDataType = sDataType;

    setChanged(true);
    notifyObservers("DataType");
}

void Setter::setDefault(const QString &sDefault)
{
    msDefault = sDefault;

    setChanged(true);
    notifyObservers("Default");
}

void Setter::setField(const QString &sField)
{
    msField = sField;

    setChanged(true);
    notifyObservers("Field");
}

void Setter::setPure(const bool bPure)
{
    Function::setPure(bPure);
}

void Setter::setStatic(const bool bStatic)
{
    Function::setStatic(bStatic);
}

void Setter::setVirtual(const bool bVirtual)
{
    Function::setVirtual(bVirtual);
}

Setter &Setter::operator=(const Setter &refCopy)
{
    Function::operator=(refCopy);
    setConstantArg(refCopy.isConstantArgument());
    setDataType(refCopy.getDataType());
    setDefault(refCopy.getDefault());
    setField(refCopy.getField());

    return(*this);
}

Setter &Setter::operator=(Setter &&refMove)
{
    Function::operator=(refMove);
    setConstantArg(refMove.isConstantArgument());
    setDataType(refMove.getDataType());
    setDefault(refMove.getDefault());
    setField(refMove.getField());

    return(*this);
}

bool Setter::operator==(const Setter &refOther)
{
    return  (   Function::operator==(refOther)
            &&  (isConstantArgument() == refOther.isConstantArgument())
            &&  (getDataType() == refOther.getDataType())
            &&  (getDefault() == refOther.getDefault())
            &&  (getField() == refOther.getField()));
}

bool Setter::operator!=(const Setter &refOther)
{
    return(!operator==(refOther));
}

Setter::operator const QString() const
{
    return(toString());
}
