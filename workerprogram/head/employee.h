#pragma once
#include <iostream>
using namespace std;

#include"worker.h"

class employee : public worker
{
public:
    employee(int id,string name,int depid);
    ~employee();
    void showinfo();//展示类中内容
    string getdepname();//根据职位id获取职位名
};

