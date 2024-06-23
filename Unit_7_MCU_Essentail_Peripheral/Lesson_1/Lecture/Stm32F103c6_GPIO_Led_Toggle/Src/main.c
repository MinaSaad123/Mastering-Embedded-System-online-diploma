/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina Saad
 * @brief          : Main program body
 ******************************************************************************
 */

//type definition
typedef volatile unsigned int vuint32_t;
typedef unsigned int          uint32_t;

/************GPIO Base Addresses*************/
//GPIOA
#define GPIOA_BASE      0x40010800
//GPIOB
#define GPIOB_BASE      0x40010C00

/***************GPIO Register Addresses****************/
//Port Configuration Register low (PortA , PortB)
#define GPIOA_CRL      *(vuint32_t*)(GPIOA_BASE + 0x00)
#define GPIOB_CRL      *(vuint32_t*)(GPIOB_BASE + 0x00)
//Port Configuration Register high (PortA , PortB)
#define GPIOA_CRH      *(vuint32_t*)(GPIOA_BASE + 0x04)
#define GPIOB_CRH      *(vuint32_t*)(GPIOB_BASE + 0x04)
//Port output data register (GPIOx_ODR)
#define GPIOB_ODR      *(vuint32_t*)(GPIOB_BASE + 0x0C)
//Port input data register
#define GPIOA_IDR      *(vuint32_t*)(GPIOA_BASE + 0x08)

/**************RCC Base Addresses***************/
#define RCC_BASE       0x40021000

/***************RCC Register Addresses****************/
#define RCC_APB2ENR    *(vuint32_t*)(RCC_BASE + 0x18)

/*****************Function_Definition*****************/
//========GPIO_INIT
void GPIO_INIT()
{
	//Reset all Pins
	GPIOA_CRL = 0;
	GPIOB_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_CRH = 0;

	/**Make (PortA1, PortA13) Input Floating**/
	//PortA1
	GPIOA_CRL   |= (0b01 << 6); //=====Reset State
	//PortA13
	GPIOA_CRH   |= (0b01 << 22); //=====Reset State

	/**Make (PortB1, PorB13) Output Floating**/
    //PortB1
	GPIOB_CRL   |=  (0b01 << 4); //=====Reset State
	GPIOB_CRL   &= ~(0b11 << 6); //=====Push-Pull
	//PortB13
	GPIOB_CRH   |= (0b01 << 20);//=====Reset State
	GPIOB_CRH   &= ~(0b11 << 22); //=====Push-Pull

}

//========RCC_INIT
void CLOCK_INIT()
{
	//Enable (GPIOA, GPIOB) Clock
	//GPIOA
	RCC_APB2ENR |= (1 << 2);
	//GPIOB
	RCC_APB2ENR |= (1 << 3);
}
void __delay__(uint32_t Time )
{
	uint32_t i, j;
	for(i = 0;i < 255;i++)
		for(j = 0;j < 255;j++);
}

//========Main
int main(void)
{
    //Init Calling
	CLOCK_INIT();
	GPIO_INIT();

	//Infinite Loop
    while(1)
    {
    	if(((GPIOA_IDR & (1 << 1)) >> 1) == 0)
    	{
    		//Toggle Led
    		GPIOB_ODR ^= (1 << 1);
    		//========Single press
    		while(((GPIOA_IDR & (1 << 1)) >> 1) == 0);
    	}
    	else if(((GPIOA_IDR & (1 << 13)) >> 13) == 1)
    	{
    		//Toggle Led
    		GPIOB_ODR ^= (1 << 13);
    		//=======Multipress

    	}
    	__delay__(1);


    }

}
