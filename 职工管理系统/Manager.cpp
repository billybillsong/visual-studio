#include "Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Manager::DoWork()
{
	cout << "完成老板交给的任务，下发任务给员工" << endl;
}
