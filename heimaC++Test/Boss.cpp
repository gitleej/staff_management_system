#include "Boss.h"



Boss::Boss()
{
	cout << "[info] Boos�๹��" << endl;
}

Boss::Boss(int id, string name, int departId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_departId = departId;
	cout << "[info] Boos�๹��" << endl;
}


Boss::~Boss()
{
	cout << "[info] Boos������" << endl;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDepartName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDepartName()
{
	return string("�ϰ�");
}
