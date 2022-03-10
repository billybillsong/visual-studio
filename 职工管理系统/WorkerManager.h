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
	WorkerManager();	//构造函数

	void showMenu();	//显示菜单功能

	void exitSystem();   //退出系统功能

	void addWorker();	//增加职工

	void save();		//保存到文件

	int  getNumFromFile();	//读文件有几行数据

	void showInfo();

	void initWorkerArray();  //文件有数据初始化WorkerArray

	~WorkerManager();

public:
	int m_num;					//职工数量
	Worker ** workerArray;		//存放职工指针的数组
	bool fileIsEmpty;            //文件是否是空
};