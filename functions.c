#include"chess.h"
//viod LaunchGame() {
//	printf("**************************");
//	printf("*********五子棋***********");
//	printf("**************************");
//	printf("请选择 0<:人人模式 1<:人机模式");
//	int choice;
//	scanf("%d", &choice);
//}
void ChooseSide(int* player) {
	printf("请选择 0<:黑棋 1<:白棋");
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
	//0表示可以落子，1表示超出棋盘范围，2表示该位置已经有棋子了,还有其他情况没有考虑，比如输入是一个奇怪的东西
	switch (err_case) {
		case 1:
			printf("输入的位置超出了棋盘的范围，请重新输入！\n");
			player = player ^ 1;
			break;
		case 2:
			printf("提示：该位置已经有棋子了!\n");
			player = player ^ 1;
			break;
		case 0:
			ChessBoard[X][Y] = (player) ? 1 : 0;
			break;
	}
	

}
int CheckWin(char ChessBoard[ROW][COL], int X, int Y) {
	//考虑四种情况:创建一个二维数组
	
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
//打分的函数
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

//显示棋盘的函数

void showChessBoard(char ChessBoard[ROW][COL]) {
    int i=0, j=0;
    for (i = 0; i <= ROW; i++)
    {
        //第一行
		switch (i) {
		case 0: {
			//第一列

			printf(ChessBoard[i][0] == 2 ? "┌ " : ChessBoard[i][0] == 1 ? "● " : "○ ");
			//第1-19列
			for (j = 1; j <= COL - 1; j++)
			{

				printf(ChessBoard[0][j] == 2 ? "┬ " : ChessBoard[0][j] == 1 ? "● " : "○ ");
			}

			//第20列

			printf(ChessBoard[0][COL] == 2 ? "┐ " : ChessBoard[0][COL] == 1 ? "● " : "○ ");

			printf("\n");
		}; break;

			//第2-19行
		default:
			{
			j = 0;
				//第一列

				printf(ChessBoard[i][j] == 2 ? "├ " : ChessBoard[i][j] == 1 ? "● " : "○ ");

				//第1-19列
				for (j = 1; j <= COL - 1; j++)
				{

					printf(ChessBoard[i][j ] == 2 ? "┼ " : ChessBoard[i][j] == 1 ? "● " : "○ ");
				}

				//第20列

				printf(ChessBoard[i][COL] == 2 ? "┤ " : ChessBoard[i][COL] == 1 ? "● " : "○ ");

				printf("\n");
			}; break;

			//第20行
		case ROW:
			{
			j = 0;
				printf(ChessBoard[i][j] == 2 ? "└ " : ChessBoard[i ][j] == 1 ? "● " : "○ ");

				for (j = 1; j <= COL - 1; j++)
				{
					printf(ChessBoard[i][j] == 2 ? "┴ " : ChessBoard[i][j] == 1 ? "● " : "○ ");
				}


				printf(ChessBoard[i][j] == 2 ? "┘ " : ChessBoard[i][j] == 1 ? "● " : "○ ");


				printf("\n");
			}; break;
		}
    }

}
//{
//
//    int i, j;//表示棋盘横纵坐标
//    /*************************************************
//    *
//    *绘制表格需要的字符:┌ ┬ ┐├ ┼ ┤└ ┴ ┘│─●○
//    *数组的值0表示黑棋，1表示白棋，2表示该位置没有棋
//    *
//    */
//    char ChessBoard[ROW][COL];
//    int color = 0;//0表示黑棋(圆圈)，1表示白棋
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
//        printf("请输入棋子位置（棋盘大小为20*20),如2,2: ");
//        scanf("%d,%d", &i, &j);
//
//        if (i < 1 || i >20 || j < 1 || j>20)
//        {
//            printf("输入的位置超出了棋盘的范围，请重新输入！\n");
//            continue;
//        }
//
//        if ((2 != ChessBoard[i - 1][j - 1]))
//        {
//            printf("提示：该位置已经有棋子了!\n");
//            fflush(stdin);
//            continue;
//        }
//
//        color = (color + 1) % 2;//获取棋盘棋子属性
//        ChessBoard[i - 1][j - 1] = color;//将该位置棋子属性给棋盘
//
//        //根据棋盘对应位置属性，绘制最新状态的棋盘，一行行绘制，边缘特别处理
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