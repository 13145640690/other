
/*******************************************************************************
* �ļ��� : MAIN.C

* �汾     ����            ����            ˵��
* V1.0                    2015/10/11       ��ʼ�汾

* ����   : MCU:      ����:    MHz
           
*******************************************************************************/


 #include<reg52.h>
 #include "uart.h"	
 #include<stdio.h>	

 extern unsigned char date;
 extern unsigned char flag;
 
 void main(void)
 {
 
   UartInit();
   while(1)
   {
//		UART_Send_Byte(0+48);	//����48ת����ASCII��
//		UART_Send_Str("abcde\n");
		UART_Put_Num(456) ;	 //��ӡ���֡��ֽ����456
		UART_Put_Num(456) ;
		str_to_u32(123456);
   }
 
 }