#include "main.h"

GameBase::GameBase(short p_n) {

	if (p_n == 1) {
		p = new player(31,11,1);
		mine = PLAY1_mine; // 지뢰 찾으면 --하려고 넣은듯
		row = PLAY1;
		col = PLAY1;
	}
	else {
		p = new player[2];
		p[0].setData(31, 11, 2);
		p[1].setData(31, 11, 2);
		mine = PLAY2_mine; 
		row = PLAY2_row; //15
		col = PLAY2_col; //20
	}

	over = false;
	clear = false;
	base = new short*[row +2]; //행 2차원 할당, 벽포함
	for (int i = 0; i < row+2 ; i++) {
		base[i] = new short[col + 2]; //열
	}
	for (int i = 0; i < row + 2; i++) { //배열 초기화
		for (int j = 0; j < col+2; j++) {
			if (i == 0 || i == row + 1 || j == 0 || j == col + 1) base[i][j] = WALL; //벽
			else base[i][j] = 0; 
		}
	}

	//지뢰 생성
	int cnt = 0;
	while (cnt < mine) {
		int a = rand() % row + 1; //1~row
		int b = rand() % col + 1; //1~col

		if (base[a][b] == MINE || base[a][b] == WALL) continue;
		else {
			base[a][b] = MINE;
			cnt++;
		}
	}

	for (int i = 1; i <= row ; i++) {
		for (int j = 1; j <= col ; j++) {
			if (base[i][j] == MINE) countMine(i, j);
		}
	}

}
GameBase::~GameBase() {
	for (int i = 0; i < row + 2; i++) {
		delete[] base[i];
	}
	delete[] base;
	delete[] p;
}
void GameBase::showBase() {
	for (int i = 0; i < row + 2; i++) {
		for (int j = 0; j < col + 2; j++) {
			if (base[i][j] == MINE) {
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
	for (int i = 0; i < row + 2; i++,y++) {
		for (int j = 0, x=30; j < col + 2; j++) {
			if (base[i][j] == WALL) {
				setColor(6, 0); //노란색
			}
			else if (base[i][j] == MINE) {
				setColor(3, 0); //지뢰 위치 확인 게임 완성하면 지우기
			}
			gotoxy(x++,y);
			cout << "■";
			//cout << base[i][j] << " ";
			setColor(15, 0);
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

	int i = 1, j = 1;

	gotoxy(p->x, p->y); //31, 11
	setColor(4, 0);
	cout << "■";

	while (!over && !clear) {

		setColor(15, 0);
		gotoxy(50, 30);
		cout << "깃발 : " << mine-(p->flag_cnt) << " / " << mine;

		int n = keyControl();
		switch (n)
		{
		case W: { //위로 올라가기 y감소
			if (p->y >11) {
				gotoxy(p->x, p->y);
				setColor(15,0);
				cout << showNumber(i, j);
				i--;
				gotoxy(p->x, --p->y);
				setColor(4, 0);
				cout << showNumber(i, j);
				
			}
			break;
		}
		case S: { //아래로 내려가기 y증가
			 if (p->y <24) {
				 gotoxy(p->x, p->y);
				 setColor(15, 0);
				 cout << showNumber(i, j);
				 i++;
				 gotoxy(p->x, ++p->y);
				 setColor(4, 0);
				 cout << showNumber(i, j);
				
			}
			break;
		}
		case D: { //오른쪽으로 이동하기 x증가
			if (p->x < 44) {
				gotoxy(p->x, p->y);
				setColor(15, 0);
				cout << showNumber(i, j);
				j++;
				gotoxy(++p->x, p->y);
				setColor(4, 0);
				cout << showNumber(i, j);
				
			}
			break;
		}
		case A: { //왼쪽으로 이동하기 x감소
			if (p->x > 31) {
				gotoxy(p->x, p->y);
				setColor(15, 0);
				cout << showNumber(i, j);
				gotoxy(--p->x, p->y);
				j--;
				setColor(4, 0);
				cout << showNumber(i, j);
				
			}
			break;
		}
		case ENTER: {
			//처음 클릭하는 칸은 지뢰가 아니어야 함

			//if (checked[i - 1][j - 1] == 0) {
			//	checked[i - 1][j - 1] = 1; //숫자
			//	gotoxy(p->x, p->y);
			//	setColor(4, 0);
			//	cout << showNumber(i, j);
			//}
			findEmptyBase(i,j);
			break;
				
		}
		case SHIFT: {
			if (checked[i - 1][j - 1] == 0) {
				checked[i - 1][j - 1] = 2; //깃발
				gotoxy(p->x, p->y);
				setColor(4, 0);
				cout << showNumber(i, j);
				p->flag_cnt++;
			}
			else if (checked[i - 1][j - 1] == 2) { //깃발 지우기
				checked[i - 1][j - 1] = 0;
				gotoxy(p->x, p->y);
				setColor(4, 0);
				cout << showNumber(i, j);
				p->flag_cnt--;
			}
			break;
		}
		default: {}
		}
		setColor(15, 0);
		if (mine == (p->flag_cnt)) {//mine과 설치한 깃발의 갯수가 같은가?
			//if(mine이 있는 방에만 깃발이 있는가)
			checkClear();
		}
	}
	if(clear) gameClear();
}
string GameBase::showNumber(int i, int j) {
	if (checked[i-1][j-1]==1) {
		switch (base[i][j]) {
		case 0: return "○";
		case 1: return "①";
		case 2: return "②";
		case 3: return "③";
		case 4: return "④";
		case 5: return "⑤";
		case 6: return "⑥";
		case 7: return "⑦";
		case 8: return "⑧";
		case MINE: {
			//게임 오버
			gameOver();
			break;
		}
		default: {}
		}
	}
	else if (checked[i - 1][j - 1] == 2) {
		return "¶";
	}
	else {
		return "■";
	}
	
	return "";
}
void GameBase::findEmptyBase(int check_i, int check_j) {
	
	bool noMine = true;
	for (int i = check_i - 1; i <= check_i + 1; i++) {
		for (int j = check_j - 1; j <= check_j + 1; j++) {
			if (base[i][j] == MINE) noMine = false;
		}
	}
	
	if (noMine) {
		for (int i = check_i - 1; i <= check_i + 1; i++) {
			for (int j = check_j - 1; j <= check_j + 1; j++) {
				if (checked[i][j] == 0) {
					checked[i][j] = 1; //숫자
					gotoxy(p->x, p->y);
					setColor(4, 0);
					cout << showNumber(i, j);
				}
			}
		}
		findEmptyBase(check_i+(rand()%2), check_j+(rand() % 2));
	}
	
	
}

void GameBase::gameOver() {
	system("cls"); 
	gotoxy(0, 0);
	cout << "게임오버" << endl;
	over = true;

	cout << "enter 또는 space를 누르면 돌아갑니다." << endl;
	while (1) {
		if (keyControl() == SPACE || keyControl() == ENTER) break;
	}
}
void GameBase::gameClear() {
	system("cls");
	gotoxy(0,0);
	cout << "지뢰다찾음!"<<endl;

	cout << "enter 또는 space를 누르면 돌아갑니다." << endl;
	while (1) {
		if (keyControl() == SPACE || keyControl() == ENTER) break;
	}
}
void GameBase::checkClear() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (base[i][j] == MINE) {
				if(checked[i - 1][j - 1] == 2) clear = true;
			}
		}
	}
}

void GameBase::gameStart() {
	showGameBoard();
	//showBase();
	movePlayer();
}
