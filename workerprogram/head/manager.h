#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class manager : public worker
{

public:
    manager(int id,string name,int depid);
    ~manager();
    void showinfo();//չʾ��������
    string getdepname();//����ְλid��ȡְλ��
};

