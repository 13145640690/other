/*
********************************************************************************
*                                Ƕ��ʽ΢ϵͳ
*                               msOS-mcu51-v0.1
*
*                               ʵ�õ�Ƭ��ϵͳ
*                               McuSystem(MS3.3)
*                               
*                              ��оƬ:STC89C52
*                           ��������οƼ����޹�˾
*
*                                ����:����ΰ
*                                ����:������
*                                ��ʶ:wangsw
*
*                                QQ:26033613
*                               QQȺ:291235815
*                        �Ա���:http://52edk.taobao.com
*                      ��̳:http://gongkong.eefocus.com/bbs/
*                ����:http://forum.eet-cn.com/BLOG_wangsw317_1268.HTM
********************************************************************************
*�ļ���   : system.h
*����     : ϵͳ��ȫ��ͷ�ļ�
*����ʱ�� : 2013.8.17
********************************************************************************
*/


#ifndef __SYSTEM_H
#define __SYSTEM_H


#include <string.h>
#include <stdio.h>
#include "STC15F2K60S2.h"

/*
1�����Ͷ������C#����������C#��׼�����õ�Ϊint
2��char��C#��Ϊ16bit��unicode��keil C��Ϊ8bit
*/
//8bit���ֽ�
typedef signed char         sbyte;
typedef unsigned char       byte;

//16bit˫�ֽ�
//typedef signed short        short         Ĭ�ϣ�����Ҫ����
typedef unsigned short      ushort;

//32bit���ֽ�
//typedef signed long         long;         Ĭ�ϣ�����Ҫ����
typedef unsigned long       ulong;

//�ַ���
typedef signed char *       string;

//��������
typedef unsigned char       bool;

typedef void (*function)(void);
#define Function(address)  (*((function)address))()






/*���峣��*/
#define true                1
#define false               0
#define null                ((void *) 0)
#define invalid             0xFF
#define MainClock           22118400        //MCUϵͳʱ��

#define SetBit(data, offset)     data |= 1 << offset     //��λĳλΪ1
#define ResetBit(data, offset)   data &= ~(1 << offset)  //��λĳλΪ0
#define GetBit(data, offset)     ((data >> offset) &0x01) //��ȡĳλ

#define UshortToByte1(data)     ((byte *)(&data))[0]//��ȡushort�������ݸ�λ     
#define UshortToByte0(data)     ((byte *)(&data))[1]//��ȡushort�������ݵ�λ

#define GetMessageType(message)            UshortToByte1(message)
#define GetMessageData(message)            UshortToByte0(message)

#define Assert(express)  if (!(express)){printf("\nASSERT: " #express "\n");while(1);}   //(void)0


typedef enum
{
    KeyMessageType      = 0xFF,         //������Ϣ����
    UsartMessageType    = 0xFE,         //������Ϣ���� 
    Int0MessageType     = 0xFD,         //�ⲿ�ж�0��Ϣ����
    Int1MessageType     = 0xFC,         //�ⲿ�ж�1��Ϣ����
    //���������
    TimerMessageType    = 0xF0          //��Сֵ,��������ֵС����
}MessageType;


#include "device.h"

extern void EnterCritical(void);
extern void ExitCritical(void);

extern void InitializeMessageQueue(void);
extern void PostMessage(MessageType messageType, ushort value);
extern ushort PendMessageQueue(void);

extern void Delay(ushort delayClock);

extern void DelayUs(ushort delayTime);

extern void DelayMs(ushort delayTime);


extern byte HexToAscii(byte hex);

extern void PutByte(byte byte);
extern void PutString(string string, byte sum);

extern bool TimerStart(TimerhandleMode handleMode, ushort delay, function callBackFunction);
extern void TimerStop(byte id);

#endif
