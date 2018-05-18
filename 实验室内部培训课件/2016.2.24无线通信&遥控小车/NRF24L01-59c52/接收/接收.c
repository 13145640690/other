#include <reg52.H>
#include "uart.h"
#include "NRF24L01.h"

#define uchar unsigned char
#define uint unsigned int

/*******************************************************************************
* �������� : ������
* �������� : 
* ������� : 
* ���ز��� : 
* ������� : 
*******************************************************************************/


void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main(void)
{
	//�뵽ͷ�ļ����޸����ݵĿ�ȣ��Ա�֤ƥ��
	uchar i = 0;
	uchar a[Rx_Data_Width] = 0;//�����û������������յ������ݱ����ڴ�
	
	UartInit();
	init_NRF24L01() ;
	
	UART_Send_Str("��ʼ������Ϣ\r\n\r\n\r\n");
	UART_Send_Str("Recive: ");
	
	while(1)
	{
		if(NRF24L01_RxPacket(a))
		{
//			UART_Send_Str("Recive: ");
			
			for(i=0;i<3;i++)
			{
				UART_Send_Byte(a[i]);
			}
			//�ж�Tx_DS,���ģ������Ӳ���������û�д��ڡ�LED����ʾ
			UART_Send_Str("\r\n");
//			Delay500ms()	;
	  }
		 
	}	

}	