#include "WorkerManager.h"

WorkerManager::WorkerManager() :m_empNum(0), m_empArray(NULL)
{
	cout << "[info] WorkerManager�๹��" << endl;
}

WorkerManager::~WorkerManager() 
{
	if (this->m_empArray != NULL)
	{
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
	cout << "[info] WorkerManager������" << endl;
}

// չʾ�˵�
void WorkerManager::Show_Menu() 
{ 
	cout << "*****************************************" << endl;
	cout << "********** ��ӭʹ��ְ������ϵͳ **********" << endl;
    cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ��ְ����Ϣ *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�á�" << endl;
	system("pause");
	exit(0);
}

// ���ְ��
void WorkerManager::addEmp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)	// ���
	{
		// �����¿ռ��С
		int newSize = this->m_empNum + addNum;

		// �����¿ռ�
		Worker** newEmpArray = new Worker*[newSize];

		// ����ԭ������
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < m_empNum; i++)
			{
				newEmpArray[i] = this->m_empArray[i];
			}
		}

		// ���������
		for (int i = 0; i < addNum; i++)
		{
			int id;		// ְ��ID
			string name;	// ְ������
			int departId;	// ����id

			cout << "������ڣ�" << i + 1 << ")����ְ����Ա����ţ�" << endl;
			cin >> id;
			cout << "������ڣ�" << i + 1 << ")����ְ����Ա��������" << endl;
			cin >> name;
			cout << "��ѡ��ڣ�" << i + 1 << ")����ְ���ĸ�λ��"
				<< "\n1.��ͨԱ��" 
				<< "\n2.����" 
				<< "\n3.�ϰ�" << endl;
			cin >> departId;

			// ʵ������ְ��
			Worker *worker = NULL;
			switch (departId)
			{
			case 1:	// ��ͨԱ��
				worker = new Employee(id, name, departId);
				break;
			case 2:	// ����
				worker = new Manager(id, name, departId);
				break;
			case 3:	// �ϰ�
				worker = new Boss(id, name, departId);
				break;
			default:
				cout << "������������ԡ�";
				break;
			}

			// ����ְ�����浽��������
			newEmpArray[this->m_empNum + i] = worker;
			// delete worker;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->m_empArray;

		// ����ԭ�пռ�ָ��
		this->m_empArray = newEmpArray;

		// ����ְ������
		this->m_empNum = newSize;

		// ��ʾ
		cout << "�ɹ���� " << addNum << " ����ְ��" << endl;
	}
	else
	{
		cout << "������������ԡ�" << endl;
	}

	system("pause");
	system("cls");
}
