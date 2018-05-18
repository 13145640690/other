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
*�ļ���   : device_rtc.c
*����     : ����ʱ���豸
*����ʱ�� : 2013.8.17
********************************************************************************
*/


#include "system.h"


Rtc idata RtcEntity;            //����Rtcʵ��

void RtcSystemTickService(void) 
{
    static byte idata Counter = 0;
    
    if(++Counter == 100)        //ϵͳ����10msһ�Σ�1S��Ҫ100��
    {
        Counter = 0;
        RtcEntity.Second++;
    }
    
    if(RtcEntity.Second == 60)
    {
        RtcEntity.Second = 0;
        RtcEntity.Minute++;
    }
    
    if(RtcEntity.Minute == 60)
    {
        RtcEntity.Minute = 0;
        RtcEntity.Hour++;
    }
    
    if(RtcEntity.Hour == 24)
    {
        RtcEntity.Hour = 0;
        RtcEntity.Day++;
    }	
}

void InitializeRtc(void) 
{
    RtcEntity.Second = 0;
    RtcEntity.Minute = 0;
    RtcEntity.Hour = 0;
    RtcEntity.Day = 0;
}

