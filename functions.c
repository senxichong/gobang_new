#include"chess.h"
//viod LaunchGame() {
//	printf("**************************");
//	printf("*********������***********");
//	printf("**************************");
//	printf("��ѡ�� 0<:����ģʽ 1<:�˻�ģʽ");
//	int choice;
//	scanf("%d", &choice);
//}
void ChooseSide(int* player) {
	printf("��ѡ�� 0<:���� 1<:����");
	scanf("%d", player);
}
void InitChessBoard(char ChessBoard[ROW][COL]) {
	
	int i, j;
	//for (i = 0; i < ROW; i++) {
	//	for (j = 0; j < COL; j++) {
	//		ChessBoard[i][j] = ' ';
	//	}
	//}
	//for (i = 0; i < ROW; i++) {
	//	ChessBoard[i][0] = '0' + i;
	//}
	//for (j = 0; j < COL; j++) {
	//	ChessBoard[0][j] = '0' + j;
	//}
    for (i = 0; i <= ROW; i++)
    {
        for (j = 0; j <= COL; j++)
        {
            ChessBoard[i][j] = 2;
        }
    }
}

void playChess(int X, int Y, char ChessBoard[ROW][COL], int player) {
	char err_case = (X <= ROW && X >= 0 && Y <= COL && Y >= 0 && ChessBoard[X][Y] == 2) ? 0 : (ChessBoard[X][Y]!= 2) ? 2 : 1;
	//0��ʾ�������ӣ�1��ʾ�������̷�Χ��2��ʾ��λ���Ѿ���������,�����������û�п��ǣ�����������һ����ֵĶ���
	switch (err_case) {
		case 1:
			printf("�����λ�ó��������̵ķ�Χ�����������룡\n");
			player = player ^ 1;
			break;
		case 2:
			printf("��ʾ����λ���Ѿ���������!\n");
			player = player ^ 1;
			break;
		case 0:
			ChessBoard[X][Y] = (player) ? 1 : 0;
			break;
	}
	

}
int CheckWin(char ChessBoard[ROW][COL], int X, int Y) {
	//�����������:����һ����ά����
	
	char dir[][2][2] = { { {1,0},{-1,0} },{ {0,1},{0,-1} },{ {1,1},{-1,-1} },{ {1,-1},{-1,1} }};
	for (int i = 0; i < 4; i++) {
		int count = 0;
		for (int j = 0; j < 2; j++) {
			int x = X, y = Y;
			while (ChessBoard[x][y] == ChessBoard[X][Y]) {
				x += dir[i][j][0];
				y += dir[i][j][1];
				count++;
			}
		}
		if (count >= 6) {
			return 1;
		}
	}
	return 0;
}
//void getChessBoard(int* X, int* Y,char ChessBoard[ROW][COL]) {
//
//	
//
//}
//��ֵĺ���
void socre(char ChessBoard[ROW][COL], int X, int Y) {
	int i, j;
	int count = 0;
	int score = 0;
	int dir[][2][2] = { { {1,0},{-1,0} },{ {0,1},{0,-1} },{ {1,1},{-1,-1} },{ {1,-1},{-1,1} } };
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			int x = X, y = Y;
			while (ChessBoard[x][y] == ChessBoard[X][Y]) {
				x += dir[i][j][0];
				y += dir[i][j][1];
				count++;
			}
			if (count == 5) {
				score += 100;
			}
			else if (count == 4) {
				score += 10;
			}
			else if (count == 3) {
				score += 5;
			}
			else if (count == 2) {
				score += 2;
			}
			else if (count == 1) {
				score += 1;
			}
		}
	}
}

//��ʾ���̵ĺ���

void showChessBoard(char ChessBoard[ROW][COL]) {
    int i=0, j=0;
    for (i = 0; i <= ROW; i++)
    {
        //��һ��
		switch (i) {
		case 0: {
			//��һ��

			printf(ChessBoard[i][0] == 2 ? "�� " : ChessBoard[i][0] == 1 ? "�� " : "�� ");
			//��1-19��
			for (j = 1; j <= COL - 1; j++)
			{

				printf(ChessBoard[0][j] == 2 ? "�� " : ChessBoard[0][j] == 1 ? "�� " : "�� ");
			}

			//��20��

			printf(ChessBoard[0][COL] == 2 ? "�� " : ChessBoard[0][COL] == 1 ? "�� " : "�� ");

			printf("\n");
		}; break;

			//��2-19��
		default:
			{
			j = 0;
				//��һ��

				printf(ChessBoard[i][j] == 2 ? "�� " : ChessBoard[i][j] == 1 ? "�� " : "�� ");

				//��1-19��
				for (j = 1; j <= COL - 1; j++)
				{

					printf(ChessBoard[i][j ] == 2 ? "�� " : ChessBoard[i][j] == 1 ? "�� " : "�� ");
				}

				//��20��

				printf(ChessBoard[i][COL] == 2 ? "�� " : ChessBoard[i][COL] == 1 ? "�� " : "�� ");

				printf("\n");
			}; break;

			//��20��
		case ROW:
			{
			j = 0;
				printf(ChessBoard[i][j] == 2 ? "�� " : ChessBoard[i ][j] == 1 ? "�� " : "�� ");

				for (j = 1; j <= COL - 1; j++)
				{
					printf(ChessBoard[i][j] == 2 ? "�� " : ChessBoard[i][j] == 1 ? "�� " : "�� ");
				}


				printf(ChessBoard[i][j] == 2 ? "�� " : ChessBoard[i][j] == 1 ? "�� " : "�� ");


				printf("\n");
			}; break;
		}
    }

}
//{
//
//    int i, j;//��ʾ���̺�������
//    /*************************************************
//    *
//    *���Ʊ����Ҫ���ַ�:�� �� ���� �� �ȩ� �� ���������
//    *�����ֵ0��ʾ���壬1��ʾ���壬2��ʾ��λ��û����
//    *
//    */
//    char ChessBoard[ROW][COL];
//    int color = 0;//0��ʾ����(ԲȦ)��1��ʾ����
//    int iTemp = 0, jTemp = 0, countTemp = 0;
//    int colorFlag = 0;
//    char op;
//
//again:
//
//    for (i = 0; i < 20; i++)
//        for (j = 0; j < 20; j++)
//            ChessBoard[i][j] = 2;
//
//    while (1)
//    {
//        printf("����������λ�ã����̴�СΪ20*20),��2,2: ");
//        scanf("%d,%d", &i, &j);
//
//        if (i < 1 || i >20 || j < 1 || j>20)
//        {
//            printf("�����λ�ó��������̵ķ�Χ�����������룡\n");
//            continue;
//        }
//
//        if ((2 != ChessBoard[i - 1][j - 1]))
//        {
//            printf("��ʾ����λ���Ѿ���������!\n");
//            fflush(stdin);
//            continue;
//        }
//
//        color = (color + 1) % 2;//��ȡ������������
//        ChessBoard[i - 1][j - 1] = color;//����λ���������Ը�����
//
//        //�������̶�Ӧλ�����ԣ���������״̬�����̣�һ���л��ƣ���Ե�ر���
//        
//
//       
//       
//
//                
//
//        
//
//    }
//}