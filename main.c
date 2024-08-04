#include <avr/io.h>
#include <util/delay.h>

int main()
{
	// Initialize the 7-segment display segment codes for digits 0-9
	int seg_cth[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	int i;

	// Set PORTA, PORTC, and PORTD as output
	DDRA = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;

	// Initialize PORTC and PORTD to 0
	PORTC = 0x00;
	PORTD = 0x00;

	while(1)
	{
		// Green light (15 seconds)
		PORTA = 0b10; // Assume PORTA bit 1 is for green light
		for (i = 15; i > 0; i--) {
			PORTD = seg_cth[i % 10]; // Display countdown on 7-segment (units place)
			PORTC = seg_cth[i / 10]; // Display tens place if any
			_delay_ms(1000);
		}

		// Yellow light (5 seconds)
		PORTA = 0b100; // Assume PORTA bit 2 is for yellow light
		for (i = 5; i > 0; i--) {
			PORTD = seg_cth[i % 10]; // Display countdown on 7-segment (units place)
			PORTC = seg_cth[i / 10]; // Display tens place if any
			_delay_ms(1000);
		}

		// Red light (15 seconds)
		PORTA = 0b1000; // Assume PORTA bit 3 is for red light
		for (i = 15; i > 0; i--) {
			PORTD = seg_cth[i % 10]; // Display countdown on 7-segment (units place)
			PORTC = seg_cth[i / 10]; // Display tens place if any
			_delay_ms(1000);
		}
	}

	return 0;
}
