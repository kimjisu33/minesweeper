#include "main.h"

void init() {
	system("mode con cols=150 lines=36 | title 지뢰찾기 업그레이드");
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	HANDLE consoleHandel = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandel, &ConsoleCursor);

}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x*2;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void setColor(int color, int bgcolor) {
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

int keyControl() {
	int temp = _getch();

	switch (temp) {
	case 'w':case'W': return W;
	case 'a':case'A': return A;
	case 's':case'S': return S;
	case 'd':case'D': return D;
	case 13: return ENTER;
	case 32: return SPACE;
	case 9: return SHIFT; //shift가 안먹어서 임시로 tap 키 사용
	}

	return 0;
}