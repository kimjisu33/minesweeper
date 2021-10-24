#include"main.h"



void titleDraw() {
	int a = 25; int b = 7;
	gotoxy(a, b++);
	cout << "minesweeper" << endl;
	gotoxy(a, b++);
	cout << " _    _  _____    _____  _____             _____   ______" << endl;
	gotoxy(a, b++);
	cout << "| |  | ||  __ \\  / ____||  __ \\     /\\    |  __ \\ |  ____|" << endl;
	gotoxy(a, b++);
	cout << "| |  | || |__) || |  __ | |__) |   /  \\   | |  | || |__" << endl;
	gotoxy(a, b++);
	cout << "| |  | ||  ___/ | | |_ ||  _  /   / /\\ \\  | |  | ||  __|" << endl;
	gotoxy(a, b++);
	cout << "| |__| || |     | |__| || | \\ \\  / ____ \\ | |__| || |____" << endl;
	gotoxy(a, b++);
	cout << " \\____/ |_|      \\_____||_|  \\_\\/_/    \\_\\|_____/ |______|" << endl;

}

int menuDraw(int& player) {
	//w키 아니고 다른키 눌러도 한칸 올라감 나중에 해결하렴

	setColor(15, 0);

	int x = 37;
	int y = 20;
	gotoxy(x, y - 2);
	cout << "▷ "<< player <<"명 ◁";
	gotoxy(x - 1, y);
	cout << "> 게임 시작";
	gotoxy(x, y + 1);
	cout << "게임 설명";
	gotoxy(x, y + 2);
	cout << "게임 종료";

	while (1) {
		int n = keyControl();
		switch (n)
		{
		case W: case UP:{
			if (y > 20) { //20보다 작으면 안움직임
				gotoxy(x - 1, y); //원래 있던 자리 화살표 없애기
				cout << " ";
				gotoxy(x - 1, --y); //화살표 위로 이동
				cout << ">";
			}else if (y == 20) { // player 인원 메뉴 들어가기
				gotoxy(x - 1, y);
				cout << " ";
				y -= 2;
				gotoxy(x-1, y);
				cout << ">";
				gotoxy(37, 18);
				cout << "▶ " << player << "명 ◀";
				while (1) {
					if (keyControl() == A || keyControl() == D) { //인원수 정하기
						if (player == 1) player = 2;						
						else if (player == 2) player = 1;

						gotoxy(37, 18);
						cout << "▶ " << player << "명 ◀";
					
					}
					else { break; }
				}
			}
			break;
		}
		case S: case DOWN:{
			if (y == 18) { // player 인원 메뉴 빠져나오기
				gotoxy(x - 1, y); 
				cout << " ";
				y += 2;
				gotoxy(x - 1, y);
				cout << ">";
				gotoxy(37, 18);
				cout << "▷ " << player << "명 ◁";
			}
			else if (y < 22) { //22보다 크면 안움직임
				gotoxy(x - 1, y); //원래 있던 자리 화살표 없애기
				cout << " ";
				gotoxy(x - 1, ++y); //화살표 아래로 이동
				cout << ">";
			}
			break;
		}
		case SPACE: {
			return y - 20;
		}
		case ENTER: {
			return y - 20;
		}
		default: {}
		}

	}
}

void infoDraw(int player) {
	system("cls");

	if (player == 1) {
		cout << "1인용 설명 화면~" << endl;
		cout << "상 : W" << endl
			<< "하 : S" << endl
			<< "좌 : A" << endl
			<< "우 : D" << endl
			<< "지뢰찾기 : Space" << endl
			<< "깃발 설치하기 / 수거하기 : Tab" << endl<<endl;
		cout << "14 x 14 의 땅에서 25개의 지뢰 찾기!!" << endl
			<< "지뢰를 선택하면 게임 오버!!!" << endl << endl;
	}
	else if (player == 2) {
		cout << "2인용 설명 화면~" << endl;
		cout << "PLAYER 1" << endl
			<< "상 : W" << endl
			<< "하 : S" << endl
			<< "좌 : A" << endl
			<< "우 : D" << endl
			<< "지뢰찾기 : Space" << endl
			<< "깃발 설치하기 / 수거하기 : Tab" << endl << endl;
		cout << "PLAYER 2" << endl
			<< "상 : 방향키 ↑" << endl
			<< "하 : 방향키 ↓" << endl
			<< "좌 : 방향키 →" << endl
			<< "우 : 방향키 →" << endl
			<< "지뢰찾기 : Enter" << endl
			<< "깃발 설치하기 / 수거하기 : M" << endl << endl;
		cout << "14 x 14 의 땅에서 25개의 지뢰 찾기!!" << endl
			<< "지뢰를 선택하면 게임 오버!!!" << endl << endl;
		cout << "먼저 지뢰를 모두 찾은 사람이 승리!" << endl;
	}
	

	system("pause");
}

//GameBase game1(10, 10);
//GameBase game2(30, 10);
//void gameStartMenu(int player) {
//	system("cls");
//	if (player == 1) {
//		//cout << "1인용 게임 화면~" << endl;
//		sGameBase game(31,11);
//		game.gameStart();
//
//	}
//	else if (player == 2) {
//		//cout << "2인용 게임 화면~" << endl;
//		game1.showGameBoard();
//		game2.showGameBoard();
//		thread t1(gameStart1);
//		thread t2(gameStart2);
//		t1.join();
//		t2.join();
//			
//	}
//
//}
//
//void gameStart1() {
//	game1.movePlayer();
//}
//void gameStart2() {
//	game2.movePlayer();
//}

