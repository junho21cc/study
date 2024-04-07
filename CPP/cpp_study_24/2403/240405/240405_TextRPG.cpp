#include <iostream>
#include <time.h>

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 5
#define LEVEL_MAX 10


using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BT_NONE,
	BT_ATTACK,
	BT_BACK
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};
struct _tagItem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem tItem[INVENTORY_MAX];
	int iItemCount;
	int iGold;
};

struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagItem tEquip[EQ_MAX];
	bool bEquip[EQ_MAX];
	_tagInventory tInventory;
};

struct _tagMonster
{
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};

struct _tagLevelUpStatus
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;
};

// 레벨업에 필요한 경험치 목록을 만든다
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

_tagLevelUpStatus g_tLvUpTable[JOB_END] = {};
// ====================================================================================

int OutputMainMenu();
int InputInt();
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonster);
int OutputMapMenu();
void SetPlayer(_tagPlayer* pPlayer);
int SelectJob();
_tagMonster CreateMonster(char* pName, int iAttackMin, int iAttackMax, int ArmorMin, int ArmorMax, int iHp, int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax);
void SetMonster(_tagMonster* pMonsterArr);
void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonster, int iMenu);
void OutputBattleTag(int iMenu);
void OutputPlayer(_tagPlayer* pPlayer);
void OutputMonster(_tagMonster* pMonster);
int OutputBattleMenu();
void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster);
_tagLevelUpStatus CreateLvUpStatus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHPMin, int iHPMax, int iMPMin, int iMPMax);
void RunStore(_tagInventory* pInventory, _tagItem* pWeapon, _tagItem* pArmor);
void RunInventory(_tagPlayer* pPlayer);
int OutputStoreMenu();
void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount, int iStoreType);
_tagItem CreateItem(char* pName, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell, char* pDesc);
EQUIP ComputeEquipType(ITEM_TYPE eType);
int OutputInventory(_tagPlayer* pPlayer);

int main()
{
	srand((unsigned int)time(0));
	bool bLoop = true;
	// 게임을 시작할때 플레이어 정보를 설정하게 한다
	_tagPlayer tPlayer = {};

	// 플레이어 정보를 정의한다
	SetPlayer(&tPlayer);

	// 몬스터를 생성한다
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	SetMonster(tMonsterArr);

	// 경험치 테이블을 생성한다
	g_tLvUpTable[JOB_KNIGHT] = CreateLvUpStatus(4, 10, 8, 16, 50, 100, 10, 20);
	g_tLvUpTable[JOB_ARCHER] = CreateLvUpStatus(10, 15, 5, 10, 30, 60, 30, 50);
	g_tLvUpTable[JOB_WIZARD] = CreateLvUpStatus(15, 20, 3, 7, 20, 40, 50, 100);

	// 상점에서 판맹할 아이템을 목록을 생성한다
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	tStoreWeapon[0] = CreateItem((char*)"목검", IT_WEAPON, 5, 10, 1000, 500, (char*)"나무로 만든 검");
	tStoreWeapon[1] = CreateItem((char*)"돌검", IT_WEAPON, 10, 20, 2000, 1000, (char*)"돌로 만든 검");
	tStoreWeapon[2] = CreateItem((char*)"철검", IT_WEAPON, 50, 100, 10000, 5000, (char*)"철로 만든 검");
	
	
	tStoreArmor[0] = CreateItem((char*)"천갑옷", IT_ARMOR, 2, 5, 1000, 500, (char*)"천으로 만든 갑옷");
	tStoreArmor[1] = CreateItem((char*)"가죽갑옷", IT_ARMOR, 4, 10, 2000, 1000, (char*)"천으로 만든 갑옷");
	tStoreArmor[2] = CreateItem((char*)"철갑옷", IT_ARMOR, 50, 100, 15000, 8000, (char*)"천으로 만든 갑옷");

	while (bLoop)
	{
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr);
			break;
		case MM_STORE:
			RunStore(&tPlayer.tInventory, tStoreWeapon, tStoreArmor);
			break;
		case MM_INVENTORY:
			RunInventory(&tPlayer);
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}
	return 0;
}

