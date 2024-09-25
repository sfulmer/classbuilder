#pragma once

#include "Field.h"
#include "Observable.h"

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Value : public Observable
    {
    public:
        Value() { }
        Value(const Value &refCopy);
        Value(Value &&refMove);
        virtual ~Value() = 0;

        virtual const QString toString() const = 0;

        Value &operator=(const Value &refCopy);
        Value &operator=(Value &&refMove);
        bool operator==(const Value &refOther) const;
        bool operator!=(const Value &refOther) const;
    };
}
