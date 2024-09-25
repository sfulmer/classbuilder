#pragma once

#include "AccessControl.h"
#include "Argument.h"
#include "Function.h"
#include "Observable.h"

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Constructor : protected Function
    {
    public:
        Constructor(Class *ptrClass, const QList<Argument> lstArguments = QList<Argument>(), const QString &sAccess = "Public");
        Constructor(Class *ptrClass, const QList<Argument> &lstArguments, const QString &sBody = "", const QString &sAccess = "Public");
        Constructor(const Constructor &refCopy);
        Constructor(Constructor &&refMove);
        ~Constructor();

        void addArgument(const Argument &refArgument);
        void addArguments(const QList<Argument> &lstArguments);
        void clearArguments();
        const QString &getAccess() const;
        const QList<Argument> &getArguments() const;
        const QString &getBody() const;
        Class *getClass() const;
        void removeArgument(const Argument &refArgument);
        void removeArguments(const QList<Argument> lstArguments);
        void setAccess(const QString &sAccess);
        void setBody(const QString &sBody);
        void setClass(Class *ptrClass);

        virtual const QString toCPPString() const;
        virtual const QString toHString() const;

        Constructor &operator=(const Constructor &refCopy);
        Constructor &operator=(Constructor &&refMove);
        bool operator==(const Constructor &refOther) const;
        bool operator!=(const Constructor &refOther) const;
    };
}
