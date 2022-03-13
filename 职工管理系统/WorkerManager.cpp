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
		//cout << "没有文件" << endl;
		ifs.close();
	}

	//2、有文件没有数据
	char ch;
	ifs >> ch;		//读一个数据
	if (ifs.eof())	//读到EOF了
	{
		this->m_num = 0;              //初始化员工数量
		this->workerArray = NULL;     //初始化员工列表
		//cout << "有文件没有数据" << endl;
		this->fileIsEmpty = true;     //初始化文件是否为空
		ifs.close();
	}

	//3、有文件有数据
	this->m_num = this->getNumFromFile();	//初始化员工数量
	if (this->m_num > 0)
	{
		this->fileIsEmpty = false;              //初始化文件是否为空
		//cout << "有文件有数据" << endl;
		this->workerArray = new Worker*[this->m_num];    //给workerArray开辟空间
		this->initWorkerArray();                //初始化员工列表
	}


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
	string name="";	//姓名变量
	int did = 0;	//岗位编号变量
	cout << "请输入想要增加职工的人数:" << endl;
	//cin >> num;
	num=this->makeSureCinIsRight(num);
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
			//cin >> id;
			id = this->makeSureCinIsRight(id);
			cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
			cin >> name;
			cout << "请选择该职工的岗位:" << endl;
			cout << "1、老板" << endl;
			cout << "2、经理" << endl;
			cout << "3、员工" << endl;
			//cin >> did;
			did = this->makeSureCinIsRight(did);
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

		//更新文件为空flag
		this->fileIsEmpty = false;

		//提示信息
		cout << "成功添加" << num << "个职工" << endl;
	}
	else    //输入增加人数错误
	{
		cout << "输入有误" << endl;
		return;
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



void WorkerManager::showWorker()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num; i++)
		{
			this->workerArray[i]->showInfo();
		}
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

int WorkerManager::isExist(int num)
{
	int index = -1;
	for (int i = 0; i < this->m_num; i++)
	{
		if (this->workerArray[i]->m_Id == num)
		{
			index = i;
			break;
		}
	}
	return index;
}


void WorkerManager::deleteWorker()
{
	if(this->fileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int num = 0;
		cout << "请输入想要删除的职工编号:" << endl;
		//cin >> num;
		num = this->makeSureCinIsRight(num);
		int index = this->isExist(num);     //index为要删除的职工在数组中的位置
		if (index == -1)    //如果不存在
		{
			cout << "查无此人" << endl;
			return;
		}
		else                //如果存在
		{
			Worker ** newArray = new Worker*[this->m_num - 1];
			//for (int i = 0; i < this->m_num; i++)
			//{
			//	if (i != index)     //跳过位置为index的员工
			//	{
			//		newArray[i] = this->workerArray[i];
			//	}
			//	else
			//	{
			//		i--;
			//	}
			//}
			//跳过位置为index的员工
			for (int i = 0; i < index; i++)
			{
				newArray[i] = this->workerArray[i];
			}
			for (int i = index + 1; i < this->m_num; i++)
			{
				newArray[i - 1] = this->workerArray[i];
			}
			delete[] this->workerArray;      //释放原有空间
			this->workerArray = newArray;    //指向新空间
			this->m_num--;                   //更新员工数
			if (this->m_num == 0)
			{
				this->fileIsEmpty = true;    //更新文件为空flag
			}
			//将职工列表写入文件
			this->save();
			cout << "删除员工成功" << endl;
		}
	}
	
}

void WorkerManager::modifyWorkerInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要修改信息的职工编号:" << endl;
		int num = 0;
		//cin >> num;
		num = this->makeSureCinIsRight(num);
		int index = this->isExist(num);      //index为要删除的职工在数组中的位置
		if (index == -1)        //如果不存在
		{
			cout << "查无此人" << endl;
			return;
		}
		else
		{
			int id = 0;
			string name = "";
			int did = 0;
			//记录职工编号
			cout << "请输入该职工新的职工编号:" << endl;
			//cin >> id;    
			id = this->makeSureCinIsRight(id);
			//记录职工姓名
			cout << "请输入该职工的名字:" << endl;
			cin >> name;

			//记录职工岗位
			cout << "请选择该职工的岗位:" << endl;
			cout << "1、老板" << endl;
			cout << "2、经理" << endl;
			cout << "3、员工" << endl;
			//cin >> did;
			did = this->makeSureCinIsRight(did);
			//修改职工信息
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
			delete this->workerArray[index];   //释放掉要修改信息的职工原始空间
			this->workerArray[index] = worker;   //更新数据到数组中
			//将职工列表写入文件
			this->save();
			cout << "修改职工信息成功" << endl;
		}
	}
	
}

