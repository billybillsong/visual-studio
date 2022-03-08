#include "Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Boss::DoWork()
{
	cout << "管理公司的所有事务" << endl;
}