// ====================================================================================

int OutputMainMenu()
{
	system("cls");
	cout << "*********** 로비 ***********" << endl;
	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 가방" << endl;
	cout << "4. 종료" << endl;
	cout << "메뉴를 선택하세요" << endl;

	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;
	return iMenu;
}

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonster)
{
	bool bLoop = true;
	while (bLoop)
	{
		int iMenu = OutputMapMenu();
		
		if (MT_BACK == iMenu)
		{
			bLoop = false;
			continue;
		}

		// 전투시작
		RunBattle(pPlayer, pMonster, iMenu);
	}
}

int OutputMapMenu()
{
	system("cls");
	cout << "1. 쉬움" << endl;
	cout << "2. 보통" << endl;
	cout << "3. 어려움" << endl;
	cout << "4. 뒤로가기" << endl;
	cout << "맵을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MM_NONE;
	return iMenu;
}

void SetPlayer(_tagPlayer* pPlayer)
{
	// 플레이어 이름을 입력받는다
	cout << "이름 : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);

	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "기사");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMPMax = 100;
		pPlayer->iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "궁수");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMPMax = 200;
		pPlayer->iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "마법사");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMPMax = 300;
		pPlayer->iMP = 300;
		break;
	}
}

int SelectJob()
{
	int iJob = JOB_NONE;

	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요" << endl;
		iJob = InputInt();
		if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;
		}
	}
	return iJob;
}

