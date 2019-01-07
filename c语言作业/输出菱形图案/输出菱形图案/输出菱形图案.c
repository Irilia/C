#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	for (a = 1; a <= 13; a++)
	{
		switch (a)
		{
		case 1:printf("      *       \n"); break;
		case 2:printf("     ***     \n"); break;
		case 3:printf("    *****    \n"); break;
		case 4:printf("   *******   \n"); break;
		case 5:printf("  *********  \n"); break;
		case 6:printf(" *********** \n"); break;
		case 7:printf("*************\n"); break;
		case 8:printf(" *********** \n"); break;
		case 9:printf("  *********  \n"); break;
		case 10:printf("   *******   \n"); break;
		case 11:printf("    *****    \n"); break;
		case 12:printf("     ***     \n"); break;
		case 13:printf("      *       \n"); break;
		}

	}
	system("pause");
	return 0;
}