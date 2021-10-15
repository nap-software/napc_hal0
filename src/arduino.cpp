#if defined(ARDUINO)
	#include <Arduino.h> // Serial, millis(), delay()

	extern "C" {
		#include "internal.h"

		const char *nap_hal0__platform(void) {
			return "arduino";
		}

		void nap_hal0__init(void) {
			nap_hal0_internal__init();
			Serial.begin(9600);
			while (!Serial);
			Serial.println("(c) by nap.software");
			nap_hal0_internal__ready();
		}

		void nap_hal0__abort(void) {
			while (true);
		}

		void nap_hal0__puts(const char *string) {
			Serial.print(string);
		}

		unsigned long nap_hal0__time(void) {
			return millis();
		}

		void nap_hal0__delay(unsigned amount) {
			delay(amount);
		}
	}
#endif
