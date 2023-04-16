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
	printf("***** ���ھ߱� ���α׷� *****\n");
	printf("��ǻ���� 1 ~ 9 ������ ���� 3���� �����ּ���!\n");
	printf("��ǻ���� ���ڿ� �ߺ��� ���� ����!\n");
	printf("Strike : ����, �ڸ� ��� ��ġ.\n");
	printf("Ball : ���ڸ� ��ġ.\n");
	printf("Out : �ش� ���� ����.\n\n");
}

void Result2(int* ComNum, int* PlayerNum, bool isContinue)
{
	while (isContinue)
	{
		printf("1 ~ 9�� ���� 3���� ����ּ���\n");

		for (int i = 0; i < 3; i++)
		{
			printf("%d ��° �ڸ� ���� : \t", i + 1);
			scanf_s("%d", &PlayerNum[i]);

			if (PlayerNum[i] > 9 || PlayerNum[i] < 1)
			{
				i--;
				printf("1 ~ 9 ������ ���ڸ� ����ּ���.\n");
			}
			for (int j = 0; j < i; j++)
			{
				if (PlayerNum[i] == PlayerNum[j])
				{
					i--;
					printf("�ߺ��� ���ڴ� ���� �Ұ����մϴ�.\n");
					break;
				}
			}
		}

		int Strike = 0, Ball = 0, Out = 0;

		printf("���� �� ���ڵ� :\t");
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

		printf("Strike	: %d ��\n", Strike);
		printf("Ball	: %d ��\n", Ball);
		printf("Out	: %d ��\n\n", Out);

		if (Strike == 3)
		{
			printf("�����մϴ�! �����Դϴ�!!\n");
			printf("��ǻ�� ���� :\t\t");
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
