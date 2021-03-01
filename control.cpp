#include "control.h"
//int control::KSCORE_OFFSET = 0; //�÷ֳ�ʼֵ
//string control::KLEVEL_OFFSET = "δ֪"; //�ؿ���ʼֵ
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
	int N = 0;//�����ƶ�����ƫ��ֵ����֤ÿһ�ж��ǴӺ�����ΪKLEFT�ĵ㿪ʼ
	for (int coord_y = 0; coord_y <= unit::KHEIGHT - unit::KUP ; coord_y++)
	{
		gotoxy(unit::KLEFT, unit::KUP + N);
		for (int coord_x = 0; coord_x <= unit::KWIDTH - unit::KLEFT; coord_x++)
		{
			//��һ�к����һ���Լ�������������λ�������һ��
			if (coord_y == 0 || coord_y == unit::KHEIGHT - 3 || (coord_y == unit::KHEIGHT - 43 && coord_x != 0 && coord_x != 77))
			{
				cout << "-";
			}
			//�����������ڵ���
			else if (coord_y == unit::KHEIGHT - 44)
			{
				if (coord_x == 0 || coord_x == 77)
				{
					cout << "|";
				}
				else drawGameInfo();
			}
			//��ȥ��һ�к����һ�е�������
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
	cout << "��Ϸ���ƣ� ̰����";
	gotoxy(26, unit::KHEIGHT - 41);
	cout << "��д�ߣ�S.C.H";
	gotoxy(46, unit::KHEIGHT - 41);
	cout << "��ǰ�÷֣�" << unit::KSCORE_OFFSET;
	gotoxy(62, unit::KHEIGHT - 41);
	cout << "��ǰ�Ѷȣ�" << unit::KLEVEL_OFFSET<<"    ";
	/*gotoxy(KLEFT + 1, KUP + 1);

	cout << "��Ϸ���ƣ�̰����";

	gotoxy(KLEFT + 20, KUP + 1);

	cout << "��д�ߣ�***";

	gotoxy(KLEFT + 40, KUP + 1);

	cout << "��ǰ�÷�";

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	gotoxy(KLEFT + 55, KUP + 1);

	cout << "��ǰ�ؿ�";

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


//��������
void control::OpenMusic()
{
	mciSendString(TEXT("open D:/QQmusic_save/5.wma alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
}
//�ر�����
void control::CloseMusic()
{
	mciSendString(TEXT("close mysong"), NULL, 0, NULL);
}
//��ɫ����
void control::color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//��Ϸ����
void control::GameRule()
{
	//color(9);
	system("color 1F");
	gotoxy(30, 15);
	cout << "����w��s��a��d������������,��Сд������";
	gotoxy(30, 17);
	cout << "����+��- ���Ե����ߵ��ƶ��ٶȣ��Ӷ��ı���Ϸ���׳̶�";
	gotoxy(30, 19);
	cout << "���������ʼ��Ϸ�����ո���ͣ��Ϸ����Ϸ�а�q����Q����ֱ���˳���Ϸ";
	gotoxy(30, 21);
	cout<<"��Ϸ�а�R����r����ESC���ɽ�����ʱ�˵�";
	gotoxy(30, 23);
	cout << "��ͷ����ǽ������������������";
	gotoxy(30, 25);
	cout << "��ͬ�Ѷ��³Ե���ʳ��÷ָ�����ͬ";
	//color(7);
}
//���к���
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
				MessageBoxA(NULL, "game over��", "Snake", 0);
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
			MessageBoxA(NULL, "game over��", "Snake", 0);
			unit::KSCORE_OFFSET = 0;
			unit::KLEVEL_OFFSET = "δ֪";
			//color(7);
			delete s;
			delete command;
			//delete food_feed;
			break;
		}
	}
}
//���˵�����
void control::menu()
{
	char choose;
	static int t = 0;
	int N = 0;	
	const char* old_menu[3] = { "�� ʼ �� Ϸ" ,"�� Ϸ �� ��","�� �� �� Ϸ" };
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
		//���ؽ�����,ֻ�����ʼ��һ��
		if (t == 1)
		{
			cout << "Loading��" << endl;
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
		MessageBoxA(NULL, "��лʹ�ã�", "Snake", 0);
		CloseMusic();
		exit(1);
	}
	else
	{
		system("CLS");
		gotoxy(45, 20);
		cout << '\a';
		MessageBoxA(NULL, "ERROR��", "Snake", 0);
	}
	vector <const char*>().swap(main_menus);//����ڴ�
}
//��ʱ�˵�
void control::temporyMenu()
{
	//snake* ss = new snake;
	control *command = new control;
	char choose ;
	//int N = 5;
	const char* new_menu[4] = { "�� �� �� Ϸ","�� �� �� ʼ","�� Ϸ �� ��","�� �� �� Ϸ" };
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
			unit::KLEVEL_OFFSET = "δ֪";
			Run();*/
			system("CLS");
			system("color 1F");
			char ch;
			delete s;
			delete command;
			s = new snake;
			command = new control;
			unit::KSCORE_OFFSET = 0;
			unit::KLEVEL_OFFSET = "δ֪";
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
			system("echo �����������...&pause>nul");
			continue;
		}
		else if (choose == '4')
		{
			system("CLS");
			gotoxy(35, 8);
			cout << '\a';
			system("color 7");
			MessageBoxA(NULL, "��лʹ�ã�", "Snake", 0);
			CloseMusic();
			exit(1);
		}
		else
		{
			system("CLS");
			gotoxy(45, 20);
			cout << '\a';
			MessageBoxA(NULL, "ERROR��", "Snake", 0);
			//gotoxy(40, 35);
			//system("echo �����������...&pause>nul");
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
