#include "WorkerManager.h"


WorkerManager::WorkerManager()
{

	//m_num = 0;
	//this->workerArray = NULL;

	//��ʼ�����������
	//1��û���ļ�              ��ʼ��Ϊ��
	//2�����ļ�û������        ��ʼ��Ϊ��
	//3�����ļ�������          �������ݳ�ʼ��

	//1��û���ļ�
	ifstream ifs(FileName, ios::in);
	if (!ifs.is_open())
	{
		this->m_num = 0;              //��ʼ��Ա������
		this->workerArray = NULL;     //��ʼ��Ա���б�
		this->fileIsEmpty = true;     //��ʼ���ļ��Ƿ�Ϊ��
		//cout << "û���ļ�" << endl;
		ifs.close();
	}

	//2�����ļ�û������
	char ch;
	ifs >> ch;		//��һ������
	if (ifs.eof())	//����EOF��
	{
		this->m_num = 0;              //��ʼ��Ա������
		this->workerArray = NULL;     //��ʼ��Ա���б�
		//cout << "���ļ�û������" << endl;
		this->fileIsEmpty = true;     //��ʼ���ļ��Ƿ�Ϊ��
		ifs.close();
	}

	//3�����ļ�������
	this->m_num = this->getNumFromFile();	//��ʼ��Ա������
	if (this->m_num > 0)
	{
		this->fileIsEmpty = false;              //��ʼ���ļ��Ƿ�Ϊ��
		//cout << "���ļ�������" << endl;
		this->workerArray = new Worker*[this->m_num];    //��workerArray���ٿռ�
		this->initWorkerArray();                //��ʼ��Ա���б�
	}


}

void WorkerManager::showMenu()
{
	cout << "************************************************" << endl;
	cout << "************  ��ӭʹ��ְ������ϵͳ  ************" << endl;
	cout << "***************  0���˳��������  **************" << endl;
	cout << "***************  1������ְ����Ϣ  **************" << endl;
	cout << "***************  2����ʾְ����Ϣ  **************" << endl;
	cout << "***************  3��ɾ����ְְ��  **************" << endl;
	cout << "***************  4���޸�ְ����Ϣ  **************" << endl;
	cout << "***************  5������ְ����Ϣ  **************" << endl;
	cout << "***************  6�����ձ������  **************" << endl;
	cout << "***************  7����������ĵ�  **************" << endl;
	cout << "************************************************" << endl;
}

