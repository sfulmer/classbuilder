#pragma once

#include "Argument.h"
#include "Class.h"
#include <Observable.h>
#include <QList>
#include <QString>

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Function : public Observable
    {
        bool mbConstant, mbPure, mbReturnConstant, mbStatic, mbVirtual;
        Class *mPtrClass;
        QList<Argument> mLstArguments;
        QString msAccess, msBody, msName, msReturnType;
    protected:
        QList<Argument> &getArgumentsInternal() const;
        void setClass(Class *ptrlass);
    public:
        Function(const QString &sAccess = "Public");
        Function(Class *ptrClass, const QString &sName, const QList<Argument> &lstArguments, const QString &sReturnType = "void", const bool bConstant = false, const bool bReturnConstant = false, const bool bStatic = false, const bool bVirtual = false, const bool bPure = false, const QString &sBody = "", const QString &sAccess = "Public");
        Function(const Function &refCopy);
        Function(Function &&refMove);
        ~Function();

        void addArgument(const QString &sName, const bool bConstant = false, const QString &sDataType = "void", const int iPointerLevel = 0, const int iReferenceLevel = false, const QString &sDefault = "", const int iDefaultAddressOfLevel = 0, const int iDefaultDereferenceLevel = 0, const bool bDefaultLiteral = false);
        void addArgument(const Argument objArgument);
        void addArguments(const QList<Argument> &lstArguments);
        void clearArguments();
        const QString &getAccess() const;
        const QList<Argument> &getArguments() const;
        const QString &getBody() const;
        Class *getClass() const;
        const QString &getName() const;
        const QString &getReturnType() const;
        bool isConstant() const;
        bool isPure() const;
        bool isReturnConstant() const;
        bool isStatic() const;
        bool isVirtual() const;
        void removeArgument(const Argument &refArgument);
        void removeArguments(const QList<Argument> lstArguments);
        void setAccess(const QString &sAccess);
        void setBody(const QString &sBody);
        void setConstant(const bool bConstant);
        void setName(const QString &sName);
        void setPure(const bool bPure);
        void setReturnConstant(const bool bReturnConstant);
        void setReturnType(const QString &sReturnType);
        void setStatic(const bool bStatic);
        void setVirtual(const bool bVirtual);

        virtual const QString toCPPString() const;
        virtual const QString toHString() const;

        Function &operator=(const Function &refCopy);
        Function &operator=(Function &&refMove);
        bool operator==(const Function &refOther) const;
        bool operator!=(const Function &refOther) const;
        operator const QString() const;
    };
}
