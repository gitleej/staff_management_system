#pragma once
#include <iostream>
#include <string>

using namespace std;

// ְ��������
class Worker
{
public:
	Worker();
	virtual ~Worker() = 0;

	// ��ʾ������Ϣ�����麯����
	virtual void showInfo() = 0;

	// ��ȡ��λ���ƣ����麯����
	virtual string getDepartName() = 0;

	int m_Id;	// Ա�����
	string m_name;	// Ա������
	int m_departId;	// Ա�����ڲ������Ʊ��
};

