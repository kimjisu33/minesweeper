#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<thread>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

void init(); //�ܼ� ����
void gotoxy(int, int);

//Ű���� ��
#define W 0
#define S 1
#define A 2
#define D 3
#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7
#define SPACE 8
#define ENTER 9
#define TAP 10
#define M 11

//����ã�� ��
//1�ο� 14*14 40��
#define PLAY1 14
#define PLAY1_mine 25 //25
//2�ο� 15*20 75��
#define PLAY2_row 15
#define PLAY2_col 20
#define PLAY2_mine 50 //75

#define MINE 10
#define WALL 11

int keyControl(); //Ű����
void titleDraw(); //Ÿ��Ʋ �׸���
int menuDraw(int& player); //�޴� ȭ��
void infoDraw(int player); //���� ����
//void gameStartMenu(int player); //���� ȭ��
void setColor(int color, int bgcolor);
void gameStart1();
void gameStart2();

class player {
	//short life; //���� ��� (1�ο� : 1�� / 2�ο� : 2��)
	
public:
	int flag_cnt=0;//����� ��� ����
	int x; //�÷��̾��� x��ǥ
	short y; //�÷��̾��� y��ǥ
	player(){}
	player(int x, int y): x(x),y(y) {}
	void setData(int x, int y) { player(x, y); }
};

class GameBase {
	int **base;//��� �迭
	int mine; //���ڰ���
	int row, col;
	player* p;
	int p_n;

	int checked[PLAY1][PLAY1] = { 0, };
	int broken_block_cnt = 0;
	static bool over;
	bool clear;

	int key_up;
	int key_down;
	int key_left;
	int key_right;
	int key_break;
	int key_flag;

	void setMine(int);
	void countMine(int, int, bool);
	
	string showNumber(int, int);
	void findEmptyBase(int, int, int, int);

	void gameOver();
	void gameClear();
	void checkClear();


public:
	GameBase();
	GameBase(int,int,int);
	~GameBase();
	void showBase(); //��� �� ����
	void showCheck();

	void showGameBoard();
	void movePlayer();
	void gameStart();
	
};

