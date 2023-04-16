#include "pch.h"

void InitTable3(int* table);
void GameStart3();
void Result3(int* ComNum, int* PlayerNum, bool isContinue);

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int Cards[4][13] = { 0 };
	int RandNum1 = 0, RandNum2 = 0;
	int PlayerNum = 0;
	int PlayerMoney = 50000;
	bool ContinueGame = true;

	while (ContinueGame)
	{
		int Bet = 0;
		int CardCount = 0;

		while (true)
		{
			int rand1 = rand() % 4;
			int rand2 = rand() % 4;
			int rand3 = rand() % 4;
			int rand4 = rand() % 13;
			int rand5 = rand() % 13;
			int rand6 = rand() % 13;

			RandNum1 = Cards[rand1][rand4];
			RandNum2 = Cards[rand2][rand5];
			PlayerNum = Cards[rand3][rand6];

			if (RandNum1 != 0 && RandNum2 != 0 && PlayerNum != 0)
			{
				Cards[rand1][rand4] = 0;
				Cards[rand2][rand5] = 0;
				Cards[rand3][rand6] = 0;
				CardCount++;
				break;
			}
		}

		if (RandNum1 > RandNum2)
		{
			int temp;
			temp = RandNum2;
			RandNum2 = RandNum1;
			RandNum1 = temp;
		}

		printf("�÷��̾� �����ݾ� : %d\n", PlayerMoney);
		printf("ī�� �ΰ� ���� : %d\t%d\n", RandNum1, RandNum2);
		printf("�� �����Ͻðڽ��ϱ�? : ");
		scanf_s("%d", &Bet);

		if (Bet < 1000)
		{
			printf("���ñ��� 1000�� �̻� �ɾ�� �մϴ�.\n");
			printf("�� �����Ͻðڽ��ϱ�? : ");
			scanf_s("%d", &Bet);
		}

		printf("�÷��̾� ī�� : %d\n", PlayerNum);

		if (PlayerNum >= RandNum1 && PlayerNum <= RandNum2)
			printf("�¸��߽��ϴ�!\n\n");
		else
		{
			PlayerMoney -= Bet;
			printf("�����ϴ�..\n\n");
		}

		if (CardCount == 16 || PlayerMoney <= 0)
			ContinueGame = false;
	}

	return 0;
}

void InitTable3(int* table)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			table[i][j] = rand() % 13 + 1;
			for (int k = 0; k < j; k++)
			{
				if (table[i][j] == table[i][k]) // ���� �߻�
				{
					j--;
					break;
				}
			}
		}
	}
}

void GameStart3()
{
	printf("***** ������ ī����� ���α׷� *****\n");
	printf("52���� ī��(1 ~ 13 4����)�� �����մϴ�.\n");
	printf("������ ������ ī��ȿ� �ڽ��� ������ ī�尡 ���� �ȿ� ���ԵǸ� �¸��Դϴ�.\n");
	printf("���ñ��� �ּ� 1000������ �Դϴ�.\n");
	printf("�̱�� ���þ��� ȸ���մϴ�.\n");
	printf("���� ���þ��� �ҽ��ϴ�.\n\n");
	printf("���� ī��� �ٽ� ������ �ʽ��ϴ�.\n");
	printf("ī�尡 �� �������ų�, ���ñ��� 0�� �Ǹ� ����˴ϴ�.\n\n");
}
