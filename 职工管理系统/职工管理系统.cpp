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
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0 :	//�˳��������
			wm->exitSystem();
			break;
		case 1:		//����ְ����Ϣ
		{
			wm->addWorker();
			system("pause");
			system("cls");
			break;
		}

		case 2:		//��ʾְ����Ϣ
			wm->showWorker();
			system("pause");
			system("cls");
			break;
		case 3:		//ɾ����ְְ��
			wm->deleteWorker();
			system("pause");
			system("cls");
			break;
		case 4:		//�޸�ְ����Ϣ
			wm->modifyWorkerInfo();
			system("pause");
			system("cls");
			break;
		case 5:		//����ְ����Ϣ
			break;
		case 6:		//���ձ������
			break;
		case 7:		//��������ĵ�
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return;
}