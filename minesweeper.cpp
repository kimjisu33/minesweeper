#include "main.h"

int main() {
	init();
	srand((unsigned)time(0));
	//titleDraw();
	/*
	GameBase game(31,11);
	game.gameStart();
	*/
	GameBase game1(10,10);
	GameBase game2(40,10);

	game1.gameStart();
	game2.gameStart();

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

