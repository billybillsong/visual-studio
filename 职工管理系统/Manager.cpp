#include "Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Manager::showInfo()
{
	cout << "职工编号:\t" << this->m_Id
		<< "\t职工姓名:\t" << this->m_Name
		<< "\t岗位职责:\t完成老板交给的任务，并下发任务给员工" << endl;
}
