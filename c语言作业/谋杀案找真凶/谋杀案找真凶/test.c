#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()//�ĸ���
{
	char arr[4] = { 'A','B','C','D' };
	//������˵���滰��һ����˵�˼ٻ�,3+0=3��
	//a;����a��b����c��c����d��d��c˵����
	int a = 0;
	for (a = 0; a < 4; a++)//a=0
	{
		if (((arr[a] != 'A') + (arr[a] == 'C') + (arr[a] == 'D') +( arr[a] != 'D')) == 3)//1  2  3  2
		{
			printf("�����ǣ�%c\n", arr[a]);
		}
	}
	system("pause");
	return 0;
}