_tagMonster CreateMonster(char* pName, int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax)
{
	_tagMonster tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHP;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr)
{
	pMonsterArr[0] = CreateMonster((char*)"고블린", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster((char*)"오크", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster((char*)"드래곤", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonster, int iMenu)
{
	_tagMonster tMonster = pMonster[iMenu - 1];

	while (true)
	{
		system("cls");
		OutputBattleTag(iMenu);

		// 플레이어 출력
		OutputPlayer(pPlayer);

		// 몬스터 출력
		OutputMonster(&tMonster);

		switch (OutputBattleMenu())
		{
		case BT_ATTACK:
			Battle(pPlayer, &tMonster);
			break;
		case BT_BACK:
			return;

		}
	}
}

void OutputBattleTag(int iMenu)
{
	switch (iMenu)
	{
	case MT_EASY:
		cout << "*********** 쉬움 ***********" << endl;
		break;
	case MT_NORMAL:
		cout << "*********** 보통 ***********" << endl;
		break;
	case MT_HARD:
		cout << "*********** 어려움 ***********" << endl;
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer)
{
	cout << "========== Player ==========" << endl;
	cout << "이름 : " << pPlayer->strName << "\t직업 : " << pPlayer->strJobName << endl;
	cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
	
	// 장착무기 있는지 확인
	if (pPlayer->bEquip[EQ_WEAPON] == true)
		cout << "공격력 : " << pPlayer->iAttackMin << "+" << pPlayer->tEquip[EQ_WEAPON].iMin << " - " << pPlayer->iAttackMax << "+" << pPlayer->tEquip[EQ_WEAPON].iMax;
	else
		cout << "공격력 : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax;
	
	// 장착방어구 있는지 확인
	if (pPlayer->bEquip[EQ_ARMOR] == true)
		cout << "\t방어력 : " << pPlayer->iArmorMin << "+" << pPlayer->tEquip[EQ_ARMOR].iMin << " - " << pPlayer->iArmorMax << "+" << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	else
		cout << "\t방어력 : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	cout << "체력 : " << pPlayer->iHP << "/" << pPlayer->iHPMax << "\t마나 : " << pPlayer->iMP << "/" << pPlayer->iMPMax << endl;
	
	// 장착무기 있는지 확인
	if (pPlayer->bEquip[EQ_WEAPON])
		cout << "장착무기 : " << pPlayer->tEquip[EQ_WEAPON].strName;
	else
		cout << "장착무기 : 없음";
	
	// 장착방어구 있는지 확인
	if (pPlayer->bEquip[EQ_ARMOR])
		cout << "장착방어구 : " << pPlayer->tEquip[EQ_ARMOR].strName;
	else
		cout << "\t장착방어구 : 없음" << endl;
	cout << "보유골드 : " << pPlayer->tInventory.iGold << "Gold" << endl;
}

void OutputMonster(_tagMonster* pMonster)
{
	cout << "========== Monster ==========" << endl;
	cout << "이름 : " << pMonster->strName << endl;
	cout << "레벨 : " << pMonster->iLevel << "\t경험치 : " << pMonster->iExp << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax
		<< "\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHP << "/" << pMonster->iHPMax
		<< "\t마나 : " << pMonster->iMP << "/" << pMonster->iMPMax << endl;
	cout << "획득경험치 : " << pMonster->iExp << endl;
	cout << "획득골드 : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl;
}

int OutputBattleMenu()
{
	cout << "1. 공격" << endl;
	cout << "2. 도망가기" << endl;
	cout << "메뉴를 선택하세요" << endl;

	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= BT_NONE || iMenu > BT_BACK)
		return BT_NONE;
	return iMenu;
}

void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster)
{
	int iAttackMin = pPlayer->iAttackMin, iAttackMax = pPlayer->iAttackMax;
	int iArmorMin = pMonster->iArmorMin, iArmorMax = pMonster->iArmorMax;

	if (pPlayer->bEquip[EQ_WEAPON])
	{
		iAttackMin += pPlayer->tEquip[EQ_WEAPON].iMin;
		iAttackMax += pPlayer->tEquip[EQ_WEAPON].iMax;
	}

	int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
	int iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

	int iDamage = iAttack - iArmor;
	//최소 대미지는 1이다
	// 삼항 연산자 : 조건식 ? true일때값 : false일때값;
	iDamage = iDamage < 1 ? 1 : iDamage;

	pMonster->iHP -= iDamage;

	cout << pPlayer->strName << "가" << pMonster->strName << "에게" << iDamage << "피해를 입혔습니다" << endl;
	// 몬스터가 죽었을경우
	if (pMonster->iHP <= 0)
	{
		cout << pMonster->strName << "몬스터가 사망했습니다." << endl;

		pPlayer->iExp += pMonster->iExp;
		int iGold = (rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) + pMonster->iGoldMin);
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << "경험치를 획득했습니다." << endl;
		cout << iGold << "Gold를 획득했습니다." << endl;

		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		// 레벨업 체크
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])
		{
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];


			pPlayer->iLevel++;

			cout << "레벨업 하였습니다" << endl;
			// 능력치 상승
			int iHPUp = rand() % (g_tLvUpTable[pPlayer->eJob].iHPMax - g_tLvUpTable[pPlayer->eJob - 1].iHPMin + 1) + g_tLvUpTable[pPlayer->eJob - 1].iHPMin;
			int iMPUp = rand() % (g_tLvUpTable[pPlayer->eJob].iMPMax - g_tLvUpTable[pPlayer->eJob - 1].iMPMin + 1) + g_tLvUpTable[pPlayer->eJob - 1].iMPMin;

			pPlayer->iAttackMin += g_tLvUpTable[pPlayer->eJob].iAttackMin;
			pPlayer->iAttackMax += g_tLvUpTable[pPlayer->eJob].iAttackMax;
			pPlayer->iArmorMin += g_tLvUpTable[pPlayer->eJob].iArmorMin;
			pPlayer->iArmorMax += g_tLvUpTable[pPlayer->eJob].iArmorMax;
			pPlayer->iHPMax += iHPUp;
			pPlayer->iMPMax += iHPUp;
			// 레벨업하면 체력과 마나를 다시 채워준다
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}
		system("pause");
	}
	// 몬스터가 플레이어를 공격한다.
	iAttackMin = pMonster->iAttackMin, iAttackMax = pMonster->iAttackMax;
	iArmorMin = pPlayer->iArmorMin, iArmorMax = pPlayer->iArmorMax;

	if (pPlayer->bEquip[EQ_ARMOR])
	{
		iArmorMin += pPlayer->tEquip[EQ_ARMOR].iMin;
		iArmorMax += pPlayer->tEquip[EQ_ARMOR].iMax;
	}
	iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
	iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

	iDamage = iAttack - iArmor;
	iDamage = iDamage < 1 ? 1 : iDamage;

	pPlayer->iHP -= iDamage;

	cout << pMonster->strName << "가" << pPlayer->strName << "에게" << iDamage << "피해를 입혔습니다" << endl;
	// 플레이어가 죽었을 경우
	if (pPlayer->iHP <= 0)
	{
		cout << pPlayer->strName << "플레이어가 사망했습니다." << endl;

		// 플레이어는 경험치와 골드를 잃는다

		int iExp = pPlayer->iExp * 0.1f;
		int iGold = pPlayer->tInventory.iGold * 0.1f;

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << iExp << "경험치를 잃었습니다." << endl;
		cout << iGold << "Gold를 잃었습니다." << endl;

		pPlayer->iHP = pPlayer->iHPMax;
		pPlayer->iMP = pPlayer->iMPMax;
	}
	system("pause");
}

