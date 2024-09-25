#include "Observable.h"

using namespace net::draconia::util;

QList<Observer *> &Observable::getObserversInternal() const
{
    return(const_cast<QList<Observer *> &>(mLstObservers));
}

Observable::Observable()
    :   mbChanged(false)
{ }

Observable::Observable(const Observable &refCopy)
    :   mbChanged(false)
{
    Q_UNUSED(refCopy);
}

Observable::Observable(Observable &&refMove)
    :   mbChanged(false)
{
   Q_UNUSED(refMove)
}

Observable::~Observable()
{ }

void Observable::addObserver(const Observer &refObserver)
{
    mLstObservers.append(const_cast<Observer *>(&refObserver));
}

void Observable::clearObservers()
{
    mLstObservers.clear();
}

QList<Observer *> &Observable::getObservers()
{
    return(mLstObservers);
}

bool Observable::isChanged() const
{
    return(mbChanged);
}

void Observable::notifyObservers(const QString &sProperty)
{
    if(isChanged())
        for(unsigned uiLength = getObservers().length(), uiLoop = 0; uiLoop < uiLength; uiLoop++)
            getObservers()[uiLoop]->update(*this, sProperty);

    setChanged(false);
}

void Observable::removeObserver(Observer &refObserver)
{
    mLstObservers.removeOne(&refObserver);
}

void Observable::removeObservers(const QList<Observer *> &lstObservers)
{
    for(Observer * ptrObserver : lstObservers)
        mLstObservers.removeOne(ptrObserver);

    setChanged(false);
}

void Observable::setChanged(const bool bChanged)
{
    mbChanged = bChanged;
}

Observable &Observable::operator=(const Observable &refCopy)
{
    setChanged(false);

    return(*this);
}

Observable &Observable::operator=(Observable &&refMove)
{
    setChanged(false);

    return(*this);
}

bool Observable::operator==(const Observable &refOther) const
{
    return  (   (isChanged() == refOther.isChanged())
            &&  (getObserversInternal() == refOther.getObserversInternal()));
}

bool Observable::operator!=(const Observable &refOther) const
{
    return(!operator==(refOther));
}

Observer::~Observer()
{ }
