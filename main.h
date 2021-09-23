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
#define PLAY2_col 15
#define PLAY2_row 20
#define PLAY2_mine 75

#define MINE 10
#define WALL 11

int keyControl(); //Ű����
void titleDraw(); //Ÿ��Ʋ �׸���
int menuDraw(short& player); //�޴� ȭ��
void infoDraw(short player); //����  ����
void gameStart(short player); //���� ȭ��
void setColor(int color, int bgcolor);

/*
class player {
	short player_n;//���ο�����
	int x; //�÷��̾��� x��ǥ
	int y; //�÷��̾��� y��ǥ
	int life; //���� ��� (1�ο� : 1�� / 2�ο� : 2��)
	//bool flag_cnt;//��� ����
public:
	player(int);
};*/

class GameBase {
	short **base;//��� �迭
	short mine; //���ڰ���
	int checked[PLAY1_mine - 2][PLAY1_mine - 2] = { 0, };

	int p_x;
	int p_y;

	void countMine(int, int);
	void showGameBoard();
	void movePlayer();
	string showNumber(int, int);

	int f=0; //����� ��� ���� 

public:
	GameBase();
	~GameBase();
	void showBase(); //��� �� ����
	
	void gameStart();
};

