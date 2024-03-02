#include"workerprogram/head/workermanager.h"
#include"workerprogram/head/employee.h"
#include"workerprogram/head/manager.h"
#include"workerprogram/head/boss.h"

workermanager::workermanager()
{
    m_workernumber = 0;//初始化系统内员工人数为0
    workerarry = nullptr;//初始化存放员工的数组的大小

};

workermanager::~workermanager(){};

//展示菜单功能函数
void workermanager::showmeau()
{

    cout << "****************************" << endl;
    cout << "*****  0、退出管理程序  *****" << endl;
    cout << "*****  1、增加职工信息  *****" << endl;
    cout << "*****  2、显示职工信息  *****" << endl;
    cout << "*****  3、删除离职职工  *****" << endl;
    cout << "*****  4、修改职工信息  *****" << endl;
    cout << "*****  5、查找职工信息  *****" << endl;
    cout << "*****  6、按照编号排序  *****" << endl;
    cout << "*****  7、清空所有文档  *****" << endl;
    cout << "****************************" << endl;

};

void workermanager::exitsystem()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0); 
};

//增加员工
void workermanager::addworker()
{
    int m = 0;//存放本次新增的人数
    cout<<"请输入本次要新增的职工数量"<<endl;
    cin>>m;
    if (m>0)
    {
        worker**newarry= new worker*[m_workernumber + m];//创建新数组存放之前和本次要新增的员工
        //把之前的员工放进新数组
        for (int i = 0; i < m_workernumber; i++)
        {
            newarry[i] = workerarry[i];
        }
        //开始输入新增员工
        for (int i = 0; i < m; i++)
        {
            cout<<"请输入本次输入的员工类型(1-普通职工  2-经理  3-老板)"<<endl;
            int choice = 0,id = 0;
            string name;
            cin>>choice;
            switch (choice)
            {
            case 1:
                cout<<"请输入员工id"<<endl;
                cin>>id;
                cout<<"请输入员工姓名"<<endl;
                cin>>name;
                newarry[m_workernumber+i] = new employee(id,name,1);
                break;
            case 2:
                cout<<"请输入员工id"<<endl;
                cin>>id;
                cout<<"请输入员工姓名"<<endl;
                cin>>name;
                newarry[m_workernumber+i] = new manager(id,name,2);
                break;
            case 3:
                cout<<"请输入员工id"<<endl;
                cin>>id;
                cout<<"请输入员工姓名"<<endl;
                cin>>name;
                newarry[m_workernumber+i] = new boss(id,name,3);
                break;    
            default:
                cout<<"请输入正确的职工类型"<<endl;
                i--;//重新运行这次的输入
                break;
            }               
        }
        m_workernumber += m;//更新一下当前系统内的职工人数

        //释放旧的workerarry
        delete [] workerarry;

        //将新的数组赋值给 workerarry
        workerarry = newarry;

        cout<<"已成功输入"<<endl;
        save();//把员工存放到文件中
        system("pause");
        system("cls");       
    }
    else
    {
        cout<<"请输入正确的职工数量"<<endl;
        system("pause");
        system("cls");
        return;
    };
};

//展示员工
void workermanager::showworker()
{
    if(m_workernumber==0)
    {
        cout<<"当前系统中暂无员工"<<endl;
    }
    else
    {
        for (int i = 0; i < m_workernumber; i++)
        {
            workerarry[i]->showinfo();
        }
    }
    system("pause");
    system("cls");
};

//删除员工
void workermanager::deleteworker()
{
    int id,n = 0;
    cout<<"请输入要删除的人员id"<<endl;
    cin>>id;
    for (int i = 0; i < m_workernumber; i++)
    {
        if (workerarry[i]->m_id == id)
        {
            delete  workerarry[i];
            for (int j = i; j < m_workernumber-1; j++)
            {
                workerarry[j] = workerarry[j+1];
            }
            i--;//删除了i位置上的员工后，把后面的员工依次向前挪动了1个位置，因此下一次查找还应该从第i个位置上查找而不是第i+1个
            m_workernumber--;//系统内人数减1
            n++;//记录删除次数
        }
    }
    if (n==0)
    {
        cout<<"要删除的联系人不存在"<<endl;
    }
    else
    {
        save();//把删除后的员工数据保存到文件
        cout<<n<<"位员工已删除"<<endl;
    }
    system("pause");
    system("cls");

};

