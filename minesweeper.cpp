#include "main.h"

GameBase game1(1,10, 10);
GameBase game2(2,30, 10);

void gameStart1() {
	game1.movePlayer();
}
void gameStart2() {
	game2.movePlayer();
}
int main() {
	init();
	srand((unsigned)time(0));
	//titleDraw();
	
	/*GameBase game(31,11);
	game.gameStart();*/

	/*GameBase game1(10,10);
	GameBase game2(30,10);*/
	
	game1.showGameBoard();
	game2.showGameBoard();

	thread t1(gameStart1);
	thread t2(gameStart2);
	
	t1.join();
	t2.join();
	
	//gameStart(10);
	return 0;
}

//int main() {
//	srand((unsigned)time(0));
//	int player = 1; //1�ο� / 2�ο�
//
//	init();
//	while (1) {
//		titleDraw(); //Ÿ��Ʋ �׸���
//		int menuCode = menuDraw(player); //���� �޴� �����ߴ���
//		switch (menuCode) {
//		case 0: gameStartMenu(player); break;//���� ����
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

