
#include "driver_fun.h"

static void LEDs_on(void);  // All LEDs turned on for car lock
static void LEDs_off(void); // All LEDs turned off for car unlock
static void LEDs_clockwise(void); // All LEDs turned on in a clockwise manner for alarm activ/deactiv
static void LEDs_Anticlockwise(void); // All LEDs turned on in an anticlockwise manner for approach light

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

static void LEDs_anticlockwise(void)   // Switches ON LED's in AntiClockwise Rotation

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

int main(void)  //initialisation
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
			LEDs_on();
			res = 0;
		}
		else if (encdata == 10)
		{
			LEDs_off();
			res = 0;
		}
		else if (encdata == 25)
		{
			LEDs_clockwise();
			res = 0;
		}
		else if (encdata == 34)
		{
			LEDs_anticlockwise();
			res = 0;
		}
	}
}