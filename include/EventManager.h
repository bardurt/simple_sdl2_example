#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "EventInterface.h"

class EventManager : public EventInterface
{
    public:
        EventManager();
        virtual ~EventManager();
        Event getKeyEvent();

    protected:

    private:
};

#endif // EVENTMANAGER_H
