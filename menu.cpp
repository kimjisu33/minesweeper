#include"main.h"



void titleDraw() {
	gotoxy(32, 10);
	cout << "minesweeper title" << endl;

}

int menuDraw(short& player) {
	//wŰ �ƴϰ� �ٸ�Ű ������ ��ĭ �ö� ���߿� �ذ��Ϸ�

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
		case W: {
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
					if (keyControl() == A || keyControl() == D) { //�ο��� ���ϱ�
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
		case S: {
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
		cout << "1�ο� ���� ȭ��~" << endl;
		cout << "�� : W" << endl
			<< "�� : S" << endl
			<< "�� : A" << endl
			<< "�� : D" << endl
			<< "����ã�� : Enter" << endl
			<< "��� ��ġ�ϱ� / �����ϱ� : Shift" << endl<<endl;
		cout << "14 x 14 �� ������ 40���� ���� ã��!!" << endl
			<< "���ڸ� �����ϸ� ���� ����!!!" << endl << endl;
	}
	else if (player == 2) {
		cout << "2�ο� ���� ȭ��~" << endl;
		cout << "Player1" << endl
			<< "�� : W" << endl
			<< "�� : S" << endl
			<< "�� : A" << endl
			<< "�� : D" << endl
			<< "����ã�� : Space" << endl
			<< "��� ��ġ�ϱ� / �����ϱ� : Ctrl" << endl << endl;
		cout << "Player2" << endl
			<< "�� : ����Ű ��" << endl
			<< "�� : ����Ű ��" << endl
			<< "�� : ����Ű ��" << endl
			<< "�� : ����Ű ��" << endl
			<< "����ã�� : Enter" << endl
			<< "��� ��ġ�ϱ� / �����ϱ� : Shift" << endl << endl;
		cout << "15 x 20 �� ������ 75���� ���� ã��!!" << endl
			<< "10 x 5�� ����ĭ���� ���ڸ� ��� ã���� ���� ������ ���ڸ� ã�� �� �ִ�." << endl
			<< "���ڸ� �����ϸ� ���� ����!!!" << endl
			<< "��� ���ڸ� ã�� �� �� ���� ���ڸ� ã�� ����� �¸�" << endl;
	}
	

	cout << "enter �Ǵ� space�� ������ ���ư��ϴ�." << endl;

	while (1) {
		if (keyControl() == SPACE || keyControl() == ENTER) break;
	}
}

void gameStart(short player) {
	system("cls");
	if (player == 1) {
		//cout << "1�ο� ���� ȭ��~" << endl;
		GameBase game(1);
		game.gameStart();

	}
	else if (player == 2) {
		//cout << "2�ο� ���� ȭ��~" << endl;
		GameBase game(2);
		game.gameStart();
	}

	//cout << "enter �Ǵ� space�� ������ ���ư��ϴ�." << endl;

	/*while (1) {
		if (keyControl() == SPACE || keyControl() == ENTER) break;
	}*/
}




