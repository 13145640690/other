/*
ʱ�䣺2016��2��16��22:02:19
���ã��ṹ���ʹ��
*/
# include <stdio.h>
# include <string.h>  //strcpy(st.name, "lisi");��Ҫ

struct Student
{	
	int sid;      //��������Ա
	char name[200];
	int age;
}; //�ֺŲ���ʡ

int main(void)
{
	struct Student st = {1000, "zhangsan", 20};
	printf("%d  %s  %d\n", st.sid, st.name, st.age);

	st.sid = 99;
	//st.name = "lisi";  //error
	strcpy(st.name, "lisi");//ע������
	st.age = 22;
	printf("%d  %s  %d\n", st.sid, st.name, st.age);  //Ҫʹ�ýṹ��ĳ�Ա����ʽ��������.��Ա��

	//printf("%d %s %d\n", st);  //error
	return 0;
}