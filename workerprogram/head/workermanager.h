#pragma once
#include <iostream>
#include<fstream>
using namespace std;
#include"worker.h"
#define FILENAME "worker information.txt"

class workermanager
{
public:
    workermanager();

    ~workermanager();
    
    void showmeau();//չʾ�˵�

    void exitsystem();//�˳�ϵͳ

    void addworker();//����Ա��
    int m_workernumber;//��¼Ա������
    worker** workerarry;//������worker���ָ�루ָ��ͬ�����ࣩ���¿��ٿռ䣨new�����ָ������顪���ö���ָ������������ĵ�ַ

    void showworker();//չʾԱ��

    void deleteworker();//ɾ��Ա��

    void updateworker();//�޸�Ա����Ϣ

    void selectworker();//����Ա����Ϣ

    void rankworker();//��id��Ա������

    void clearworker();//���ϵͳ�е�Ա��

    //�ļ������ຯ��
    void save();//����Ա����Ϣ���ļ���
};


