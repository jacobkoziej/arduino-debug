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
#elif defined DEBUG_PRINT_FILE
#define debug_bin_info() Serial.print(F("[BIN INFO] "));\
	Serial.println(F(__FILE__": "__DATE__" - "__TIME__));
#else
#define debug_bin_info() Serial.print(F("[BIN INFO] "));\
	Serial.println(F(__DATE__" - "__TIME__));
#endif

#ifdef NDEBUG
#define debug_val(X, ...)
#elif defined DEBUG_PRINT_FILE
#define debug_val(X, ...) Serial.print(F("[VAL] "));\
	Serial.print(F(__FILE__":"));\
	Serial.print(__LINE__);\
	Serial.print(F(": "#X" == ")); Serial.println((X), ##__VA_ARGS__);
#else
#define debug_val(X, ...) Serial.print(F("[VAL] "));\
	Serial.print(__LINE__);\
	Serial.print(F(": "#X" == ")); Serial.println((X), ##__VA_ARGS__);
#endif

#ifdef NDEBUG
#define debug_warn(X)
#elif defined DEBUG_PRINT_FILE
#define debug_warn(X) if ((X)) {\
	Serial.print(F("[WARN] "));\
	Serial.print(F(__FILE__":"));\
	Serial.print(__LINE__);\
	Serial.println(F(": "#X));\
	}
#else
#define debug_warn(X) if ((X)) {\
	Serial.print(F("[WARN] "));\
	Serial.print(__LINE__);\
	Serial.println(F(": "#X));\
	}
#endif

#ifdef NDEBUG
#define debug_msg(X)
#elif defined DEBUG_PRINT_FILE
#define debug_msg(X) if ((X)) {\
	Serial.print(F("[MSG] "));\
	Serial.print(F(__FILE__":"));\
	Serial.print(__LINE__);\
	Serial.print(F(": "));\
	Serial.println(F(X));\
	}
#else
#define debug_msg(X) if ((X)) {\
	Serial.print(F("[MSG] "));\
	Serial.print(__LINE__);\
	Serial.print(F(": "));\
	Serial.println(F(X));\
	}
#endif

#ifdef NDEBUG
#define debug_assert(X)
#elif defined DEBUG_PRINT_FILE
#define debug_assert(X) if (!(X)) {\
	Serial.print(F("Assertion failed: ("#X"), file: "__FILE__", line: "));\
	Serial.println(__LINE__);\
	while (1);\
	}
#else
#define debug_assert(X) if (!(X)) {\
	Serial.print(F("Assertion failed: ("#X"), line: "));\
	Serial.println(__LINE__);\
	while (1);\
	}
#endif

#endif /* _JACOBKOZIEJ_DEBUG */
