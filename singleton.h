#pragma once

/// <summary>
/// A singleton class to make sure the inheriting classes only have one instance at a time.
/// </summary>
/// <typeparam name="T">The class you want to connect the singleton with.</typeparam>
template <class T>
class singleton
{
protected:
	
	/// <summary>
	/// Holds the instance.
	/// </summary>
	static T* singletonInstance;

public:

	virtual ~singletonInstance() {};

	/// <summary>
	/// Returns the one instance of the class if already existing.
	/// If the function is called, while no instance exists, there will be created a new one and immediately returned.
	/// </summary>
	/// <returns>The instance of the class.</returns>
	inline static T* get()
	{
		if (!singletonInstance)
		{
			singletonInstance = new T();
		}

		return singletonInstance;
	}

	/// <summary>
	/// Safely deletes the instance.
	/// This should be called if the instance is no longer needed.
	/// E.g. in the destructor of the class.
	/// </summary>
	inline static void del()
	{
		if (singletonInstance)
		{
			delete singletonInstance;
			singletonInstance = nullptr;
		}

		return;
	}
};

template <class T>
T* singleton<T>::singletonInstance = 0;
