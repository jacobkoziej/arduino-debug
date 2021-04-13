/*
 * arduino-debug -- serial debugging for Arduino
 * Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _JACOBKOZIEJ_DEBUG
#define _JACOBKOZIEJ_DEBUG

#include <Arduino.h>


#ifdef NDEBUG
#define debug_bin_info()
#else
#define debug_bin_info() Serial.println(F(\
	__FILE__": "__DATE__" - "__TIME__));
#endif

#ifdef NDEBUG
#define debug_value(X, ...)
#else
#define debug_value(X, ...) Serial.print(F(__FILE__":"));\
	Serial.print(__LINE__);\
	Serial.print(F(": "#X" == ")); Serial.println((X), ##__VA_ARGS__);
#endif

#ifdef NDEBUG
#define debug_assert(X)
#else
#define debug_assert(X) if (!(X)) {\
	Serial.print(F("Assertion failed: ("#X"), line: "));\
	Serial.println(__LINE__);\
	while (1);\
	}
#endif

#endif /* _JACOBKOZIEJ_DEBUG */
