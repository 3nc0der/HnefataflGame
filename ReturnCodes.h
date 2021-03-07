#pragma once

/// <summary>
/// An enum class for ReturnCodes.
/// Will be used for all functions, which are usually void.
/// </summary>
enum class ReturnCodes
{
	/// <summary>
	/// Return this if there is no error.
	/// </summary>
	OK = 0,

	/// <summary>
	/// Return this if there is an internal error, that occured in the program, whithout human input.
	/// </summary>
	ERROR = 1,

	/// <summary>
	/// Return this if the user aborted the command.
	/// </summary>
	ABORTED = 2,

	/// <summary>
	/// Return this if there is an error because of an invalid parameter.
	/// Doesn`t mean the user is responsible for the invalid argument.
	/// </summary>
	INVALID_ARGUMENT = 3
};
