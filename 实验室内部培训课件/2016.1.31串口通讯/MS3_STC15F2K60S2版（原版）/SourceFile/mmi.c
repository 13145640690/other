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
*�ļ���   : mmi.c
*����     : �������
*����ʱ�� : 2013.8.17
********************************************************************************
*/


#include "system.h"
#include "app.h"


/*******************************************************************************
����Ϊ״̬����ʽ����
*******************************************************************************/
typedef enum
{
    WorkState = 1,
    SetupState = 2,
    ServiceState = 3
}MenuState;

static MenuState idata State = WorkState;

static void WorkStateProcess(Key key)
{
    printf("��ǰ��������: key = %c\n", key);
    if (key == '2')
    {
        printf("    �л�Ϊ���ý���\n");
        State = SetupState;
    }
}

static void SetupStateProcess(Key key)
{
    printf("��ǰ���ý���: key = %c\n", key);
    if (key == '3')
    {
        printf("    �л�Ϊά������\n");
        State = ServiceState;
    }     
}

static void ServiceStateProcess(Key key)
{
    printf("��ǰά������: key = %c\n", key);
    if (key == '1')
    {
        printf("    �л�Ϊ��������\n");
        State = WorkState;
    }  
}

/*******************************************************************************
* ������	: KeyProcess
* ����	    : ״̬������������
* �������  : key ��������
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/30       ��ʼ�汾
*******************************************************************************/
void KeyProcess(Key key)
{
    switch (State)
    {
        case WorkState:
            WorkStateProcess(key);
            break;
        case SetupState:
            SetupStateProcess(key);
            break;
        case ServiceState:
            ServiceStateProcess(key);
            break;
    }
}

/*******************************************************************************
����Ϊ����ָ�뷽ʽ����
*******************************************************************************/

void (*MmiFunction)(Key key);                           //���庯��ָ�����


/*******************************************************************************
* ������	: InitializeIdleForm
* ����	    : �����ʼ��
* �������  : ��
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/30       ��ʼ�汾
*******************************************************************************/
static void InitializeIdleForm(void)
{
    printf("\nmsOS-mcu51-v0.1(MS3.3) Start\n");
    printf("\ndate:2013.8.17\n");
    printf("\nHardware Plat:MCU51Series\n");
    printf("\Author: wangsw\n");
    printf("\n\n");
	
    printf("1:��������\n");
    printf("2:���ý���\n");
    printf("3:ά������\n");
	
    printf("Menu = idle\n");
    printf("Please press 1 , 2 or 3  to select menu\n");
}

//������������Ϊǰ��ĵ��ú���ģ��������޷�ʶ��������Ҫ����
static void WorkPointerProcess(Key key);
static void SetupPointerProcess(Key key);
static void ServicePointerProcess(Key key);

static void WorkPointerProcess(Key key)
{
    printf("��ǰ��������: key = %c\n", key);
    if (key == '2')
    {
        printf("    �л�Ϊ���ý���\n");
        MmiFunction = SetupPointerProcess;
    }
}

static void SetupPointerProcess(Key key)
{
    printf("��ǰ���ý���: key = %c\n", key);
    if (key == '3')
    {
        printf("    �л�Ϊά������\n");
        MmiFunction = ServicePointerProcess;
    }     
}

static void ServicePointerProcess(Key key)
{
    printf("��ǰά������: key = %c\n", key);
    if (key == '1')
    {
        printf("    �л�Ϊ��������\n");
        MmiFunction = WorkPointerProcess;
    }  
}

/*******************************************************************************
* ������	: InitializeMmi
* ����	    : MMI��ʼ��
* �������  : ��
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/30       ��ʼ�汾
*******************************************************************************/
void InitializeMmi(void)
{

    InitializeIdleForm();
	P1  = 0 ;
    MmiFunction = WorkPointerProcess;
}

/*******************************************************************************
* ������	: TimerCallBack
* ����	    : �����ʱ�����Ժ�����������ʱ������ѭ����ӡ��Ϣ
* �������  : ��
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/30       ��ʼ�汾
*******************************************************************************/
void TimerCallBack(void)
{
    printf("�����ʱ����ʱִ��\n");
    TimerStart(TimerMessageHandle, 1000, TimerCallBack);
}

/*******************************************************************************
* ������	: UsartProcess
* ����	    : ������Ϣ������
* �������  : value ��������
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/30       ��ʼ�汾
*******************************************************************************/
void UsartProcess(byte value)
{
    printf("Usart Receive = %x", (ushort)value);

    TimerCallBack();
}
