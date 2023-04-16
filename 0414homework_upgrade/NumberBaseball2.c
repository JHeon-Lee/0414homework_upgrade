#include "pch.h"

void InitTable2(int* table);
void GameStart2();
void Result2(int* ComNum, int* PlayerNum, bool isContinue);

int main()
{
	srand((unsigned int)time(NULL));
	rand();

	int ComNumbers[3] = { 0 };
	int PlayerNumbers[3] = { 0 };
	bool ContinueGame = true;

	InitTable2(ComNumbers);
	GameStart2();

	Result2(ComNumbers, PlayerNumbers, ContinueGame);
	

	return 0;
}

void InitTable2(int* table)
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

void GameStart2()
{
	printf("***** 숫자야구 프로그램 *****\n");
	printf("컴퓨터의 1 ~ 9 사이의 숫자 3개를 맞춰주세요!\n");
	printf("컴퓨터의 숫자엔 중복된 숫자 없음!\n");
	printf("Strike : 숫자, 자리 모두 일치.\n");
	printf("Ball : 숫자만 일치.\n");
	printf("Out : 해당 숫자 없음.\n\n");
}

void Result2(int* ComNum, int* PlayerNum, bool isContinue)
{
	while (isContinue)
	{
		printf("1 ~ 9의 숫자 3개를 골라주세요\n");

		for (int i = 0; i < 3; i++)
		{
			printf("%d 번째 자리 숫자 : \t", i + 1);
			scanf_s("%d", &PlayerNum[i]);

			if (PlayerNum[i] > 9 || PlayerNum[i] < 1)
			{
				i--;
				printf("1 ~ 9 사이의 숫자를 골라주세요.\n");
			}
			for (int j = 0; j < i; j++)
			{
				if (PlayerNum[i] == PlayerNum[j])
				{
					i--;
					printf("중복된 숫자는 선택 불가능합니다.\n");
					break;
				}
			}
		}

		int Strike = 0, Ball = 0, Out = 0;

		printf("내가 고른 숫자들 :\t");
		for (int i = 0; i < 3; i++)
			printf("%d\t", PlayerNum[i]);
		printf("\n");

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (ComNum[i] == PlayerNum[j])
				{
					if (ComNum[i] == PlayerNum[i])
						Strike++;
					else
						Ball++;
				}
				Out = 3 - (Strike + Ball);
			}
		}

		printf("\n");

		printf("Strike	: %d 개\n", Strike);
		printf("Ball	: %d 개\n", Ball);
		printf("Out	: %d 개\n\n", Out);

		if (Strike == 3)
		{
			printf("축하합니다! 정답입니다!!\n");
			printf("컴퓨터 숫자 :\t\t");
			for (int i = 0; i < 3; i++)
			{
				printf("%d\t", ComNum[i]);
			}
			isContinue = false;
		}
		else
			isContinue = true;
	}
}
