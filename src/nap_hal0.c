#include "internal.h"
#include "nap_hal0.h"
#include <string.h> // memset()
#include <stdarg.h> // va_list, va_start(), va_end()
#include <stdio.h> // vsnprintf()

const char *nap_hal0__version(void) {
	return "0.0.2";
}

void nap_hal0_internal__init(void) {
	nap_hal0__printf(
		"nap_hal0 initialized. Version: %s\n", nap_hal0__version()
	);
}

void nap_hal0__printf(const char *fmt, ...) {
	va_list args;
	char buffer[1024];
	memset(buffer, 0, sizeof(buffer));

	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	nap_hal0__puts(buffer);
}
