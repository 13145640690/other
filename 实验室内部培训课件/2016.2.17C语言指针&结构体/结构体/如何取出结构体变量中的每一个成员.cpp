#include <stdio.h>


struct Student
{
    int age;
	float score;
	char sex;
};


int main (void)
{
	struct Student st = {80, 66.7, 'B'};  //��ʼ��  �����ͬʱ����ֵ
	struct Student *pst = &st;
	pst->age = 78;  //�ڶ��ַ�ʽ    
	st.score = 66.7f;  //��һ�ַ�ʽ   66.7��C������Ĭ����double���ͣ����ϣ��ʵ��һ��ʵ����float���ͣ��������ĩβ��f��F

	printf ("%d %f\n",st.age, pst->score );

    return 0;
}

