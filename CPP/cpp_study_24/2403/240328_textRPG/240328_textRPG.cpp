#include <iostream>
#include <time.h>

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 5

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
	BT_NON,
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

int main()
{
	srand((unsigned int)time(0));

	int iMenu;
	// 게임을 시작할때 플레이어 정보를 설정하게 된다
	_tagPlayer tPlayer = {};

	// 플레이어 이름을 입력받는다
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;

	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요" << endl;
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;
		}
		switch (iJob)
		{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobName, "기사");
			tPlayer.iAttackMin = 5;
			tPlayer.iAttackMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iArmorMin = 20;
			tPlayer.iHPMax = 500;
			tPlayer.iHP = 500;
			tPlayer.iMPMax = 100;
			tPlayer.iMP = 100;
			break;
		case JOB_ARCHER:
			strcpy_s(tPlayer.strJobName, "궁수");
			tPlayer.iAttackMin = 10;
			tPlayer.iAttackMax = 15;
			tPlayer.iArmorMin = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iHPMax = 400;
			tPlayer.iHP = 400;
			tPlayer.iMPMax = 200;
			tPlayer.iMP = 200;
			break;
		case JOB_WIZARD:
			strcpy_s(tPlayer.strJobName, "마법사");
			tPlayer.iAttackMin = 10;
			tPlayer.iAttackMax = 15;
			tPlayer.iArmorMin = 5;
			tPlayer.iArmorMin = 10;
			tPlayer.iHPMax = 300;
			tPlayer.iHP = 300;
			tPlayer.iMPMax = 300;
			tPlayer.iMP = 300;
			break;
		}

	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;


	//몬스터 생성
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	// 고블린
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// 트롤
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// 드래곤
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	// 상점에서 판매할 아이템 목록을 생성한다
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	// 목검
	strcpy_s(tStoreWeapon[0].strName, "목검");
	strcpy_s(tStoreWeapon[0].strTypeName, "검");
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 600;
	strcpy_s(tStoreWeapon[0].strDesc, "나무로 만들어진 검. 누구나 사용할 수 있다.");
	// 활
	strcpy_s(tStoreWeapon[1].strName, "나무활");
	strcpy_s(tStoreWeapon[1].strTypeName, "활");
	tStoreWeapon[1].iMin = 10;
	tStoreWeapon[1].iMax = 20;
	tStoreWeapon[1].iPrice = 1800;
	tStoreWeapon[1].iSell = 1000;
	strcpy_s(tStoreWeapon[1].strDesc, "나무로 만들어진 활. 잘만들었다.");
	// 지팡이
	strcpy_s(tStoreWeapon[2].strName, "나무지팡이");
	strcpy_s(tStoreWeapon[2].strTypeName, "지팡이");
	tStoreWeapon[2].iMin = 30;
	tStoreWeapon[2].iMax = 50;
	tStoreWeapon[2].iPrice = 5000;
	tStoreWeapon[2].iSell = 3000;
	strcpy_s(tStoreWeapon[2].strDesc, "나무로 만들어진 지팡이.");

	while (1)
	{
		system("cls");
		cout << "*********** 로비 ***********" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요" << endl;

		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP:
			while (1)
			{
				system("cls");
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (iMenu == MT_BACK)
					break;
				
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (1) {
					system("cls");
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
					default:
						cout << "잘못 선택하였습니다." << endl;
						break;
					}

					// 플레이어 정보를 출력한다
					cout << "========== Player ==========" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax
						<< "\t방어력 : " << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHP << "/" << tPlayer.iHPMax
						<< "\t마나 : " << tPlayer.iMP << "/" << tPlayer.iHPMax << endl;
					cout << "보유골드 : " << tPlayer.tInventory.iGold << "Gold" << endl;

					cout << "========== Monster ==========" << endl;
					cout << "이름 : " << tMonster.strName << endl;
					cout << "레벨 : " << tMonster.iLevel << "\t경험치 : " << tMonster.iExp << endl;
					cout << "공격력 : " << tMonster.iAttackMin << "-" << tMonster.iAttackMax
						<< "\t방어력 : " << tMonster.iArmorMin << "-" << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << "/" << tMonster.iHPMax
						<< "\t마나 : " << tMonster.iMP << "/" << tMonster.iHPMax << endl;
					cout << "획득경험치 : " << tMonster.iExp << endl;
					cout << "획득골드 : " << tMonster.iGoldMin << "-" << tMonster.iGoldMax << endl << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요" << endl;

					cin >> iMenu;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == BT_BACK)
						break;

					switch (iMenu)
					{
					case BT_ATTACK:
					{
						// 플레이어가 몬스터를 공격한다
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;
						//최소 대미지는 1이다
						// 삼항 연산자 : 조건식 ? true일때값 : false일때값;
						iDamage = iDamage < 1 ? 1 : iDamage;

						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << "가" << tMonster.strName << "에게" << iDamage << "피해를 입혔습니다" << endl;
						// 몬스터가 죽었을경우
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << "몬스터가 사망했습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "경험치를 획득했습니다." << endl;
							cout << iGold << "Gold를 획득했습니다." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							system("pause");
							break;
						}
						// 몬스터가 플레이어를 공격한다.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << "가" << tPlayer.strName << "에게" << iDamage << "피해를 입혔습니다" << endl;
						// 플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << "플레이어가 사망했습니다." << endl;

							// 플레이어는 경험치와 골드를 잃는다

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << "경험치를 잃었습니다." << endl;
							cout << iGold << "Gold를 잃었습니다." << endl;

							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");
					}
						break;
					}

				}
			}

			break;
		case MM_STORE:
			while (1)
			{
				system("cls");
				cout << "*********** 상점 ***********" << endl;
				cout << "1. 무기" << endl;
				cout << "2. 방어구" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요 : ";
				cin >> iMenu;


				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (iMenu == IT_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					while (1)
					{
						system("cls");
						cout << "*********** 무기상점 ***********" << endl;
						
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". 이름 : " << tStoreWeapon[i].strName << "\t종류 : " << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 : " << tStoreWeapon[i].iMin << "-" << tStoreWeapon[i].iMax << endl;
							cout << "판매가격 : " << tStoreWeapon[i].iPrice << "\t구매가격 : " << tStoreWeapon[i].iSell << endl;
							cout << "설명 : " << tStoreWeapon[i].strDesc << endl << endl;
						}

						cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << "Gold" << endl;
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;
						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						// 상점 판매 목록 배열의 인덱스를 구한다
						int iWeaponIndex = iMenu - 1;

						// 인벤토리가 꽉 찼는지 검사한다
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "가방이 꽉 찼습니다." << endl;
							system("pause");
							continue;
						}
						//돈이 부족한 경우
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
							continue;
						}
						// 인벤토리에 무기를 넣어준다
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];
						tPlayer.tInventory.iItemCount++;

						// 골드를 차감한다
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << "아이템을 구매했습니다." << endl;
						system("pause");
					}

					break;
				case SM_ARMOR:
					while (1)
					{
						system("cls");
						cout << "*********** 방어구상점 ***********" << endl;

						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". 이름 : " << tStoreArmor[i].strName << "\t종류 : " << tStoreArmor[i].strTypeName << endl;
							cout << "방어력 : " << tStoreArmor[i].iMin << "-" << tStoreArmor[i].iMax << endl;
							cout << "판매가격 : " << tStoreArmor[i].iPrice << "\t구매가격 : " << tStoreArmor[i].iSell << endl;
							cout << "설명 : " << tStoreArmor[i].strDesc << endl << endl;
						}

						cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << "Gold" << endl;
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;
						else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						// 상점 판매 목록 배열의 인덱스를 구한다
						int iArmorIndex = iMenu - 1;

						// 인벤토리가 꽉 찼는지 검사한다
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "가방이 꽉 찼습니다." << endl;
							system("pause");
							continue;
						}
						//돈이 부족한 경우
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
							continue;
						}
						// 인벤토리에 무기를 넣어준다
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];
						tPlayer.tInventory.iItemCount++;

						// 골드를 차감한다
						tPlayer.tInventory.iGold -= tStoreWeapon[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << "아이템을 구매했습니다." << endl;
						system("pause");
					}
					break;
				}

			}
			break;
		case MM_INVENTORY:
			while (1)
			{
				system("cls");
				cout << "*********** 인벤토리 ***********" << endl;
				// 플레이어 정보를 출력한다
				cout << "========== Player ==========" << endl;
				cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
				cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
				cout << "공격력 : " << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax
					<< "\t방어력 : " << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << endl;
				cout << "체력 : " << tPlayer.iHP << "/" << tPlayer.iHPMax
					<< "\t마나 : " << tPlayer.iMP << "/" << tPlayer.iHPMax << endl;
				cout << "보유골드 : " << tPlayer.tInventory.iGold << "Gold" << endl;
				cout << "========== 장비리스트 ==========" << endl;
				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << i + 1 << ". 이름 : " << tPlayer.tInventory.tItem[i].strName << "\t종류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << "-" << tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "판매가격 : " << tPlayer.tInventory.tItem[i].iPrice << "\t구매가격 : " << tPlayer.tInventory.tItem[i].iSell << endl;
					cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
				}
				system("pause");
				break;
			}

			break;
		default:
			cout << "잘못 선택하였습니다." << endl;
			break;
		}

	}


	return 0;
}