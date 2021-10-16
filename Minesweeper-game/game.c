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
	//��ӡ�к�
	for ( i = 0; i <=row; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	//��ӡ�к�
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
	//���׵�����
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
	//�ǰ�ASCLL����������ص�������
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
		printf("�������±�<-:");
		scanf("%d%d", &x, &y);
		//�ж��Ƿ������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			if (mine[x][y] == '1')
			{
				printf("���ź���������ʧ����\n");
				DisPalyBoard(mine, ROW, COL);
				break;
			}
			//������
			else
			{
				//ͳ��������Χ����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisPalyBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("�������벻��ȷ�����������룺");
		}
	}
	if (win == row * col - EASY_MINE)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisPalyBoard(mine, ROW, COL);
			
	}
}
