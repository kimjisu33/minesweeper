#include "main.h"

GameBase game1(2,11, 11);
GameBase game2(3,30, 11);

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
	
	GameBase game(1,31,11);
	game.gameStart();
	
	/*game1.showGameBoard();
	game2.showGameBoard();

	thread t1(gameStart1);
	thread t2(gameStart2);
	
	t1.join();
	t2.join();*/
	
	//gameStart(10);
	return 0;
}

//int main() {
//	srand((unsigned)time(0));
//	int player = 1; //1인용 / 2인용
//
//	init();
//	while (1) {
//		titleDraw(); //타이틀 그리기
//		int menuCode = menuDraw(player); //무슨 메뉴 선택했는지
//		switch (menuCode) {
//		case 0: gameStartMenu(player); break;//게임 시작
//		case 1: infoDraw(player); break; //게임 설명
//		case 2: return 0; //종료
//		}
//		system("cls"); //콘솔창 지우기
//	}
//	
//
//	cout << endl << endl;
//	return 0;
//}

