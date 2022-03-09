#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	m_num = 0;
	this->workerArray = NULL;
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
	string name;	//��������
	int did = 0;	//��λ��ű���
	cout << "��������Ҫ����ְ��������:" << endl;
	cin >> num;
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
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1���ϰ�" << endl;
			cout << "2������" << endl;
			cout << "3��Ա��" << endl;
			cin >> did;
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

		//��ʾ��Ϣ
		cout << "�ɹ����" << num << "��ְ��" << endl;
	}
	else    //����������������
	{
		cout << "��������" << endl;
	}
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
		cout << "ְ���б�Ϊ��" << endl;
	}
}

WorkerManager::~WorkerManager()
{
	if (this->workerArray != NULL)
	{
		delete this->workerArray;
		this->workerArray = NULL;
	}
}


