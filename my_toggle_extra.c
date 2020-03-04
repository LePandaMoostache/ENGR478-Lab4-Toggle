#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

#define 	RED_MASK 		0x02	// PF1, 2^1 = 2
#define   BLUE_MASK   0x04	// PF2, 2^2 = 4 
#define   GREEN_MASK  0x08	// PF3, 2^3 = 8

#define		SW2					0x01 // PF0, 2^0 = 1
#define 	SW1					0x10 // PF4, 2^4 = 16

#define 	SPEED				5
//*****************************************************************************
//
//!
//! A very simple example that toggles the on-board red LED using direct register
//! access.
//
//*****************************************************************************


void
PortFunctionInit(void)
{
//
		volatile uint32_t ui32Loop;   
	// Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the red LED (PF1).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= RED_MASK;
    GPIO_PORTF_DEN_R |= RED_MASK;
	
	  //
    // Enable the GPIO pin for the blue LED (PF2).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= BLUE_MASK;
    GPIO_PORTF_DEN_R |= BLUE_MASK;
		
		//
    // Enable the GPIO pin for the green LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= GREEN_MASK;
    GPIO_PORTF_DEN_R |= GREEN_MASK;

}

void 
RequiredFunc(void)
{
		// Turn on the LED.
		GPIO_PORTF_DATA_R |= GREEN_MASK;
	
	
		// Loop Forever
		while(1)
		{
				// Delay for a bit.
				SysCtlDelay(2000000*5);
				GPIO_PORTF_DATA_R ^= GREEN_MASK;
		}
}

void
ToggleAll(void)
{
		// Turn all LED colors ON
		GPIO_PORTF_DATA_R |= RED_MASK;
		GPIO_PORTF_DATA_R |= GREEN_MASK;
		GPIO_PORTF_DATA_R |= BLUE_MASK;
	
		// Loop Forever
		while(1)
		{
				// Toggle LED colors
			
				// Delay for a bit.
				SysCtlDelay(2000000*SPEED);
				GPIO_PORTF_DATA_R ^= RED_MASK;
				// Delay for a bit.
				SysCtlDelay(2000000*SPEED);
				GPIO_PORTF_DATA_R ^= GREEN_MASK;
				// Delay for a bit.
				SysCtlDelay(2000000*SPEED);
				GPIO_PORTF_DATA_R ^= BLUE_MASK;
		}
	
}

void
AlternateAll(void)
{

		while(1) 
		{
				GPIO_PORTF_DATA_R |= RED_MASK;
        // Delay for a bit.
				SysCtlDelay(2000000*SPEED);	
				GPIO_PORTF_DATA_R &= ~RED_MASK;

				GPIO_PORTF_DATA_R = BLUE_MASK;
        // Delay for a bit.
				SysCtlDelay(2000000*SPEED);	
				GPIO_PORTF_DATA_R &= ~BLUE_MASK;

				GPIO_PORTF_DATA_R |= GREEN_MASK;
        // Delay for a bit.
				SysCtlDelay(2000000*SPEED);
				GPIO_PORTF_DATA_R &= ~GREEN_MASK;
		}

}
int main(void)
{
	
		//initialize the GPIO ports	
		PortFunctionInit();

		//RequiredFunc();
		//ToggleAll();
		AlternateAll();

}
