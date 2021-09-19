#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
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
#define PLAY1_mine 20
//2인용 15*20 75개
#define PLAY2_col 15
#define PLAY2_row 20
#define PLAY2_mine 75

#define MINE 20
#define WALL 21

int keyControl(); //키보드
void titleDraw(); //타이틀 그리기
int menuDraw(short& player); //메뉴 화면
void infoDraw(short player); //게임  설명
void gameStart(short player); //게임 화면
void setColor(int color, int bgcolor);

/*
class player {
	short player_n;//몇인용인지
	int x; //플레이어의 x좌표
	int y; //플레이어의 y좌표
	int life; //남은 목숨 (1인용 : 1개 / 2인용 : 2개)
	//bool flag_cnt;//깃발 개수
public:
	player(int);
};*/

class GameBase {
	int **base;//배경 배열
	int mine; //지뢰개수

	int p_x;
	int p_y;

	void countMine(int, int);
	void showGameBoard();
	void movePlayer();
	string showNumber(int, int);
public:
	GameBase();
	~GameBase();
	void showBase(); //배경 값 보기
	
	void gameStart();
};

