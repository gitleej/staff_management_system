#pragma once
#include "Worker.h"
class Manager :
	public Worker
{
public:
	Manager();
	Manager(int id, string name, int departId);
	~Manager();

	// ��ʾ������Ϣ
	virtual void showInfo();

	// ��ȡ��λ����
	virtual string getDepartName();
};

