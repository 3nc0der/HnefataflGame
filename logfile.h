#pragma once

#include <Windows.h>
#include <fstream>
#include "singleton.h"

using namespace std;

/// <summary>
/// Needed for formatted text.
/// The maximum buffer size.
/// </summary>
constexpr int MAX_BUFFER = 1024;

/// <summary>
/// Predefined colors of the log.
/// For easier coloring of text.
/// </summary>
typedef enum class log_color
{
	BLACK = 0,
	WHITE = 1,
	BLUE = 2,
	GREEN = 3,
	RED = 4,
	PURPLE = 5,
	YELLOW = 6,
	CYAN = 7,
	DEFAULT = 8
}LOG_COLOR;

#define LOG logfile::get()

/// <summary>
/// A log file class with multiple features.
/// Receive an instance by using the <c>LOG</c>-macro.
/// </summary>
class logfile : public singleton<logfile>
{
public:

	/// <summary>
	/// Creates a new log file instance, but is called automatically by the singleton class.
	/// </summary>
	logfile();

	~logfile();

	/// <summary>
	/// The basic logging function.
	/// </summary>
	/// <param name="text">The string that will be written to the log.</param>
	void writeToLog(const char* text);

	/// <summary>
	/// Logs a text with color.
	/// </summary>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="color">A member of the LOG_COLOR enum.</param>
	void writeToLog(const char* text, log_color color);

	/// <summary>
	/// Adds a specially marked line to the log, as the message is critical and should be seen quickly.
	/// </summary>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="color">A member of the LOG_COLOR enum.</param>
	/// <param name="critical">Set to true if the message is critical.</param>
	void writeToLog(const char* text, log_color color, bool critical);

	//give the wanted color like this "RGB" aka "FF00FF"
	void writeToLog(const char* text, const char* color);

	//if the message is critical it will be visible in the log
	void writeToLog(const char* text, const char* color, bool critical);

	//basic writetolog formatted function
	void writeToLogf(const char* text, ...);

	//use one of the predefined colors
	void writeToLogf(log_color color, const char* text, ...);

	//if the message is critical it will be visible in the log
	void writeToLogf(log_color color, bool critical, const char* text, ...);

	//give the color like this "RGB" aka "FF00FF"
	void writeToLogf(const char* color, const char* text, ...);

	//if the message is critical it will be visible in the log
	void writeToLogf(const char* color, bool critical, const char* text, ...);

private:

	//file variable
	FILE *log;

	//holds current log file name
	const char* logName = "logfile.html";

	//holds the last string that was written to log
	string lastString = "";

	//holds amount of last string written
	int timesLastStringWritten = 0;

	//tells whether the write lock is active or not
	bool writeLock = false;
};