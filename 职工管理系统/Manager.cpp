#include "Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Manager::DoWork()
{
	cout << "����ϰ彻���������·������Ա��" << endl;
}
