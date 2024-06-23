#include "stdint.h"
/******************************************************************/
/*                       main prototype                           */
/******************************************************************/
extern void main();

/******************************************************************/
/*                       setting variable                         */
/******************************************************************/
extern uint32_t S_DATA;
extern uint32_t E_DATA;
extern uint32_t S_BSS;
extern uint32_t E_BSS;
extern uint32_t STACK_TOP;
extern uint32_t E_TEXT;
int i = 0;


/******************************************************************/
/*                       function prototype                       */
/******************************************************************/
void DEFAULT_HANDLER();
void  RESET(void);



/******************************************************************/
/*                       symbols attribute                        */
/******************************************************************/
void NMI(void)__attribute__((weak, alias("DEFAULT_HANDLER")));
void HARD_FAULT(void)__attribute__((weak, alias("DEFAULT_HANDLER")));
void MEM_MANAGE(void)__attribute__((weak, alias("DEFAULT_HANDLER")));
void BUS_FAULT(void)__attribute__((weak, alias("DEFAULT_HANDLER")));
void USGE_FAULT(void) __attribute__((weak, alias("DEFAULT_HANDLER")));


/******************************************************************/
/*                       vectors sections                         */
/******************************************************************/
uint32_t vectors[]__attribute__((section(".VECTORS"))) = {

   (uint32_t) &STACK_TOP,
   (uint32_t) &RESET,
   (uint32_t) &NMI,
   (uint32_t) &HARD_FAULT,
   (uint32_t) &MEM_MANAGE,
   (uint32_t) &BUS_FAULT,
   (uint32_t) &USGE_FAULT,

};

/******************************************************************/
/*                       function_defination                      */
/******************************************************************/
void  RESET(void)
{

/******************************************************************/
/*                        calculate size                          */
/******************************************************************/
uint32_t BSS_SIZE = ((unsigned char* )&E_BSS - (unsigned char* )&S_BSS);
uint32_t DATA_SIZE = (unsigned char)((unsigned char* )&E_DATA - (unsigned char* )&S_DATA);
unsigned char *P_DATA = (unsigned char*)&E_TEXT;
unsigned char *P_DST = (unsigned char*)&S_DATA;


/******************************************************************/
/*                       copy data section                        */
/******************************************************************/
   for(i = (DATA_SIZE );i != 0;--i)
   {
        *((unsigned char*)P_DST++) = *((unsigned char*)P_DATA++);
   }
   
/******************************************************************/
/*                       copy bss section                         */
/******************************************************************/
   for(i = (BSS_SIZE);i != 0;--i)
   {
        *((unsigned char*)P_DST++) = ((unsigned char)0) ;
   }
   
//cailing main 
   main();
//this line is necassary if the last instructions in main doesnt refer to infinite loop
for(;;); 

}
void DEFAULT_HANDLER()
{

   RESET();

}