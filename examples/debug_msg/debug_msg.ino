/*
 * Debug MSG
 *
 * Print a debug message.
 *
 * This example is in the public domain.
 */

#include <debug.h>


void setup()
{
	// initialize the serial interface for debugging
	Serial.begin(9600);

	// print a debug message
	debug_msg("Hello, I'm a happy debug message!");
}

void loop()
{
	debug_msg("Time to count to a million!");
	for (long i = 0; i < 1000000L; i++) {
		Serial.println(i);
		delay(1000);
	}
}
