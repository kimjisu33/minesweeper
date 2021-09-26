#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
using namespace std;

void init(); //�ܼ� ����
void gotoxy(int, int);

//Ű���� ��
#define W 0
#define S 1
#define A 2
#define D 3
#define SPACE 4
#define ENTER 5
#define SHIFT 6

//����ã�� ��
//1�ο� 14*14 40��
#define PLAY1 14
#define PLAY1_mine 20
//2�ο� 15*20 75��
#define PLAY2_row 15
#define PLAY2_col 20
#define PLAY2_mine 50 //75

#define MINE 10
#define WALL 11

int keyControl(); //Ű����
void titleDraw(); //Ÿ��Ʋ �׸���
int menuDraw(short& player); //�޴� ȭ��
void infoDraw(short player); //���� ����
void gameStart(short player); //���� ȭ��
void setColor(int color, int bgcolor);


class player {
	short life; //���� ��� (1�ο� : 1�� / 2�ο� : 2��)
	
public:
	short flag_cnt=0;//����� ��� ����
	short x; //�÷��̾��� x��ǥ
	short y; //�÷��̾��� y��ǥ
	player(){}
	player(short x, short y, short life): x(x),y(y),life(life) {}
	void setData(short x, short y, short life) { player(x, y, life); }
};

class GameBase {
	short **base;//��� �迭
	short mine; //���ڰ���
	short checked[PLAY1_mine - 2][PLAY1_mine - 2] = { 0, };

	int row, col;
	player* p;
	/*int p_x;
	int p_y;*/
	//int f=0; //����� ��� ���� 

	void countMine(int, int);
	void showGameBoard();
	void movePlayer();
	string showNumber(int, int);

	

public:
	GameBase(short);
	~GameBase();
	void showBase(); //��� �� ����
	
	void gameStart();
};

