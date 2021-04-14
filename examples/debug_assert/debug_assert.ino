/*
 * Debug ASSERT
 *
 * Assert that a condition is met.
 *
 * This example is in the public domain.
 */

#include <debug.h>


// store the needed pins in a easy to access array
int my_hardware_pins[3] = {9, 10, 11};


void setup()
{
	// initialize the serial interface for debugging
	Serial.begin(9600);

	// set all the needed pins as outputs
	debug_msg("Setting pins as outputs");
	for (int i = 0; i < 3; i++) {
		pinMode(my_hardware_pins[i], OUTPUT);
	}

	// set the pins to an initial state
	debug_msg("Setting pins to an initial state");
	set_pins(my_hardware_pins, 3, 256);

	/*
	 * The code above will produce the following debug output:
	 *
	 *  * [MSG] 22: Setting pins as outputs
	 *  * [MSG] 28: Setting pins to an initial state
	 *  * [ASSERT FAILED] 62: (val >= 0) && (val < 256)
	 *
	 * Note that after the assertion failed, program execution halted.
	 */
}

void loop()
{
	debug_msg("Starting loop");

	for (int i = 254; i >= 0; i--) {
		set_pins(my_hardware_pins, 3, i);
		delay(10);
	}
	for (int i = 1; i <= 255; i++) {
		set_pins(my_hardware_pins, 3, i);
		delay(10);
	}
}


/* set the passed hardware pins to val */
void set_pins(int *pins, int len, int val)
{
	debug_assert(pins != NULL);
	debug_assert(len > 0);
	debug_assert((val >= 0) && (val < 256));

	for (int i = 0; i < len; i++) {
		analogWrite(pins[i], val);
	}
}
