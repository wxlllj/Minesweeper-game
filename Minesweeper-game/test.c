#include "game.h"



void game()
{
	
	//�����׵���Ϣ
	//1�����ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2�����ú����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ӡ����
	//DisPalyBoard(mine, ROW, COL);
	DisPalyBoard(show, ROW, COL);
	//������
	IsMine(mine, ROW, COL);
	DisPalyBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
	
}

void menu()
{
	printf("##################################\n");
	printf("#######    1.����ɨ��        #####\n");
	printf("#######    2.exit            #####\n");
	printf("##################################\n");
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��<-:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�����˳���Ϸ\n");
			break;
		default:
			printf("���ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}