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
	int dx;//������
	int dy;//������
	const char* pic;//�ַ�/ͼƬ
	static const int KLEFT = 3; //������߽�����ര�ڵľ���
	static const int KUP = 3;  //�����ϱ߽����ϲര�ڵľ���
	static const int KWIDTH = 80; //���
	static const int KHEIGHT = 45; //�߶�
	static int KSCORE_OFFSET; //�÷�
	static string KLEVEL_OFFSET; //�Ѷ�
public:
	unit(int x = 0, int y = 0, const char* pic = "*") :dx(x), dy(y), pic(pic) {};
	~unit();
	void show(); //չʾ�����ڵ�λ��
	void erase();//�������ڵĵ�
	static void gotoxy(int x,int y);//����ƶ�
};