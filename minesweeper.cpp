#include "main.h"

int main() {
	init();
	srand((unsigned)time(0));
	GameBase game;
	//game.showBase();
	game.showGameBoard();

	return 0;
}

//int main() {
//	srand((unsigned)time(0));
//	short player = 1; //1�ο� / 2�ο�
//
//	init();
//	while (1) {
//		titleDraw(); //Ÿ��Ʋ �׸���
//		int menuCode = menuDraw(player); //���� �޴� �����ߴ���
//		switch (menuCode) {
//		case 0: gameStart(player); break;//���� ����
//		case 1: infoDraw(player); break; //���� ����
//		case 2: return 0; //����
//		}
//		system("cls"); //�ܼ�â �����
//	}
//	
//
//	cout << endl << endl;
//	return 0;
//}

