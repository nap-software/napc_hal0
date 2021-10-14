#include "../src/nap_hal0.h"
#include <assert.h> // assert()
#include <string.h> // strcmp()

int main(void) {
	nap_hal0__init();

	nap_hal0__puts("It works!\n");
	nap_hal0__printf("platform:%s\n", nap_hal0__platform());

	unsigned long then = nap_hal0__time();

	nap_hal0__delay(1250);

	unsigned long delta = nap_hal0__time() - then;

	nap_hal0__printf("Delta is %lu\n", delta);

	return 0;
}
