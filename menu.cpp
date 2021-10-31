#include"main.h"



void titleDraw() {
	setColor(11, 0);
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

	setColor(15, 0);

	int x = 37;
	int y = 20;
	gotoxy(x, y - 2);
	cout << "�� "<< player <<"�� ��";
	gotoxy(x - 1, y);
	cout << "> ���� ����";
	gotoxy(x, y + 1);
	cout << "���� ����";
	gotoxy(x, y + 2);
	cout << "���� ����";

	while (1) {
		int n = keyControl();
		switch (n)
		{
		case W: case UP:{
			if (y > 20) { //20���� ������ �ȿ�����
				gotoxy(x - 1, y); //���� �ִ� �ڸ� ȭ��ǥ ���ֱ�
				cout << " ";
				gotoxy(x - 1, --y); //ȭ��ǥ ���� �̵�
				cout << ">";
			}else if (y == 20) { // player �ο� �޴� ����
				gotoxy(x - 1, y);
				cout << " ";
				y -= 2;
				gotoxy(x-1, y);
				cout << ">";
				gotoxy(37, 18);
				cout << "�� " << player << "�� ��";
				while (1) {
					if (keyControl() == A || keyControl() == D|| keyControl() == LEFT || keyControl() == RIGHT) { //�ο��� ���ϱ�
						if (player == 1) player = 2;						
						else if (player == 2) player = 1;

						gotoxy(37, 18);
						cout << "�� " << player << "�� ��";
					
					}
					else { break; }
				}
			}
			break;
		}
		case S: case DOWN:{
			if (y == 18) { // player �ο� �޴� ����������
				
				gotoxy(x - 1, y); 
				cout << " ";
				y += 2;
				gotoxy(x - 1, y);
				cout << ">";
				gotoxy(37, 18);
				cout << "�� " << player << "�� ��";
			}
			else if (y < 22) { //22���� ũ�� �ȿ�����
				gotoxy(x - 1, y); //���� �ִ� �ڸ� ȭ��ǥ ���ֱ�
				cout << " ";
				gotoxy(x - 1, ++y); //ȭ��ǥ �Ʒ��� �̵�
				cout << ">";
			}
			break;
		}
		case SPACE: {
			PlaySound(TEXT("sound\\menu_click"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			return y - 20;
		}
		case ENTER: {
			PlaySound(TEXT("sound\\menu_click"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			return y - 20;
		}
		default: {}
		}

	}
}

void infoDraw(int player) {
	system("cls");

	if (player == 1) {
		cout << "1�ο� ����" << endl<<endl;

		cout << "�� : W" << endl
			<< "�� : S" << endl
			<< "�� : A" << endl
			<< "�� : D" << endl
			<< "����ã�� : Space" << endl
			<< "��� ��ġ�ϱ� / �����ϱ� : Tab" << endl<<endl;
		
		cout << "14 x 14 �� ������ 25���� ���� ã�� !!" << endl
			<< "���ڸ� �����ϸ� ���� ���� !!!" << endl << endl<<endl;
	}
	else if (player == 2) {
		cout << "2�ο� ����" << endl<<endl;
		cout << "PLAYER 1" << endl
			<< "�� : W" << endl
			<< "�� : S" << endl
			<< "�� : A" << endl
			<< "�� : D" << endl
			<< "����ã�� : Space" << endl
			<< "��� ��ġ�ϱ� / �����ϱ� : Tab" << endl << endl;

		cout << "PLAYER 2" << endl
			<< "�� : ����Ű ��" << endl
			<< "�� : ����Ű ��" << endl
			<< "�� : ����Ű ��" << endl
			<< "�� : ����Ű ��" << endl
			<< "����ã�� : Enter" << endl
			<< "��� ��ġ�ϱ� / �����ϱ� : M" << endl << endl;

		cout << "14 x 14 �� ������ 25���� ���� ã��!!" << endl
			<< "���ڸ� �����ϸ� ���� ����!!!(������ �¸�)" << endl;
		cout << "���� ���ڸ� ��� ã�� ����� �¸�!" << endl << endl<<endl;
	}
	

	system("pause");
}


void gameStartMenu(int player) {
	system("cls");
	GameBase::over = false;
	if (player == 1) {
		//cout << "1�ο� ���� ȭ��~" << endl;
		
		GameBase game(1,31,11);
		game.gameStart();

	}
	else if (player == 2) {
		//cout << "2�ο� ���� ȭ��~" << endl;
		thread t1([]() {
			srand((unsigned)time(0));
			GameBase game1(2, 15, 11);
			game1.gameStart();
			});
		thread t2([]() {
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			srand((unsigned)time(0));
			GameBase game2(3, 45, 11);
			game2.gameStart();
			});

		t1.join();
		t2.join();
			
	}

}


