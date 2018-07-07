#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

#include "KeyEvents.h"

/*
 Interface for event handling.
*/
class EventInterface
{

public:
	EventInterface(){}
	virtual ~EventInterface(){}
	virtual Event getKeyEvent() = 0;
};
#endif // EVENTINTERFACE_H
