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
	void showMenu();	//显示菜单功能

	void exitSystem();   //退出系统功能

	void addWorker(int id,string name,int did);	//增加职工

	void addWorkerArray(int num);	

	void showInfo();

public:
	Worker * worker;
	Worker ** workerArray;
};