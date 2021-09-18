#include "main.h"

GameBase::GameBase() {
	mine = PLAY1_mine; //���� ���� �̰� �ֳ־���..?

	p_x = 31;
	p_y = 11;

	base = new int* [PLAY1 + 2]; //2���� �Ҵ�, ������
	for (int i = 0; i < PLAY1 + 2; i++) {
		base[i] = new int[PLAY1 + 2];
	}
	for (int i = 0; i < PLAY1 + 2; i++) { //�迭 �ʱ�ȭ
		for (int j = 0; j < PLAY1 + 2; j++) {
			if (i == 0 || i == PLAY1 + 1 || j == 0 || j == PLAY1 + 1) base[i][j] = WALL; //��
			else base[i][j] = 0;
		}
	}

	//���� ����
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
	cout << "�����������������";*/
	for (int i = 0; i < PLAY1 + 2; i++,y++) {
		for (int j = 0, x=30; j < PLAY1 + 2; j++) {
			if (base[i][j] == WALL) {
				setColor(6, 0); //�����
			}else if (base[i][j] == MINE) {
				setColor(3, 0); //���� ��ġ Ȯ�� ���� �ϼ��ϸ� �����
			}
			gotoxy(x++,y);
			cout << "��";
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

	int i = 1, j = 1;

	gotoxy(p_x, p_y); //31, 11
	cout << "��";
	while (1) {
		int n = keyControl();
		switch (n)
		{
		case W: { //���� �ö󰡱� y����
			if (p_y>11) { 
				gotoxy(p_x, p_y);
				cout << "��";
				gotoxy(p_x, --p_y);
				cout << "��";
				i--;
			}
			break;
		}
		case S: { //�Ʒ��� �������� y����
			 if (p_y<24) { 
				 gotoxy(p_x, p_y);
				 cout << "��";
				 gotoxy(p_x, ++p_y);
				 cout << "��";
				 i++;
			}
			break;
		}
		case D: { //���������� �̵��ϱ� x����
			if (p_x < 44) {
				gotoxy(p_x, p_y);
				cout << "��";
				gotoxy(++p_x, p_y);
				cout << "��";
				j++;
			}
			break;
		}
		case A: { //�������� �̵��ϱ� x����
			if (p_x > 31) {
				gotoxy(p_x, p_y);
				cout << "��";
				gotoxy(--p_x, p_y);
				cout << "��";
				j--;
			}
			break;
		}
		case ENTER: {
			switch (base[i][j]) {
			case 0: {
				gotoxy(p_x, p_y);
				cout << "  ";
				break;
			}
			case 1: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 2: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 3: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 4: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 5: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 6: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 7: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case 8: {
				gotoxy(p_x, p_y);
				cout << "��";
				break;
			}
			case MINE: {
				//���� ����
			}
			
			}
		}
		case SHIFT: {
		
		}
		default: {}
		}

	}
}

void GameBase::gameStart() {
	showGameBoard();
	movePlayer();
}
