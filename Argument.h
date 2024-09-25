#pragma once

#include "Field.h"
#include <QException>
#include "Variable.h"

namespace net::draconia::classbuilder::model
{
    class Argument : protected Variable
    {
    public:
        Argument(const QString sAccess = "Private");
        Argument(const QString &sName, const QString &sDataType, const int iPointerLevel = 0, const int iReferenceLevel = 0, const bool bConstant = false, const QString &sDefaultValue = "", const bool bDefaultLiteral = true, const int iDefaultAddressOfLevel = 0, const int iDefaultDereferenceLevel = 0);
        Argument(const Argument &refCopy);
        Argument(Argument &&refMove);
        ~Argument();

        const QString &getDataType() const;
        int getDefaultAddressOfLevel() const;
        int getDefaultDereferenceLevel() const;
        const QString &getDefaultValue() const;
        const QString &getName() const;
        int getPointerLevel() const;
        int getReferenceLevel() const;
        bool isConstant() const;
        bool isDefaultLiteral() const;
        void setConstant(const bool bConstant);
        void setDataType(const QString &sDataType);
        void setDefaultAddressOfLevel(const int iDefaultAddressOfLevel);
        void setDefaultLiteral(const bool bDefaultLiteral);
        void setDefaultDereferenceLevel(const int iDefaultDereferenceLevel);
        void setDefaultValue(const QString &sDefaultValue);
        void setName(const QString &sName);
        void setPointerLevel(const int iPointerLevel);
        void setReferenceLevel(const int iReferenceLevel);

        virtual const QString toCPPString() const;
        virtual const QString toHString() const;

        Argument &operator=(const Argument &refCopy);
        Argument &operator=(Argument &&refMove);
        bool operator==(const Argument &refOther) const;
        bool operator!=(const Argument &refOther) const;
    };
}
