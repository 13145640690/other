/*
********************************************************************************
*                                Ƕ��ʽ΢ϵͳ
*                               msOS for Mcu51
*
*                               ��оƬ:MCU51
*                           ��������οƼ����޹�˾
*
*                                ����:����ΰ
*                                ����:������
*                                ��ʶ:Wangsw
*
*                                QQ:26033613
*                               QQȺ:291235815
*                        �Ա���:http://52edk.taobao.com
*                      ��̳:http://gongkong.eefocus.com/bbs/
*                    Google��Դ:https://code.google.com/p/msos/
*                ����:http://forum.eet-cn.com/BLOG_wangsw317_1268.HTM
********************************************************************************
*�ļ���     : app.c
*����       : Ӧ�ò㣬ϵͳ���
*ԭ��       : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/23       ��ʼ�汾
********************************************************************************
*/

#include "system.h"
#include "app.h"


void Initialize(void)
{			
    InitializeRtc();
    
	  InitializeUsart();

    InitializeMmi();

    InitializeMessageQueue();

    InitializeSystemTick();
}



/*******************************************************************************
* ������	: main
* ����	    : ϵͳ�������
* �������  : ��
* ���ز���  : ��
********************************************************************************
*�汾     ����            ����            ˵��
*V0.1    Wangsw        2013/09/23       ��ʼ�汾
*******************************************************************************/
unsigned int text = 0 ;
int main(void)
{
    ushort idata messageData;
    byte idata type;
    byte idata value;
	
    Initialize();
	
	
    while(true)
    {
        messageData = PendMessageQueue();
		
        type = GetMessageType(messageData);
        value = GetMessageData(messageData);
		
		text = value ;
		printf("%d\n",text);
		
        switch(type)						
        {
            case KeyMessageType:                //״̬���뺯��ָ�뷽ʽ��ѡһ��
#if 0
                (*MmiFunction)(value);             //����ָ�봦��ʽ
#else
                KeyProcess(value);              //״̬������ʽ
#endif
                break;
#if 1
            case UsartMessageType:
                UsartProcess(value);
                break;
#endif
            //�������Ϣ��������
            default:                //�����ʱ������
                Function(messageData);
                break;
        }
    }
}





