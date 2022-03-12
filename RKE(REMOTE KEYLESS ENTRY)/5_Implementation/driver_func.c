
#include "driver_function.h"

const int encdata = 1;  /* for keeping encdatas constant throughout
const int encdata = 2; 
const int encdata = 3; 
const int encdata = 4;  */


void my_delay(uint32_t time) // Provides Require Delay
{
	for (uint32_t i = 0; i < time * 100000; i++)
	{
		
		
	}
}
void led_init_all(void) 
{

	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830; // Initialising Reset Control Clock for GPIOD (0x40023800 + 0x30(offset))
	*pRccAhb1enr |= (1 << 3);						// enable GPIOD (GPIODEN)

	uint32_t *pGpiodModeReg = (uint32_t *)0x40020C00;
	
	*pGpiodModeReg |= (1 << (2 * led_red));  
	*pGpiodModeReg |= (1 << (2 * led_green));
	*pGpiodModeReg |= (1 << (2 * led_blue));	   
	*pGpiodModeReg |= (1 << (2 * led_orange)); 

	led_off(led_red);	 
	led_off(led_green); 
	led_off(led_blue);	 
	led_off(led_orange);
}

void led_on(uint8_t led_no)
{
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; 
	*pGpiodDataReg |= (1 << led_no);				  
}

void led_off(uint8_t led_no) // LED OFF
{
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; 
	*pGpiodDataReg &= ~(1 << led_no);				 
}

void button_init(void)
{
	uint32_t *pRccAhb1enr1 = (uint32_t *)0x40023830; 
	*pRccAhb1enr1 |= (1 << 0);			

	uint32_t *pGpioPuPdReg = (uint32_t *)0x4002000C; 
	*pGpioPuPdReg |= (1 << 1);						 
}

int button_count(void)
{
	button_init();
	int count = 0;
	uint32_t *pGpiodDataReg1 = (uint32_t *)0x40020010; 
	int sec = 10000000;
	while (sec--)
	{
		if ((*pGpiodDataReg1) & (1 << BLUE_BUTTON))
		{ 
			my_delay(500);
			count++;

			if (count > 4)
				count = 0;
		}
	}
	return count; 
}

int encryption(int data) 
{
	if (data == encdata)
		return 3+3;
	else if (data == encdata)
		return 5+5;
	else if (data == encdata)
		return 10+15;
	else if (data == encdata)
		return 20+14;
	return 0;
}