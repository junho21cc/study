#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int target_number, target_type;
	int result_number[100], result_type, count = 0;

	printf("���� ������ �Է��ϼ���: ");
	scanf("%d%d", &target_number, &target_type);

	printf("�ٲ� ������ �Է��ϼ���");
	scanf("%d", &result_type);

	if (target_type == 10)
	{
		if (result_type < target_type)
		{
			while (1)
			{
				result_number[count] = target_number % result_type;
				target_number = target_number / result_type;
				count++;
				if (target_number < result_type)
				{
					result_number[count] = target_number;
					break;
				}
			}
		}
	}

	for (int i = count; i >= 0; i--)
	{
		printf("%d", result_number[i]);
	}

	return 0;
}