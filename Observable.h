#pragma once

#include <QList>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Observer;

            class Observable
            {
                bool mbChanged = false;
                QList<Observer *> mLstObservers;
            protected:
                QList<Observer *> &getObserversInternal() const;
            public:
                Observable();
                Observable(const Observable &refCopy);
                Observable(Observable &&refMove);
                ~Observable();

                void addObserver(const Observer &refObserver);
                void clearObservers();
                QList<Observer *> &getObservers();
                bool isChanged() const;
                void notifyObservers(const QString &sProperty);
                void removeObserver(Observer &refObserver);
                void removeObservers(const QList<Observer *> &lstObservers);
                void setChanged(const bool bChanged = true);

                Observable &operator=(const Observable &refCopy);
                Observable &operator=(Observable &&refMove);
                bool operator==(const Observable &refOther) const;
                bool operator!=(const Observable &refOther) const;
            };

            class Observer
            {
            public:
                virtual ~Observer();

                virtual void update(Observable &refObservable, const QString &sProperty) = 0;
            };
        }
    }
}
