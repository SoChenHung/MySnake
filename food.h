#pragma once
#include "unit.h"
#include<ctime>

class food :
    public unit
{
public:
    food(int x = 0, int y = 0, const char* pic = "$");
    virtual ~food();
    void createPos();//食物坐标随机生成
};





