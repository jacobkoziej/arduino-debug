/*
 * Debug PRINT FILE
 *
 * Enable the printing of filenames in debug output.
 * This feature is only practical for a multi-file program.
 *
 * This example is in the public domain.
 */

#define DEBUG_PRINT_FILE
#include <debug.h>

/*
 * To enable filename printing all you need to do is define DEBUG_PRINT_FILE.
 *
 * NOTE:
 * DEBUG_PRINT_FILE MUST be defined before including the debug library to take
 * effect.
 */


void setup()
{
	// initialize the serial interface
	Serial.begin(9600);

	// the following will print the filename on top of compilation time
	debug_bin_info();
}

void loop()
{
}
