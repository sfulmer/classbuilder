#pragma once

#include "Constructor.h"
#include "Field.h"
#include "Function.h"
#include <Observable.h>
#include "Parent.h"

using net::draconia::util::Observable;

namespace net::draconia::classbuilder::model
{
    class Class : public Observable
    {
        QMap<Class *, QString> mMapParents;
        QList<Constructor> mLstConstructors;
        QList<Field> mLstFields;
        QList<Function> mLstFunctions;
        QList<Parent> mLstParents;
        QString msName;
    protected:
        QList<Constructor> &getConstructorsInternal() const;
        QList<Field> &getFieldsInternal() const;
        QList<Function> &getFunctionsInternal() const;
        QList<Parent> &getParentsInternal() const;
        virtual const QString toString() const;
    public:
        Class();
        Class(const QString &sName, const QList<Field> lstFields = QList<Field>(), const QList<Constructor> lstConstructors = QList<Constructor>(), const QList<Function> lstFunctions = QList<Function>());
        Class(const Class &refCopy);
        Class(Class &&refMove);
        ~Class();

        void addConstructor(const QString &sClassName, const QList<Argument> lstArguments, const QString sAccess = "Public");
        void addConstructor(const Constructor objConstructor);
        void addConstructors(const QList<Constructor> lstConstructors);
        void addField(const Field &refFie);
        void addField(const QString &sName, const QString &sDataType, const QString &sDefaultValue = "", const bool bConstant = false, const bool bStatic = false, const QString &sAccess = "Private");
        void addFields(const QList<Field> &lstFields);
        void addFunction(const Function &refFunction);
        void addFunction(const QString &sName, const QList<Argument> &lstArguments, const QString &sReturnType = "void", const bool bConstant = false, const bool bReturnConstant = false, const bool bStatic = false, const QString &sAccess = "Public");
        void addFunctions(const QList<Function> &lstFunctions);
        void addParent(Class *ptrParentClass, const QString &sAccess = "Public");
        void addParent(const Parent &refParent);
        void addParents(const QList<Parent> &lstParents);
        void clearConstructors();
        void clearFields();
        void clearFunctions();
        void clearParents();
        const QList<Constructor> &getConstructors() const;
        const QList<Field> &getFields() const;
        const QList<Function> &getFunctions() const;
        const QList<Parent> &getParents() const;
        const QString &getName() const;
        void removeConstructor(Constructor &refConstructor);
        void removeConstructors(const QList<Constructor> &lstConstructors);
        void removeField(Field &refField);
        void removeFields(const QList<Field> &lstFields);
        void removeFunction(Function &refFunction);
        void removeFunctions(const QList<Function> &lstFunctions);
        void removeParent(Parent &refParent);
        void removeParents(const QList<Parent> &lstParents);
        void setName(const QString &sName);

        Class &operator=(const Class &refCopy);
        Class &operator=(Class &&refMove);
        bool operator==(const Class &refOther) const;
        bool operator!=(const Class &refOther) const;
        operator const QString() const;
    };
}
