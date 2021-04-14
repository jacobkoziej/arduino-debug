/*
 * Debug DISABLE
 *
 * Disable all debug messages.
 *
 * This example is in the public domain.
 */

#define NDEBUG
#include <debug.h>

/*
 * To disable debugging all you need to do is define NDEBUG.
 * (NDEBUG is short for no debug)
 *
 * NOTE:
 * NDEBUG MUST be defined before including the debug library to take effect.
 */


void setup()
{
	// initialize the serial interface
	Serial.begin(9600);

	// the following will print
	Serial.print("Program start time: ");
	Serial.println(micros());

	// while this won't
	debug_msg("Completed hardware setup");
}

void loop()
{
}
