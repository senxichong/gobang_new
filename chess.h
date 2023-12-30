#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

#define ROW 12
#define COL 12
void LaunchGame();
//void drawChessBoard(int row,int col,char ChessBoard[ROW][COL]);
//void InitChessBoard(char ChessBoard[ROW][COL]);
void playChess(int X,int Y,char ChessBoard[ROW][COL],int player);
int CheckWin(char ChessBoard[ROW][COL],int X,int Y);
//void getChessBoard(int* X, int* Y);
void showChessBoard(char ChessBoard[ROW][COL]);
void socre(char ChessBoard[ROW][COL],int player);
void ChooseSide(int* player);