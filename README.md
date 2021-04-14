# arduino-debug

> Serial debugging for Arduino

Ever get tired of the endless commenting in/out of `Serial.print()`s for
debugging?


## Features

* Stupid easy to disable/enable debugging.
* Labels and line numbers in output for easy debugging.
* [`Serial.print()`] formatting options when printing values.
* Use of the [`F()`] macro to cut down on SRAM usage.
* Toggle to enable filename printing in debug output for multi-file programs.


## Usage

To start using the library, `#include <debug.h>` at the top of your program.

* `debug_bin_info()` - print when the current program was compiled
* `debug_val(var)` - print the value of `var`
* `debug_msg("message")` - print a message
* `debug_warn(var == x)` - print a warning when condition is met
* `debug_assert(var == x)` - assert that condition is met, else halt execution

To disable debugging, `#define NDEBUG` **BEFORE** `#include <debug.h>`.

To enable filename printing, `#define DEBUG_PRINT_FILE` **BEFORE**
`#include <debug.h>`.


## Limitations

This library is exclusively composed of preprocessor macros and makes heavy use
of the [`F()`] macro, which comes with it own set of advantages and
disadvantages.

Only string literals can be used for `debug_msg()` as the input is being passed
directly to the [`F()`] macro.

> For example:

```arduino
// this will work
debug_msg("It works!");

// while this will not
char *msg = "If only it worked...";
debug_msg(msg);
```

`debug_val()` will only print what is passed into the macro as the name, so
loop printing becomes problematic.

> For example:

```arduino
int arr[5] = {1, 2, 3, 4, 5};

// the following will always show 'arr[i] =='
for (int i = 0; i < 5; i++) {
	debug_val(arr[i]);
}
```


## Copyright & Licensing

Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>

Distributed under the [LGPLv3]


---

> Made with love for the Mechatronics & Robotics major at Brooklyn Technical High
> School.

> Inspired by [Zed A. Shaw's Awesome Debug Macros].


[`Serial.print()`]: https://www.arduino.cc/reference/en/language/functions/communication/serial/print/
[`F()`]: https://www.arduino.cc/reference/en/language/variables/utilities/progmem/
[LGPLv3]: LICENSE.md
[Zed A. Shaw's Awesome Debug Macros]: https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/dbg.h
