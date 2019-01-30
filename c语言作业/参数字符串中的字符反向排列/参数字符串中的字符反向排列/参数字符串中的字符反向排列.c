#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int i = 0;
void reverse_string(char * string)
{
	int stb = 0;
	while(i<5/2)
	{
		stb = *string;
		*string = *(string + 4-2*i);
		*(string + 4-2*i) = stb;
		i++;
	   reverse_string(string + 1);
	}
}

int main()
{
	char arr[5] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		scanf("%c", &arr[i]);
		getchar();
	}
	reverse_string(arr);
	for(i = 0;i < sz; i++)
	{
    	printf("%c",arr[i]);
	}
	system("pause");
	return 0;
}