#if defined(__cplusplus)
	#error This source file must not be compiled by a C++ compiler.
#endif

#if !defined(ARDUINO)
	#include "internal.h"
	#include <stdlib.h> // exit(), EXIT_FAILURE
	#include <stdio.h> // fprintf(), stderr
	#include <time.h> // clock_gettime()
	#include <unistd.h> // sleep(), usleep()

	// Start time of program
	static struct timespec _programStart;

	const char *nap_hal0__platform(void) {
		return "linux";
	}

	void nap_hal0__init(void) {
		nap_hal0_internal__init();
		clock_gettime(CLOCK_MONOTONIC_RAW, &_programStart);
		nap_hal0_internal__ready();
	}

	void nap_hal0__abort(void) {
		exit(EXIT_FAILURE);
	}

	void nap_hal0__puts(const char *string) {
		fprintf(stderr, "%s", string);
	}

	unsigned long nap_hal0__time(void) {
		struct timespec now;

		clock_gettime(CLOCK_MONOTONIC_RAW, &now);

		long delta_seconds = (now.tv_sec - _programStart.tv_sec);
		long delta_nseconds = (now.tv_nsec - _programStart.tv_nsec);

		long delta = 0;

		delta += (delta_seconds * 1000); // 1sec = 1000ms
		delta += (delta_nseconds / 1000000); // 1000000ns = 1ms

		return delta;
	}

	void nap_hal0__delay(unsigned amount) {
		unsigned seconds = (amount / 1000);
		unsigned long milliseconds = amount - (seconds * 1000);
		unsigned long microseconds = milliseconds * 1000;

		sleep(seconds);
		usleep(microseconds);
	}
#endif
