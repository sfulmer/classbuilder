#pragma once

#include "AccessControl.h"
#include "Class.h"
#include <Observable.h>
#include <QString>

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Field : public Observable
    {
        bool mbConstant, mbDefaultLiteral, mbStatic;
        Class *mPtrClass;
        int miDefaultAddressOfLevel, miDefaultDereferenceLevel, miPointerLevel, miReferenceLevel;
        QString msAccess, msDataTpe, msDefaultValue, msName;
    protected:
        void setClass(Class *ptrClass);
    public:
        Field(const QString sAccess = "Private");
        Field(Class *ptrClass, const QString &sName, const QString &sDataType, const int iPointerLevel = 0, const int iReferenceLevel = 0, const QString &sDefaultValue = "", const bool bDefaultLiteral = false, const int iDefaultAddressOfLevel = 0, const int iDefaultDereferenceLevel = 0, const bool bConstant = false, const bool bStatic = false, const QString &sAccess = "Private");
        Field(const Field &refCopy);
        Field(Field &&refMove);
        ~Field();

        const QString &getAccess() const;
        int getAddresssOfLevel() const;
        Class *getClass() const;
        const QString &getDataType() const;
        int getDefaultAddressOfLevel() const;
        int getDefaultDereferenceLevel() const;
        const QString &getDefaultValue() const;
        const QString &getName() const;
        int getPointerLevel() const;
        int getReferenceLevel() const;
        bool isConstant() const;
        bool isDefaultLiteral() const;
        bool isStatic() const;
        void setAccess(const QString &sAccess);
        void setConstant(const bool bConstant);
        void setDataType(const QString &sDataType);
        void setDefaultAddressOfLevel(const int iDefaultAddressOfLevel);
        void setDefaultDereferenceLevel(const int iDefaultDereferenceLevel);
        void setDefaultLiteral(const bool bDefaultLiteral);
        void setDefaultValue(const QString &sDefaultValue);
        void setName(const QString &sName);
        void setPointerLevel(const int iPointerLevel);
        void setReferenceLevel(const int iReferenceLevel);
        void setStatic(const bool bStatic);

        virtual const QString toCPPString() const;
        virtual const QString toHString() const;

        Field &operator=(const Field &refCopy);
        Field &operator=(Field &&refMove);
        bool operator==(const Field &refOther) const;
        bool operator!=(const Field &refOther) const;
    };

    class BadTypeException : public QException
    {
     public:
        virtual BadTypeException *clone() const;
        virtual void raise() const;
    };
}
