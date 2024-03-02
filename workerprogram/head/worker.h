#pragma once
#include <iostream>
using namespace std;

class worker
{

public:
    worker(){};//构造函数
    virtual ~worker(){};//虚构函数，因为是抽象类所以用虚析构函数
    int m_id;//员工id
    string m_name;//员工姓名
    int m_depid;//职位id(1-普通职工，2-经理，3-老板)

    virtual void showinfo() = 0;//展示类中内容
    virtual string getdepname() = 0;//根据职位id获取职位名
};

