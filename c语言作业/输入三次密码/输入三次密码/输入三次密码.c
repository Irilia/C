#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char password[20] = {"0"};
	char cipher[] = { "123456" };
	int i = 0;
	int a = 0;
	int count = 0;
	printf("���������룺");
	scanf("%s", password);
	for(i=0;i<3;i++)
	{ 
		
	    if (a = strcmp(password, cipher)==0)
	    {
		printf("��½�ɹ���");
		break;
	    }
	    else if (a = strcmp(password, cipher)!=0)
	    {
		    count++;
			if (count == 3)
			{ 
				printf("������������˳�����"); 
				break;
			}
			printf("��������������������룺");
		    scanf("%s", password);
			
			
	    }
		
	}
	

	system("pause");
	return 0;
}