#include "mc96f6432.h"

#ifndef __key_h_
#define __key_h_


//IO define
#define KEYA	(P1 & 0x01)		//��Ӳ���ϵ����ӹ�ϵ������	
#define	KEYB	(P1 & 0x02)		//��Ӳ���ϵ����ӹ�ϵ������
#define	KEYC	(P1 & 0x03)		//��Ӳ���ϵ����ӹ�ϵ������
#define	KEYD	(P1 & 0x04)		//��Ӳ���ϵ����ӹ�ϵ������

//���尴�����º��Ӧkey��״ֵ̬		
#define KEYA_VALUE	0x0e	//00001110
#define KEYB_VALUE	0X0d	//00001101
#define KEY2_VALUE	0x0b	//00001011
#define KEY3_VALUE	0X07	//00000111
#define KEY_NULL	0x0f

//���尴������ֵ�����£��������������ͷţ�
#define KEY_DOWN		0X80
#define	KEY_LONG		0X40
#define	KEY_CONTINUE	0X20
#define	KEY_UP			0X10

//���峤����˫����tick��
#define	KEY_LONG_PERIOD		100			//����tick��100
#define KEY_CONTINUE_PERIOD	25			//�ۼ�tick��25

//����IO��
//#define KeyPort P2
//sbit IO_Key0 = KeyPort^0;
//sbit IO_Key1 = KeyPort^1;
//sbit IO_Key2 = KeyPort^2;
//sbit IO_Key3 = KeyPort^3;
sbit IO_KeyA = P2^0;
sbit IO_KeyB = P1^0;

#define LEDPort P4
sbit LED0 = LEDPort^0;
//sbit LED1 = LEDPort^1;
//sbit LED2 = LEDPort^2;
//sbit LED3 = LEDPort^3;

//���尴��״̬
#define KEY_STATE_INIT		0			//��ʼ��
#define	KEY_STATE_WOBBLE	1           //����
#define	KEY_STATE_PRESS		2			//��������
#define	KEY_STATE_LONG		3			//��������
#define	KEY_STATE_CONTINUE	4			//����˫��
#define	KEY_STATE_RELEASE	5			//�����ͷ�



//extern void Key_Update(void);
extern void GetKey(unsigned char *pKeyValue);
extern unsigned char KeyValue;

#endif
