#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
using namespace std;

void init(); //콘솔 설정
void gotoxy(int, int);

//키보드 값
#define W 0
#define S 1
#define A 2
#define D 3
#define SPACE 4
#define ENTER 5
#define SHIFT 6

//지뢰찾기 판
//1인용 14*14 40개
#define PLAY1 14
#define PLAY1_mine 20 //20
//2인용 15*20 75개
#define PLAY2_row 15
#define PLAY2_col 20
#define PLAY2_mine 50 //75

#define MINE 10
#define WALL 11

int keyControl(); //키보드
void titleDraw(); //타이틀 그리기
int menuDraw(short& player); //메뉴 화면
void infoDraw(short player); //게임 설명
void gameStart(short player); //게임 화면
void setColor(int color, int bgcolor);


class player {
	//short life; //남은 목숨 (1인용 : 1개 / 2인용 : 2개)
	
public:
	short flag_cnt=0;//사용한 깃발 개수
	short x; //플레이어의 x좌표
	short y; //플레이어의 y좌표
	player(){}
	player(short x, short y): x(x),y(y) {}
	void setData(short x, short y) { player(x, y); }
};

class GameBase {
	int **base;//배경 배열
	int mine; //지뢰개수
	int row, col;
	player* p;

	int checked[PLAY1][PLAY1] = { 0, };
	bool over;
	bool clear;

	void setMine(int);
	void countMine(int, int, bool);
	void showGameBoard();
	void movePlayer();
	string showNumber(int, int);
	void findEmptyBase(int, int, int, int);

	void gameOver();
	void gameClear();
	void checkClear();


public:
	GameBase();
	GameBase(int,int);
	~GameBase();
	void showBase(); //배경 값 보기
	void showCheck();

	void gameStart();
	
};

