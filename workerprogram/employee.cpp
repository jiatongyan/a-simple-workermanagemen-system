#include "workerprogram/head/employee.h"

employee::employee(int id,string name,int depid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depid = depid;
}

employee::~employee()
{
}

void employee::showinfo()
{
    cout<<"Ա��idΪ: "<<this->m_id;
    cout<<"\tԱ������Ϊ: "<<this->m_name;
    cout<<"\tԱ����ְλ��: "<<this->getdepname();
    cout<<"\tԱ����ְ����: ��ɾ����´������"<<endl;
};

string employee::getdepname()
{
    return "��ְͨ��";
};