//======================================================
// Main program routine
// - Device name  : MC96F6432
// - Package type : 44MQFP
//======================================================
/*
����������
��������ַ(2bits)�Ե�ʱ��Ÿ����ڷ����յ�������


*/
#include "MC96F6432.h"
#include "key.h"
#include "sch.h"
#include "IOTest.h"
#include "FSM.H"
#include "GlobalVar.h"
#include "uart0.h"


void main()
{
	cli();          	// disable INT. during peripheral setting
	Peripheral_Init();
	SCH_Init_T2_1ms();  //��ʼ��systickΪ1ms
	sei();          	// enable INT.
	
	SCH_Add_Task(UART0_TX,0,10);     
	SCH_Start();
	
	// TODO: add your main code here
	while(1)
	{
		SCH_Dispatch_Tasks();
	}
}
