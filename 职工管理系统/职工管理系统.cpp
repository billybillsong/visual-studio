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
			int num;	//增加人数变量
			int id = 0;		//职工编号变量
			string name;	//姓名变量
			int did = 0;	//岗位编号变量
			cout << "请输入想要增加职工的人数:" << endl;
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				cout << "请输入第" << i + 1 << "个职工的职工编号:" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
				cin >> name;
				cout << "请选择该职工的岗位:" << endl;
				cout << "1、老板" << endl;
				cout << "2、经理" << endl;
				cout << "3、员工" << endl;
				cin >> did;
				//增加职工
				wm->addWorker(id, name, did);
				wm->addWorkerArray(num);

			}
			system("cls");
			break;
		}

		case 2:		//显示职工信息
			wm->showInfo();
			system("pause");
			system("cls");
			break;
		case 3:		//删除离职职工
			break;
		case 4:		//修改职工信息
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