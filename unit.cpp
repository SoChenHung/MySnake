#include "unit.h"

int unit::KSCORE_OFFSET = 0; //�÷ֳ�ʼֵ
string unit::KLEVEL_OFFSET = "δ֪";

void unit::show()
{
	gotoxy(dx,dy);
	cout << pic;
}
void unit::erase()
{
	gotoxy(dx, dy);
	cout << " ";

}
void unit::gotoxy(int x,int y)
{
	HANDLE hOut;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);

}
unit::~unit() {}
