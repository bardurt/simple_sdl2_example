#ifndef EVENTINTERFACE_H_INCLUDED
#define EVENTINTERFACE_H_INCLUDED

#include "KeyEvents.h"

class EventInterface
{

public:
	EventInterface(){}
	virtual ~EventInterface(){}
	virtual Event getKeyEvent() = 0;
};
#endif // EVENTINTERFACE_H_INCLUDED
