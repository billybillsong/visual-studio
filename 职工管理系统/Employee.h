#pragma once
#include "Worker.h"


class Employee : public Worker
{
public:
	Employee(int id, string name,int did);

	void showInfo();
};
