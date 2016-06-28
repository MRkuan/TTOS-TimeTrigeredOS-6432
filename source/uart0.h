/*
* Copyright (c) 2016,
* All rights reserved.
*
* �ļ����ƣ� usart0.h
* �ļ���ʶ�� �����ù���ƻ���
* ժ Ҫ�� ��������ͷ�ļ�����ʹ��usart0��C�ļ��а���
*
* ��ǰ�汾�� 1.0
* �� �ߣ� vivi
* ������ڣ� 2016��4��13��
* *
*/
#ifndef _uart0_h_
#define _uart0_h_
#include "globalvar.h"
#ifndef TRUE
#define FALSE 0
#define TRUE (!FALSE)
#endif

//2��byte��֡ͷ��2��byte��֡β��1������
#ifndef TXDATACNT
#define TXDATACNT (4+1)
#endif
#define Is_Buff_Full BYTEBIT.BIT0 

//Global Variable
extern unsigned char UART_BUFF_TX[];

//Global functions
extern unsigned char UART0_read();
extern void UART0_WriteOneByte(unsigned char dat);
extern void UART0_Init();  
extern void UART0_TX();

#endif