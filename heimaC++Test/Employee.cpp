#include "Employee.h"


// ���캯��
Employee::Employee()
{
	cout << "[info] Employee�๹��" << endl;
}

// ���캯��
Employee::Employee(int id, string name, int departId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_departId = departId;

	cout << "[info] Employee�๹��" << endl;
}

// ��������
Employee::~Employee()
{
	cout << "[info] Employee������" << endl;
}

// ��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDepartName() 
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDepartName()
{
	return string("��ͨԱ��");
}
