#include "HashTable.h"

int main()
{
	HashTable* HT = HT_CreateHashTable(6151);

	
	HT_Set(HT, "AMUNOREANA");
	HT_Set(HT, "SDF");
	HT_Set(HT, "SDGDSSEGSDGSGD");
	HT_Set(HT, "SDGHSEFGDSHE");
	HT_Set(HT, "EGHSFSDFS");
	HT_Set(HT, "SEGDSFS");
	
	printf("Data %s, HashIndex = %d\n", HT_Get(HT, "AMUNOREANA"), HT_Hash("AMUNOREANA", 6151));
	printf("Data %s, HashIndex = %d\n", HT_Get(HT, "SDF"), HT_Hash("SDF", 6151));
	printf("Data %s, HashIndex = %d\n", HT_Get(HT, "SDGDSSEGSDGSGD"), HT_Hash("SDGDSSEGSDGSGD", 6151));
	printf("Data %s, HashIndex = %d\n", HT_Get(HT, "SDGHSEFGDSHE"), HT_Hash("SDGHSEFGDSHE", 6151));
	printf("Data %s, HashIndex = %d\n", HT_Get(HT, "EGHSFSDFS"), HT_Hash("EGHSFSDFS", 6151));
	printf("Data %s, HashIndex = %d\n", HT_Get(HT, "SEGDSFS"), HT_Hash("SEGDSFS", 6151));
	

	HT_DestroyHashTable(HT);

	return 0;
}