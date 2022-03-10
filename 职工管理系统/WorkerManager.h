#pragma once
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

	void showInfo();

	void initWorkerArray();  //�ļ������ݳ�ʼ��WorkerArray

	~WorkerManager();

public:
	int m_num;					//ְ������
	Worker ** workerArray;		//���ְ��ָ�������
	bool fileIsEmpty;            //�ļ��Ƿ��ǿ�
};