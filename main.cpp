#include "main.h"

using namespace std;

int main()
{
	//隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	//开始游戏
	//设置窗口名字
	system("title Snake");
	control *CU = new control;
	control control;
	control.OpenMusic();
	while (true)
	{
		//control. menu();
		system("color F0");
		CU->menu();
		unit::gotoxy(40,35);
		system("echo 按任意键继续...&pause>nul");
		system("CLS");
	}
	delete CU;
	CU = NULL;
	return 0;
}
/*int main()
{
	control control;
	control.drawtest();
	food* feed = new food;
	feed->createPos();
	feed->show();
	snake s;
	while (true)
	{
		if (s.snakeLifeDeath())
		{
			s.showbody();
			s.changeDirection();
			s.erasebody();
			s.move();
			control.drawGameInfo();
			s.eatFood(feed);
			control.drawGameInfo();
		}
		else
		{
			s.showbody();
			break;
		}
	}
	feed->createPos();
	feed->show();
	system("pause>nul");
}*/
