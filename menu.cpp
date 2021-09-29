#include"main.h"



void titleDraw() {
	gotoxy(32, 10);
	cout << "minesweeper title" << endl;

}

int menuDraw(short& player) {
	//w키 아니고 다른키 눌러도 한칸 올라감 나중에 해결하렴

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
		case W: {
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
		case S: {
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

void infoDraw(short player) {
	system("cls");

	if (player == 1) {
		cout << "1인용 설명 화면~" << endl;
		cout << "상 : W" << endl
			<< "하 : S" << endl
			<< "좌 : A" << endl
			<< "우 : D" << endl
			<< "지뢰찾기 : Enter" << endl
			<< "깃발 설치하기 / 수거하기 : Shift" << endl<<endl;
		cout << "14 x 14 의 땅에서 40개의 지뢰 찾기!!" << endl
			<< "지뢰를 선택하면 게임 오버!!!" << endl << endl;
	}
	else if (player == 2) {
		cout << "2인용 설명 화면~" << endl;
		cout << "Player1" << endl
			<< "상 : W" << endl
			<< "하 : S" << endl
			<< "좌 : A" << endl
			<< "우 : D" << endl
			<< "지뢰찾기 : Space" << endl
			<< "깃발 설치하기 / 수거하기 : Ctrl" << endl << endl;
		cout << "Player2" << endl
			<< "상 : 방향키 ↑" << endl
			<< "하 : 방향키 ↓" << endl
			<< "좌 : 방향키 →" << endl
			<< "우 : 방향키 →" << endl
			<< "지뢰찾기 : Enter" << endl
			<< "깃발 설치하기 / 수거하기 : Shift" << endl << endl;
		cout << "15 x 20 의 땅에서 75개의 지뢰 찾기!!" << endl
			<< "10 x 5의 개인칸에서 지뢰를 모두 찾으면 공동 구역의 지뢰를 찾을 수 있다." << endl
			<< "지뢰를 선택하면 게임 오버!!!" << endl
			<< "모든 지뢰를 찾은 후 더 많은 지뢰를 찾은 사람이 승리" << endl;
	}
	

	cout << "enter 또는 space를 누르면 돌아갑니다." << endl;

	while (1) {
		if (keyControl() == SPACE || keyControl() == ENTER) break;
	}
}

void gameStart(short player) {
	system("cls");
	if (player == 1) {
		//cout << "1인용 게임 화면~" << endl;
		GameBase game(1);
		game.gameStart();

	}
	else if (player == 2) {
		//cout << "2인용 게임 화면~" << endl;
		GameBase game(2);
		game.gameStart();
	}

	//cout << "enter 또는 space를 누르면 돌아갑니다." << endl;

	/*while (1) {
		if (keyControl() == SPACE || keyControl() == ENTER) break;
	}*/
}




