#include "WorkerManager.h"

WorkerManager::WorkerManager() :m_empNum(0), m_empArray(NULL), m_fileIsEmpty(false)
{
	// ����ʱ���ر�������
	ifstream ifs;
	// ���ļ�
	ifs.open(FILENAME, ios::in);

	// ����ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << FILENAME << "�ļ�������" << endl;
		// ��ʼ����Ա����
		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_fileIsEmpty = true;
		// �ر��ļ�
		/*ifs.close();
		return;*/
	}
	else // �ļ�����
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())	// ����Ƿ��ļ���β��������ļ���β�����ļ�Ϊ��
		{
			cout << FILENAME << "�ļ����ڣ��������ݡ�" << endl;
			// ��ʼ����Ա����
			this->m_empNum = 0;
			this->m_empArray = NULL;
			this->m_fileIsEmpty = true;
			// �ر��ļ�
			/*ifs.close();
			return;*/
		}
		else // �ļ������Ҳ�Ϊ��
		{
			cout << FILENAME << "�ļ����ڣ��Ҳ�Ϊ�ա�" << endl;
			// ��ʼ����Ա����
			this->m_empNum = getLocalEmpNum();
			this->m_empArray = new Worker*[this->m_empNum];
			initEmpInfoFromLocal();
		}
	}

	// �ر��ļ�
	ifs.close();
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

// ��ȡְ������
int WorkerManager::getEmpNum()
{
	return this->m_empNum;
}

bool WorkerManager::getFileIsEmptyFlag()
{
	return this->m_fileIsEmpty;
}

// չʾ�˵�
void WorkerManager::Show_Menu() 
{ 
	cout << "******************************************" << endl;
	cout << "********** ��ӭʹ��ְ������ϵͳ **********" << endl;
    cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ��ְ����Ϣ *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "******************************************" << endl;

	// ��ȡְ������
	cout << "��ǰ��ְԱ������Ϊ��" << this->getEmpNum() << endl;

	// ��ȡ�ļ�״̬
	cout << "�ļ��Ƿ������Ϣ��" << this->getFileIsEmptyFlag() << endl;

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

		// �������ݵ�����
		this->save();

		// �����ļ���Ϊ�յı�־
		this->m_fileIsEmpty = false;

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

// ����ְ����Ϣ������
void WorkerManager::save()
{
	ofstream ofs;
	// ���ļ�
	ofs.open(FILENAME, ios::out);

	// д���ļ�
	for (int i = 0; i < m_empNum; i++)
	{
		ofs << this->m_empArray[i]->m_Id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_departId << " " << endl;
	}

	// �ر��ļ�
	ofs.close();
}

// �ӱ����ļ��ֻ�ȡְ������
int WorkerManager::getLocalEmpNum()
{
	// ����ļ��Ƿ�Ϊ��
	if (this->m_fileIsEmpty == true)
	{
		return 0;
	}

	// �ļ���Ϊ��ʱ��ȡ
	int empNum = 0;	// ������
	int id;	// ְ�����
	string name;	// ְ������
	int departId;	// ְ����λ

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	while (ifs >> id && ifs >> name && ifs >> departId)	// ���ո�ָ�
	{
		empNum++;
	}

	return empNum;
}

void WorkerManager::initEmpInfoFromLocal()
{
	// ��ȡ�ļ�
	ifstream ifs;
	// ���ļ�
	ifs.open(FILENAME, ios::in);

	int index = 0;	// ������
	int id;	// ְ��ID
	string name;	// ְ������
	int departId;	// ְ����λID

	// ��ȡ�ļ������ո�ָ�Ԫ��
	while (ifs >> id && ifs >> name && ifs >> departId)
	{
		Worker *worker = NULL;
		// ѡ���֧
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
			break;
		}

		// ���µ�������
		this->m_empArray[index] = worker;
		index++;
	}

	// �ر��ļ�
	ifs.close();
}

// ��ʾԱ����Ϣ
void WorkerManager::showEmpInfo()
{
	// ����Ƿ�Ϊ��
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_empNum; i++)
		{
			this->m_empArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

// ɾ��ְ����Ϣ
void WorkerManager::delEmpInfo()
{
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
	}
	else
	{
		// ���ձ��ɾ��ְ��
		cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
		int id = -1;	// ��ɾ��ְ��id
		cin >> id;		// ��������
		int index = this->isEmpExist(id);	// ��ȡԱ�����
		if (index != -1)
		{
			cout << "���Ϊ " << id << " ��ְ����Ϣ��ɾ��" << endl;
			this->m_empArray[index]->showInfo();
			// ������Ϣ
			this->m_empNum--;
			for (int i = index; i < this->m_empNum; i++)
			{
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			// ���µ�����
			this->save();
			// ���Ա������
			if (this->m_empNum == 0)
			{
				this->m_fileIsEmpty = true;
			}

			// ��ʾ
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ����Ϊ " << id << " ��ְ����Ϣ" << endl;
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isEmpExist(int id)
{
	int index = -1;
	// ����Ƿ����ְ����Ϣ
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
		return index;
	}

	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->m_empArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}
