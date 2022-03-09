#pragma once
#include <iostream>
using namespace std;


class Worker
{
public:
	//Worker(int id,string name,int did);

	virtual void DoWork() = 0;


public:
	int m_Id;
	string m_Name;
	int m_DepId;
};