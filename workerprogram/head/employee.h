#pragma once
#include <iostream>
using namespace std;

#include"worker.h"

class employee : public worker
{
public:
    employee(int id,string name,int depid);
    ~employee();
    void showinfo();//չʾ��������
    string getdepname();//����ְλid��ȡְλ��
};

