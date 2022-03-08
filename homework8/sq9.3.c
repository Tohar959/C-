#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#define arraysize 50
#define wordSize 10
void hidinigword(char str1[], char wordstr[]);
void main()
{
	char str[arraysize];
	char word[wordSize];
	printf("pls enter sentence :\n");
	gets(str);
	printf("pls enter word :");
	gets(word);
	hidinigword(str, word);
	puts(str);

}
void hidinigword(char str1[], char wordstr[])
{
	char* ptrstr = &str1;
	int leg = strlen(wordstr);
	while (ptrstr != '\0')
	{

		ptrstr = strstr(str1, wordstr);
		if (ptrstr)
		{
			for (int i = 0; i < leg; i++)
			{
				*(ptrstr + i) = '*';

			}
		}

	}
}
