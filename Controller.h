#pragma once

#include "Observable.h"

using net::draconia::util::Observable;

namespace net::draconia::classbuilder
{
    class Controller : public Observable
    {
    public:
        Controller();
        ~Controller();
    };
}
