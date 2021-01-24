#include "WorkerManager.h"

WorkerManager::WorkerManager() :m_empNum(0), m_empArray(NULL)
{
	cout << "[info] WorkerManager类构造" << endl;
}

WorkerManager::~WorkerManager() 
{
	if (this->m_empArray != NULL)
	{
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
	cout << "[info] WorkerManager类析构" << endl;
}

// 展示菜单
void WorkerManager::Show_Menu() 
{ 
	cout << "*****************************************" << endl;
	cout << "********** 欢迎使用职工管理系统 **********" << endl;
    cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除职工信息 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用。" << endl;
	system("pause");
	exit(0);
}

// 添加职工
void WorkerManager::addEmp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)	// 添加
	{
		// 计算新空间大小
		int newSize = this->m_empNum + addNum;

		// 开辟新空间
		Worker** newEmpArray = new Worker*[newSize];

		// 保存原有数据
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < m_empNum; i++)
			{
				newEmpArray[i] = this->m_empArray[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;		// 职工ID
			string name;	// 职工姓名
			int departId;	// 部门id

			cout << "请输入第（" << i + 1 << ")个新职工的员工编号：" << endl;
			cin >> id;
			cout << "请输入第（" << i + 1 << ")个新职工的员工姓名：" << endl;
			cin >> name;
			cout << "请选择第（" << i + 1 << ")个新职工的岗位："
				<< "\n1.普通员工" 
				<< "\n2.经理" 
				<< "\n3.老板" << endl;
			cin >> departId;

			// 实例化新职工
			Worker *worker = NULL;
			switch (departId)
			{
			case 1:	// 普通员工
				worker = new Employee(id, name, departId);
				break;
			case 2:	// 经理
				worker = new Manager(id, name, departId);
				break;
			case 3:	// 老板
				worker = new Boss(id, name, departId);
				break;
			default:
				cout << "输入错误，请重试。";
				break;
			}

			// 将新职工保存到新数组中
			newEmpArray[this->m_empNum + i] = worker;
			// delete worker;
		}

		// 释放原有空间
		delete[] this->m_empArray;

		// 更改原有空间指向
		this->m_empArray = newEmpArray;

		// 更新职工人数
		this->m_empNum = newSize;

		// 提示
		cout << "成功添加 " << addNum << " 名新职工" << endl;
	}
	else
	{
		cout << "输入错误，请重试。" << endl;
	}

	system("pause");
	system("cls");
}
