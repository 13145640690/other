/*
	ʱ�䣺2016��2��17��08:48:01
	���ã�malloc������̬�ڴ�ķ��䡣
*/
# include <stdio.h>
# include <malloc.h>

int main(void)
{
	int a[5] = {4, 10, 2, 8, 6};
	
	int len;
	printf("����������Ҫ���������ĳ���: len = ");
	scanf("%d", &len);
	int * pArr = (int *)malloc(sizeof(int) * len);  //��һ��malloc����ֻ�ܷ��ص�һ���ֽڵĵ�ַ�����ǹ涨   �ڶ����������ϵͳ������Ӧ�ĵ�ַ  
	//Ȼ���ǰ�ĸ��ֽڵĵ�ַ������PArr
//	*pArr = 4;  //������ a[0] = 4;
//	pArr[1] = 10; //������a[1] = 10;
//	printf("%d %d\n", *pArr, pArr[1]);

	//���ǿ��԰�pArr����һ����ͨ������ʹ��
	for (int i=0; i<len; ++i)
		scanf("%d", &pArr[i]);

	for (i=0; i<len; ++i)
		printf("%d\n", *(pArr+i));

	
	free(pArr);  //��pArr������Ķ�̬�����20���ֽڵ��ڴ��ͷ�

	return 0;
}