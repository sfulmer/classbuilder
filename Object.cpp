#include "Object.h"

using namespace net::draconia::classbuilder::model;

Object::Object(const QString &sName, Class *ptrDataType, const int iPointerLevel, const int iReferenceLevel)
    :   Observable()
    ,   mPtrDataType(ptrDataType)
    ,   miPointerLevel(iPointerLevel)
    ,   miReferenceLevel(iReferenceLevel)
    ,   msName(sName)
{ }

Object::Object(const Object &refCopy)
    :   Object(refCopy.getName(), refCopy.getDataType(), refCopy.getPointerLevel(), refCopy.getReferenceLevel())
{ }

Object::Object(Object &&refMove)
    :   Object(refMove.getName(), refMove.getDataType(), refMove.getPointerLevel(), refMove.getReferenceLevel())
{ }

const QString Object::getAlteredName() const
{
    const QString sDataType = getDataType()->getName().toLower().trimmed();
    QString sName = "";

    if(sDataType.endsWith("string"))
        sName += "s";
    else if(sDataType.startsWith("unsigned "))
        {
        sName += "u";

        if(sDataType == "int")
            sName += "i";
        else if(sDataType == "long")
            sName += "l";
        else if(sDataType == "long long")
            sName += "ll";
        else if(sDataType == "long double")
            sName += "ld";
        else if(sDataType == "bool")
            sName += "b";
        }
    else if (sDataType == "float")
        sName += "f";
    else if(sDataType == "double")
        sName += "d";
    else if(sDataType == "long double")
        sName += "ld";
    else if(sDataType == "bool")
        sName += "b";
    else if(getPointerLevel() >= 1)
        sName += "ptr";
    else if(getReferenceLevel() >= 0)
        sName += "ref";
    else
        sName += "obj";

    sName += getName()[0].toUpper() + QStringRef(&getName(), 1, getName().length() - 1).toString();

    return(sName);
}

Class *Object::getDataType() const
{
    return(mPtrDataType);
}

const QString &Object::getName() const
{
    return(msName);
}

int Object::getPointerLevel() const
{
    return(miPointerLevel);
}

int Object::getReferenceLevel() const
{
    return(miReferenceLevel);
}

void Object::setDataType(Class *ptrDataType)
{
    mPtrDataType = ptrDataType;

    setChanged(true);
    notifyObservers("DataType");
}

void Object::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers("Name");
}

void Object::setPointerLevel(const int iPointerLevel)
{
    miPointerLevel = iPointerLevel;

    setChanged(true);
    notifyObservers("PointerLevel");
}

void Object::setReferenceLevel(const int iReferenceLevel)
{
    miReferenceLevel = iReferenceLevel;

    setChanged(true);
    notifyObservers("ReferenceLevel");
}

Object &Object::operator=(const Object &refCopy)
{
    setDataType(refCopy.getDataType());
    setName(refCopy.getName());
    setPointerLevel(refCopy.getPointerLevel());
    setReferenceLevel(refCopy.getReferenceLevel());

    return(*this);
}

Object &Object::operator=(Object &&refMove)
{
    setDataType(refMove.getDataType());
    setName(refMove.getName());
    setPointerLevel(refMove.getPointerLevel());
    setReferenceLevel(refMove.getReferenceLevel());

    return(*this);
}

bool Object::operator==(const Object &refOther) const
{
    return  (   (getDataType() == refOther.getDataType())
            &&  (getName() == refOther.getName())
            &&  (getPointerLevel() == refOther.getPointerLevel())
            &&  (getReferenceLevel() == refOther.getReferenceLevel()));
}

bool Object::operator!=(const Object &refOther) const
{
    return(!operator==(refOther));
}
