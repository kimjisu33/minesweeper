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
//	short player = 1; //1인용 / 2인용
//
//	init();
//	while (1) {
//		titleDraw(); //타이틀 그리기
//		int menuCode = menuDraw(player); //무슨 메뉴 선택했는지
//		switch (menuCode) {
//		case 0: gameStart(player); break;//게임 시작
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

