#pragma once

#include<iostream>
#include<random>
#include<Windows.h>
#include<cstring>
//#include <thread>
//#include<conio.h>
//#include "food.h"
#include "snake.h"
using namespace std;
class control
{
public:
	control() {
		//HANDLE hOut;
		//CONSOLE_SCREEN_BUFFER_INFO scr;

		//hOut = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������ 
		//GetConsoleScreenBufferInfo(hOut, &scr);
		//m_coor.X = scr.srWindow.Right;
		//m_coor.Y = scr.srWindow.Bottom;
	}
	virtual ~control();
	void drawGameArea(); //��Ϸ����
	void drawGameInfo(); //��Ϸ����
	void OpenMusic(); //������
	void CloseMusic(); //�ر�����
	void color(int color); //��ɫ����
	void GameRule(); //��Ϸ����
	void Run(); //��Ϸ����
	void menu(); //���˵�
	void temporyMenu();//��ʱ�˵�
	//void drawtest();
	//void getBufferInfo();
	static void gotoxy(int x, int y);
public:
	//�˵�Ԫ��
	vector<const char*>main_menus;
	vector<const char*>tempory_menus;
	food* food_feed ;
	COORD m_coor;
	snake* s ;
	control* command ;
	//�˵�ָ��
	int menu_command = 0;
};