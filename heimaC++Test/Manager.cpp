#include "Manager.h"



Manager::Manager()
{
	cout << "[info] Manager�๹��" << endl;
}

Manager::Manager(int id, string name, int departId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_departId = departId;
	cout << "[info] Manager�๹��" << endl;
}


Manager::~Manager()
{
	cout << "[info] Manager������" << endl;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDepartName()
		<< "\t��λְ������ϰ彻�������񣬲��·�����ͨԱ��" << endl;
}

string Manager::getDepartName()
{
	return string("����");
}
