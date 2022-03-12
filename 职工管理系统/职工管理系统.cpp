#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include <string>


void main()
{
	WorkerManager * wm = new WorkerManager();
	int choice = 0;
	while (true)
	{
		wm->showMenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0 :	//退出管理程序
			wm->exitSystem();
			break;
		case 1:		//增加职工信息
		{
			wm->addWorker();
			system("pause");
			system("cls");
			break;
		}

		case 2:		//显示职工信息
			wm->showWorker();
			system("pause");
			system("cls");
			break;
		case 3:		//删除离职职工
			wm->deleteWorker();
			system("pause");
			system("cls");
			break;
		case 4:		//修改职工信息
			wm->modifyWorkerInfo();
			system("pause");
			system("cls");
			break;
		case 5:		//查找职工信息
			break;
		case 6:		//按照编号排序
			break;
		case 7:		//清空所有文档
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return;
}