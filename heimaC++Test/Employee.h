// ��ͨԱ���ļ�
#pragma once
#include "Worker.h"

#include <iostream>

using namespace std;

class Employee :
	public Worker
{
public:
	Employee();
	Employee(int id, string name, int departId);
	~Employee();

	// ��ʾ������Ϣ
	virtual void showInfo();

	// ��ȡ��λ����
	virtual string getDepartName();
};

