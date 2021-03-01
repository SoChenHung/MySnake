#include "unit.h"

int unit::KSCORE_OFFSET = 0; //得分初始值
string unit::KLEVEL_OFFSET = "未知";

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
