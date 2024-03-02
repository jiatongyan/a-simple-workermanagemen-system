#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class manager : public worker
{

public:
    manager(int id,string name,int depid);
    ~manager();
    void showinfo();//展示类中内容
    string getdepname();//根据职位id获取职位名
};

