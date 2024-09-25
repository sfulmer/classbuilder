#include "General.h"

using namespace net::draconia::classbuilder::model;
using net::draconia::classbuilder::model::AccessControl;

QMap<AccessControl, QString> General::AccessControlValues{{Private, "Private"}, {Protected, "Prortected"}, {Public, "Public"}};