//修改员工
void workermanager::updateworker()
{
    int id =0 ,n= 0,p=0;
    string name;
    cout<<"输入要修改的员工id"<<endl;
    cin>>id;
    for (int i = 0; i < m_workernumber; i++)
    {
        if (id==workerarry[i]->m_id)
        {
            cout<<"请输入员工姓名"<<endl;
            cin>>name;
            cout<<"请设置员工职位(1-普通职工  2-经理  3-老板)"<<endl;
            cin>>n;
            switch (n)
            {
            case 1:
                delete workerarry[i];
                workerarry[i] = new employee(id,name,1);
                break;
            case 2:
                delete workerarry[i];
                workerarry[i] = new manager(id,name,2);
                break;
            case 3: 
                delete workerarry[i];
                workerarry[i] = new boss(id,name,3);
                break;
            default:
                cout<<"请输入正确的职工类型"<<endl;
                i--;//重新运行这次的输入
                p--;//这次误操作不记录为修改次数
                break;
            }
            p++;//记录修改次数
        }
    }
    if (p==0)
    {
        cout<<"要修改的联系人不存在"<<endl;
    }
    else
    {
        save();//把修改后的员工数据存放到文件中
        cout<<p<<"位员工已修改"<<endl;
    }
    system("pause");
    system("cls"); 
};

//查找员工
void workermanager::selectworker()
{
    int m = 0,n = 0;
    cout<<"请输入查找的员工id"<<endl;
    cin>>m;
    for (int i = 0; i < m_workernumber; i++)
    {
        if (m==workerarry[i]->m_id)
        {
            workerarry[i]->showinfo();
            n++;
        }        
    }
    if (n==0)
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls"); 
};

//按照id给员工排序
void workermanager::rankworker()
{
    worker* temp = NULL;
    for (int i = 0; i < m_workernumber-1; i++)
    {
        for (int j = 0; j < m_workernumber-1-i; j++)
        {
            if (workerarry[j]->m_id>workerarry[j+1]->m_id)
            {
                temp = workerarry[j];
                workerarry[j] = workerarry[j+1];
                workerarry[j+1] = temp;
            }
        }
        
    }
    save();//把排序后的员工数据存放到文件中
    cout<<"已按照id为员工进行排序"<<endl;
    system("pause");
    system("cls");
};

//清空系统中的员工
void workermanager::clearworker()
{
    int m = 0;
    cout<<"您确定要清空系统中所有员工吗? (1-确定  0-取消)"<<endl;
    cin>>m;
    if (m==1)
    {
        m_workernumber = 0;
        delete [] workerarry;//释放workarry数组
        workerarry = nullptr;//必须给workerarry重新初始化到空指针上，否则之后新增员工时有重新释放workerarry数组的操作这样会导致重新释放同一块内存的问题
        save();//把清空后的员工数据存放到文件中
        cout<<"系统中所有员工已清空"<<endl;
    }
    else
    {
        cout<<"请重新选择操作"<<endl;
    }
    system("pause");
    system("cls");
};

//保存系统中员工到文件中
void workermanager::save()
{
    ofstream ofs;
    ofs.open(FILENAME);
    for (int i = 0; i < m_workernumber; i++)
    {
        ofs<<"员工id: "<<workerarry[i]->m_id<<"  ";
        ofs<<"员工姓名: "<<workerarry[i]->m_name<<"  ";
        if (workerarry[i]->m_depid==1)
        {
            ofs<<"员工职位: 普通职工  ";
            ofs<<"员工职责: 完成经理下发的任务"<<endl;
        }
        else if(workerarry[i]->m_depid==2)
        {
            ofs<<"员工职位: 经理  ";
            ofs<<"员工职责: 完成老板下发的任务, 安排任务给普通职工"<<endl;
        }
        else
        {
            ofs<<"员工职位: 老板 ";
            ofs<<"员工职责: 负责整个公司的事务"<<endl;
        }
    }
    ofs.close();
    
};