#include "WorkerManager.h"


WorkerManager::WorkerManager()
{

	//m_num = 0;
	//this->workerArray = NULL;

	//初始化分三种情况
	//1、没有文件              初始化为空
	//2、有文件没有数据        初始化为空
	//3、有文件有数据          依据数据初始化

	//1、没有文件
	ifstream ifs(FileName, ios::in);
	if (!ifs.is_open())
	{
		this->m_num = 0;              //初始化员工数量
		this->workerArray = NULL;     //初始化员工列表
		this->fileIsEmpty = true;     //初始化文件是否为空
		ifs.close();
	}

	//2、有文件没有数据
	char ch;
	ifs >> ch;		//读一个数据
	if (ifs.eof())	//读到EOF了
	{
		this->m_num = 0;              //初始化员工数量
		this->workerArray = NULL;     //初始化员工列表
		this->fileIsEmpty = true;     //初始化文件是否为空
		ifs.close();
	}

	//3、有文件有数据
	this->m_num = this->getNumFromFile();	//初始化员工数量
	this->fileIsEmpty = false;              //初始化文件是否为空
	this->workerArray = new Worker*[this->m_num];    //给workerArray开辟空间
	this->initWorkerArray();                //初始化员工列表

}

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

void WorkerManager::addWorker()
{
	int num = 0;	//增加人数变量
	int id = 0;		//职工编号变量
	string name;	//姓名变量
	int did = 0;	//岗位编号变量
	cout << "请输入想要增加职工的人数:" << endl;
	cin >> num;
	if (num > 0)    //输入增加人数正确
	{
		int New_num = this->m_num + num;
		Worker ** New_WorkerArray = new Worker*[New_num];
		//复制原有数组this->WorkerArray到新数组New_WorkerArray
		for (int i = 0; i < this->m_num; i++)
		{
			New_WorkerArray[i] = this->workerArray[i];
		}
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
			Worker * worker = NULL;
			switch (did)
			{
			case EmployeeDepId:	//岗位是员工
				worker = new Employee(id, name, did);
				break;
			case ManagerDepId:	//岗位是经理
				worker = new Manager(id, name, did);
				break;
			case BossDepId:		//岗位是老板
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			New_WorkerArray[this->m_num + i] = worker;
		}
		//释放原有空间
		delete[] this->workerArray;

		//更改新空间的指向
		this->workerArray = New_WorkerArray;

		//更新职工数量
		this->m_num = New_num;

		//将职工列表写入文件
		this->save();

		//提示信息
		cout << "成功添加" << num << "个职工" << endl;
	}
	else    //输入增加人数错误
	{
		cout << "输入有误" << endl;
	}
}

void WorkerManager::save()
{
	ofstream ofs(FileName, ios::out);

	//示例写文件格式
	//1 张三 1
	for (int i = 0; i < this->m_num; i++)
	{
		ofs << this->workerArray[i]->m_Id << " "
			<< this->workerArray[i]->m_Name<<" "
			<< this->workerArray[i]->m_DepId << endl;
	}

	ofs.close();

}

int WorkerManager::getNumFromFile()
{
	ifstream ifs(FileName, ios::in);
	int num = 0;
	int id;
	string name;
	int did;
	while (ifs>>id && ifs>>name && ifs>>did)
	{
		num++;
	}
	ifs.close();
	return num;
}



void WorkerManager::showInfo()
{
	if (this->m_num > 0)
	{
		for (int i = 0; i < this->m_num; i++)
		{
			cout << this->workerArray[i]->m_Id << "   "
				<< this->workerArray[i]->m_Name << "   "
				<< this->workerArray[i]->m_DepId << endl;
		}
	}
	else
	{
		cout << "职工列表为空" << endl;
	}
}

void WorkerManager::initWorkerArray()
{
	ifstream ifs(FileName, ios::in);
	int id;
	string name;
	int did;
	int index = 0;   //计数
	while (ifs>>id && ifs>>name && ifs>>did)
	{
		switch (did)
		{
		case EmployeeDepId:
			this->workerArray[index] = new Employee(id,name,did);
			break;
		case ManagerDepId:
			this->workerArray[index] = new Manager(id, name, did);
			break;
		case BossDepId:
			this->workerArray[index] = new Boss(id, name, did);
			break;
		default:
			break;
		}
		index++;
	}
	ifs.close();

}

WorkerManager::~WorkerManager()
{
	if (this->workerArray != NULL)
	{
		delete[] this->workerArray;
		this->workerArray = NULL;
	}
}


