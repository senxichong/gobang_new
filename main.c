
#include"chess.h"
int main() {
	//printf("**************************");
	//printf("*********������***********");
	//printf("**************************")��
	//printf("��ѡ�� 0<:���˶�ս 1<:�˻�ģʽ")
	//int choice;
	//scanf("%d", &choice);
		//�������£��������ʹ�ˣ�Ҳ������AL
	char ChessBoard[ROW][COL];//ÿ�����Ӻ�Ҫ��ӡ���̣�������֤��Ӯ
	//�׷��������ӣ�֮���ж���Ӯ
	//�жϲ�����Ӯ�ͼ���ѭ��
	//�����������ѡ��
	//InitChessBoard(ChessBoard);///��������㷨���ü�֦�㷨

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
