#pragma once

#include <QMap>
#include <QString>

namespace net::draconia::classbuilder::model
{
    enum AccessControl {Private, Protected, Public};

    QMap<AccessControl, QString> mapAccessControlValues{{Private, "Private"}, {Protected, "Prortected"}, {Public, "Public"}};;
}
