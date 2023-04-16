#include "pch.h"

void InitTable(int* table);
void GameStart();
void NumberSelect(int* table);
void Result(int* LottoNum, int* PlayerNum, int Count, bool Bonus);

int main()
{
	// ����, ���� ����
	srand((unsigned int)time(NULL));
	rand();

	int LottoNumbers[7] = { 0 };
	int PlayerNumbers[6] = { 0 };
	int count = 0;
	bool bonus = 0;

	InitTable(LottoNumbers);
	GameStart();
	NumberSelect(PlayerNumbers);
	Result(LottoNumbers, PlayerNumbers, count, bonus);

	return 0;
}

void InitTable(int* table)
{
	for (int i = 0; i < 3; i++)
	{
		table[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (table[i] == table[j])
			{
				i--;
				break;
			}
		}
	}
}

void GameStart()
{
	printf("***** �ζ� ���α׷� *****\n");
	printf("1�� : 6�� ��� ��ġ\n");
	printf("2�� : 5�� + ���ʽ� ��ġ\n");
	printf("3�� : 5�� ��ġ\n");
	printf("4�� : 4�� ��ġ\n");
	printf("5�� : 3�� ��ġ\n\n");
}

void NumberSelect(int* table)
{
	printf("1 ~ 45�� ���� 6���� ����ּ���.\n");

	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			printf("������ ����!\t\t");
			scanf_s("%d", &table[i]);
			printf("\n");
		}
		else
		{
			printf("%d �� ������ϴ�.\t", i);
			scanf_s("%d", &table[i]);
		}
		if (table[i] > 45 || table[i] < 1)
		{
			i--;
			printf("1 ~ 45 ������ ���ڸ� ����ּ���.\n");
		}
		for (int j = 0; j < i; j++)
		{
			if (table[i] == table[j])
			{
				i--;
				printf("�ߺ��� ���ڴ� ���� �Ұ����մϴ�.\n");
				break;
			}
		}
	}
}

void Result(int* LottoNum, int* PlayerNum, int Count, bool Bonus)
{
	printf("���� �� ���ڵ� :\t");
	for (int i = 0; i < 6; i++)
		printf("%d\t", PlayerNum[i]);
	printf("\n");

	printf("��÷ ��ȣ!! :\t\t");
	for (int i = 0; i < 7; i++)
	{
		if (i == 6)
			printf("���ʽ� ����!! : %d", LottoNum[6]);
		else
			printf("%d\t", LottoNum[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (LottoNum[6] == PlayerNum[j])
				Bonus = true;
			if (LottoNum[i] == PlayerNum[j])
				Count++;
		}
	}

	switch (Count)
	{
	case 0:
	case 1:
	case 2:
		printf("���Դϴ�...\n");
		break;
	case 3:
		printf("5���Դϴ�!\n");
		break;
	case 4:
		printf("4���Դϴ�!\n");
		break;
	case 5:
	{
		if (Bonus == true)
		{
			printf("2���Դϴ�!\n");
			break;
		}
		else
		{
			printf("3���Դϴ�!\n");
			break;
		}
	}
	case 6:
		printf("�����մϴ�! 1���Դϴ�!!\n");
		break;
	}
}
