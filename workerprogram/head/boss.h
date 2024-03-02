#pragma once
#include <iostream>
using namespace std;
#include"worker.h"

class boss : public worker
{
public:
    boss(int id,string name,int depid);
    ~boss();
    void showinfo();//展示类中内容
    string getdepname();//根据职位id获取职位名
};

