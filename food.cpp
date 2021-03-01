#include "food.h"


food::food(int x, int y,const char* pic)
{
	dx = x;
	dy = y;
	this->pic = pic;
}
void food::createPos()
{
	srand((unsigned)time(NULL));
	dx = KLEFT + 1 + rand() % (KWIDTH-6); //随机生成食物的横坐标
	dy = KUP + 4 + rand() % (KHEIGHT-7); //随机生成食物的纵坐标
	//dx = KLEFT + 1 + rand() % (m_coor.X - 2 * unit::KLEFT);
	//dy = KUP + 1 + rand() % (m_coor.Y - 2 * unit::KUP );

	//cout << dx << "," << dy << endl;
}
food::~food(){}