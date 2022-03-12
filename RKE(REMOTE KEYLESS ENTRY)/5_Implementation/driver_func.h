
#ifndef DRIVER_FUNC_H_
#define DRIVER_FUNC_H_
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define led_red 12  
#define led_green 13 
#define led_blue 14    
#define led_orange 15   
#define BLUE_BUTTON 0 
 

void my_delay(uint32_t time); 
void led_init_all(void);      
void led_on(uint8_t led_no); 
void led_off(uint8_t led_no); 
void button_init(void);       
int button_count(void);       
int encryption(int enc);      

#endif 