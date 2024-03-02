#pragma once
#include <iostream>
#include<fstream>
using namespace std;
#include"worker.h"
#define FILENAME "worker information.txt"

class workermanager
{
public:
    workermanager();

    ~workermanager();
    
    void showmeau();//展示菜单

    void exitsystem();//退出系统

    void addworker();//增加员工
    int m_workernumber;//记录员工人数
    worker** workerarry;//数组存放worker类的指针（指向不同的子类），新开辟空间（new）存放指针的数组——用二级指针接收这个数组的地址

    void showworker();//展示员工

    void deleteworker();//删除员工

    void updateworker();//修改员工信息

    void selectworker();//查找员工信息

    void rankworker();//按id给员工排序

    void clearworker();//清空系统中的员工

    //文件操作类函数
    void save();//保存员工信息到文件中
};


