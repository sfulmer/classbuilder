#pragma once

#include "Class.h"
#include <Observable.h>
#include <QList>

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class ClassModel : public Observable
    {
        QList<Class> mLstClasses;
    public:
        ClassModel();
        ClassModel(const ClassModel &refCopy);
        ClassModel(ClassModel &&refMove);
        ~ClassModel();

        void addClass(const Class &refClass);
        void addClasses(const QList<Class> &lstClasses);
        void clearClasses();
        const QList<Class> &getClasses() const;
        void removeClass(const Class &refClass);
        void removeClasses(const QList<Class> &lstClasses);

        ClassModel &operator=(const ClassModel &refCopy);
        ClassModel &operator=(ClassModel &&refMove);
        bool operator==(const ClassModel &refOther) const;
        bool operator!=(const ClassModel &refOther) const;
    };
}
