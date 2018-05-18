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
*�ļ���   : system.c
*����     : ϵͳӦ���ļ�
*����ʱ�� : 2013.8.17
********************************************************************************
*/

#include "system.h"



#define MessageBufferSum 4                              //������Ϣ���д洢����
static ushort idata MessageBuffer[MessageBufferSum];

struct MessageQueue                                     //����һ�����нṹ��
{                                                       
    ushort  * Start;                                    //ָ��ָ����п�ʼ
    ushort  * End;                                      //ָ��ָ����н���
    ushort  * In;                                       //ָ�����һ����Ϣ
    ushort  * Out;                                      //ָ��ȡ��һ����Ϣ
    byte      Size;                                     //���г���
    byte      Entries;                                  //��Ϣ����
} ;
static struct MessageQueue idata MessageQueue;



static bool EaSave;
static byte CriticalNesting = 0;
byte code HextoAscii[16] = 
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

void Delay(ushort delayClock)
{
	while(delayClock--);
}

void DelayUs(ushort delayTime)
{
    while(delayTime--);
}

void DelayMs(ushort delayTime)
{
	while(delayTime--)
	{
		DelayUs(1000);
	}
}

byte HexToAscii(byte hex)
{
	Assert(hex < 16);                   //���ԣ�һ���������󣬾�ִ��
	return HextoAscii[hex];
}


/*******************************************************************************
* ������	: EnterCritical
* ����	    : �����ٽ�̬����ֹ�жϲ���
* �������  : ��
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/10/11       ��ʼ�汾
*******************************************************************************/
void EnterCritical(void)
{
    if (CriticalNesting == 0)   //��һ���ٽ�̬Ƕ�ף�����ȫ���жϼĴ������ر��ж�
    {
        EaSave = EA;
        EA = 0;
    }
    CriticalNesting++;    
}


/*******************************************************************************
* ������	: ExitCritical
* ����	    : �˳��ٽ�̬���ָ�ԭ��״̬
* �������  : ��
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/10/11       ��ʼ�汾
*******************************************************************************/
void ExitCritical(void)
{
    if (CriticalNesting > 0)
    {
        CriticalNesting--;
        if (CriticalNesting == 0)//��һ���ٽ�̬Ƕ�ף��ָ�ԭ״̬
        {
            EA = EaSave;
        }
    }
}

void InitializeMessageQueue(void)
{
    MessageQueue.Start = &MessageBuffer[0];
    MessageQueue.End = &MessageBuffer[MessageBufferSum];
    MessageQueue.In = MessageQueue.Start;
    MessageQueue.Out = MessageQueue.Start;
    MessageQueue.Size = MessageBufferSum;
    MessageQueue.Entries = 0;
}

/*******************************************************************************
* ������	: PostMessage
* ����	    : ������Ϣ
* �������  : message: ��Ϣ����, 
*             value:��Ϣֵ��MessageTimer����Ϊ16bit��ַ�����������¶���8bit����         
* ���ز���  : ��
*******************************************************************************/
void PostMessage(MessageType messageType, ushort value)
{
	Assert(MessageQueue.Entries < MessageQueue.Size);//���ԣ��ж���Ϣ�����Ƿ�����
    
    EnterCritical();            //����״̬ ���ر��жϷ�ֹ��������ϵ�����Ϣ����

    if (messageType == TimerMessageType)  //�����ʱ��������������Ϣ�������⴦��
    {
        *MessageQueue.In = value;         //�����ʱ�����ݵ��Ǻ���ָ�룬ֱ�Ӹ�ֵ
    }
    else                                      //������Ϣ������Ϣ��������Ϣֵ�ϲ�
    {
        UshortToByte1(*MessageQueue.In) = messageType;//�����͸�����Ϣ�ߵ�ַ
        UshortToByte0(*MessageQueue.In) = value & 0xFF;//��ֵ������Ϣ�͵�ַ
    }
    
	MessageQueue.In++;                                          //��Ϣ����ڼ�һ        
    MessageQueue.Entries++;                                     //��Ϣ������һ 

    if(MessageQueue.In == MessageQueue.End)                     //�����ѭ��
    {
        MessageQueue.In = MessageQueue.Start;
    }
    
	ExitCritical();                                         //�ظ��ر��ж�ǰ״̬
}

/*******************************************************************************
* ������	: PendMessageQueue
* ����	    : �ȴ���Ϣ
* �������  : ��       
* ���ز���  : ��
*******************************************************************************/
ushort PendMessageQueue(void)
{    
    ushort message;
    
    while(MessageQueue.Entries == 0)//����Ƿ������Ϣ
    {
      //�Ƽ������ι��
    };          

    //EnterCritical();              //���Բ����ٽ�̬����ֻ��һ���ط���ȡ

    message = *MessageQueue.Out++;

    MessageQueue.Entries--;
    
    if (MessageQueue.Out == MessageQueue.End) 
    {
        MessageQueue.Out = MessageQueue.Start;
    }

    //ExitCritical();
    return(message);
}


