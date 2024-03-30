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
	// ������ �����Ҷ� �÷��̾� ������ �����ϰ� �ȴ�
	_tagPlayer tPlayer = {};

	// �÷��̾� �̸��� �Է¹޴´�
	cout << "�̸� : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;

	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ���" << endl;
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
			strcpy_s(tPlayer.strJobName, "���");
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
			strcpy_s(tPlayer.strJobName, "�ü�");
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
			strcpy_s(tPlayer.strJobName, "������");
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


	//���� ����
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	// ���
	strcpy_s(tMonsterArr[0].strName, "���");
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

	// Ʈ��
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
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

	// �巡��
	strcpy_s(tMonsterArr[2].strName, "�巡��");
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

	// �������� �Ǹ��� ������ ����� �����Ѵ�
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	// ���
	strcpy_s(tStoreWeapon[0].strName, "���");
	strcpy_s(tStoreWeapon[0].strTypeName, "��");
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 600;
	strcpy_s(tStoreWeapon[0].strDesc, "������ ������� ��. ������ ����� �� �ִ�.");
	// Ȱ
	strcpy_s(tStoreWeapon[1].strName, "����Ȱ");
	strcpy_s(tStoreWeapon[1].strTypeName, "Ȱ");
	tStoreWeapon[1].iMin = 10;
	tStoreWeapon[1].iMax = 20;
	tStoreWeapon[1].iPrice = 1800;
	tStoreWeapon[1].iSell = 1000;
	strcpy_s(tStoreWeapon[1].strDesc, "������ ������� Ȱ. �߸������.");
	// ������
	strcpy_s(tStoreWeapon[2].strName, "����������");
	strcpy_s(tStoreWeapon[2].strTypeName, "������");
	tStoreWeapon[2].iMin = 30;
	tStoreWeapon[2].iMax = 50;
	tStoreWeapon[2].iPrice = 5000;
	tStoreWeapon[2].iSell = 3000;
	strcpy_s(tStoreWeapon[2].strDesc, "������ ������� ������.");

	while (1)
	{
		system("cls");
		cout << "*********** �κ� ***********" << endl;
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ���" << endl;

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
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;
				cout << "���� �����ϼ��� : ";
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
						cout << "*********** ���� ***********" << endl;
						break;
					case MT_NORMAL:
						cout << "*********** ���� ***********" << endl;
						break;
					case MT_HARD:
						cout << "*********** ����� ***********" << endl;
						break;
					default:
						cout << "�߸� �����Ͽ����ϴ�." << endl;
						break;
					}

					// �÷��̾� ������ ����Ѵ�
					cout << "========== Player ==========" << endl;
					cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobName << endl;
					cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << endl;
					cout << "���ݷ� : " << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax
						<< "\t���� : " << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << endl;
					cout << "ü�� : " << tPlayer.iHP << "/" << tPlayer.iHPMax
						<< "\t���� : " << tPlayer.iMP << "/" << tPlayer.iHPMax << endl;
					cout << "������� : " << tPlayer.tInventory.iGold << "Gold" << endl;

					cout << "========== Monster ==========" << endl;
					cout << "�̸� : " << tMonster.strName << endl;
					cout << "���� : " << tMonster.iLevel << "\t����ġ : " << tMonster.iExp << endl;
					cout << "���ݷ� : " << tMonster.iAttackMin << "-" << tMonster.iAttackMax
						<< "\t���� : " << tMonster.iArmorMin << "-" << tMonster.iArmorMax << endl;
					cout << "ü�� : " << tMonster.iHP << "/" << tMonster.iHPMax
						<< "\t���� : " << tMonster.iMP << "/" << tMonster.iHPMax << endl;
					cout << "ȹ�����ġ : " << tMonster.iExp << endl;
					cout << "ȹ���� : " << tMonster.iGoldMin << "-" << tMonster.iGoldMax << endl << endl;

					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� �����ϼ���" << endl;

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
						// �÷��̾ ���͸� �����Ѵ�
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;
						//�ּ� ������� 1�̴�
						// ���� ������ : ���ǽ� ? true�϶��� : false�϶���;
						iDamage = iDamage < 1 ? 1 : iDamage;

						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << "��" << tMonster.strName << "����" << iDamage << "���ظ� �������ϴ�" << endl;
						// ���Ͱ� �׾������
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << "���Ͱ� ����߽��ϴ�." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "����ġ�� ȹ���߽��ϴ�." << endl;
							cout << iGold << "Gold�� ȹ���߽��ϴ�." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							system("pause");
							break;
						}
						// ���Ͱ� �÷��̾ �����Ѵ�.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << "��" << tPlayer.strName << "����" << iDamage << "���ظ� �������ϴ�" << endl;
						// �÷��̾ �׾��� ���
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << "�÷��̾ ����߽��ϴ�." << endl;

							// �÷��̾�� ����ġ�� ��带 �Ҵ´�

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << "����ġ�� �Ҿ����ϴ�." << endl;
							cout << iGold << "Gold�� �Ҿ����ϴ�." << endl;

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
				cout << "*********** ���� ***********" << endl;
				cout << "1. ����" << endl;
				cout << "2. ��" << endl;
				cout << "3. �ڷΰ���" << endl;
				cout << "������ �����ϼ��� : ";
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
						cout << "*********** ������� ***********" << endl;
						
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". �̸� : " << tStoreWeapon[i].strName << "\t���� : " << tStoreWeapon[i].strTypeName << endl;
							cout << "���ݷ� : " << tStoreWeapon[i].iMin << "-" << tStoreWeapon[i].iMax << endl;
							cout << "�ǸŰ��� : " << tStoreWeapon[i].iPrice << "\t���Ű��� : " << tStoreWeapon[i].iSell << endl;
							cout << "���� : " << tStoreWeapon[i].strDesc << endl << endl;
						}

						cout << STORE_WEAPON_MAX + 1 << ". �ڷΰ���" << endl;
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << "Gold" << endl;
						cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "������ �������� �����ϼ��� : ";
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
							cout << "�߸� �����Ͽ����ϴ�." << endl;
							system("pause");
							continue;
						}

						// ���� �Ǹ� ��� �迭�� �ε����� ���Ѵ�
						int iWeaponIndex = iMenu - 1;

						// �κ��丮�� �� á���� �˻��Ѵ�
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "������ �� á���ϴ�." << endl;
							system("pause");
							continue;
						}
						//���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "���� �ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}
						// �κ��丮�� ���⸦ �־��ش�
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];
						tPlayer.tInventory.iItemCount++;

						// ��带 �����Ѵ�
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << "�������� �����߽��ϴ�." << endl;
						system("pause");
					}

					break;
				case SM_ARMOR:
					while (1)
					{
						system("cls");
						cout << "*********** ������ ***********" << endl;

						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". �̸� : " << tStoreArmor[i].strName << "\t���� : " << tStoreArmor[i].strTypeName << endl;
							cout << "���� : " << tStoreArmor[i].iMin << "-" << tStoreArmor[i].iMax << endl;
							cout << "�ǸŰ��� : " << tStoreArmor[i].iPrice << "\t���Ű��� : " << tStoreArmor[i].iSell << endl;
							cout << "���� : " << tStoreArmor[i].strDesc << endl << endl;
						}

						cout << STORE_ARMOR_MAX + 1 << ". �ڷΰ���" << endl;
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << "Gold" << endl;
						cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "������ �������� �����ϼ��� : ";
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
							cout << "�߸� �����Ͽ����ϴ�." << endl;
							system("pause");
							continue;
						}

						// ���� �Ǹ� ��� �迭�� �ε����� ���Ѵ�
						int iArmorIndex = iMenu - 1;

						// �κ��丮�� �� á���� �˻��Ѵ�
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "������ �� á���ϴ�." << endl;
							system("pause");
							continue;
						}
						//���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "���� �ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}
						// �κ��丮�� ���⸦ �־��ش�
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];
						tPlayer.tInventory.iItemCount++;

						// ��带 �����Ѵ�
						tPlayer.tInventory.iGold -= tStoreWeapon[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << "�������� �����߽��ϴ�." << endl;
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
				cout << "*********** �κ��丮 ***********" << endl;
				// �÷��̾� ������ ����Ѵ�
				cout << "========== Player ==========" << endl;
				cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobName << endl;
				cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << endl;
				cout << "���ݷ� : " << tPlayer.iAttackMin << "-" << tPlayer.iAttackMax
					<< "\t���� : " << tPlayer.iArmorMin << "-" << tPlayer.iArmorMax << endl;
				cout << "ü�� : " << tPlayer.iHP << "/" << tPlayer.iHPMax
					<< "\t���� : " << tPlayer.iMP << "/" << tPlayer.iHPMax << endl;
				cout << "������� : " << tPlayer.tInventory.iGold << "Gold" << endl;
				cout << "========== ��񸮽�Ʈ ==========" << endl;
				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << i + 1 << ". �̸� : " << tPlayer.tInventory.tItem[i].strName << "\t���� : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "���ݷ� : " << tPlayer.tInventory.tItem[i].iMin << "-" << tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "�ǸŰ��� : " << tPlayer.tInventory.tItem[i].iPrice << "\t���Ű��� : " << tPlayer.tInventory.tItem[i].iSell << endl;
					cout << "���� : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
				}
				system("pause");
				break;
			}

			break;
		default:
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			break;
		}

	}


	return 0;
}