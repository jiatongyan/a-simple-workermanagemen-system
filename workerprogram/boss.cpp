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
    cout<<"员工id为: "<<this->m_id;
    cout<<"\t员工姓名为: "<<this->m_name;
    cout<<"\t员工的职位是: "<<this->getdepname();
    cout<<"\t员工的职责是: 负责全公司大小事务"<<endl;
};

string boss::getdepname()
{
    return "老板";
};