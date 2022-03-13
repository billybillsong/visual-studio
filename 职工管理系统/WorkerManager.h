#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <string>
#include <fstream>
#define EmployeeDepId 3
#define ManagerDepId 2
#define BossDepId 1
#define FileName "WorkerList.txt"


class WorkerManager
{
public:
	WorkerManager();	//���캯��

	void showMenu();	//��ʾ�˵�����

	void exitSystem();   //�˳�ϵͳ����

	void addWorker();	//����ְ��

	void save();		//���浽�ļ�

	int  getNumFromFile();	//���ļ��м�������

	void showWorker();

	void initWorkerArray();  //�ļ������ݳ�ʼ��WorkerArray

	int isExist(int num);    //�鿴���Ϊnum��ְ���Ƿ����,���ڵĻ�������wokerArray�е�λ��
	
	void deleteWorker();     //ɾ��ְ��

	void modifyWorkerInfo();  //�޸�ְ����Ϣ

	int makeSureCinIsRight(int a);    //ȷ���������int���ͣ����������������ͻ�����ʾ��������

	void findWorker();        //����ְ����Ϣ

	void SortWorkerArray();    //���ձ������


	~WorkerManager();

public:
	int m_num;					//ְ������
	Worker ** workerArray;		//���ְ��ָ�������
	bool fileIsEmpty;            //�ļ��Ƿ��ǿ�
};