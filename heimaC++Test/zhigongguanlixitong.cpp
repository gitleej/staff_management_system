#include <iostream>

#include "WorkerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

// ������Կ���
#define TEST 0

using namespace std;

// ���Դ���
void test()
{
	Worker *worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}

void func()
{
	// ʵ���� WorkerManager ����
	WorkerManager wm;
	// �˵�ѡ���־
	int choise = -1;

	// ѭ�����з�֧�˵�ѡ��
	while (true)
	{
		// ��ʾ�˵�
		wm.Show_Menu();

		// ���ܲ˵�����
		cout << "����������ѡ��" << endl;
		cin >> choise;

		// ��֧ѡ��
		switch (choise)
		{
		case 0:	// �˳�����
			wm.ExitSystem();
			return;
			break;
		case 1:	// ���Ա��
			wm.addEmp();
			break;
		case 2:	// ��ʾԱ��
			wm.showEmpInfo();
			break;
		case 3:	// ɾ��Ա��
			wm.delEmpInfo();
			break;
		case 4:	// �޸�Ա��
			wm.modEmpInfo();
			break;
		case 5:	// ����Ա��
			wm.findEmpInfo();
			break;
		case 6:	// ����Ա��
			break;
		case 7:	// ����ļ�
			break;
		default:// ˢ����Ļ
			system("cls");
			break;
		}
	}
}

int main() {
#if TEST
	// ����
	test();
#else
	// ���ܺ���
	func();
#endif // TEST
	system("pause");

	return 0;
}