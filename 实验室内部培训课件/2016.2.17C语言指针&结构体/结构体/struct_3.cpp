/*
ʱ�䣺2016��2��16��22:45:40
���ã��ṹ����ָ�������
��������ͨ������ṹ��ָ�������Ϊ�������ε����⣺ָ�������->;��ͨ������.�ķ�ʽ
*/

# include <stdio.h>
# include <string.h>

struct Student
{	
	int sid;
	char name[200];
	int age;
}; //�ֺŲ���ʡ

void f(struct Student * pst);   //��ֵ
void g(struct Student st);      //���
void g2(struct Student *pst);   //���

int main(void)
{
	struct Student st;  //�Ѿ�Ϊst��������ڴ�

	f(&st);
//	g(st);   //���ַ�ʽ���ڴ� ��ʱ�� ���Ƽ���������208���ֽ�  ��Ϊ������������ı��������͹�ȥ��
	g2(&st);

	//printf("%d %s %d\n", st.sid, st.name, st.age);

	return 0;
}

//���ַ�ʽ���ڴ� ��ʱ�� ���Ƽ���������208���ֽ�   ��Ϊst����ռ208���ֽ�
void g(struct Student st)
{
	printf("%d %s %d\n", st.sid, st.name, st.age);	
}

//��ʾ��ָ���ǿ��
void g2(struct Student *pst)
{
	printf("%d %s %d\n", pst->sid, pst->name, pst->age);	//��pst��ָ�������ʱ�����->�ķ�ʽ
}


//��ֵ������������4���ֽ�
void f(struct Student * pst)
{
	(*pst).sid = 99;
	strcpy(pst->name, "zhangsan");
	pst->age = 22;
}