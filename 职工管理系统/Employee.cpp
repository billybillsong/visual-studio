#include "Employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Employee::DoWork()
{
	cout << "��ɾ�����������" << endl;
}
