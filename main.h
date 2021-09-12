#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
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
#define PLAY2_X 15
#define PLAY2_Y 20
#define PLAY2_mine 75

int keyControl(); //Ű����
void titleDraw(); //Ÿ��Ʋ �׸���
int menuDraw(short& player); //�޴� ȭ��
void infoDraw(short player); //����  ����
void gameStart(short player); //���� ȭ��
void setColor(int color, int bgcolor);

class player {
	//���ο�����
	int x; //�÷��̾��� x��ǥ
	int y; //�÷��̾��� y��ǥ
	int life; //���� ��� (1�ο� : 1�� / 2�ο� : 2��)
	int around_mine_cnt; //�ֺ� ���� ��
	bool flag_cnt;//��� ����
public:
};

class GameBase {
	int **base;//��� �迭
	int mine; //���ڰ���
	int countMine(int i, int j);
public:
	GameBase();
	~GameBase();
	void showBase();
	void showGameBoard();
	void gameStart();
};

