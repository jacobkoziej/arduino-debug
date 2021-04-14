/*
 * Debug WARN
 *
 * Print a warning message when a condition is met.
 *
 * This example is in the public domain.
 */

#include <debug.h>


int x = 5;
int y = 2;


void setup()
{
	// initialize the serial interface for debugging
	Serial.begin(9600);


	// warn if the integer division results in a remainder
	debug_warn(x % y != 0);
	Serial.print("x / y == ");
	Serial.println(x / y);
}

void loop()
{
}
