#include "main.h"

bool GameBase::over = false;
//bool GameBase::clear = false;

GameBase::GameBase(int n, int x, int y) {
	
	p_n = n;
	if (p_n == 1) { //1인용
		key_up = W;
		key_down = S;
		key_left = A;
		key_right = D;
		key_break = ENTER;
		key_flag = TAP;
	}else if (p_n == 2) { //2인용 1p
		key_up = W;
		key_down = S;
		key_left = A;
		key_right = D;
		key_break = SPACE;
		key_flag = TAP;
	}else if (p_n == 3) { //2인용 2p
		key_up = UP;
		key_down = DOWN;
		key_left = LEFT;
		key_right = RIGHT;
		key_break = ENTER;
		key_flag = M;
	}

	clear = false;
	p = new player(x, y);
	mine = PLAY1_mine; // 지뢰 찾으면 --하려고 넣은듯
	row = PLAY1;
	col = PLAY1;

	base = new int*[row +2]; //행 2차원 할당, 벽포함
	for (int i = 0; i < row+2 ; i++) {
		base[i] = new int[col + 2]; //열
	}
	for (int i = 0; i < row + 2; i++) { //배열 초기화
		for (int j = 0; j < col+2; j++) {
			if (i == 0 || i == row + 1 || j == 0 || j == col + 1) base[i][j] = WALL; //벽
			else base[i][j] = 0; 
		}
	}

	//지뢰 생성
	setMine(mine);

}
GameBase::~GameBase() {
	for (int i = 0; i < row + 2; i++) {
		delete[] base[i];
	}
	delete[] base;
	delete[] p;
}

void GameBase::showBase() { //체크용
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
void GameBase::showCheck() { //체크용
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (base[i+1][j+1] == MINE) setColor(6, 0);
			cout<<checked[i][j];
			setColor(7, 0);
		}
		cout << endl;
	}
}

