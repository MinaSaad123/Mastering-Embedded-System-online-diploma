/*
 * ATmega_Interrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MENA SAAD
 */


//Include Libs
#include <avr/interrupt.h>
#include <util/delay.h>

//attributes
void INT0_vect(void) __attribute__ ((__signal__));
void INT1_vect(void) __attribute__ ((__signal__));
void INT2_vect(void) __attribute__ ((__signal__));

//Typedef
typedef volatile unsigned int vuint32_t;
/************************Macros***************************/
/*************GPIO***********/
//PortD
#define PORTD    *((vuint32_t* )0x32)
#define DDRD     *((vuint32_t* )0x31)
#define PIND     *((vuint32_t* )0x30)
//PortB
#define PORTB    *((vuint32_t* )0x38)
#define DDRB     *((vuint32_t* )0x37)
#define PINB     *((vuint32_t* )0x36)

/*************INTERRUPT***********/
//Register address which control on Trigger INT0, INT1
#define MCUCR    *((vuint32_t* )0x55)

//Register address which control on Trigger INT2
#define MCUCSR   *((vuint32_t* )0x54)

//Register address which control on  Interrupt INT0, INT1, INT2
#define GICR     *((vuint32_t* )0x5B)


/*****************function definition*******************/
/**GPIO_INIT definition**/
void GPIO_INIT()
{
	/** I Can Decrease Number of Lines But i do This For Readability**/
	//Make PortD2 as Input:
	DDRD    &= ~(1 << 2);
	//Make PortD3 as Input:
	DDRD    &= ~(1 << 3);
	//Make PortB2 as Input:
	DDRB    &= ~(1 << 2);
	//Pull-up off
	PORTD   &= ~(1 << 2);
	//Pull-up off
	PORTD   &= ~(1 << 3);
	//Pull-up off
	PORTB   &= ~(1 << 2);
	//Make  (PortD3, PortD5, PortD7 ) as Output:
	DDRD    |= (0xE0);
	//Make  (PortD3, PortD5, PortD7 ) Drive to Zero:
	PORTD   &= ~(0xE0);


}

/**INTERRUPT_INIT definition**/
void INTERRUPT_INIT()
{
	//Any Logical Change to PortB2
	MCUCSR   |= (0b10 << 6);
	//Raising Edge For PortD3
	MCUCR    |= (0b11 << 2);
	//Any Logical Change to PortD2
	MCUCR    |= (0b01 << 0);
    //Enable Interrupts
	GICR     |= (0b11100000);

}


int main()
{
	//Calling function
	GPIO_INIT();
	INTERRUPT_INIT();

	//Enable Global Interrupt
	sei();

	//Infinite Loops
	while(1);

    return 0;
}

/**INTERRUPT_Handler definition**/
//========INT0
void INT0_vect(void)
{
	//Set PortD5
	PORTD  |= (1 << 5);
	//Delay
    _delay_ms(1000);
	//Reset PortD5
    PORTD  &= ~(1 << 5);

}
//========INT1
void INT1_vect(void)
{
	//Set PortD6
	PORTD  |= (1 << 6);
	//Delay
    _delay_ms(1000);
	//Reset PortD6
    PORTD  &= ~(1 << 6);
}
//========INT2
void INT2_vect(void)
{
	//Set PortD7
	PORTD  |= (1 << 7);
	//Delay
    _delay_ms(1000);
	//Reset PortD7
    PORTD  &= ~(1 << 7);

}






