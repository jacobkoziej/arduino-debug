/*
 * Debug BIN INFO
 *
 * Print information about when the sketch was compiled.
 *
 * This example is in the public domain.
 */

#include <debug.h>


void setup()
{
	// initialize the serial interface for debugging
	Serial.begin(9600);

	// print information about when the sketch was compiled
	debug_bin_info();
}

void loop()
{
}
