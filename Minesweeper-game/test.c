#include "game.h"



void game()
{
	
	//布置雷的信息
	//1、布置好雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2、布置好排雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	//DisPalyBoard(mine, ROW, COL);
	DisPalyBoard(show, ROW, COL);
	//布置雷
	IsMine(mine, ROW, COL);
	DisPalyBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
	
}

void menu()
{
	printf("##################################\n");
	printf("#######    1.进入扫雷        #####\n");
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
		printf("请选择<-:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("你已退出游戏\n");
			break;
		default:
			printf("你的选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}