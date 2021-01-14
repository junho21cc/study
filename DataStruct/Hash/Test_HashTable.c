#include "HashTable.h"

int main()
{
	HashTable* HT = HT_CreateHashTable(3);

	for (int i = 0; i < 3; i++)
	{
		HT_Set(HT, 100 + i);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("Data %d, HashIndex = %d\n", HT_Get(HT, 100 + i), HT_Hash(100 + i, 3));
	}

	HT_DestroyHashTable(HT);

	return 0;
}