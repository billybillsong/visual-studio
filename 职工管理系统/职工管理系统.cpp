#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include <string>
#include <cstdlib>


//void test01()
//{
//	int a = 0;
//	cout << "请输入你的年龄:" << endl;
//
//	while (true)
//	{
//		cin >> a;
//		if (!cin)
//		{
//			cout << "输入错误，请重新输入" << endl;
//			cin.clear();
//			//cin.sync();    //清空流
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //VS用这行代码代替cin.sync()
//		}
//		else
//		{
//			cout << "你的年龄是:" << a << "岁" << endl;
//			break;
//		}
//	}
//	system("pause");
//	system("cls");
//}

void main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择:" << endl;
		//cin >> choice;
		choice = wm.makeSureCinIsRight(choice);
		switch (choice)
		{
		case 0 :	//退出管理程序
			wm.exitSystem();
			break;
		case 1:		//增加职工信息
		{
			wm.addWorker();
			system("pause");
			system("cls");
			break;
		}

		case 2:		//显示职工信息
			wm.showWorker();
			system("pause");
			system("cls");
			break;
		case 3:		//删除离职职工
			wm.deleteWorker();
			system("pause");
			system("cls");
			break;
		case 4:		//修改职工信息
			wm.modifyWorkerInfo();
			system("pause");
			system("cls");
			break;
		case 5:		//查找职工信息
			wm.findWorker();
			system("pause");
			system("cls");
			break;
		case 6:		//按照编号排序
			wm.SortWorkerArray();
			system("pause");
			system("cls");
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

