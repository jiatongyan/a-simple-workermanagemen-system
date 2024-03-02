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
    cout<<"员工id为: "<<this->m_id;
    cout<<"\t员工姓名为: "<<this->m_name;
    cout<<"\t员工的职位是: "<<this->getdepname();
    cout<<"\t员工的职责是: 完成经理下达的任务"<<endl;
};

string employee::getdepname()
{
    return "普通职工";
};