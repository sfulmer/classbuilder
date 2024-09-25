#pragma once

#include "Function.h"
#include "Object.h"
#include "Value.h"

namespace net::draconia::classbuilder::model
{
    class ValueFunction : public Value
    {
        Function *mPtrFunction;
        int miPointerLevel, miReferenceLevel;
        Object *mPtrObject;
        QList<Value *> mLstValues;
    protected:
        QList<Value *> getValuesInternal() const;
        void setValues(const QList<Value *> lstValues);
    public:
        ValueFunction(Object *ptrObject, Function *ptrFunction, const int iPointerLevel = 0, const int iReferenceLevel = 0, const QList<Value *> &lstValues = QList<Value *>());
        ValueFunction(const ValueFunction &refCopy);
        ValueFunction(ValueFunction &&refMove);
        virtual ~ValueFunction();

        void addValue(const Value *ptrValue);
        void addValues(const QList<Value *> lstValues);
        void clearValues();
        Function *getFunction() const;
        Object *getObject() const;
        int getPointerLevel() const;
        int getReferenceLevel() const;
        const QList<Value *> getValues() const;
        void removeValue(const Value *ptrValue);
        void removeValues(const QList<Value *> lstValues);
        void setFunction(Function *Function);
        void setObject(Object *ptrObject);
        void setPointerLevel(const int iPointerLevel);
        void setReferenceLevel(const int iReferenceLevel);

        virtual const QString toString() const;

        ValueFunction &operator=(const ValueFunction &refCopy);
        ValueFunction &operator=(ValueFunction &&refMove);
        bool operator==(const ValueFunction &refOther) const;
        bool operator!=(const ValueFunction &refOther) const;
    };
}
