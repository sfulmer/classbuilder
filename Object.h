#pragma once

#include "Class.h"
#include "Observable.h"

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Object : public Observable
    {
        Class *mPtrDataType;
        int miPointerLevel, miReferenceLevel;
        QString msName;
    public:
        Object(const QString &sName, Class *ptrDataType, const int iPointerLevel = 0, const int iReferenceLevel = 0);
        Object(const Object &refCopy);
        Object(Object &&refMove);
        virtual ~Object() = 0;

        virtual const QString getAlteredName() const;
        Class *getDataType() const;
        const QString &getName() const;
        int getPointerLevel() const;
        int getReferenceLevel() const;
        void setDataType(Class *ptrDataType);
        void setName(const QString &sName);
        void setPointerLevel(const int iPOinterLevel);
        void setReferenceLevel(const int iReferenceLevel);

        virtual const QString toString() const = 0;

        Object &operator=(const Object &refCopy);
        Object &operator=(Object &&refMove);
        bool operator==(const Object &refOther) const;
        bool operator!=(const Object &refOther) const;
    };
}
