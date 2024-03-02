#include"workerprogram/head/workermanager.h"
#include"workerprogram/head/employee.h"
#include"workerprogram/head/manager.h"
#include"workerprogram/head/boss.h"

workermanager::workermanager()
{
    m_workernumber = 0;//��ʼ��ϵͳ��Ա������Ϊ0
    workerarry = nullptr;//��ʼ�����Ա��������Ĵ�С

};

workermanager::~workermanager(){};

//չʾ�˵����ܺ���
void workermanager::showmeau()
{

    cout << "****************************" << endl;
    cout << "*****  0���˳��������  *****" << endl;
    cout << "*****  1������ְ����Ϣ  *****" << endl;
    cout << "*****  2����ʾְ����Ϣ  *****" << endl;
    cout << "*****  3��ɾ����ְְ��  *****" << endl;
    cout << "*****  4���޸�ְ����Ϣ  *****" << endl;
    cout << "*****  5������ְ����Ϣ  *****" << endl;
    cout << "*****  6�����ձ������  *****" << endl;
    cout << "*****  7����������ĵ�  *****" << endl;
    cout << "****************************" << endl;

};

void workermanager::exitsystem()
{
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0); 
};

//����Ա��
void workermanager::addworker()
{
    int m = 0;//��ű�������������
    cout<<"�����뱾��Ҫ������ְ������"<<endl;
    cin>>m;
    if (m>0)
    {
        worker**newarry= new worker*[m_workernumber + m];//������������֮ǰ�ͱ���Ҫ������Ա��
        //��֮ǰ��Ա���Ž�������
        for (int i = 0; i < m_workernumber; i++)
        {
            newarry[i] = workerarry[i];
        }
        //��ʼ��������Ա��
        for (int i = 0; i < m; i++)
        {
            cout<<"�����뱾�������Ա������(1-��ְͨ��  2-����  3-�ϰ�)"<<endl;
            int choice = 0,id = 0;
            string name;
            cin>>choice;
            switch (choice)
            {
            case 1:
                cout<<"������Ա��id"<<endl;
                cin>>id;
                cout<<"������Ա������"<<endl;
                cin>>name;
                newarry[m_workernumber+i] = new employee(id,name,1);
                break;
            case 2:
                cout<<"������Ա��id"<<endl;
                cin>>id;
                cout<<"������Ա������"<<endl;
                cin>>name;
                newarry[m_workernumber+i] = new manager(id,name,2);
                break;
            case 3:
                cout<<"������Ա��id"<<endl;
                cin>>id;
                cout<<"������Ա������"<<endl;
                cin>>name;
                newarry[m_workernumber+i] = new boss(id,name,3);
                break;    
            default:
                cout<<"��������ȷ��ְ������"<<endl;
                i--;//����������ε�����
                break;
            }               
        }
        m_workernumber += m;//����һ�µ�ǰϵͳ�ڵ�ְ������

        //�ͷžɵ�workerarry
        delete [] workerarry;

        //���µ����鸳ֵ�� workerarry
        workerarry = newarry;

        cout<<"�ѳɹ�����"<<endl;
        save();//��Ա����ŵ��ļ���
        system("pause");
        system("cls");       
    }
    else
    {
        cout<<"��������ȷ��ְ������"<<endl;
        system("pause");
        system("cls");
        return;
    };
};

//չʾԱ��
void workermanager::showworker()
{
    if(m_workernumber==0)
    {
        cout<<"��ǰϵͳ������Ա��"<<endl;
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

//ɾ��Ա��
void workermanager::deleteworker()
{
    int id,n = 0;
    cout<<"������Ҫɾ������Աid"<<endl;
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
            i--;//ɾ����iλ���ϵ�Ա���󣬰Ѻ����Ա��������ǰŲ����1��λ�ã������һ�β��һ�Ӧ�ôӵ�i��λ���ϲ��Ҷ����ǵ�i+1��
            m_workernumber--;//ϵͳ��������1
            n++;//��¼ɾ������
        }
    }
    if (n==0)
    {
        cout<<"Ҫɾ������ϵ�˲�����"<<endl;
    }
    else
    {
        save();//��ɾ�����Ա�����ݱ��浽�ļ�
        cout<<n<<"λԱ����ɾ��"<<endl;
    }
    system("pause");
    system("cls");

};

//�޸�Ա��
void workermanager::updateworker()
{
    int id =0 ,n= 0,p=0;
    string name;
    cout<<"����Ҫ�޸ĵ�Ա��id"<<endl;
    cin>>id;
    for (int i = 0; i < m_workernumber; i++)
    {
        if (id==workerarry[i]->m_id)
        {
            cout<<"������Ա������"<<endl;
            cin>>name;
            cout<<"������Ա��ְλ(1-��ְͨ��  2-����  3-�ϰ�)"<<endl;
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
                cout<<"��������ȷ��ְ������"<<endl;
                i--;//����������ε�����
                p--;//������������¼Ϊ�޸Ĵ���
                break;
            }
            p++;//��¼�޸Ĵ���
        }
    }
    if (p==0)
    {
        cout<<"Ҫ�޸ĵ���ϵ�˲�����"<<endl;
    }
    else
    {
        save();//���޸ĺ��Ա�����ݴ�ŵ��ļ���
        cout<<p<<"λԱ�����޸�"<<endl;
    }
    system("pause");
    system("cls"); 
};

//����Ա��
void workermanager::selectworker()
{
    int m = 0,n = 0;
    cout<<"��������ҵ�Ա��id"<<endl;
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
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls"); 
};

//����id��Ա������
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
    save();//��������Ա�����ݴ�ŵ��ļ���
    cout<<"�Ѱ���idΪԱ����������"<<endl;
    system("pause");
    system("cls");
};

//���ϵͳ�е�Ա��
void workermanager::clearworker()
{
    int m = 0;
    cout<<"��ȷ��Ҫ���ϵͳ������Ա����? (1-ȷ��  0-ȡ��)"<<endl;
    cin>>m;
    if (m==1)
    {
        m_workernumber = 0;
        delete [] workerarry;//�ͷ�workarry����
        workerarry = nullptr;//�����workerarry���³�ʼ������ָ���ϣ�����֮������Ա��ʱ�������ͷ�workerarry����Ĳ��������ᵼ�������ͷ�ͬһ���ڴ������
        save();//����պ��Ա�����ݴ�ŵ��ļ���
        cout<<"ϵͳ������Ա�������"<<endl;
    }
    else
    {
        cout<<"������ѡ�����"<<endl;
    }
    system("pause");
    system("cls");
};

//����ϵͳ��Ա�����ļ���
void workermanager::save()
{
    ofstream ofs;
    ofs.open(FILENAME);
    for (int i = 0; i < m_workernumber; i++)
    {
        ofs<<"Ա��id: "<<workerarry[i]->m_id<<"  ";
        ofs<<"Ա������: "<<workerarry[i]->m_name<<"  ";
        if (workerarry[i]->m_depid==1)
        {
            ofs<<"Ա��ְλ: ��ְͨ��  ";
            ofs<<"Ա��ְ��: ��ɾ����·�������"<<endl;
        }
        else if(workerarry[i]->m_depid==2)
        {
            ofs<<"Ա��ְλ: ����  ";
            ofs<<"Ա��ְ��: ����ϰ��·�������, �����������ְͨ��"<<endl;
        }
        else
        {
            ofs<<"Ա��ְλ: �ϰ� ";
            ofs<<"Ա��ְ��: ����������˾������"<<endl;
        }
    }
    ofs.close();
    
};