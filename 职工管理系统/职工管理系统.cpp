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
			int num;	//������������
			int id = 0;		//ְ����ű���
			string name;	//��������
			int did = 0;	//��λ��ű���
			cout << "��������Ҫ����ְ��������:" << endl;
			cin >> num;
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
				//����ְ��
				wm->addWorker(id, name, did);
				wm->addWorkerArray(num);

			}
			system("cls");
			break;
		}

		case 2:		//��ʾְ����Ϣ
			wm->showInfo();
			system("pause");
			system("cls");
			break;
		case 3:		//ɾ����ְְ��
			break;
		case 4:		//�޸�ְ����Ϣ
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