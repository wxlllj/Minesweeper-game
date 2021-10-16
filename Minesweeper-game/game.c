#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisPalyBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for ( i = 0; i <=row; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	//打印行号
	for ( i = 1; i <= row; i++)
	{
		printf("%d", i);
		for ( j = 1; j <= col; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
void IsMine(char board[ROWS][COLS], int row, int col)
{
	//放雷的数量
	int count = EASY_MINE;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;
		if (board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//是按ASCLL码相减，返回的是正数
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	//81-10=71
	while (win < row * col - EASY_MINE)
	{
		printf("请输入下标<-:");
		scanf("%d%d", &x, &y);
		//判断是否坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//是雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你排雷失败了\n");
				DisPalyBoard(mine, ROW, COL);
				break;
			}
			//不是雷
			else
			{
				//统计坐标周围的雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisPalyBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标输入不正确，请重新输入：");
		}
	}
	if (win == row * col - EASY_MINE)
	{
		printf("恭喜你，排雷成功\n");
		DisPalyBoard(mine, ROW, COL);
			
	}
}
