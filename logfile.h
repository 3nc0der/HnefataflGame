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

	/// <summary>
	/// Writes the text to the log with a custom color.
	/// </summary>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="color">A string describing the custom color. e.g. for blue type "0000FF"</param>
	void writeToLog(const char* text, const char* color);

	/// <summary>
	/// Writes the text to the log with a custom color.
	/// Adds a specially marked line to the log, as the message is critical and should be seen quickly.
	/// </summary>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="color">A string describing the custom color. e.g. for blue type "0000FF"</param>
	/// <param name="critical">Set to true if the message is critical.</param>
	void writeToLog(const char* text, const char* color, bool critical);

	/// <summary>
	/// The basic logging function for formatted text.
	/// </summary>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="">The parameter list with all the values present in the string.</param>
	void writeToLogf(const char* text, ...);

	/// <summary>
	/// Logs a formatted text with a predefined color.
	/// </summary>
	/// <param name="color">A member of the LOG_COLOR enum.</param>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="">The parameter list with all the values present in the string.</param>
	void writeToLogf(log_color color, const char* text, ...);

	/// <summary>
	/// Adds a specially marked line to the log, as the message is critical and should be seen quickly.
	/// </summary>
	/// <param name="color">A member of the LOG_COLOR enum.</param>
	/// <param name="critical">Set to true if the message is critical.</param>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="">The parameter list with all the values present in the string.</param>
	void writeToLogf(log_color color, bool critical, const char* text, ...);

	/// <summary>
	/// Writes formatted text to the log with a custom color.
	/// </summary>
	/// <param name="color">A string describing the custom color. e.g. for blue type "0000FF"</param>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="">The parameter list with all the values present in the string.</param>
	void writeToLogf(const char* color, const char* text, ...);

	/// <summary>
	/// Writes formatted text to the log with a custom color.
	/// Adds a specially marked line to the log, as the message is critical and should be seen quickly.
	/// </summary>
	/// <param name="color">A string describing the custom color. e.g. for blue type "0000FF"</param>
	/// <param name="critical">Set to true if the message is critical.</param>
	/// <param name="text">The string that will be written to the log.</param>
	/// <param name="">The parameter list with all the values present in the string.</param>
	void writeToLogf(const char* color, bool critical, const char* text, ...);

private:

	/// <summary>
	/// The file.
	/// </summary>
	FILE *log;

	/// <summary>
	/// The name of this log file.
	/// </summary>
	const char* logName = "logfile.html";

	/// <summary>
	/// The last string that has been written to the log file.
	/// </summary>
	string lastString = "";

	/// <summary>
	/// How many times the last string was written.
	/// </summary>
	int timesLastStringWritten = 0;

	/// <summary>
	/// Tells whether the write lock is active or not.
	/// </summary>
	bool writeLock = false;
};