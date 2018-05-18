/*******************************************************************************
* �ļ��� : mmi.c

* �汾     ����            ����            ˵��
* V1.0                    2015/01/29     ��ʼ�汾

* ����   : MCU:stc89c52      ����:    MHz
* ����   �� ʹ�ô���ʵ�ֶ������� 
*******************************************************************************/
#include "uart.h"
#include "mmi.h"

unsigned char State;		 //��ʾ״̬��־λ

/*******************************************************************************
* ������	: Delay10ms
* ����	    : ��ʱ����
* �������  : x x��10����     
* ���ز���  : ��
*******************************************************************************/
void Delay10ms(unsigned char x)		//@11.0592MHz
{
	unsigned char i, j,y;
	for(y = 0;y<x;y++)
	{
		i = 18;
		j = 235;
		do
		{
			while (--j);
		} while (--i);
	}
}
/*******************************************************************************
* ������	: KeyProcess
* ����	    : ����������
* �������  : key   ������ֵ���������룩   
* ���ز���  : ��
*******************************************************************************/
void KeyProcess(unsigned char key)
{
    switch (State)
    {
        case FIRSTUISTATE_1:
            FirstUI_1(key);
            break;
        case FIRSTUISTATE_2:
            FirstUI_2(key);
            break;
        case FIRSTUISTATE_3:
            FirstUI_3(key);
            break;
        case SECONDUISTATE_1:
            SecondUI_1(key);
            break;
        case SECONDUISTATE_2:
            SecondUI_2(key);
            break;
    }
}

/*******************************************************************************
* ������	: RemapKey
* ����	    : �������뷵��
* �������  : ��     
* ���ز���  : Keyreturn  ����ָ��������
*******************************************************************************/
int RemapKey(void)
{
	unsigned char Keyreturn = 0;

	if(key_1 == 0)  //-------key_1
	{
		Delay10ms(1);
		if(key_1 == 0)
		{
			Keyreturn = RETURNKEY_1;
			while(!key_1);  //�ȴ������ͷ�
		
		}
	}	
	if(key_2 == 0)	//   key_2
	{
		Delay10ms(1);
		if(key_2 == 0)
		{
			Keyreturn = RETURNKEY_2;
			while(!key_2);  //�ȴ������ͷ�
		
		}
	}
	if(key_3 == 0)   //   key_3
	{
		Delay10ms(1);
		if(key_3 == 0)
		{
			Keyreturn = RETURNKEY_3;
			while(!key_3);  //�ȴ������ͷ�
		
		}
	}	
	if(key_4 == 0)	//  key_4
	{
		Delay10ms(1);
		if(key_4 == 0)
		{
			Keyreturn = RETURNKEY_4;
			while(!key_4);  //�ȴ������ͷ�
		
		}
	}
	
	return Keyreturn;					 
}

/*******************************************************************************
* ������	: Init_UI
* ����	    : ��ʼ������
* �������  : ��     
* ���ز���  : ��
*******************************************************************************/
void Init_UI()
{
	State = FIRSTUISTATE_1;
    UART_Send_Str("    ****************************\n");
	UART_Send_Str("    *      ��ʼ���ɹ�          *\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    *         Welcome          *\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    *   Intelligent Control    *\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    ****************************\n");
	UART_Send_Enter();
	UART_Send_Enter();
	UART_Send_Enter();
	Delay10ms(50);
    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    *          �� 1            *\n");
	UART_Send_Str("    *             2            *\n");
	UART_Send_Str("    *             3            *\n");
	UART_Send_Str("    *                          *\n");
	UART_Send_Str("    *                    ȷ��  *\n");
	UART_Send_Str("    ****************************\n");
	UART_Send_Enter();
	UART_Send_Enter();
	UART_Send_Enter();
}

/*******************************************************************************
* ����	    : ������ʾ
* �������  : key    
* ���ز���  : ��
*******************************************************************************/
void FirstUI_1(unsigned char key)
{

	if (key == RETURNKEY_1)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *             1            *\n");
		UART_Send_Str("    *          �� 2            *\n");
		UART_Send_Str("    *             3            *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                    ȷ��  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = FIRSTUISTATE_2;
			
	}
}

void FirstUI_2(unsigned char key)
{
	if (key == RETURNKEY_1)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *             1            *\n");
		UART_Send_Str("    *             2            *\n");
		UART_Send_Str("    *          �� 3            *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                    ȷ��  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = FIRSTUISTATE_3;	
	}
	if (key == RETURNKEY_2)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *          �� 1            *\n");
		UART_Send_Str("    *             2            *\n");
		UART_Send_Str("    *             3            *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                    ȷ��  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = FIRSTUISTATE_1;			
	}
	if (key == RETURNKEY_3)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    *          �� 1            *\n");
		UART_Send_Str("    *             2            *\n");
		UART_Send_Str("    * �Ѿ��������ѡ��   ����  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = SECONDUISTATE_1;		
	}
}

void FirstUI_3(unsigned char key)
{
	if (key == RETURNKEY_2)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *             1            *\n");
		UART_Send_Str("    *          �� 2            *\n");
		UART_Send_Str("    *             3            *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                    ȷ��  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = FIRSTUISTATE_2;		
	}
}

void SecondUI_1(unsigned char key)
{
	if (key == RETURNKEY_2)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    *             1            *\n");
		UART_Send_Str("    *          �� 2            *\n");
		UART_Send_Str("    * �Ѿ��������ѡ��   ����  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = SECONDUISTATE_2;		
	}
	if (key == RETURNKEY_4)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *          �� 1            *\n");
		UART_Send_Str("    *             2            *\n");
		UART_Send_Str("    *             3            *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                    ȷ��  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = FIRSTUISTATE_1;		
	}

}

void SecondUI_2(unsigned char key)
{
	if (key == RETURNKEY_1)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    *          �� 1            *\n");
		UART_Send_Str("    *             2            *\n");
		UART_Send_Str("    * �Ѿ��������ѡ��   ����  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = SECONDUISTATE_1;		
	}
	if (key == RETURNKEY_4)
	{
	    UART_Send_Str("    *********�� ӭ ѡ ��********\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *          �� 1            *\n");
		UART_Send_Str("    *             2            *\n");
		UART_Send_Str("    *             3            *\n");
		UART_Send_Str("    *                          *\n");
		UART_Send_Str("    *                    ȷ��  *\n");
		UART_Send_Str("    ****************************\n");
		UART_Send_Enter();
		UART_Send_Enter();
		UART_Send_Enter();
		State = FIRSTUISTATE_1;		
	}

}