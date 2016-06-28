/*
������ģ���ʺ����4����ɨ�裬ͨ��KeyScan����ʵ��Ӳ����Ӧ�÷ֲ�


*/


#include "key.h"

unsigned char KeyValue;

//static unsigned char KeyScan(void)
//{
//	if((KeyPort & 0x01) == 0) return KEY0_VALUE;
//	if((KeyPort & 0x02) == 0) return KEY1_VALUE;
//	if((KeyPort & 0x04) == 0) return KEY2_VALUE;
//	if((KeyPort & 0x08) == 0) return KEY3_VALUE;
//	return KEY_NULL;
//}

static unsigned char KeyScan(void)
{
	if(KEYA == 0) return KEYA_VALUE;
	if(KEYB == 0) return KEYB_VALUE;
	return KEY_NULL;
}

void GetKey(unsigned char* pKeyValue)
{
	static unsigned char KeyState 	= KEY_STATE_INIT;
	static unsigned char KeyTimeCnt	= 0;
	static unsigned char LastKey 	= KEY_NULL;
	static unsigned char KeyTemp 	= KEY_NULL;	
	
	KeyTemp = KeyScan();
	switch(KeyState)
	{
		//��ʼ״̬
		case KEY_STATE_INIT:
		{
			if(KEY_NULL != KeyTemp)      //�м�����
			{
				KeyState = KEY_STATE_WOBBLE;
			}
		}
		break;
		
		//����
		case KEY_STATE_WOBBLE:
		{
			KeyState = KEY_STATE_PRESS;
		}
		break;
		
		//����ȷ�ϰ���		
		case KEY_STATE_PRESS:
		{
			if(KEY_NULL != KeyTemp)       //�м�����
			{
				LastKey = KeyTemp;
				KeyTemp |= KEY_DOWN;
				KeyState = KEY_STATE_LONG;
			}
			else
			{
				KeyState = KEY_STATE_INIT;				
			}
		}
		break;
		
		case KEY_STATE_LONG:
		{
			if(KEY_NULL != KeyTemp)       //�м�����
			{
				if(++KeyTimeCnt > KEY_LONG_PERIOD)
				{
					KeyTimeCnt = 0;
					KeyTemp |= KEY_LONG;
					KeyState = KEY_STATE_CONTINUE;
				}
			}
			else
			{
				KeyState = KEY_STATE_RELEASE;
			}
		}
		break;
		
		//���������ۼ�
		case KEY_STATE_CONTINUE:
		{
			if(KEY_NULL != KeyTemp)     //�м�����
			{
				if(++KeyTimeCnt > KEY_CONTINUE_PERIOD)
				{
					KeyTimeCnt = 0;
					KeyTemp |= KEY_CONTINUE;
				}
			}				
			else
			{
				KeyState = KEY_STATE_RELEASE;
			}
		}
		break;
		
		//�����ͷ�
		case KEY_STATE_RELEASE:
		{
			KeyTimeCnt = 0;
			LastKey |= KEY_UP;
			KeyTemp = LastKey;
			KeyState = KEY_STATE_INIT;
		}
		break;
		
		default: break;
	}
	*pKeyValue = KeyTemp;
}
//void Key_Update(void)
//{
//	GetKey(&KeyValue);
//	if(KeyValue == (KEY0_VALUE | KEY_DOWN)) 		
//	{
//		LED1 = !LED1;
//	}
//	if(KeyValue == (KEY0_VALUE | KEY_LONG)) 
//	{				
//		LED2 = !LED2;
//	}
//	if(KeyValue == (KEY0_VALUE | KEY_CONTINUE))	
//	{				
//		LED3 = !LED3;
//	}
////	if(KeyValue == KEY_NULL)
////	{
////		LED0 = 1;
////		LED1 = 1;
////		LED2 = 1;
////		LED3 = 1;
////	}
//}
