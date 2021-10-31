#include "main.h"

//
//int main() {
//	init();
//	srand((unsigned)time(0));
//	//titleDraw();
//	
//	/*GameBase game(1,31,11);
//	game.gameStart();*/
//
//	/*GameBase game1(2, 15, 11);
//	GameBase game2(3, 45, 11);
//	game1.showGameBoard();
//	game2.showGameBoard();*/
//
//	thread t1([]() {
//		srand((unsigned)time(0));
//		GameBase game1(2, 15, 11);
//		game1.gameStart();
//		});
//	thread t2([]() {
//		this_thread::sleep_for(std::chrono::milliseconds(1000));
//		srand((unsigned)time(0));
//		GameBase game2(3, 45, 11);
//		game2.gameStart();
//		});
//	
//	t1.join();
//	t2.join();
//	
//	return 0;
//}

int main() {
	srand((unsigned)time(0));
	int player = 1; //1인용 / 2인용

	init();
	while (1) {
		titleDraw(); //타이틀 그리기
		int menuCode = menuDraw(player); //무슨 메뉴 선택했는지
		switch (menuCode) {
		case 0: gameStartMenu(player); break;//게임 시작
		case 1: infoDraw(player); break; //게임 설명
		case 2: return 0; //종료
		}
		system("cls"); //콘솔창 지우기
	}
	

	cout << endl << endl;
	return 0;
}

