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

		//hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄 
		//GetConsoleScreenBufferInfo(hOut, &scr);
		//m_coor.X = scr.srWindow.Right;
		//m_coor.Y = scr.srWindow.Bottom;
	}
	virtual ~control();
	void drawGameArea(); //游戏区域
	void drawGameInfo(); //游戏索引
	void OpenMusic(); //打开音乐
	void CloseMusic(); //关闭音乐
	void color(int color); //颜色设置
	void GameRule(); //游戏规则
	void Run(); //游戏运行
	void menu(); //主菜单
	void temporyMenu();//临时菜单
	//void drawtest();
	//void getBufferInfo();
	static void gotoxy(int x, int y);
public:
	//菜单元素
	vector<const char*>main_menus;
	vector<const char*>tempory_menus;
	food* food_feed ;
	COORD m_coor;
	snake* s ;
	control* command ;
	//菜单指令
	int menu_command = 0;
};