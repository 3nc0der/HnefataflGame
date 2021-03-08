#include "Observable.h"

void Observable::notifyObserver()
{
	if (observer.size() != 0)
	{
		for (Observer o : observer)
		{
			o.update();
		}
	}
}

void Observable::addObserver(Observer& o)
{
	observer.push_back(o);
}
