#include "Argument.h"

using namespace net::draconia::classbuilder::model;

Argument::Argument(const QString sAccess)
    :   Field(sAccess)
{ }

Argument::Argument(const QString &sName, const QString &sDataType, const int iPointerLevel, const int iReferenceLevel, const bool bConstant, const QString &sDefaultValue, const bool bDefaultLiteral, const int iDefaultAddressOfLevel, const int iDefaultDereferenceLevel)
    :   Field(nullptr, sName, sDataType, iPointerLevel, iReferenceLevel, sDefaultValue, bDefaultLiteral, iDefaultAddressOfLevel, iDefaultDereferenceLevel, bConstant)
{ }

Argument::Argument(const Argument &refCopy)
    :   Argument(refCopy.getName(), refCopy.getDataType(), refCopy.getPointerLevel(), refCopy.getReferenceLevel(), refCopy.isConstant(), refCopy.getDefaultValue(), refCopy.isDefaultLiteral(), refCopy.getDefaultAddressOfLevel(), refCopy.getDefaultAddressOfLevel())
{ }

Argument::Argument(Argument &&refMove)
    :   Argument(refMove.getName(), refMove.getDataType(), refMove.getPointerLevel(), refMove.getReferenceLevel(), refMove.isConstant(), refMove.getDefaultValue(), refMove.isDefaultLiteral(), refMove.getDefaultAddressOfLevel(), refMove.getDefaultAddressOfLevel())
{ }

Argument::~Argument()
{ }

const QString Argument::getAlteredName() const
{
    const QString sDataType = getDataType().toLower().trimmed();
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
        }
    else if (sDataType == "float")
        sName += "f";
    else if(sDataType == "double")
        sName += "d";
    else if(sDataType == "long double")
        sName += "ld";
    else if(sDataType == "bool")
        sName += "b";
    else
        sName += "obj";

    sName += getName()[0].toUpper() + QStringRef(&getName(), 1, getName().length() - 1).toString();

    return(sName);
}

const QString &Argument::getDataType() const
{
    return(Field::getDataType());
}

int Argument::getDefaultAddressOfLevel() const
{
    return(Field::getDefaultAddressOfLevel());
}

int Argument::getDefaultDereferenceLevel() const
{
    return(Field::getDefaultDereferenceLevel());
}

const QString &Argument::Argument::getDefaultValue() const
{
    return(Field::getDefaultValue());
}

const QString  &Argument::getName() const
{
    return(Field::getName());
}

int Argument::getPointerLevel() const
{
    return(Field::getPointerLevel());
}

int Argument::getReferenceLevel() const
{
    return(Field::getReferenceLevel());
}

bool Argument::isConstant() const
{
    return(Field::isConstant());
}

void Argument::setConstant(const bool bConstant)
{
    Field::setConstant(bConstant);
}

void Argument::setDataType(const QString &sDataType)
{
    Field::setDataType(sDataType);
}

void Argument::setDefaultAddressOfLevel(const int iDefaultAddressOfLevel)
{
    Field::setDefaultAddressOfLevel(iDefaultAddressOfLevel);
}

void Argument::setDefaultDereferenceLevel(const int iDefaultDereferenceLevel)
{
    Field::setDefaultDereferenceLevel(iDefaultDereferenceLevel);
}

void Argument::setDefaultValue(const QString &sDefaultValue)
{
    Field::setDefaultValue(sDefaultValue);
}

void Argument::setName(const QString &sName)
{
    Field::setName(sName);
}

void Argument::setPointerLevel(const int iPointerLevel)
{
    Field::setPointerLevel(iPointerLevel);
}

void Argument::setReferenceLevel(const int iReferenceLevel)
{
    Field::setReferenceLevel(iReferenceLevel);
}

const QString Argument::toCPPString() const
{

}

const QString Argument::toHString() const
{

}

Argument &Argument::operator=(const Argument &refCopy)
{
    Field::operator=(refCopy);

    return(*this);
}

Argument &Argument::operator=(Argument &&refMove)
{
    Field::operator=(refMove);

    return(*this);
}

bool Argument::operator==(const Argument &refOther) const
{
    return(Field::operator==(refOther));
}

bool Argument::operator!=(const Argument &refOther) const
{
    return(!operator==(refOther));
}
