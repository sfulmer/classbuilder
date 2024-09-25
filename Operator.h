#pragma once

#include "Function.h"

namespace net::draconia::classbuilder::model
{
    class Operator : protected Function
    {
    protected:
        virtual const QString toString() const = 0;

        Operator(const QString &sName, const QList<Argument> &lstArguments, const QString &sReturnType = "void", const bool bConstant = false, const bool bReturnConstant = false, const bool bStatic = false, const bool bVirtual = false, const bool bPure = false, const QString &sAccess = "Public");
    public:
        Operator(const QString &sAccess = "Public");
        Operator(const Operator &refCopy);
        Operator(Operator &&refMove);
        virtual ~Operator() = 0;

        const QString &getAccess() const;
        const QList<Argument> &getArguments() const;
        const QString &getName() const;
        const QString &getReturnType() const;
        bool isConstant() const;
        bool isPure() const;
        bool isReturnConstant() const;
        bool isStatic() const;
        bool isVirtual() const;
        void setAccess(const QString &sAccess);
        void setPure(const bool bPure);
        void setStatic(const bool bStatic);
        void setVirtual(const bool bVirtual);

        Operator &operator=(const Operator &refCopy);
        Operator &operator=(Operator &&refMove);
        bool operator==(const Operator &refOther) const;
        bool operator!=(const Operator &refOther) const;
        operator const QString() const;
    };
    };
}
