#include"workerprogram/head/boss.h"

boss::boss(int id,string name,int depid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depid = depid;
}

boss::~boss()
{
}

void boss::showinfo()
{
    cout<<"Ա��idΪ: "<<this->m_id;
    cout<<"\tԱ������Ϊ: "<<this->m_name;
    cout<<"\tԱ����ְλ��: "<<this->getdepname();
    cout<<"\tԱ����ְ����: ����ȫ��˾��С����"<<endl;
};

string boss::getdepname()
{
    return "�ϰ�";
};