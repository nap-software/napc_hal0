# napc_hal0@0.0.3

This library provides HAL (Hardware Abstraction Layer) for Arduino/Linux on the most basic level:

- Support for printing strings (console / serial)
- Measuring time since program start (in milliseconds)
- Delaying program execution by a set amount of milliseconds
- Aborting the program


### `void nap_hal0__init(void)`

Call this function before using any of the `nap_hal0__` functions.

---

### `const char *nap_hal0__version(void)`

Returns the version of the library.

---

### `const char *nap_hal0__platform(void)`

Returns the current platform. (can be `arduino` or `linux`)

---

### `void nap_hal0__abort(void)`

Aborts program execution.

On arduino this is an endless loop, on linux `exit()` is called.

---

### `void nap_hal0__puts(const char *string)`

Prints a string on the console.

On arduino this sends `string` via Serial, on linux `fprintf(stderr)` is used.

---

### `void nap_hal0__printf(const char *fmt, ...)`

Same as `printf()` but with HAL (internally uses `nap_hal0__puts`).

---

### `void nap_hal0__delay(unsigned amount)`

Delays program execution by `amount` milliseconds.

---

### `unsigned long nap_hal0__time(void)`

Returns the number of milliseconds since program start.
