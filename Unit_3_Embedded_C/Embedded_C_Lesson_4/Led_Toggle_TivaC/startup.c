/////main prototype
void main(void);

/***************************************************************/
/*                     setting symbols                         */
/***************************************************************/
extern unsigned int S_bss;
extern unsigned int E_bss;
extern unsigned int S_data;
extern unsigned int E_data;
extern unsigned int E_text;
unsigned char* P_src = (unsigned char*)&S_data;
unsigned char* P_DST = (unsigned char*)&E_text;
 
/***************************************************************/
/*                     function defination                     */
/***************************************************************/

void RESET()
{
	int i;

/***************************************************************/
/*                     calculate size                          */
/***************************************************************/
unsigned int data_size = (unsigned int)((unsigned int*)&E_data - (unsigned int*)&S_data);
unsigned int bss_size  = (unsigned int)((unsigned int*)&E_bss - (unsigned int*)&S_bss);

/***************************************************************/
/*                     copy data                               */
/***************************************************************/
for(i = data_size;i != 0;--i )
{
	*((unsigned char*)P_src++) = *((unsigned char*)P_DST);
}

/***************************************************************/
/*                     copy  bss                               */
/***************************************************************/
for(i = bss_size;i != 0;--i )
{
	*((unsigned char*)P_src++) = (unsigned char)0;
}
//////calling main
main();
//// looping at herself
for(;;);

}
void DEFAULT_HANDLER()
{

	RESET();
}
///////stack size which will be in bss
static  unsigned int vectors_tables[256];

/***************************************************************/
/*                     symbols attribute                       */
/***************************************************************/
void NMI(void)__attribute__((weak, alias("DEFAULT_HANDLER")));
void HARD_FAULT(void)__attribute__((weak, alias("DEFAULT_HANDLER")));
void MEM_MANAGE(void)__attribute__((weak, alias("DEFAULT_HANDLER")));

/***************************************************************/
/*                initializing vectors in flash                */
/***************************************************************/
void (* const g_p_vec[])()__attribute__((section(".vectors"))) = {
  
(void (*)()) ((unsigned int )&vectors_tables + sizeof(vectors_tables)),
&NMI,
&HARD_FAULT,
&MEM_MANAGE
};

