#if defined(ARDUINO)
	#include <Arduino.h> // Serial, millis(), delay()

	extern "C" {
		#include "nap_hal0.h"

		const char *nap_hal0__platform(void) {
			return "arduino";
		}

		void nap_hal0__init(void) {
			Serial.begin(9600);
			while (!Serial);
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