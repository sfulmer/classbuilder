#pragma once

#include "Class.h"
#include "Operator.h"

namespace net::draconia::classbuilder::model
{
    class OperatorAssignment : public Operator
    {
        Class *mPtrClass;
    protected:
        void setClass(Class *ptrClass);
    public:
        OperatorAssignment(Class *ptrClass, const bool bStatic = false, const bool bVirtual = false, const bool bPure = false, const QString &sAccess = "Public");
        OperatorAssignment(const OperatorAssignment &refCopy);
        OperatorAssignment(OperatorAssignment &&refMove);
        virtual ~OperatorAssignment();

        const QString &getAccess() const;
        const QList<Argument> &getArguments() const;
        Class *getClass() const;
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

        OperatorAssignment &operator=(const OperatorAssignment &refCopy);
        OperatorAssignment &operator=(OperatorAssignment &&refMove);
        bool operator==(const OperatorAssignment &refOther) const;
        bool operator!=(const OperatorAssignment &refOther) const;
        operator const QString() const;
    };
}