void WorkerManager::exitSystem()
{
	cout << "�ټ�����ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker()
{
	int num = 0;	//������������
	int id = 0;		//ְ����ű���
	string name="";	//��������
	int did = 0;	//��λ��ű���
	cout << "��������Ҫ����ְ��������:" << endl;
	//cin >> num;
	num=this->makeSureCinIsRight(num);
	if (num > 0)    //��������������ȷ
	{
		int New_num = this->m_num + num;
		Worker ** New_WorkerArray = new Worker*[New_num];
		//����ԭ������this->WorkerArray��������New_WorkerArray
		for (int i = 0; i < this->m_num; i++)
		{
			New_WorkerArray[i] = this->workerArray[i];
		}
		for (int i = 0; i < num; i++)
		{
			cout << "�������" << i + 1 << "��ְ����ְ�����:" << endl;
			//cin >> id;
			id = this->makeSureCinIsRight(id);
			cout << "�������" << i + 1 << "��ְ��������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1���ϰ�" << endl;
			cout << "2������" << endl;
			cout << "3��Ա��" << endl;
			//cin >> did;
			did = this->makeSureCinIsRight(did);
			Worker * worker = NULL;
			switch (did)
			{
			case EmployeeDepId:	//��λ��Ա��
				worker = new Employee(id, name, did);
				break;
			case ManagerDepId:	//��λ�Ǿ���
				worker = new Manager(id, name, did);
				break;
			case BossDepId:		//��λ���ϰ�
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			New_WorkerArray[this->m_num + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->workerArray;

		//�����¿ռ��ָ��
		this->workerArray = New_WorkerArray;

		//����ְ������
		this->m_num = New_num;

		//��ְ���б�д���ļ�
		this->save();

		//�����ļ�Ϊ��flag
		this->fileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << num << "��ְ��" << endl;
	}
	else    //����������������
	{
		cout << "��������" << endl;
		return;
	}
}

void WorkerManager::save()
{
	ofstream ofs(FileName, ios::out);

	//ʾ��д�ļ���ʽ
	//1 ���� 1
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
	int index = 0;   //����
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int num = 0;
		cout << "��������Ҫɾ����ְ�����:" << endl;
		//cin >> num;
		num = this->makeSureCinIsRight(num);
		int index = this->isExist(num);     //indexΪҪɾ����ְ���������е�λ��
		if (index == -1)    //���������
		{
			cout << "���޴���" << endl;
			return;
		}
		else                //�������
		{
			Worker ** newArray = new Worker*[this->m_num - 1];
			//for (int i = 0; i < this->m_num; i++)
			//{
			//	if (i != index)     //����λ��Ϊindex��Ա��
			//	{
			//		newArray[i] = this->workerArray[i];
			//	}
			//	else
			//	{
			//		i--;
			//	}
			//}
			//����λ��Ϊindex��Ա��
			for (int i = 0; i < index; i++)
			{
				newArray[i] = this->workerArray[i];
			}
			for (int i = index + 1; i < this->m_num; i++)
			{
				newArray[i - 1] = this->workerArray[i];
			}
			delete[] this->workerArray;      //�ͷ�ԭ�пռ�
			this->workerArray = newArray;    //ָ���¿ռ�
			this->m_num--;                   //����Ա����
			if (this->m_num == 0)
			{
				this->fileIsEmpty = true;    //�����ļ�Ϊ��flag
			}
			//��ְ���б�д���ļ�
			this->save();
			cout << "ɾ��Ա���ɹ�" << endl;
		}
	}
	
}

void WorkerManager::modifyWorkerInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸���Ϣ��ְ�����:" << endl;
		int num = 0;
		//cin >> num;
		num = this->makeSureCinIsRight(num);
		int index = this->isExist(num);      //indexΪҪɾ����ְ���������е�λ��
		if (index == -1)        //���������
		{
			cout << "���޴���" << endl;
			return;
		}
		else
		{
			int id = 0;
			string name = "";
			int did = 0;
			//��¼ְ�����
			cout << "�������ְ���µ�ְ�����:" << endl;
			//cin >> id;    
			id = this->makeSureCinIsRight(id);
			//��¼ְ������
			cout << "�������ְ��������:" << endl;
			cin >> name;

			//��¼ְ����λ
			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1���ϰ�" << endl;
			cout << "2������" << endl;
			cout << "3��Ա��" << endl;
			//cin >> did;
			did = this->makeSureCinIsRight(did);
			//�޸�ְ����Ϣ
			Worker * worker = NULL;
			switch (did)
			{
			case EmployeeDepId:	//��λ��Ա��
				worker = new Employee(id, name, did);
				break;
			case ManagerDepId:	//��λ�Ǿ���
				worker = new Manager(id, name, did);
				break;
			case BossDepId:		//��λ���ϰ�
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			delete this->workerArray[index];   //�ͷŵ�Ҫ�޸���Ϣ��ְ��ԭʼ�ռ�
			this->workerArray[index] = worker;   //�������ݵ�������
			//��ְ���б�д���ļ�
			this->save();
			cout << "�޸�ְ����Ϣ�ɹ�" << endl;
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
			cout << "����������ͣ�����������" << endl;
			cin.clear();
			//cin.sync();    //�����
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //VS�����д������cin.sync()
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	else
	{
		//1������ְ����Ų���
		//2��������������
		cout << "��������Ҫ���ҵķ�ʽ:" << endl;
		cout << "1������Ա����Ų���" << endl;
		cout << "2��������������" << endl;
		int choice = 0;
		choice = this->makeSureCinIsRight(choice);
		if (choice == 1)     //����ְ����Ų���
		{
			cout << "��������Ҫ���ҵ�ְ����Ա�����:" << endl;
			int num = 0;
			num = this->makeSureCinIsRight(num);
			int index = this->isExist(num);
			if (index == -1)  //û�ҵ�
			{
				cout << "���޴���" << endl;
				return;
			}
			else     //�ҵ���  
			{
				cout << "���ҳɹ�,Ա�����Ϊ" << num 
					<< "�ŵ�Ա����Ա����ϢΪ:" << endl;
				this->workerArray[index]->showInfo();
			}
		}
		else if (choice == 2)  //������������
		{
			cout << "��������Ҫ���ҵ�ְ��������:" << endl;
			string name = "";
			cin >> name;
			bool flag = false;     //���ҳɹ���ʶ  trueΪ���ҳɹ���flaseΪû�ҵ�
			for (int i = 0; i < this->m_num; i++)
			{
				if (this->workerArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���Ա�����Ϊ" << this->workerArray[i]->m_Id
						<< "�ŵ�Ա����Ա����ϢΪ:" << endl;
					this->workerArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "���޴���" << endl;
				return;
			}
		}
		else
		{
			cout << "�������" << endl;
			return;
		}
	}
	
}

void WorkerManager::SortWorkerArray()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num -1; i++)
		{
			for (int j = 0; j < this->m_num - i - 1; j++)
			{
				if (this->workerArray[j]->m_Id > this->workerArray[j + 1]->m_Id)
				{
					//λ��Ϊj��j+1�Ķ��󽻻�λ��
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
					delete this->workerArray[j];   //�ͷ�this->workerArray[j]�ռ�
					//��this->workerArray[j]���·���ռ�

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
					delete this->workerArray[j + 1]; //�ͷ�this->workerArray[j+1]�ռ�
					//this->workerArray[j + 1] = temp_worker;
					//��this->workerArray[j+1]���·���ռ�
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
		this->save();   //���浽�ļ�
		cout << "��ְ����Ŵ�С����˳�����гɹ�" << endl;
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


