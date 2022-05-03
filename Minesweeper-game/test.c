#include "game.h"



void game()
{
	
	//²¼ÖÃÀ×µÄÐÅÏ¢
	//1¡¢²¼ÖÃºÃÀ×µÄÐÅÏ¢
	char mine[ROWS][COLS] = { 0 };//11*11
	//2¡¢²¼ÖÃºÃÅÅÀ×µÄÐÅÏ¢
	char show[ROWS][COLS] = { 0 };
	//³õÊ¼»¯ÆåÅÌ
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//´òÓ¡ÆåÅÌ
	//DisPalyBoard(mine, ROW, COL);
	DisPalyBoard(show, ROW, COL);
	//²¼ÖÃÀ×
	IsMine(mine, ROW, COL);
	DisPalyBoard(mine, ROW, COL);
	//É¨À×
	FindMine(mine, show, ROW, COL);
	
}

void menu()
{
	printf("##################################\n");
	printf("#######    1.½øÈëÉ¨À×        #####\n");
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
		printf("ÇëÑ¡Ôñ<-:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÄãÒÑÍË³öÓÎÏ·\n");
			break;
		default:
			printf("ÄãµÄÑ¡Ôñ´íÎó£¬ÇëÖØÐÂÑ¡Ôñ\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;

}