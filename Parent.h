#pragma once

#include "Class.h"
#include "Observable.h"

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Parent : public Observable
    {
        Class *mPtrParentClass;
        QString msAccess;
    protected:
        virtual QString toString() const;
    public:
        Parent(Class *ptrParentClass, const QString &sAccess = "Public");
        Parent(const Parent &refCopy);
        Parent(Parent &&refMove);
        ~Parent();

        const QString &getAccess() const;
        Class *getParentClass() const;
        void setAccess(const QString &sAccess);
        void setParentClass(Class *ptrParentClass);

        Parent &operator=(const Parent &refCopy);
        Parent &operator=(Parent &&refCopy);
        bool operator==(const Parent &refOther) const;
        bool operator!=(const Parent &refOther) const;
        operator const QString() const;
    };
}
