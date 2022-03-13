#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include <string>
#include <cstdlib>


//void test01()
//{
//	int a = 0;
//	cout << "�������������:" << endl;
//
//	while (true)
//	{
//		cin >> a;
//		if (!cin)
//		{
//			cout << "�����������������" << endl;
//			cin.clear();
//			//cin.sync();    //�����
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   //VS�����д������cin.sync()
//		}
//		else
//		{
//			cout << "���������:" << a << "��" << endl;
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
		cout << "����������ѡ��:" << endl;
		//cin >> choice;
		choice = wm.makeSureCinIsRight(choice);
		switch (choice)
		{
		case 0 :	//�˳��������
			wm.exitSystem();
			break;
		case 1:		//����ְ����Ϣ
		{
			wm.addWorker();
			system("pause");
			system("cls");
			break;
		}

		case 2:		//��ʾְ����Ϣ
			wm.showWorker();
			system("pause");
			system("cls");
			break;
		case 3:		//ɾ����ְְ��
			wm.deleteWorker();
			system("pause");
			system("cls");
			break;
		case 4:		//�޸�ְ����Ϣ
			wm.modifyWorkerInfo();
			system("pause");
			system("cls");
			break;
		case 5:		//����ְ����Ϣ
			wm.findWorker();
			system("pause");
			system("cls");
			break;
		case 6:		//���ձ������
			wm.SortWorkerArray();
			system("pause");
			system("cls");
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

