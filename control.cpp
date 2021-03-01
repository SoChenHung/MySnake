#include "control.h"
//int control::KSCORE_OFFSET = 0; //得分初始值
//string control::KLEVEL_OFFSET = "未知"; //关卡初始值
//const int in_terface::KWIDTH = m_coor.X - 2 * KLEFT;
//const int in_terface::KHEIGHT = m_coor.Y - 1 - 2 * KUP;

void control::gotoxy(int x, int y)
{
	HANDLE hOut;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
void control::drawGameArea()
{
	int N = 0;//用于移动光标的偏移值，保证每一行都是从横坐标为KLEFT的点开始
	for (int coord_y = 0; coord_y <= unit::KHEIGHT - unit::KUP ; coord_y++)
	{
		gotoxy(unit::KLEFT, unit::KUP + N);
		for (int coord_x = 0; coord_x <= unit::KWIDTH - unit::KLEFT; coord_x++)
		{
			//第一行和最后一行以及界面索引所在位置下面的一行
			if (coord_y == 0 || coord_y == unit::KHEIGHT - 3 || (coord_y == unit::KHEIGHT - 43 && coord_x != 0 && coord_x != 77))
			{
				cout << "-";
			}
			//界面索引所在的行
			else if (coord_y == unit::KHEIGHT - 44)
			{
				if (coord_x == 0 || coord_x == 77)
				{
					cout << "|";
				}
				else drawGameInfo();
			}
			//除去第一行和最后一行的其他行
			else if (coord_x == 0 || coord_x == 77)
			{
				cout << "|";
			}
			else cout << " ";
		}
		N++;
		//cout << N;
	}	
}
void control::drawGameInfo()
{
	gotoxy(6, unit::KHEIGHT - 41);
	cout << "游戏名称： 贪吃蛇";
	gotoxy(26, unit::KHEIGHT - 41);
	cout << "编写者：S.C.H";
	gotoxy(46, unit::KHEIGHT - 41);
	cout << "当前得分：" << unit::KSCORE_OFFSET;
	gotoxy(62, unit::KHEIGHT - 41);
	cout << "当前难度：" << unit::KLEVEL_OFFSET<<"    ";
	/*gotoxy(KLEFT + 1, KUP + 1);

	cout << "游戏名称：贪吃蛇";

	gotoxy(KLEFT + 20, KUP + 1);

	cout << "编写者：***";

	gotoxy(KLEFT + 40, KUP + 1);

	cout << "当前得分";

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	gotoxy(KLEFT + 55, KUP + 1);

	cout << "当前关卡";

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;*/
}

//void control::drawtest()
//
//{
//	for (int i = unit::KLEFT; i <= m_coor.X - 2 * unit::KLEFT; i++)
//	{
//		gotoxy(i, unit::KUP);
//		cout << "-";
//		gotoxy(i, unit::KUP + 2);
//		cout << "-";
//		gotoxy(i, m_coor.Y - 2 * unit::KUP);
//		cout << "-";
//	}
//
//	for (int i = unit::KUP + 1; i <= m_coor.Y - 1 - 2 * unit::KUP; i++)
//	{
//		gotoxy(unit::KLEFT, i);
//		cout << "|";
//		gotoxy(m_coor.X - 2 * unit::KLEFT, i);
//		cout << "|";
//	}
//	drawGameInfo();
//	//cout<<m_coor.X<<","<<m_coor.Y;
//}


//播放音乐
void control::OpenMusic()
{
	mciSendString(TEXT("open D:/QQmusic_save/5.wma alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
}
//关闭音乐
void control::CloseMusic()
{
	mciSendString(TEXT("close mysong"), NULL, 0, NULL);
}
//颜色函数
void control::color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//游戏规则
void control::GameRule()
{
	//color(9);
	system("color 1F");
	gotoxy(30, 15);
	cout << "按键w、s、a、d控制上下左右,大小写不敏感";
	gotoxy(30, 17);
	cout << "按键+，- 可以调整蛇的移动速度，从而改变游戏难易程度";
	gotoxy(30, 19);
	cout << "按任意键开始游戏，按空格暂停游戏，游戏中按q或者Q均可直接退出游戏";
	gotoxy(30, 21);
	cout<<"游戏中按R或者r或者ESC均可进入临时菜单";
	gotoxy(30, 23);
	cout << "蛇头碰到墙或者碰到蛇身都会死亡";
	gotoxy(30, 25);
	cout << "不同难度下吃到的食物得分各不相同";
	//color(7);
}
//运行函数
void control::Run()
{
	if (tempory_menus.size())
	{
		vector <const char*>().swap(tempory_menus);
	}
	food_feed = new food;
	s = new snake;
	command = new control;
	char ch;
	//color(9);
	system("color 1F");
	command->drawGameArea();
	//face.drawtest();
	s->showbody();
	ch = _getch();
	s->erasebody();
	food_feed->createPos();
	food_feed->show();
	while (true)
	{
		if (s->snakeLifeDeath())
		{
			s->showbody();
			s->changeDirection();
			s->erasebody();
			s->move();
			command->drawGameInfo();
			s->eatFood(food_feed); 
			command->drawGameInfo();
			if (s->order == 2)
			{
				system("CLS");
				system("color 7");
				cout<<'\a';
				MessageBoxA(NULL, "game over！", "Snake", 0);
				s->order = 0;
				break;
			}
			if (s->order == 100)
			{
				system("CLS");
				//system("color 7");
				temporyMenu();
				if (menu_command == 1)
				{
					command->drawGameArea();
					command->drawGameInfo();
					food_feed->show();
					s->showbody();
					ch = _getch();
					s->erasebody();
					s->order = 0;
					menu_command = 0;
				}
			}
		}
		else
		{
			s->showbody();
			gotoxy(s->Head_dx, s->Head_dy);
			cout << '\a';
			MessageBoxA(NULL, "game over！", "Snake", 0);
			unit::KSCORE_OFFSET = 0;
			unit::KLEVEL_OFFSET = "未知";
			//color(7);
			delete s;
			delete command;
			//delete food_feed;
			break;
		}
	}
}
//主菜单函数
void control::menu()
{
	char choose;
	static int t = 0;
	int N = 0;	
	const char* old_menu[3] = { "开 始 游 戏" ,"游 戏 规 则","退 出 游 戏" };
	for (int i = 0; i < 3; i++)
	{
		main_menus.push_back(old_menu[i]);
	}
	for (unsigned int i = 0; i < main_menus.size(); i++)
	{
		gotoxy(50, 20+N);
		cout << i + 1 << "." << main_menus[i];
		N += 5;
	}
	choose = _getch();
	if (choose == '1')
	{
		t += 1;
		system("CLS");
		//加载进度条,只加载最开始的一次
		if (t == 1)
		{
			cout << "Loading：" << endl;
			for (int i = 0; i <= 100; i++)
			{
				cout << '\b' << '\b' << '\b' << i << "%";
				Sleep(20);
			}
			Sleep(30);
		}
		system("CLS");
		Run();
	}
	else if (choose == '2')
	{
		system("CLS");
		GameRule();
	}
	else if (choose == '3')
	{
		system("CLS");
		gotoxy(35, 8);
		cout << '\a';
		system("color 7");
		MessageBoxA(NULL, "感谢使用！", "Snake", 0);
		CloseMusic();
		exit(1);
	}
	else
	{
		system("CLS");
		gotoxy(45, 20);
		cout << '\a';
		MessageBoxA(NULL, "ERROR！", "Snake", 0);
	}
	vector <const char*>().swap(main_menus);//清空内存
}
//临时菜单
void control::temporyMenu()
{
	//snake* ss = new snake;
	control *command = new control;
	char choose ;
	//int N = 5;
	const char* new_menu[4] = { "继 续 游 戏","重 新 开 始","游 戏 规 则","退 出 游 戏" };
	for (int i = 0; i < 4; i++)
	{
		tempory_menus.push_back(new_menu[i]);
	}
	while (1)
	{
		system("CLS");
		//system("color 7");
		system("color F0");
		int N = 5;
		for (unsigned int i = 0; i < tempory_menus.size(); i++)
		{
			gotoxy(50, 10 + N);
			cout << i + 1 << "." << tempory_menus[i];
			N += 5;
		} 
		choose = _getch();
		if (choose == '1')
		{
			system("color 1F");
			menu_command = 1;
			break;
		}
		else if (choose == '2')
		{
			/*unit::KSCORE_OFFSET = 0;
			unit::KLEVEL_OFFSET = "未知";
			Run();*/
			system("CLS");
			system("color 1F");
			char ch;
			delete s;
			delete command;
			s = new snake;
			command = new control;
			unit::KSCORE_OFFSET = 0;
			unit::KLEVEL_OFFSET = "未知";
			command->drawGameArea();
			command->drawGameInfo();
			food_feed->erase();
			food_feed->createPos();
			food_feed->show();
			s->order = 0;
			s->showbody();
			ch = _getch();
			s->erasebody();
			break; 
		}
		else if (choose == '3')
		{
			system("CLS");
			GameRule();
			gotoxy(40, 35);
			system("echo 按任意键继续...&pause>nul");
			continue;
		}
		else if (choose == '4')
		{
			system("CLS");
			gotoxy(35, 8);
			cout << '\a';
			system("color 7");
			MessageBoxA(NULL, "感谢使用！", "Snake", 0);
			CloseMusic();
			exit(1);
		}
		else
		{
			system("CLS");
			gotoxy(45, 20);
			cout << '\a';
			MessageBoxA(NULL, "ERROR！", "Snake", 0);
			//gotoxy(40, 35);
			//system("echo 按任意键继续...&pause>nul");
			continue;
		}
	}
	//vector <const char*>().swap(menus);
	//tempory_menus.erase(tempory_menus.begin(),tempory_menus.end());
	vector <const char*>().swap(tempory_menus);
}
control::~control()
{
	delete s;
	s = NULL;
	delete command;
	command = NULL;
	delete food_feed;
	food_feed = NULL;
}
