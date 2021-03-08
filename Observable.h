#pragma once

#include "Observer.h"
#include <list>

/// <summary>
/// An observable class, which can add observers and can also notify those.
/// </summary>
class Observable
{
public:

	/// <summary>
	/// Call if there where changes the observer should know about.
	/// This will notify the observers and by that update them.
	/// </summary>
	void notifyObserver();

	/// <summary>
	/// Adds the given observer to the list of observers.
	/// </summary>
	/// <param name="o">The observer to add. Must not be NULL.</param>
	void addObserver(Observer &o);

private:

	/// <summary>
	/// The observer list. Stores all the added observers.
	/// </summary>
	std::list<Observer> observer;
};
