
#include"chess.h"
int main() {
	//printf("**************************");
	//printf("*********五子棋***********");
	//printf("**************************")；
	//printf("请选择 0<:人人对战 1<:人机模式")
	//int choice;
	//scanf("%d", &choice);
		//黑棋先下，黑棋可以使人，也可以是AL
	char ChessBoard[ROW][COL];//每次落子后都要打印棋盘，并且验证输赢
	//白方可以落子，之后判断输赢
	//判断不了输赢就继续循环
	//根据以往情况选择
	//InitChessBoard(ChessBoard);///下棋核心算法采用剪枝算法

	int win_sign = 0;
	int player = 0;
	ChooseSide( &player);
	InitChessBoard(ChessBoard);
	while (!win_sign) {
		int X, Y;
		player = player ^ 1;
		printf("Please input the position you want to play:\n");
		scanf("%d %d", &X, &Y);
		playChess(X, Y, ChessBoard, player);
	/*	drawChessBoard(ROW, COL, ChessBoard);*/
		showChessBoard(ChessBoard);
		win_sign = CheckWin(ChessBoard, X, Y);

	}
	
	return 0;


}
