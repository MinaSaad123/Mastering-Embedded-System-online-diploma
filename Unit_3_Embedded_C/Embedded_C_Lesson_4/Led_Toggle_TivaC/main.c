
/***************************************************************/
/*                            macros                           */
/***************************************************************/
#define SYSCTL_R            *((volatile unsigned int *)(0x400FE108))
#define GPIO_PORTF_DATA_R   *((volatile unsigned int *)(0x400253FC))
#define GPIO_PORTF_DIR_R    *((volatile unsigned int *)(0x40025400))
#define GPIO_PORTF_DEN_R    *((volatile unsigned int *)(0x4002551C))

/***************************************************************/
/*                         main function                       */
/***************************************************************/
void  main(void)
{
	int i;
	SYSCTL_R  = 0x20;
	//delay for clock
	for(i = 5000;i != 0;--i);
	GPIO_PORTF_DEN_R |= (1<<3);
    GPIO_PORTF_DIR_R |= (1<<3);
    while(1)
    {
    GPIO_PORTF_DATA_R |= (1<<3);
    for(i = 5000;i != 0;--i);
    GPIO_PORTF_DATA_R &= ~(1<<3);
    for(i = 5000;i != 0;--i);


    }
}