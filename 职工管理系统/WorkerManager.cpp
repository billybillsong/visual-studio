#include "WorkerManager.h"


void WorkerManager::showMenu()
{
	cout << "************************************************" << endl;
	cout << "************  欢迎使用职工管理系统  ************" << endl;
	cout << "***************  0、退出管理程序  **************" << endl;
	cout << "***************  1、增加职工信息  **************" << endl;
	cout << "***************  2、显示职工信息  **************" << endl;
	cout << "***************  3、删除离职职工  **************" << endl;
	cout << "***************  4、修改职工信息  **************" << endl;
	cout << "***************  5、查找职工信息  **************" << endl;
	cout << "***************  6、按照编号排序  **************" << endl;
	cout << "***************  7、清空所有文档  **************" << endl;
	cout << "************************************************" << endl;
}

void WorkerManager::exitSystem()
{
	cout << "再见，欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker(int id, string name, int did)
{
	switch (did)
	{
	case EmployeeDepId:	//岗位是员工
		worker = new Employee(id, name, did);
		break;
	case ManagerDepId:	//岗位是经理
		worker = new Manager(id, name,did);
		break;
	case BossDepId:		//岗位是老板
		worker = new Boss(id, name, did);
		break;
	default:
		break;
	}
}

void WorkerManager::addWorkerArray(int num)
{
	workerArray = new Worker*[num];
	for (int i = 0; i < num; i++)
	{
		workerArray[i] = worker;
	}
}

void WorkerManager::showInfo()
{
	int num = sizeof(this->workerArray)/4;
	cout << num;
	if (num == 0)
	{
		cout << "职工列表为空" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << this->workerArray[i]->m_Id << "   "
				<< this->workerArray[i]->m_Name << "   "
				<< this->workerArray[i]->m_DepId << endl;
		}
	}

}


