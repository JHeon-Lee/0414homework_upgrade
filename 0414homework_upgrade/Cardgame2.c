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

		printf("플레이어 보유금액 : %d\n", PlayerMoney);
		printf("카드 두개 오픈 : %d\t%d\n", RandNum1, RandNum2);
		printf("얼마 베팅하시겠습니까? : ");
		scanf_s("%d", &Bet);

		if (Bet < 1000)
		{
			printf("베팅금은 1000원 이상 걸어야 합니다.\n");
			printf("얼마 베팅하시겠습니까? : ");
			scanf_s("%d", &Bet);
		}

		printf("플레이어 카드 : %d\n", PlayerNum);

		if (PlayerNum >= RandNum1 && PlayerNum <= RandNum2)
			printf("승리했습니다!\n\n");
		else
		{
			PlayerMoney -= Bet;
			printf("졌습니다..\n\n");
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
				if (table[i][j] == table[i][k]) // 오류 발생
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
	printf("***** 월남뽕 카드게임 프로그램 *****\n");
	printf("52장의 카드(1 ~ 13 4더미)로 시작합니다.\n");
	printf("랜덤한 두장의 카드안에 자신의 숨겨진 카드가 범위 안에 포함되면 승리입니다.\n");
	printf("베팅금은 최소 1000원부터 입니다.\n");
	printf("이기면 베팅액을 회수합니다.\n");
	printf("지면 베팅액을 잃습니다.\n\n");
	printf("사용된 카드는 다시 사용되지 않습니다.\n");
	printf("카드가 다 떨어지거나, 베팅금이 0이 되면 종료됩니다.\n\n");
}
