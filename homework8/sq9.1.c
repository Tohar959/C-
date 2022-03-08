#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#define arraysize 50
void main()
{
	char str[arraysize];
	char tav;
	char* ptr;
	printf("pls enter sentence :");
	gets(str);
	ptr = &str;
	while (*ptr!=0)
	{
		tav = *ptr;
		*ptr = *(ptr + 1);
		*(ptr + 1) = tav;
		ptr=ptr+2;
	}
	puts(str);



}

