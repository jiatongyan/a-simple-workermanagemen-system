#include"workerprogram/head/manager.h"

manager::manager(int id,string name,int depid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depid = depid;
}

manager::~manager()
{
}

void manager::showinfo()
{
    cout<<"Ա��idΪ: "<<this->m_id;
    cout<<"\tԱ������Ϊ: "<<this->m_name;
    cout<<"\tԱ����ְλ��: "<<this->getdepname();
    cout<<"\tԱ����ְ����: ����ϰ��´������, �·��������ְͨ��"<<endl;
};

string manager::getdepname()
{
    return "����";
};