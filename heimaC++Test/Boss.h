#pragma once
#include "Worker.h"
class Boss :
	public Worker
{
public:
	Boss();
	Boss(int id, string name, int departId);
	~Boss();

	// ��ʾ������Ϣ
	virtual void showInfo();

	// ��ȡ��λ����
	virtual string getDepartName();
};

