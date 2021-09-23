#include "main.h"

GameBase::GameBase() {
	mine = PLAY1_mine; //���� ���� �̰� �ֳ־���..?

	p_x = 31;
	p_y = 11;

	base = new short* [PLAY1 + 2]; //2���� �Ҵ�, ������
	for (int i = 0; i < PLAY1 + 2; i++) {
		base[i] = new short[PLAY1 + 2];
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

		if (base[a][b] == MINE || base[a][b] == WALL) continue; //���⿡ WALL�� üũ �Ǿ��ϴ�
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
			}
			else if (base[i][j] == MINE) {
				setColor(3, 0); //���� ��ġ Ȯ�� ���� �ϼ��ϸ� �����
			}
			gotoxy(x++,y);
			cout << "��";
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

	gotoxy(p_x, p_y); //31, 11
	setColor(4, 0);
	cout << "��";

	while (1) {

		setColor(15, 0);
		gotoxy(40, 30);
		cout << "ã�� ���� ���� : " << f << " / " << PLAY1_mine;

		int n = keyControl();
		switch (n)
		{
		case W: { //���� �ö󰡱� y����
			if (p_y>11) { 
				gotoxy(p_x, p_y);
				setColor(15,0);
				cout << showNumber(i, j);
				i--;
				gotoxy(p_x, --p_y);
				setColor(4, 0);
				cout << showNumber(i, j);
				
			}
			break;
		}
		case S: { //�Ʒ��� �������� y����
			 if (p_y<24) { 
				 gotoxy(p_x, p_y);
				 setColor(15, 0);
				 cout << showNumber(i, j);
				 i++;
				 gotoxy(p_x, ++p_y);
				 setColor(4, 0);
				 cout << showNumber(i, j);
				
			}
			break;
		}
		case D: { //���������� �̵��ϱ� x����
			if (p_x < 44) {
				gotoxy(p_x, p_y);
				setColor(15, 0);
				cout << showNumber(i, j);
				j++;
				gotoxy(++p_x, p_y);
				setColor(4, 0);
				cout << showNumber(i, j);
				
			}
			break;
		}
		case A: { //�������� �̵��ϱ� x����
			if (p_x > 31) {
				gotoxy(p_x, p_y);
				setColor(15, 0);
				cout << showNumber(i, j);
				gotoxy(--p_x, p_y);
				j--;
				setColor(4, 0);
				cout << showNumber(i, j);
				
			}
			break;
		}
		case ENTER: {
			if (checked[i - 1][j - 1] == 0) {
				checked[i - 1][j - 1] = 1; //����
				gotoxy(p_x, p_y);
				setColor(4, 0);
				cout << showNumber(i, j);
			}
			break;
				
		}
		case SHIFT: {
			if (checked[i - 1][j - 1] == 0) {
				checked[i - 1][j - 1] = 2; //���
				gotoxy(p_x, p_y);
				setColor(4, 0);
				cout << showNumber(i, j);
				f++;
			}
			else if (checked[i - 1][j - 1] == 2) {
				checked[i - 1][j - 1] = 0;
				gotoxy(p_x, p_y);
				setColor(4, 0);
				cout << showNumber(i, j);
				f--;
			}
			break;
		}
		default: {}
		}
		setColor(15, 0);
	}
}
string GameBase::showNumber(int i, int j) {
	if (checked[i-1][j-1]==1) {
		switch (base[i][j]) {
		case 0: return "��";
		case 1: return "��";
		case 2: return "��";
		case 3: return "��";
		case 4: return "��";
		case 5: return "��";
		case 6: return "��";
		case 7: return "��";
		case 8: return "��";
		case MINE: {
			//���� ����
			gotoxy(40, 30);
			cout << "���ӿ���";
			break;
		}
		default: {}
		}
	}
	else if (checked[i - 1][j - 1] == 2) {
		return "��";
	}
	else {
		return "��";
	}
	
	return "";
}

void GameBase::gameStart() {
	showGameBoard();
	movePlayer();
}