_tagLevelUpStatus CreateLvUpStatus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHPMin, int iHPMax, int iMPMin, int iMPMax)
{
	_tagLevelUpStatus tLvUptable = {};

	tLvUptable.iAttackMin = iAttackMin;
	tLvUptable.iAttackMax = iAttackMax;
	tLvUptable.iArmorMin = iArmorMin;
	tLvUptable.iArmorMax = iArmorMax;
	tLvUptable.iHPMin = iHPMin;
	tLvUptable.iHPMax = iHPMax;
	tLvUptable.iMPMin = iMPMin;
	tLvUptable.iMPMax = iMPMax;

	return tLvUptable;
}

_tagItem CreateItem(char* pName, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell, char* pDesc)
{
	_tagItem tItem = {};

	strcpy_s(tItem.strName, pName);
	strcpy_s(tItem.strDesc, pDesc);

	tItem.eType = eType;

	switch (eType)
	{
	case IT_WEAPON:
		strcpy_s(tItem.strTypeName, "무기");
		break;
	case IT_ARMOR:
		strcpy_s(tItem.strTypeName, "방어구");
		break;
	}
	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;
}

void RunStore(_tagInventory* pInventory, _tagItem* pWeapon, _tagItem* pArmor)
{
	while (true)
	{
		switch (OutputStoreMenu())
		{
		case SM_WEAPON:
			BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, SM_WEAPON);
			break;
		case SM_ARMOR:
			BuyItem(pInventory, pArmor, STORE_ARMOR_MAX, SM_ARMOR);
			break;
		case SM_BACK:
			return;
		}

	}
}

int OutputStoreMenu()
{
	system("cls");
	cout << "*********** 상점 ***********" << endl;
	cout << "1. 무기" << endl;
	cout << "2. 방어구" << endl;
	cout << "3. 뒤로가기" << endl;
	cout << "상점을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= SM_NONE || iMenu > SM_BACK)
		return SM_NONE;

	return iMenu;
}

