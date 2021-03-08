#pragma once

/// <summary>
/// An observer class to implement the Observer pattern.
/// If an observer is notified the update function will be called.
/// </summary>
class Observer
{
public:

	/// <summary>
	/// The update function.
	/// Should be overwritten by the class implementing the observer, as this function is empty and won't do anything.
	/// </summary>
	void update();
};
