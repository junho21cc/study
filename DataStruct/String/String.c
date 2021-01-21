#include <string.h>
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

char* StrReverse(char* str)
{
	int size = strlen(str);
	char temp;

	for (int i = 0; i < size / 2; i++)
	{
		temp = str[i];
		str[i] = str[(size - 1) - i];
		str[(size - 1) - i] = temp;
	}
	return str;
}
