#include "WorkerManager.h"


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

void WorkerManager::addWorker(int id, string name, int did)
{
	switch (did)
	{
	case EmployeeDepId:	//��λ��Ա��
		worker = new Employee(id, name, did);
		break;
	case ManagerDepId:	//��λ�Ǿ���
		worker = new Manager(id, name,did);
		break;
	case BossDepId:		//��λ���ϰ�
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
		cout << "ְ���б�Ϊ��" << endl;
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


