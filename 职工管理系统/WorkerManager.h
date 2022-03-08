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
	void showMenu();	//��ʾ�˵�����

	void exitSystem();   //�˳�ϵͳ����

	void addWorker(int id,string name,int did);	//����ְ��

	void addWorkerArray(int num);	

	void showInfo();

public:
	Worker * worker;
	Worker ** workerArray;
};