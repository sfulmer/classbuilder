#pragma once


#include "Object.h"
#include "Value.h"

namespace net::draconia::classbuilder::model
{
    class Variable : public Object
    {
        bool mbConstant;
        Value *mPtrValue;
    public:
        Variable(const QString &sName, Class *ptrDataType, const int iPointerLevel = 0, const int iReferenceLevel = 0, const bool bConstant = false, Value *ptrValue = nullptr);
        Variable(const Variable &refCopy);
        Variable(Variable &&refMove);
        virtual ~Variable();

        Value *getValue() const;
        bool isConstant() const;
        void setConstant(const bool bConstant);
        void setValue(Object *ptrObject, Field *ptrField, const int iPointerLevel = 0, const int iReferenceLevel = 0);
        void setValue(Object *ptrObject, Function *ptrFunction, const int iPointerLevel = 0, const int iReferenceLevel = 0, const QList<Value *> &lstArguments = QList<Value *>());
        void setValue(const QString &sValue);
        void setValue(Value *ptrValue);

        virtual const QString toString() const;

        Variable &operator=(const Variable &refCopy);
        Variable &operator=(Variable &&refMove);
        bool operator==(const Variable &refOther) const;
        bool operator!=(const Variable &refOther) const;
    };
}
