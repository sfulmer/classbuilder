#include "Field.h"

using namespace net::draconia::classbuilder::model;

void Field::setClass(Class *ptrClass)
{
    mPtrClass = ptrClass;

    setChanged(true);
    notifyObservers("Class");
}

Field::Field(const QString sAccess)
    :   Observable()
    ,   mPtrClass(nullptr)
    ,   msAccess(sAccess)
{ }

Field::Field(Class *ptrClass, const QString &sName, const QString &sDataType, const int iPointerLevel, const int iReferenceLevel, const QString &sDefaultValue, const bool bDefaultLiteral, const int iDefaultAddressOfLevel, const int iDefaultDereferenceLevel, const bool bConstant, const bool bStatic, const QString &sAccess)
    :   Observable()
    ,   mbConstant(bConstant)
    ,   mbDefaultLiteral(bDefaultLiteral)
    ,   mbStatic(bStatic)
    ,   mPtrClass(ptrClass)
    ,   miDefaultAddressOfLevel(iDefaultAddressOfLevel)
    ,   miDefaultDereferenceLevel(iDefaultDereferenceLevel)
    ,   miPointerLevel(iPointerLevel)
    ,   miReferenceLevel(iReferenceLevel)
    ,   msAccess(sAccess)
    ,   msDataTpe(sDataType)
    ,   msDefaultValue(sDefaultValue)
    ,   msName(sName)
{ }

Field::Field(const Field &refCopy)
    :   Field(refCopy.getClass(), refCopy.getName(), refCopy.getDataType(), refCopy.getPointerLevel(), refCopy.getReferenceLevel(), refCopy.getDefaultValue(), refCopy.isDefaultLiteral(), refCopy.getDefaultAddressOfLevel(), refCopy.getDefaultDereferenceLevel(), refCopy.isConstant(), refCopy.isStatic(), refCopy.getAccess())
{ }

Field::Field(Field &&refMove)
    :   Field(refMove.getClass(), refMove.getName(), refMove.getDataType(), refMove.getPointerLevel(), refMove.getReferenceLevel(), refMove.getDefaultValue(), refMove.isDefaultLiteral(), refMove.getDefaultAddressOfLevel(), refMove.getDefaultDereferenceLevel(), refMove.isConstant(), refMove.isStatic(), refMove.getAccess())
{ }

Field::~Field()
{ }

const QString &Field::getAccess() const
{
    return(msAccess);
}

Class *Field::getClass() const
{
    return(mPtrClass);
}

const QString &Field::getDataType() const
{
    return(msDataTpe);
}

int Field::getDefaultAddressOfLevel() const
{
    return(miDefaultAddressOfLevel);
}

int Field::getDefaultDereferenceLevel() const
{
    return(miDefaultDereferenceLevel);
}

const QString &Field::getDefaultValue() const
{
    return(msDefaultValue);
}

const QString &Field::getName() const
{
    return(msName);
}

int Field::getPointerLevel() const
{
    return(miPointerLevel);
}

int Field::getReferenceLevel() const
{
    return(miReferenceLevel);
}

bool Field::isConstant() const
{
    return(mbConstant);
}

bool Field::isDefaultLiteral() const
{
    return(mbDefaultLiteral);
}

bool Field::isStatic() const
{
    return(mbStatic);
}

void Field::setAccess(const QString &sAccess)
{
    msAccess = sAccess;

    setChanged(true);
    notifyObservers("Access");
}

void Field::setConstant(const bool bConstant)
{
    mbConstant = bConstant;

    setChanged(true);
    notifyObservers("Constant");
}

void Field::setDataType(const QString &sDataType)
{
    msDataTpe = sDataType;

    setChanged(true);
    notifyObservers("DataType");
}

void Field::setDefaultAddressOfLevel(const int iDefaultAddressOfLevel)
{
    miDefaultAddressOfLevel = iDefaultAddressOfLevel;

    setChanged(true);
    notifyObservers("DefaultAddressOfLevel");
}

void Field::setDefaultLiteral(const bool bDefaultLiteral)
{
    mbDefaultLiteral = bDefaultLiteral;

    setChanged(true);
    notifyObservers("DefaultLiteral");
}

void Field::setDefaultValue(const QString &sDefaultValue)
{
    msDefaultValue = sDefaultValue;

    setChanged(true);
    notifyObservers("DefaultValue");
}

void Field::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers("Name");
}

void Field::setStatic(const bool bStatic)
{
    mbStatic = bStatic;

    setChanged(true);
    notifyObservers("Static");
}

const QString Field::toCPPString() const
{
    QString str;

    if(isStatic())
        {
        str = QString(isConstant() ? "const" : "") + QString(" ") + getDataType() + QString(" ");

        for(unsigned uiLength = getPointerLevel(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
            str += "*";
        for(unsigned uiLength = getReferenceLevel(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
            str += "&";

        if(isStatic())
            {
            str += getClass()->getName() + "::" + getName();


            if(!getDefaultValue().isEmpty())
                {
                str += QString(" = ");

                if(!isDefaultLiteral())
                    {
                    for(unsigned uiLength = getDefaultDereferenceLevel(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
                        str += "*";
                    for(unsigned uiLength = getDefaultAddressOfLevel(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
                        str += "&";

                    str += getDefaultValue();
                    }
                else if(getDataType().toLower().endsWith("string"))
                    str += "\"" + getDefaultValue() + "\"";
                else if(getDataType().toLower().contains("char"))
                    str += "\'" + getDefaultValue() + "\'";
                else
                    str += getDefaultValue();

                str+= ";";
                }
            }
        }

    return(str);
}

const QString Field::toHString() const
{
    QString str;

    str = QString(isConstant() ? "const" : "") + QString(" ") + getDataType() + QString(" ") + getName();

    if(!getDefaultValue().isEmpty())
        str += QString(" = ") + getDefaultValue() + QString(";");

    return(str);
}

Field &Field::operator=(const Field &refCopy)
{
    setAccess(refCopy.getAccess());
    setConstant(refCopy.isConstant());
    setDatType(refCopy.getDataType());
    setDefaultValue(refCopy.getDefaultValue());
    setName(refCopy.getName());
    setStatic(refCopy.isStatic());

    return(*this);
}

Field &Field::operator=(Field &&refMove)
{
    setAccess(refMove.getAccess());
    setConstant(refMove.isConstant());
    setDatType(refMove.getDataType());
    setDefaultValue(refMove.getDefaultValue());
    setName(refMove.getName());
    setStatic(refMove.isStatic());

    return(*this);
}

bool Field::operator==(const Field &refOther) const
{
    return  (   (isConstant() == refOther.isConstant())
            &&  (getDataType() == refOther.getDataType())
            &&  (getDefaultValue() == refOther.getDefaultValue())
            &&  (getName() == refOther.getName())
            &&  (isStatic() == refOther.isStatic()));
}

bool Field::operator!=(const Field &refOther) const
{
    return(!operator==(refOther));
}

BadTypeException *BadTypeException::clone() const
{
    return(new BadTypeException());
}

void BadTypeException::raise() const
{
    throw *this;
}
