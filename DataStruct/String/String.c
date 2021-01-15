#include "String.h"

char* StrCpy(char* dest, char* src)
{
	for (int i = 0; i < strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return dest;
}

int StrCmp(char* str1, char* str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				return 1;
			}
		}
		return 0;
	}
}

char* StrReverse(char* string)
{
	int size = strlen(string);
	char temp;

	for (int i = 0; i < size; i++) 
	{
		temp = string[i];
		string[i] = string[(size - 1) - i];
		string[(size - 1) - i] = temp;
	}
	return string;
}