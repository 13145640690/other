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
*�ļ���   : device.h
*����     : �豸��ͷ�ļ�
*����ʱ�� : 2013.8.17
********************************************************************************
*/

#ifndef __DEVICE_H
#define __DEVICE_H


/*���������Լ��������޸�*/
typedef enum 
{
    AddKey                  = 0x00,
    AddLongKey              = 0x30,
    
    SubKey                  = 0x04,
    SubLongKey              = 0x34,

    AssistUpKey             = 0x01,
    AssistUpLongKey         = 0x31,

    AssistDownKey           = 0x05,
    AssistDownLongKey       = 0x35,
    
    SaveKey                 = 0x02,
    SaveLongKey             = 0x32,

    TextBoxFocusKey         = 0x06,
    FormFocusLongKey        = 0x36,
    
    StartKey                = 0x03,
    StartLongKey            = 0x33,
    
    StopKey                 = 0x07,
    StopLongKey             = 0x37
}Key;

typedef enum 
{
    TimerSystemTickHandle   = 0,        //ϵͳ�����д���
    TimerMessageHandle      = 1	        //��ѭ����Ϣ�д���
}TimerhandleMode;	

typedef struct
{
    byte Second;                        //��
    byte Minute;                        //��
    byte Hour;                          //ʱ
    ushort Day;                         //��
}Rtc;

typedef enum
{
    SystemTick10000,
    SystemTick1000,
    SystemTick100
}SystemTick;


extern Rtc idata RtcEntity;

extern void KeySystemTickService(void);

extern void RtcSystemTickService(void);

extern void TimerSystemTickService(void);


extern void InitializeRtc(void);

extern void InitializeUsart(void);

extern void InitializeSystemTick(void);



#endif

