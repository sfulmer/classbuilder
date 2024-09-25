#pragma once

#include "Function.h"

namespace net::draconia::classbuilder::model
{
    class Setter : protected Function
    {
        bool mbConstantArg;
        QString msDataType, msDefault, msField;
    public:
        Setter(const QString &sAccess = "Public");
        Setter(const QString &sField, const QString &sDatType = "void", const QString &sDefault = "", const bool bConstantArg = true, const bool bStatic = false, const bool bVirtual = false, const bool bPure = false, const QString &sAccess = "Public");
        Setter(const Setter &refCopy);
        Setter(Setter &&refMove);
        ~Setter();

        const QString &getAccess() const;
        const QString &getDataType() const;
        const QString &getDefault() const;
        const QString &getField() const;
        bool isConstantArgument() const;
        bool isPure() const;
        bool isStatic() const;
        bool isVirtual() const;
        void setAccess(const QString &sAccess);
        void setConstant(const bool bConstantArg);
        void setConstantArg(const bool bConstant);
        void setDataType(const QString &sDataType);
        void setDefault(const QString &sDefault);
        void setField(const QString &sField);
        void setPure(const bool bPure);
        void setStatic(const bool bStatic);
        void setVirtual(const bool bVirtual);

        Setter &operator=(const Setter &refCopy);
        Setter &operator=(Setter &&refMove);
        bool operator==(const Setter &refOther);
        bool operator!=(const Setter &refOther);
        operator const QString() const;
    };
}
