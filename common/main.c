#include "main.h"

int main(void) {
	unsigned int curr = 0, prev = 0;

	board_init();

	print_post_info();

	while (1) {
		if (BSP_PB_GetState(BUTTON_USER)) {
			BSP_LED_On(LED_BLUE);
			BSP_LED_On(LED_RED);
		}
		else {
			BSP_LED_Off(LED_BLUE);
			BSP_LED_Off(LED_RED);
		}

		/* Blink Red LED */
		curr = ticks / 250;
		if (curr != prev) {
			if (curr % 2) BSP_LED_On(LED_GREEN);
			else BSP_LED_Off(LED_GREEN);
		}
		prev = curr;
	}
}

