#include "Employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Employee::showInfo()
{
	cout << "职工编号:\t" << this->m_Id
		<< "\t职工姓名:\t" << this->m_Name
		<< "\t岗位职责:\t完成经理交给的任务" << endl;
}