void GameBase::showGameBoard() {
	int x = p->x-1;
	int y = p->y-1;
	for (int i = 0; i < row + 2; i++,y++) {
		for (int j = 0, x= p->x-1 ; j < col + 2; j++) {
			if (base[i][j] == WALL) {
				if (p_n == 1 || p_n == 2)setColor(6, 0); //노란색 
				else setColor(9,0); //파란색
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

void GameBase::countMine(int m_i, int m_j, bool plus) {
	for (int i = m_i - 1; i <= m_i + 1; i++) {
		for (int j = m_j - 1; j <= m_j + 1; j++) {
			if (base[i][j] == MINE || base[i][j] == WALL) continue;
			if (plus) base[i][j]++;
			else base[i][j]--;
		}
	}
}
void GameBase::setMine(int mine) {

	int cnt = 0;
	while (cnt < mine) {
		int a = rand() % row + 1; //1~row
		int b = rand() % col + 1; //1~col

		if (base[a][b] == MINE || base[a][b] == WALL) continue;
		else {
			base[a][b] = MINE;
			countMine(a,b,true);
			cnt++;
		}
	}
}

void GameBase::movePlayer() {

	int i = 1, j = 1;
	bool first = true;
	int min_x = p->x;
	int max_x = p->x+PLAY1-1;
	int min_y = p->y;
	int max_y = p->y+ PLAY1-1;

	gotoxy(p->x, p->y); //31, 11
	setColor(4, 0);
	cout << "■";

	while (!over && !clear) {

		setColor(15, 0);
		gotoxy(max_x - 8, max_y+3);
		cout << "깃발 : " << mine - (p->flag_cnt)<<"    ";
		gotoxy(max_x - 3, max_y+3);
		cout<< " / " << mine;

		int key = keyControl();
		if (key == key_up) {
			if (p->y > min_y) {
				gotoxy(p->x, p->y);
				setColor(15, 0);
				cout << showNumber(i, j);
				i--;
				gotoxy(p->x, --p->y);
				setColor(4, 0);
				cout << showNumber(i, j);

			}
		}else if (key == key_down) {
			if (p->y < max_y) {
				gotoxy(p->x, p->y);
				setColor(15, 0);
				cout << showNumber(i, j);
				i++;
				gotoxy(p->x, ++p->y);
				setColor(4, 0);
				cout << showNumber(i, j);

			}
		}else if(key==key_left){
			if (p->x > min_x) {
				gotoxy(p->x, p->y);
				setColor(15, 0);
				cout << showNumber(i, j);
				gotoxy(--p->x, p->y);
				j--;
				setColor(4, 0);
				cout << showNumber(i, j);

			}
		}else if(key==key_right){
			if (p->x < max_x) {
				gotoxy(p->x, p->y);
				setColor(15, 0);
				cout << showNumber(i, j);
				j++;
				gotoxy(++p->x, p->y);
				setColor(4, 0);
				cout << showNumber(i, j);

			}
		}
		else if (key == key_break) {
			if (first && base[i][j] == MINE) { //처음 클릭하는 칸은 지뢰가 아니어야 함
				setMine(1);
				countMine(i, j, false);
				base[i][j] = 0;
			}
			if (base[i][j] == MINE && checked[i - 1][j - 1] != 2) {
				gameOver();
			}
			else if (checked[i - 1][j - 1] == 0) {
				//주변에 지뢰있으면 1개만음
				findEmptyBase(i, j, p->x, p->y);
			}
			first = false;
		}
		else if (key == key_flag) {
			if (checked[i - 1][j - 1] == 0) {
				PlaySound(TEXT("sound\\flag_install"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
				checked[i - 1][j - 1] = 2; //깃발 설치
				gotoxy(p->x, p->y);
				setColor(4, 0);
				cout << showNumber(i, j);
				p->flag_cnt++;
				first = false;
				
			}
			else if (checked[i - 1][j - 1] == 2) { //깃발 지우기
				checked[i - 1][j - 1] = 0;
				gotoxy(p->x, p->y);
				setColor(4, 0);
				cout << showNumber(i, j);
				p->flag_cnt--;
				if (broken_block_cnt == 0) first = true;
			}
		}
		
		setColor(15, 0);
		if (mine==(p->flag_cnt)) {
			checkClear();
			if (clear) {
				over = true;
			}
		}
		else if (row * col - broken_block_cnt == mine) {
			clear = true;
			over = true;
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
		default: {}
		}
	}
	else if (checked[i - 1][j - 1] == 2) {
		setColor(11, 0);
		return "¶";
	}
	else {
		return "■";
	}
	
	return "";
}
void GameBase::findEmptyBase(int click_i, int click_j, int click_x, int click_y) {
	
	
	for (int i = click_i - 1, y = click_y - 1 ; i <= click_i + 1; i++, y++) {
		for (int j = click_j - 1, x = click_x-1 ; j <= click_j + 1; j++, x++) {
			if (base[i][j] == WALL || base[i][j] == MINE || checked[i - 1][j - 1] == 2) continue;

			if (checked[i - 1][j - 1] == 0) {
				broken_block_cnt++;
				checked[i - 1][j - 1] = 1; //숫자
				setColor(15, 0);
				gotoxy(x, y);
				cout << showNumber(i, j);

			}
		}
	}

	//if (base[click_i][click_j] == 0) { //주변에 지뢰가 없으면
	//	for (int i = click_i - 1, y = click_y - 1; i <= click_i + 1; i++, y++) {
	//		for (int j = click_j - 1, x = click_x - 1; j <= click_j + 1; j++, x++) {
	//			if (base[i][i] == WALL || (i==click_i&&j==click_j)) continue;
	//			findEmptyBase(i, j, x, y);
	//		}
	//	}
	//}
	
	if (base[click_i][click_j] == 0) { //주변에 지뢰가 없으면
		int a = 0, b = 0;
		while (true) {
			a = rand() % 3 - 1; // -1 ~ 1
			b = rand() % 3 - 1;

			if (!(a == 0 && b == 0) && base[click_i + a][click_j + b] != WALL && checked[click_i + a][click_j + b] != 2) break;
		}//랜덤 돌리기
		findEmptyBase(click_i + a, click_j + b, click_x + b, click_y + a);
	}
}

void GameBase::gameOver() {
	int x=30, y=10;
	
	if (p_n == 2) {
		x = 14;
	}
	else if (p_n == 3) {
		x = 44;
	}

	setColor(4, 0);
	for (int i = 0,b=y; i < row + 2; i++,b++) {
		for (int j = 0, a=x ; j < col + 2; j++,a++) {
			if (base[i][j] == MINE) {
				gotoxy(a, b);
				cout << "※";
			}
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	int a = 20; int b = 7;
	gotoxy(a, b++);
	cout << "  _____            __  __  ______    ____  __      __ ______  _____" << endl;
	gotoxy(a, b++);
	cout << " / ____|    /\\    |  \\/  ||  ____|  / __ \\ \\ \\    / /|  ____||  __ \\" << endl;
	gotoxy(a, b++);
	cout << "| |  __    /  \\   | \\  / || |__    | |  | | \ \  / / | |__   | |__) |" << endl;
	gotoxy(a, b++);
	cout << "| | |_ |  / /\\ \\  | |\\/| ||  __|   | |  | |  \\ \\/ /  |  __|  |  _  /" << endl;
	gotoxy(a, b++);
	cout << "| |__| | / ____ \\ | |  | || |____  | |__| |   \\  /   | |____ | | \\ \\" << endl;
	gotoxy(a, b++);
	cout << " \\_____|/_/    \\_\\|_|  |_||______|  \\____/     \\/    |______||_|  \\_\\" << endl;
	
	over = true;
	setColor(15, 0);
	gotoxy(a, b+10);
	system("pause");
}
void GameBase::gameClear() {
	int x = 30, y = 10;

	if (p_n == 2) {
		x = 14;
	}
	else if (p_n == 3) {
		x = 44;
	}

	setColor(10, 0);
	for (int i = 0, b = y; i < row + 2; i++, b++) {
		for (int j = 0, a = x; j < col + 2; j++, a++) {
			if (base[i][j] == MINE) {
				gotoxy(a, b);
				cout << "♣";
			}
		}
		cout << endl;
	}
	system("pause");

	system("cls");
	setColor(6, 0);
	int a = 20; int b = 7;
	gotoxy(a, b++);
	cout << " ::::::::  :::        ::::::::::     :::     :::::::::     :::    :::" << endl;
	gotoxy(a, b++);
	cout << ":+:    :+: :+:        :+:          :+: :+:   :+:    :+:    :+:    :+:" << endl;
	gotoxy(a, b++);
	cout << "+:+        +:+        +:+         +:+   +:+  +:+    +:+    +:+    +:+" << endl;
	gotoxy(a, b++);
	cout << "+#+        +#+        +#++:++#   +#++:++#++: +#++:++#:     +#+    +#+" << endl;
	gotoxy(a, b++);
	cout << "+#+        +#+        +#+        +#+     +#+ +#+    +#+    +#+    +#+" << endl;
	gotoxy(a, b++);
	cout << "#+#    #+# #+#        #+#        #+#     #+# #+#    #+#" << endl;
	gotoxy(a, b++);
	cout << " ########  ########## ########## ###     ### ###    ###    ###    ###" << endl;


	setColor(15, 0);
	gotoxy(a, b+10);
	system("pause");
}
void GameBase::checkClear() {
	clear = true;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (base[i][j] == MINE) {
				if (checked[i - 1][j - 1] != 2) {
					clear = false;
					break;
				}
			}
		}
		if (!clear) break;
	}
}

void GameBase::gameStart() {
	showGameBoard();
	movePlayer();
}
 