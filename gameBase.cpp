#include "main.h"

GameBase::GameBase() {
	mine = PLAY1_mine; //지뢰 개수 이거 왜넣었지..?

	p_x = 31;
	p_y = 11;

	base = new int* [PLAY1 + 2]; //2차원 할당, 벽포함
	for (int i = 0; i < PLAY1 + 2; i++) {
		base[i] = new int[PLAY1 + 2];
	}
	for (int i = 0; i < PLAY1 + 2; i++) { //배열 초기화
		for (int j = 0; j < PLAY1 + 2; j++) {
			if (i == 0 || i == PLAY1 + 1 || j == 0 || j == PLAY1 + 1) base[i][j] = WALL; //벽
			else base[i][j] = 0;
		}
	}

	//지뢰 생성
	int cnt = 0;
	while (cnt < PLAY1_mine) {
		int a = rand() % PLAY1 + 1; //1~10
		int b = rand() % PLAY1 + 1; //1~10

		if (base[a][b] == MINE || base[a][b] == WALL) continue;
		else {
			base[a][b] = MINE;
			cnt++;
		}
	}

	for (int i = 1; i < PLAY1 + 1; i++) {
		for (int j = 1; j < PLAY1 + 1; j++) {
			if (base[i][j] == MINE) countMine(i, j);
		}
	}

}
GameBase::~GameBase() {
	for (int i = 0; i < PLAY1 + 2; i++) {
		delete[] base[i];
	}
	delete[] base;
}
void GameBase::showBase() {
	for (int i = 0; i < PLAY1 + 2; i++) {
		for (int j = 0; j < PLAY1 + 2; j++) {
			if (base[i][j] == 1) {
				setColor(6, 0);
			}
			cout << base[i][j];
			setColor(7, 0);
		}
		cout << endl;
	}
}
void GameBase::showGameBoard() {
	int x = 30;
	int y = 10;
	/*gotoxy(x, y);
	cout << "■■■■■■■■■■■■■■■■";*/
	for (int i = 0; i < PLAY1 + 2; i++,y++) {
		for (int j = 0, x=30; j < PLAY1 + 2; j++) {
			if (base[i][j] == WALL) {
				setColor(6, 0); //노란색
			}else if (base[i][j] == MINE) {
				setColor(3, 0); //지뢰 위치 확인 게임 완성하면 지우기
			}
			gotoxy(x++,y);
			cout << "■";
			//cout << base[i][j] << " ";
			setColor(7, 0);
		}
		cout << endl;
	}
	
}


void GameBase::countMine(int m_i, int m_j) {
	for (int i = m_i - 1; i <= m_i + 1; i++) {
		for (int j = m_j - 1; j <= m_j + 1; j++) {
			if (base[i][j] == MINE || base[i][j] == WALL)continue;
			base[i][j]++;
		}
	}
}

void GameBase::movePlayer() {

	gotoxy(p_x, p_y);
	cout << "□";
	while (1) {
		int n = keyControl();
		switch (n)
		{
		case W: {
			if (p_x > 20) { //20보다 작으면 안움직임
				
			}
			break;
		}
		case S: {
			 if (p_y < 22) { //22보다 크면 안움직임

			}
			break;
		}
		case SPACE: {

		}
		case ENTER: {

		}
		default: {}
		}

	}
}

void GameBase::gameStart() {
	showGameBoard();
	movePlayer();
}
