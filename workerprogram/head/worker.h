#pragma once
#include <iostream>
using namespace std;

class worker
{

public:
    worker(){};//���캯��
    virtual ~worker(){};//�鹹��������Ϊ�ǳ���������������������
    int m_id;//Ա��id
    string m_name;//Ա������
    int m_depid;//ְλid(1-��ְͨ����2-����3-�ϰ�)

    virtual void showinfo() = 0;//չʾ��������
    virtual string getdepname() = 0;//����ְλid��ȡְλ��
};

