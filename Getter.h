#pragma once

#include "Function.h"

namespace net::draconia::classbuilder::model
{
    class Getter : protected Function
    {
        QString msField;
    public:
        Getter(const QString &sAccess = "Public");
        Getter(const QString &sField, const QString &sReturnType = "void", const bool bConstant = true, const bool bReturnConstant = false, const bool bStatic = false, const bool bVirtual = false, const bool bPure = false, const QString &sAccess = "Public");
        Getter(const Getter &refCopy);
        Getter(Getter &&refMove);
        ~Getter();

        const QString &getAccess() const;
        const QString &getField() const;
        const QString &getReturnType() const;
        bool isConstant() const;
        bool isPure() const;
        bool isReturnConstant() const;
        bool isStatic() const;
        bool isVirtual() const;
        void setAccess(const QString &sAccess);
        void setConstant(const bool bConstant);
        void setField(const QString &sField);
        void setPure(const bool bPure);
        void setReturnConstant(const bool bReturnConstant);
        void setReturnType(const QString &sReturnType);
        void setStatic(const bool bStatic);
        void setVirtual(const bool bVirtual);

        Getter &operator=(const Getter &refCopy);
        Getter &operator=(Getter &&refMove);
        bool operator==(const Getter &refOther);
        bool operator!=(const Getter &refOther);
        operator const QString() const;
    };
}
