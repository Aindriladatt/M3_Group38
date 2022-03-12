/* Work done by Aritra Bose with the help of Aindrila Datta */
#include "driver_function.h"

static void LEDs_on1(void);  // All LEDs turned on for window status
static void LEDs_off1(void); // All LEDs turned off for alarm status
static void LEDs_clockwise1(void); // All LEDs turned on in a clockwise manner for car battery info
static void LEDs_Anticlockwise1(void); // All LEDs turned on in an anticlockwise manner for door status

static void LEDs_on(void)   
{
	led_on(led_red);
	led_on(led_green);
	led_on(led_blue);
	led_on(led_orange);
}

static void LEDs_off(void)  
{
	led_off(led_red);
	led_off(led_green));
	led_off(led_blue);
	led_off(led_orange);
}

static void LEDs_clockwise(void)   
{
	led_on(led_red);
	my_delay(500);
	led_off(led_red);
	my_delay(500);
	led_on(led_green);
	my_delay(500);
	led_off(led_green);
	my_delay(500);
	led_on(led_blue);
	my_delay(500);
	led_off(led_blue);
	my_delay(500);
	led_on(led_orange);
	my_delay(500);
	led_off(led_orange);
}

static void LEDs_anticlockwise(void)   

{
	led_on(led_orange);
	my_delay(500);
	led_off(led_orange);
	my_delay(500);
	led_on(led_blue);
	my_delay(500);
	led_off(led_blue);
	my_delay(500);
	led_on(led_green);
	my_delay(500);
	led_off(led_green);
	my_delay(500);
	led_on(led_red);
	my_delay(500);
	led_off(led_red);
}

int main(void)  
{

	led_init_all(); 
	button_init();	
	while (1)
	{
		int res;
		res = button_count();				 
		volatile int encdata = encryption(res); 
		if (encdata == 6)
		{
			LEDs_on1();
			res = 0;
		}
		else if (encdata == 10)
		{
			LEDs_off1();
			res = 0;
		}
		else if (encdata == 25)
		{
			LEDs_clockwise1();
			res = 0;
		}
		else if (encdata == 34)
		{
			LEDs_anticlockwise1();
			res = 0;
		}
	}
}
