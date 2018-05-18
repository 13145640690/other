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
*�ļ���   : device_key.c
*����     : �����豸
*����ʱ�� : 2013.8.17
********************************************************************************
*/


#include "system.h"


#define ShortInterval			3		//�̰��������ģ����õ���3
#define LongInterval			40		//������������
#define DoubleHitInterval	    10		//��ֹ����˫���󶯽���

static byte idata ScanValueSave = invalid;    //��һ�ΰ����洢ֵ
static byte idata ScanCounter = 0;            //�������½��ļ�����
static byte idata DoubleHitCounter = 0;       //��ֹ����˫���󶯽��ļ�����



/*******************************************************************************
* ������	: RemapKey
* ����	    : �̰���ӳ��
* �������  : scanValue:ɨ��ֵ
* ���ز���  : �̰�����ӳ��ֵ
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/27       ��ʼ�汾
*******************************************************************************/
static byte RemapKey(byte scanValue) 
{
    switch(scanValue)
    {
        case 0x77:
            return(12);
        case 0x7B:
            return(8);
        case 0x7D:
            return(4);
        case 0x7E:
            return(0);
        case 0xB7:
            return(13);
        case 0xBB:
            return(9);
        case 0xBD:
            return(5);
        case 0xBE:
            return(1);
        case 0xD7:
            return(14);
        case 0xDB:
            return(10);
        case 0xDD:
            return(6);
        case 0xDE:
            return(2);
        case 0xE7:
            return(15);
        case 0xEB:
            return(11);
        case 0xED:
            return(7);
        case 0xEE:
            return(3);
        default:
            return(invalid);
    }
}



/*******************************************************************************
* ������	: RemapLongKey
* ����	    : ��������ӳ��
* �������  : scanValue ɨ��ֵ
* ���ز���  : ��������ӳ��ֵ
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/27       ��ʼ�汾
*******************************************************************************/
static byte RemapLongKey(byte scanValue) 
{
    switch(scanValue)
    {
        case 0x77:
            return(0x30);
        case 0x7B:
            return(0x31);
        case 0x7D:
            return(0x32);
        case 0x7E:
            return(0x33);
        case 0xB7:
            return(0x34);
        case 0xBB:
            return(0x35);
        case 0xBD:
            return(0x36);
        case 0xBE:
            return(0x37);
        case 0xD7:
            return(0x38);
        case 0xDB:
            return(0x39);
        case 0xDD:
            return(0x3A);
        case 0xDE:
            return(0x3B);
        case 0xE7:
            return(0x3C);
        case 0xEB:
            return(0x3D);
        case 0xED:
            return(0x3E);
        case 0xEE:
            return(0x3F);
        default:
            return(invalid);
    }	
}

/*****************************************************************************
* ������	: ScanPin
* ����	    : P1��4*4���󰴼�ɨ��
* �������  : ��
* ���ز���  : byte���Ͱ���ɨ��ֵ
*****************************************************************************/
static byte ScanPin(void)
{
    byte scanValue;
	
    P1 = 0x0F;                      //P17~P14�õ�
    Delay(1);                       //��ʱ���ȴ���ƽ�ȶ�
    scanValue = P1;                 //��ȡ��4λ����ֵ
	
    P1 = 0xF0;                      //P17~P14�õ�
    Delay(1);	                    //��ʱ���ȴ���ƽ�ȶ�
    scanValue = scanValue | P1 ;    //��ȡ����λ����ֵ�������λ�ϲ�
	
    return(scanValue);              //����ֵ
}

/*******************************************************************************
* ������	: KeySystemTickService
* ����	    : ����ɨ�������򣬼��10mSһ��ɨ���ȡ������Ϣ
* �������  : ��
* ���ز���  : �׳��������ְ���ֵ��Ϣ
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/27       ��ʼ�汾
*******************************************************************************/
void KeySystemTickService(void) 
{
    byte scanValue;

    scanValue = ScanPin();                     //��ȡ���󰴼�ֵ

    if (scanValue == invalid)                  //�ж��Ƿ��ͷŰ���
    {
        if (DoubleHitCounter)                  //��ֹ˫��������
        {
            DoubleHitCounter--;
            ScanCounter = 0;
            ScanValueSave = invalid;
            return;
        }
        
        if (ScanValueSave == invalid)           //�жϰ���ֵ�Ƿ���Ч
        {
            ScanCounter = 0;
            return;
        }
            
        if (ScanCounter == LongInterval)        //�ж�Ϊ�����������ͳ�������Ϣ 
        {
            PostMessage(KeyMessageType, RemapLongKey(ScanValueSave)); 
        } 
        else if (ScanCounter > ShortInterval)   //�ж�Ϊ�̰��������Ͷ̰�����Ϣ 
        {
            PostMessage(KeyMessageType, RemapKey(ScanValueSave));
        }
        ScanCounter = 0;                        
        ScanValueSave = invalid;
        DoubleHitCounter = DoubleHitInterval;   //�趨��ֹ˫������ֵ
    } 
    else                                        //��⵽����ֵ
    {
        ScanCounter++;
	
        if (ScanCounter == 1)                   //�洢��һ�ΰ���ֵ
        {
            ScanValueSave = scanValue;
        } 
        else if (ScanCounter == 2)              //�жϰ���ֵ�Ƿ���Ч
        {
            if (scanValue != ScanValueSave)
            {
                ScanValueSave = invalid;
                ScanCounter = 0;
            }
        }
        else if (ScanCounter >= LongInterval)   //��ֹ����ֵ���ѭ��
        {
            ScanCounter = LongInterval;
        }
    }
}






