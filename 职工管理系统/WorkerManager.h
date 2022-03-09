#pragma once
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <string>
#define EmployeeDepId 3
#define ManagerDepId 2
#define BossDepId 1


class WorkerManager
{
public:
	WorkerManager();	//���캯��

	void showMenu();	//��ʾ�˵�����

	void exitSystem();   //�˳�ϵͳ����

	void addWorker();	//����ְ��


	void showInfo();

	~WorkerManager();

public:
	int m_num;					//ְ������
	Worker ** workerArray;		//���ְ��ָ�������
};