#include "main.h"


int main() {
	srand((unsigned)time(0));
	int player = 1; //1�ο� / 2�ο�

	init();
	while (1) {
		titleDraw(); //Ÿ��Ʋ �׸���
		int menuCode = menuDraw(player); //���� �޴� �����ߴ���
		switch (menuCode) {
		case 0: gameStartMenu(player); break;//���� ����
		case 1: infoDraw(player); break; //���� ����
		case 2: return 0; //����
		}
		system("cls"); //�ܼ�â �����
	}
	

	
	return 0;
}

