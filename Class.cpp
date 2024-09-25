#include "AccessControl.h"
#include "Class.h"

using namespace net::draconia::classbuilder::model;

QList<Constructor> &Class::getConstructorsInternal() const
{
    return(const_cast<QList<Constructor> &>(mLstConstructors));
}

QList<Field> &Class::getFieldsInternal() const
{
    return(const_cast<QList<Field> &>(mLstFields));
}

QList<Function> &Class::getFunctionsInternal() const
{
    return(const_cast<QList<Function> &>(mLstFunctions));
}

QList<Parent> &Class::getParentsInternal() const
{
    return(const_cast<QList<Parent> &>(mLstParents));
}

const QString Class::toString() const
{
    QString str = "class " + getName();

    if(!getParents().empty())
        {
        str += " : " ;

        for(unsigned uiLength = getParents().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
            {
            const Parent &refParent = getParents()[uiLoop];

            str += (QString)refParent;

            if(uiLoop < (uiLength - 1))
                str += ", ";
            }
        }

    str += "\n{";

    for(const QString &sAccess : {"Private", "Protected", "Public"})
        {
        if(sAccess != "Private")
            str += sAccess[0].toLower() + QStringRef(&sAccess, 1, sAccess.length() - 1).toString();

        str += "\n";

        for(const Field &refField : getFieldsInternal())
            if(refField.getAccess().trimmed().toLower() == sAccess.trimmed().toLower())
                str += (QString)(refField);
        if(sAccess.trimmed().toLower() != "public")
            {
            for(const Function &refFunction : getFunctionsInternal())
                if(refFunction.getAccess().trimmed().toLower() == sAccess.trimmed().toLower())
                    str += (QString)(refFunction);
            str += QString("\n");
            for(const Constructor &refConstructor : getConstructorsInternal())
                if(refConstructor.getAccess().trimmed().toLower() == sAccess.trimmed().toLower())
                    str += (QString)(refConstructor);
            for(const Function &refFunction : getFunctionsInternal())
                if(refFunction.getAccess().trimmed().toLower() == sAccess.trimmed().toLower())
                    str += (QString)(refFunction);
            }
        else
            {
            for(const Constructor &refConstructor : getConstructorsInternal())
                if(refConstructor.getAccess().trimmed().toLower() == sAccess.trimmed().toLower())
                    str += (QString)(refConstructor);
            str += QString("\n");
            }
        }

    str += QString("\n}");

    return(str);
}

Class::Class()
    :   Observable()
{ }

Class:: Class(const QString &sName, const QList<Field> lstFields = QList<Field>(), const QList<Constructor> lstConstructors = QList<Constructor>(), const QList<Function> lstFunctions = QList<Function>());
Class::Class(const Class &refCopy);
Class::Class(Class &&refMove);
Class::~Class();

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

Class Class::&operator=(const Class &refCopy)
Class Class::&operator=(Class &&refMove)
bool Class::operator==(const Class &refOther) const
bool Class::operator!=(const Class &refOther) const
Class::operator const QString() const
