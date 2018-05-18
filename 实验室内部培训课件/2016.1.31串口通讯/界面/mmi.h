
/*******************************************************************************
* �ļ��� : MMI.H

* ����   :����ͷ�ļ�
           
*******************************************************************************/

#ifndef __MMI_H__
#define __MMI_H__

#define RETURNKEY_1	 1
#define RETURNKEY_2	 2
#define RETURNKEY_3	 3
#define RETURNKEY_4	 4

#define FIRSTUISTATE_1   5
#define FIRSTUISTATE_2   6
#define FIRSTUISTATE_3	 7
#define SECONDUISTATE_1	 8
#define SECONDUISTATE_2	 9

/*��ʱ*/
void Delay10ms(unsigned char x);		//@11.0592MHz
/*��������ֵ*/
int RemapKey(void);
/*�������봦��*/
void KeyProcess(unsigned char key);
/*��ʼ������*/
void Init_UI();

void FirstUI_1(unsigned char key);
void FirstUI_2(unsigned char key);
void FirstUI_3(unsigned char key);
void SecondUI_1(unsigned char key);
void SecondUI_2(unsigned char key);

#endif /*__MMI_H__*/


