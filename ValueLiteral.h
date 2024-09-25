#pragma once

#include "Value.h"

namespace net::draconia::classbuilder::model
{
    class ValueLiteral : public Value
    {
        QString msValue;
    public:
        ValueLiteral(const QString &sValue = "");
        ValueLiteral(const ValueLiteral &refCopy);
        ValueLiteral(ValueLiteral &&refMove);
        virtual ~ValueLiteral();

        const QString &getValue() const;
        void setValue(const QString &sValue);

        virtual const QString toString() const;

        ValueLiteral &operator=(const ValueLiteral &refCopy);
        ValueLiteral &operator=(ValueLiteral &&refMove);
        bool operator==(const ValueLiteral &refOther) const;
        bool operator!=(const ValueLiteral &refOther) const;
    };
}
