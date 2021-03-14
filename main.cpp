#include "Shell.h"

/// <summary>
/// The main method of the program.
/// </summary>
/// <returns>A windows error code.</returns>
int main()
{
	LOG->writeToLog("Game is running...", LOG_COLOR::BLUE, true);

	Shell game = Shell();

	game.execute();

	LOG->writeToLog("Game stops...", LOG_COLOR::BLUE, true);
}
