#include "main.h"

GameBase::GameBase() {
	mine = PLAY1_mine; //���� ����

	base = new int* [PLAY1 + 2]; //2���� �Ҵ�, ������
	for (int i = 0; i < PLAY1 + 2; i++) {
		base[i] = new int[PLAY1 + 2];
	}

	for (int i = 0; i < PLAY1 + 2; i++) {
		for (int j = 0; j < PLAY1 + 2; j++) {
			if (i == 0 || i == PLAY1 + 1 || j == 0 || j == PLAY1 + 1) base[i][j] = 3;
			else base[i][j] = 0;
		}
	}

	int i = 0;
	while (i < mine) {
		int a = rand() % PLAY1 + 1; //1~10
		int b = rand() % PLAY1 + 1; //1~10

		//���ڻ���
		if (base[a][b] == 1 || base[a][b] == 3) continue;
		else {
			base[a][b] = 1;
			i++;
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
	for (int i = 0; i < PLAY1 + 2; i++) {
		for (int j = 0; j < PLAY1 + 2; j++) {
			if (base[i][j] == 3) {
				setColor(6, 6); //�����
			}else if (base[i][j] == 1) {
				setColor(3, 0); //���� ��ġ Ȯ�� ���� �ϼ��ϸ� �����
			}
			cout << "��";
			setColor(7, 0);
		}
		cout << endl;
	}
}