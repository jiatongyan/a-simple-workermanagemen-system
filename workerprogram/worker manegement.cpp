#include<iostream>
using namespace std;
//��Ϊvscode�������⣬��Ҫ��ͷ�ļ���ͬʱ���ö�Ӧ��Դ�ļ�
#include"workerprogram/head/workermanager.h"
#include"workermanager.cpp"
#include"workerprogram/head/worker.h"
#include"workerprogram/head/employee.h"
#include"employee.cpp"
#include"workerprogram/head/manager.h"
#include"manager.cpp"
#include"workerprogram/head/boss.h"
#include"boss.cpp"

int main()
{

    workermanager wk;
    int choice = 0;
    while (true)
    {
        wk.showmeau();
        cout<<"������ѡ��"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 0:
            wk.exitsystem();
            break;
        case 1:
            wk.addworker();
            break;
        case 2:
            wk.showworker();
            break;
        case 3:
            wk.deleteworker();
            break;
        case 4:
            wk.updateworker();
            break;
        case 5:
            wk.selectworker();
            break;
        case 6:
            wk.rankworker();
            break;
        case 7:
            wk.clearworker();
            break;
        default:
            system("cls");
            break;
        }
    }
    
    system("pause");
    return 0;
};