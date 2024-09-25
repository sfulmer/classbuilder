#pragma once

#include "Field.h"
#include "Object.h"
#include "Value.h"

namespace net::draconia::classbuilder::model
{
    class ValueField : public Value
    {
        Field *mPtrField;
        int miPointerLevel, miReferenceLevel;
        Object *mPtrObject;
    public:
        ValueField(Object *ptrObject, Field *ptrField, const int iPointerLevel = 0, const int iReferenceLevel = 0);
        ValueField(const ValueField &refCopy);
        ValueField(ValueField &&refMove);
        virtual ~ValueField();

        Field *getField() const;
        Object *getObject() const;
        int getPointerLevel() const;
        int getReferenceLevel() const;
        void setField(Field *ptrField);
        void setObject(Object *ptrObject);
        void setPointerLevel(const int iPointerLevel);
        void setReferenceLevel(const int iReferenceLevel);

        virtual const QString toString() const;

        ValueField &operator=(const ValueField &refCopy);
        ValueField &operator=(ValueField &&refMove);
        bool operator==(const ValueField &refOther) const;
        bool operator!=(const ValueField &refOther) const;
    };
}
