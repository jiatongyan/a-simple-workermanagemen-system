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
    cout<<"员工id为: "<<this->m_id;
    cout<<"\t员工姓名为: "<<this->m_name;
    cout<<"\t员工的职位是: "<<this->getdepname();
    cout<<"\t员工的职责是: 完成老板下达的任务, 下发任务给普通职工"<<endl;
};

string manager::getdepname()
{
    return "经理";
};