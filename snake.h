#pragma once
#include "food.h"
#include<conio.h>
#include<cstdio>

using namespace std;

//定义方向的结构体
typedef enum {
    UP , DOWN , LEFT , RIGHT   //0 ->上  1-> 下   2->左   3->右
}directions;

class snake 
{
public:
    snake(int len = 4 , int x = 37, int y = 21, int speed = 110, directions direction = RIGHT, const char* pic = "@");
    virtual ~snake();

    //蛇的行为
    void move();//移动
    void changeDirection();//改变方向
    void growup();//蛇身变大
    void showbody();//创建蛇身  
    void erasebody();//擦除身体
    void eraseSnakeTail();//删除蛇尾
    bool eatFood(food *food);//判断是否吃到食物
    bool snakeLifeDeath();//蛇的生与死

public:
    //指令，用来控制游戏局部功能
    int order = 0;
    //蛇的属性
    int Head_dx;//蛇头横坐标
    int Head_dy;//蛇头纵坐标
    int body_length;//蛇身长度
    int move_speed;//移动速度
    directions body_enumDirectionTravle;//行进方向
    vector<unit>  snake_vecBody;//蛇身数组
    //vector<Head> snake_vecBody;
    const char* s_pic;//用来显示蛇身的字符


};



