#pragma once

#include <QMap>
#include <QString>

namespace net::draconia::classbuilder::model
{
    enum AccessControl {Private, Protected, Public};

    class General
    {
    public:
        static QMap<AccessControl, QString> AccessControlValues;

        General();
    };
}