int OutputItemList(_tagInventory* pInventory, _tagItem* pStore, int iItemCount)
{
	for (int i = 0; i < iItemCount; i++)
	{
		cout << i + 1 << ". 이름 : " << pStore[i].strName << "\t종류 : " << pStore[i].strTypeName << endl;
		cout << "공격력 : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
		cout << "판매가격 : " << pStore[i].iPrice << "\t구매가격 : " << pStore[i].iSell << endl;
		cout << "설명 : " << pStore[i].strDesc << endl << endl;
	}

	cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl;
	cout << "보유금액 : " << pInventory->iGold << "Gold" << endl;
	cout << "남은공간 : " << INVENTORY_MAX - pInventory->iItemCount << endl;
	cout << "구입할 아이템을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > iItemCount + 1)
		return INT_MAX;
	return iMenu;
}

void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount, int iStoreType)
{
	while (true)
	{
		system("cls");
		switch (iStoreType)
		{
		case SM_WEAPON:
			cout << "무기상점" << endl;
			break;
		case SM_ARMOR:
			cout << "방어구 상점" << endl;
			break;
		}

		int iInput = OutputItemList(pInventory, pStore, iItemCount);

		if (iInput == INT_MAX)
		{
			cout << "잘못입력하였습니다" << endl;
			system("pause");
			continue;
		}
		else if (iInput == iItemCount + 1)
			break;

		// 상점 판매 목록 배열의 인덱스를 구한다
		int iIndex = iInput - 1;

		// 인벤토리가 꽉 찼는지 검사한다
		if (pInventory->iItemCount == INVENTORY_MAX)
		{
			cout << "가방이 꽉 찼습니다." << endl;
			system("pause");
			continue;
		}
		//돈이 부족한 경우
		else if (pInventory->iGold < pStore[iIndex].iPrice)
		{
			cout << "보유 금액이 부족합니다." << endl;
			system("pause");
			continue;
		}
		// 인벤토리에 무기를 넣어준다
		pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];
		pInventory->iItemCount++;

		// 골드를 차감한다
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << "아이템을 구매했습니다." << endl;
		system("pause");
	}
}

void RunInventory(_tagPlayer* pPlayer)
{
	while (1)
	{
		int iInput = OutputInventory(pPlayer);

		if (iInput == INT_MAX)
			continue;
		else if (iInput == pPlayer->tInventory.iItemCount + 1)
			break;
		// 아이템 인덱스를 구해준다.
		int idx = iInput - 1;

		// 제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를 결정한다
		EQUIP eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);

		if (pPlayer->bEquip[eq] == true)
		{
			_tagItem tSwap = pPlayer->tEquip[eq];
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}
		else
		{
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
			for (int i = idx; i < pPlayer->tInventory.iItemCount - 1; i++)
			{
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}
			pPlayer->tInventory.iItemCount--;

			pPlayer->bEquip[eq] = true;
		}
	}
}

int OutputInventory(_tagPlayer* pPlayer)
{
	system("cls");

	cout << "가방" << endl;

	OutputPlayer(pPlayer);
	// 장비 정보를 출력해준다
	cout << "========== 장비리스트 ==========" << endl;
	for (int i = 0; i < pPlayer->tInventory.iItemCount; i++)
	{
		cout << i + 1 << ". 이름 : " << pPlayer->tInventory.tItem[i].strName << "\t종류 : " << pPlayer->tInventory.tItem[i].strTypeName << endl;
		cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
		cout << "판매가격 : " << pPlayer->tInventory.tItem[i].iPrice << "\t구매가격 : " << pPlayer->tInventory.tItem[i].iSell << endl;
		cout << "설명 : " << pPlayer->tInventory.tItem[i].strDesc << endl << endl;
	}

	cout << pPlayer->tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
	cout << "장착할 아이템을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > pPlayer->tInventory.iItemCount + 1)
		return INT_MAX;

	return iMenu;
}

EQUIP ComputeEquipType(ITEM_TYPE eType)
{
	EQUIP eq;
	switch (eType)
	{
	case IT_WEAPON:
		eq = EQ_WEAPON;
		break;
	case IT_ARMOR:
		eq = EQ_ARMOR;
		break;
	}

	return eq;
}