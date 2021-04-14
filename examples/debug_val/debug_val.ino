/*
 * Debug VAL
 *
 * Print the value of a variable in memory.
 *
 * This example is in the public domain.
 */

#include <debug.h>


float pi     = 3.141592;
int   days   = 85;
int   arr[3] = {1, 2, 3};
char  *msg   = "Hello world!";


void setup()
{
	// initialize the serial interface for debugging
	Serial.begin(9600);

	// print the value of 'pi' to 6 decimal places
	debug_val(pi, 6);

	// print the value of 'days'
	debug_val(days);

	// print the value of 'days' in hexadecimal
	debug_val(days, HEX);

	// print the value of the third element in 'arr'
	debug_val(arr[2]);

	// print the value of 'msg'
	debug_val(msg);
}

void loop()
{
}
