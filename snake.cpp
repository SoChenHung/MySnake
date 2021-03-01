#include "snake.h"


//snake::snake(int len, int x, int y, int speed, directions direction, vector<unit> vecBody, char pic = '*')
snake::snake(int len, int x, int y, int speed, directions direction, const char* pic)
{
	//初始长度
	this->body_length = len;
	//蛇头坐标
	this->Head_dx = x;
	this->Head_dy = y;
	//初速度
	this->move_speed = speed;
	//初始移动方向
	this->body_enumDirectionTravle = direction;
	//UI图标
	this->s_pic = pic;
	//ÉßÉíÊý×é
	/*const char* p = "&";
	snake_vecBody.push_back('&');*/
	//snake_vecBody[0].pic = "&";
	for (int len = 0; len < body_length; len++)
	{
		unit myunit(0, 0, pic);
		snake_vecBody.push_back(myunit);
		snake_vecBody[0].pic = "&";
		switch (direction)
		{
		case UP:
			snake_vecBody[len].dx = Head_dx;
			snake_vecBody[len].dy = Head_dy + len;
			break;
		case DOWN:
			snake_vecBody[len].dx = Head_dx;
			snake_vecBody[len].dy = Head_dy - len;
			break;
		case LEFT:
			snake_vecBody[len].dx = Head_dx + len;
			snake_vecBody[len].dy = Head_dy;
			break;
		case RIGHT:
			snake_vecBody[len].dx = Head_dx - len;
			snake_vecBody[len].dy = Head_dy;
			break;
		default:
			break;
		}
	}
}
void snake::showbody()
{
	//for (int i = 0; i < this->snake_vecBody.size(); i++)
	for (int i = 0; i < this->body_length; i++)
	{
		snake_vecBody[i].show();
	}
}
void snake::erasebody()
{
	//for (int i = 0; i < this->snake_vecBody.size(); i++)
	for (int i = 0; i < this->body_length; i++)
	{
		snake_vecBody[i].erase();
	}
}
void snake::move()
{
	//ÉßÍ·ÒÆ¶¯
	vector<unit> head = snake_vecBody;
	switch (this->body_enumDirectionTravle)
	{
	case UP:
		head[0].dy--;
		//snake_vecBody[0].dy--;
		break;
	case DOWN:
		head[0].dy++;
		//snake_vecBody[0].dy++;
		break;
	case LEFT:
		head[0].dx--;
		//snake_vecBody[0].dx--;
		break;
	case RIGHT:
		head[0].dx++;
		//snake_vecBody[0].dx++;
		break;
	default:
		break;
	}
	snake_vecBody.insert(snake_vecBody.begin(), head[0]);//²åÈëÐÂÉßÍ·
	for (unsigned int i = 0; i < snake_vecBody.size(); i++)
	{
		if (i != 0)
		{
			snake_vecBody[i].pic = this->s_pic;
		}

	}
	showbody();
	Sleep(move_speed);
	erasebody();
}
void snake::changeDirection()
{
	char ch;
	//监控键盘
	if (_kbhit())
	{
		unit::gotoxy(0, unit::KHEIGHT + 2);
		ch = _getch();
		if (ch == ' ')
		{
			int x;
			unit::gotoxy(Head_dx, Head_dy);
			cout << '\a';
			x = MessageBoxA(NULL, "暂停游戏", "Snake", 0);
			if (x == 2)	order = 2;
		}
		else if (ch == 'r' || ch == 'R' || ch == 27)
		{
			cout << '\a';
			order = 100;
		}
		else if (ch == 'q' || ch == 'Q')
		{
			system("CLS");
			unit::gotoxy(35, 8);
			cout << '\a';
			MessageBoxA(NULL, "感谢使用", "Snake", 0);
			system("color 7");
			exit(1);
		}
		else {
			cout << ch;
			switch (ch)
			{
			case 72:
			case 'w':
			case 'W':
				if (this->body_enumDirectionTravle == DOWN)
				{
					break;
				}
				this->body_enumDirectionTravle = UP;
				break;
			case 80:
			case 's':
			case 'S':
				if (this->body_enumDirectionTravle == UP)
				{
					break;
				}
				this->body_enumDirectionTravle = DOWN;
				break;
			case 75:
			case 'a':
			case 'A':
				if (this->body_enumDirectionTravle == RIGHT)
				{
					break;
				}
				this->body_enumDirectionTravle = LEFT;
				break;
			case 77:
			case 'd':
			case 'D':
				if (this->body_enumDirectionTravle == LEFT)
				{
					break;
				}
				this->body_enumDirectionTravle = RIGHT;
				break;
			case '+':
				if (this->move_speed >= 20)   //ËÙ¶ÈMAX = 10  
				{
					this->move_speed -= 10;
				}
				break;
			case '-':
				if (this->move_speed <= 120)  //ËÙ¶ÈMIN = 130
				{
					this->move_speed += 10;
				}
			default:
				break;
			}

		}
	}
	if (move_speed >= 10 && move_speed <= 30)		
		unit::KLEVEL_OFFSET = "111";
	else if (move_speed >= 40 && move_speed <= 60)	
		unit::KLEVEL_OFFSET = "222";
	else if (move_speed >= 70 && move_speed <= 100)	
		unit::KLEVEL_OFFSET = "333";
	else if (move_speed >= 110 && move_speed <= 130)	
		unit::KLEVEL_OFFSET = "444";

}
void snake::eraseSnakeTail()
{
	snake_vecBody.erase(snake_vecBody.end() - 1);//删除旧蛇尾
}
bool snake::eatFood(food* food)
{
	//吃到食物
	if (food->dx == snake_vecBody[0].dx && food->dy == snake_vecBody[0].dy)
	{
		growup();
		if (unit::KLEVEL_OFFSET == "简单")
		{
			unit::KSCORE_OFFSET += 30;
		}
		else if (unit::KLEVEL_OFFSET == "一般")
		{
			unit::KSCORE_OFFSET += 10;
		}
		else if (unit::KLEVEL_OFFSET == "困难")
		{
			unit::KSCORE_OFFSET += 5;
		}
		else if (unit::KLEVEL_OFFSET == "魔鬼")
		{
			unit::KSCORE_OFFSET += 3;
		}
		while (true)
		{
			food->createPos();
			for (int i = 1; i < body_length; i++)
			{
				if (food->dx != snake_vecBody[i].dx && food->dy != snake_vecBody[i].dy)
				{
					//cout << food->dx << "," << food->dy;
					food->show();
					return true;
				}
				else if (food->dx == snake_vecBody[i].dx && food->dy == snake_vecBody[i].dy)
				{
					break;
				}
			}
		}
		//food->createPos();
		//return true;
	}
	//没有吃到食物
	else
	{
		eraseSnakeTail();
		return false;
	}
}
void snake::growup()
{
	//蛇身长度+1
	this->body_length++;
}
bool snake::snakeLifeDeath()
{
	bool survival_status;
	//碰壁死
	if (snake_vecBody[0].dx <= unit::KLEFT || snake_vecBody[0].dx >= unit::KWIDTH
		|| snake_vecBody[0].dy <= unit::KHEIGHT - 40 || snake_vecBody[0].dy >= unit::KHEIGHT)
	{
		survival_status = false;
		return survival_status;
	}
	//自残死
	for (int i = 1; i < body_length; i++)
	{
		if (snake_vecBody[i].dx == snake_vecBody[0].dx && snake_vecBody[i].dy == snake_vecBody[0].dy)
		{
			survival_status = false;
			return false;
		}
	}
	survival_status = true;
	return survival_status;
}
snake::~snake() {}