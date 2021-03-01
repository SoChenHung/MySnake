#pragma once
#include<iostream>
#include<vector>
#include<cstring>
#include<random>
#include<Windows.h>
#include<cstdlib>
#include<thread>
using namespace std;

class unit
{
public:
	int dx;//横坐标
	int dy;//纵坐标
	const char* pic;//字符/图片
	static const int KLEFT = 3; //界面左边界与左侧窗口的距离
	static const int KUP = 3;  //界面上边界与上侧窗口的距离
	static const int KWIDTH = 80; //宽度
	static const int KHEIGHT = 45; //高度
	static int KSCORE_OFFSET; //得分
	static string KLEVEL_OFFSET; //难度
public:
	unit(int x = 0, int y = 0, const char* pic = "*") :dx(x), dy(y), pic(pic) {};
	~unit();
	void show(); //展示点所在的位置
	void erase();//擦除存在的点
	static void gotoxy(int x,int y);//光标移动
};