int WorkerManager::makeSureCinIsRight(int a)
{
	while (true)
	{
		cin >> a;
		if (!cin)
		{
			cout << "输入错误类型，请重新输入" << endl;
			cin.clear();
			//cin.sync();    //清空流
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //VS用这行代码代替cin.sync()
		}
		else
		{
			return a;
		}
	}
}

void WorkerManager::findWorker()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	else
	{
		//1、按照职工编号查找
		//2、按照姓名查找
		cout << "请输入想要查找的方式:" << endl;
		cout << "1、按照员工编号查找" << endl;
		cout << "2、按照姓名查找" << endl;
		int choice = 0;
		choice = this->makeSureCinIsRight(choice);
		if (choice == 1)     //按照职工编号查找
		{
			cout << "请输入想要查找的职工的员工编号:" << endl;
			int num = 0;
			num = this->makeSureCinIsRight(num);
			int index = this->isExist(num);
			if (index == -1)  //没找到
			{
				cout << "查无此人" << endl;
				return;
			}
			else     //找到了  
			{
				cout << "查找成功,员工编号为" << num 
					<< "号的员工，员工信息为:" << endl;
				this->workerArray[index]->showInfo();
			}
		}
		else if (choice == 2)  //按照姓名查找
		{
			cout << "请输入想要查找的职工的姓名:" << endl;
			string name = "";
			cin >> name;
			bool flag = false;     //查找成功标识  true为查找成功，flase为没找到
			for (int i = 0; i < this->m_num; i++)
			{
				if (this->workerArray[i]->m_Name == name)
				{
					cout << "查找成功，员工编号为" << this->workerArray[i]->m_Id
						<< "号的员工，员工信息为:" << endl;
					this->workerArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查无此人" << endl;
				return;
			}
		}
		else
		{
			cout << "输入错误" << endl;
			return;
		}
	}
	
}

void WorkerManager::SortWorkerArray()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num -1; i++)
		{
			for (int j = 0; j < this->m_num - i - 1; j++)
			{
				if (this->workerArray[j]->m_Id > this->workerArray[j + 1]->m_Id)
				{
					//位置为j和j+1的对象交换位置
					Worker * temp_worker = NULL;
					//temp_worker = this->workerArray[j];
					switch (this->workerArray[j]->m_DepId)
					{
					case EmployeeDepId:
						temp_worker = new Employee(this->workerArray[j]->m_Id, this->workerArray[j]->m_Name, this->workerArray[j]->m_DepId);
						break;
					case ManagerDepId:
						temp_worker = new Manager(this->workerArray[j]->m_Id, this->workerArray[j]->m_Name, this->workerArray[j]->m_DepId);
						break;
					case BossDepId:
						temp_worker = new Boss(this->workerArray[j]->m_Id, this->workerArray[j]->m_Name, this->workerArray[j]->m_DepId);
						break;
					default:
						break;
					}
					delete this->workerArray[j];   //释放this->workerArray[j]空间
					//给this->workerArray[j]重新分配空间

					switch (this->workerArray[j+1]->m_DepId)
					{
					case EmployeeDepId:
						this->workerArray[j] = new Employee(this->workerArray[j+1]->m_Id, this->workerArray[j + 1]->m_Name, this->workerArray[j + 1]->m_DepId);
						break;
					case ManagerDepId:
						this->workerArray[j] = new Manager(this->workerArray[j + 1]->m_Id, this->workerArray[j + 1]->m_Name, this->workerArray[j + 1]->m_DepId);
						break;
					case BossDepId:
						this->workerArray[j] = new Boss(this->workerArray[j + 1]->m_Id, this->workerArray[j + 1]->m_Name, this->workerArray[j + 1]->m_DepId);
						break;
					default:
						break;
					}
					//this->workerArray[j] = this->workerArray[j + 1];
					delete this->workerArray[j + 1]; //释放this->workerArray[j+1]空间
					//this->workerArray[j + 1] = temp_worker;
					//给this->workerArray[j+1]重新分配空间
					switch (temp_worker->m_DepId)
					{
					case EmployeeDepId:
						this->workerArray[j+1] = new Employee(temp_worker->m_Id, temp_worker->m_Name, temp_worker->m_DepId);
						break;
					case ManagerDepId:
						this->workerArray[j + 1] = new Manager(temp_worker->m_Id, temp_worker->m_Name, temp_worker->m_DepId);
						break;
					case BossDepId:
						this->workerArray[j + 1] = new Boss(temp_worker->m_Id, temp_worker->m_Name, temp_worker->m_DepId);
						break;
					default:
						break;
					}
					delete temp_worker;
				}
			}
		}
		this->save();   //保存到文件
		cout << "按职工编号从小到大顺序排列成功" << endl;
	}
}



WorkerManager::~WorkerManager()
{
	if (this->workerArray != NULL)
	{
		delete[] this->workerArray;
		this->workerArray = NULL;
	}
}


