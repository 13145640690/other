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
*�ļ���   : device_timer.c
*����     : �����ʱ���豸
*����ʱ�� : 2013.8.17
********************************************************************************
*/

#include "system.h"

#define TimerSum		0x08     //�����ʱ������
static byte idata State = 0;    //������ǼĴ�������λ��ǣ���8·������Ƿ����

struct Timer                     //Timer���ͣ�������ʱʱ��ͻص���������
{
    ushort  Delay;
    function CallBackFuction;
};
static struct Timer idata Block[TimerSum];  //�洢��ʱ���ص�����Timer��������
static TimerhandleMode idata Mode;          //����ģʽ




void TimerSystemTickService(void)
{
    byte i = 0;
    byte stateCopy;
    
    if (State == 0x00) return;      //������Ϊ�գ�����

    EnterCritical();
  
    stateCopy = State;              //����һ�ݾ�����
    while (stateCopy)	
    {
        if ((stateCopy & 0x01) == 1) 
        {
            if ((--Block[i].Delay) == 0) //�����ݼ�����ʱ
            {
                if (GetBit(Mode, i))     //��ȡ����ģʽ����������ʽ
                    //�׳���Ϣ����ѭ����ִ��
                    PostMessage(TimerMessageType, (ushort)(Block[i].CallBackFuction));
                else 
                    (*(Block[i].CallBackFuction))(); //ֱ����ϵͳ�����д���
                    
                ResetBit(State, i);     //�������������һ·��ʱ����̬�˳�                 
            }
        }
        stateCopy = stateCopy >> 1;
        i++;
    }
    ExitCritical();
}

/*****************************************************************************
* ������	: TimerStart
* ����	    : �����ʱ��
* �������  : handleMode: ���ִ���ʽ��һ��ֱ���ڽ����ж��д����ʺϷ��õ͵�,
*                         ��һ������Ϣ�д����ʺϴ�����øߵġ�
*           : delay:��ʱ����������ϵͳ����Ϊ��λ
*           : callBackFunction: �ص�ִ�к�������ʱ��ʱ��ִ�д˺�����
*             data:��Ϣֵ��MessageTimer����Ϊ32bit��ַ,���������¶���24bit����
* ���ز���  : byte���ͣ�����ID�ţ���0��ʼ����ʧ���򷵻�invalid(-1)
*****************************************************************************/
byte TimerStart(TimerhandleMode handleMode, ushort delay, function callBackFunction)
{
    byte i;
	unsigned int j;
    EnterCritical();
    for(i = 0; i < TimerSum; i++) 
    {
        if(!GetBit(State, i)) 
        {			
            Block[i].Delay = delay;                                 //��ʱʱ��
            Block[i].CallBackFuction = callBackFunction;            //�ص�����
            if(handleMode)                                          //����ģʽ
            {
                SetBit(Mode, i);
				j = Mode;
				printf("Mode = %d\n",j);
            } 
            else 
            {
                ResetBit(Mode, i);
				j = Mode;
				printf("Mode = %d\n",j);
            }
            SetBit(State, i); 			//��λ����
            ExitCritical();
            return(i);
        }
    }
    ExitCritical();
    return(invalid);
}


/*******************************************************************************
* ������	: TimerStop
* ����	    : �ر�ĳһ·��ʱ��
* �������  : id TimerStartִ�к󷵻ص�id��0��1��2...
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/25       ��ʼ�汾
*******************************************************************************/
void TimerStop(byte id) 
{
    if (id >= TimerSum) return;     
        
    EnterCritical();
	
    ResetBit(State, id);            //��λ����λ
	
    ExitCritical();
}


