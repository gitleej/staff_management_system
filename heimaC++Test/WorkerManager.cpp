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
	// ��Ҫ���ͷŶ���ָ��
	if (this->m_empArray != NULL)
	{
		// �ͷŶ���ָ��
		for (int i = 0; i < this->m_empNum; i++)
		{
			delete this->m_empArray[i];
			this->m_empArray[i] = NULL;
		}
		// �ͷ�һ��ָ��
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

			while (true)
			{
				cout << "������ڣ�" << i + 1 << ")����ְ����Ա����ţ�" << endl;
				cin >> id;

				if (isEmpExist(id) == -1)
				{
					break;
				}
				else
				{
					cout << "��ְ������Ѵ��ڣ����������롣" << endl;
				}
			}
			
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
			// �����ļ���Ϊ�յı�־
			this->m_fileIsEmpty = false;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->m_empArray;

		// ����ԭ�пռ�ָ��
		this->m_empArray = newEmpArray;

		// ����ְ������
		this->m_empNum = newSize;

		// �������ݵ�����
		this->save();

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

// ����������
int WorkerManager::isEmpExist(string name, vector<int>& dstIndex)
{
	bool flag = false;
	int index = -1;
	// ����Ƿ����ְ����Ϣ
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
		return index;
	}

	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->m_empArray[i]->m_name == name)
		{
			dstIndex.push_back(i);
			flag = true;
		}
	}

	// ����Ƿ���ҵ�
	if (flag)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

// �޸�ְ����Ϣ
void WorkerManager::modEmpInfo()
{
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
	}
	else
	{
		// ���ձ���޸�Ա����Ϣ
		cout << "��������Ҫ�޸�ְ���ı�ţ�" << endl;
		int id = -1;	// ���޸�ְ��id
		cin >> id;		// ��������
		
		int index = this->isEmpExist(id);
		if (index != -1)
		{
			// ��ȷ�ҵ�Ա�����
			// ���ԭʼ��Ϣ
			delete this->m_empArray[index];

			int newId;
			string newName;
			int newDepartId;
			while (true)
			{
				cout << "�鵽��"<< id <<" ְ����������ְ���±�ţ�" << endl;
				cin >> newId;
				// ���id�Ƿ��ظ�
				if (this->isEmpExist(newId) == -1)
				{
					break;
				}
				else
				{
					cout << "��ְ������Ѵ��ڣ����������롣" << endl;
				}
			}

			cout << "������ְ��������" << endl;
			cin >> newName;
			
			cout << "��ѡ��ְ���ĸ�λ��"
				<< "\n1.��ͨԱ��"
				<< "\n2.����"
				<< "\n3.�ϰ�" << endl;
			cin >> newDepartId;

			Worker * worker = NULL;
			// ѡ���֧
			switch (newDepartId)
			{
			case 1:	// ��ְͨ��
				worker = new Employee(newId, newName, newDepartId);
				break;
			case 2:	// ����
				worker = new Manager(newId, newName, newDepartId);
				break;
			case 3:	// �ϰ�
				worker = new Boss(newId, newName, newDepartId);
				break;
			default:
				break;
			}
			// �������ݵ�������
			this->m_empArray[index] = worker;

			// ���µ��ļ�
			this->save();

			// ��ʾ
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			// ���޴���
			cout << "δ�ҵ����Ϊ " << id << " ��ְ����Ϣ���޸�ʧ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

// ����Ա����Ϣ
void WorkerManager::findEmpInfo()
{
	// ����Ƿ����ְ����Ϣ
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
	}
	else
	{
		// ���ҷ�ʽ
		int findType = -1;
		while (true)
		{
			cout << "��ѡ����ҷ�ʽ��\n"
				<< "1.����Ų���\n"
				<< "2.����������" << endl;
			cin >> findType;

			if (findType == 1 || findType == 2)
			{
				break;
			}
			else
			{
				cout << "���ҷ�ʽѡ�����������ѡ����ҷ�ʽ��" << endl;
			}
		}
		
		// ��֧ѡ��
		switch (findType)
		{
		case 1:	// ����Ų���
		{
			cout << "�����������ְ����ţ�" << endl;
			int id = -1;
			cin >> id;

			int index = this->isEmpExist(id);
			if (index != -1)
			{
				this->m_empArray[index]->showInfo();
			}
			else
			{
				cout << "δ�ҵ����Ϊ " << id << " ��ְ����Ϣ" << endl;
			}

			break;
		}
		case 2:
		{
			cout << "�����������ְ��������" << endl;
			string name;
			cin >> name;

			vector<int> result;
			int ret = isEmpExist(name, result);
			if (ret != -1)
			{
				for (auto it = result.begin(); it != result.end(); it++)
				{
					this->m_empArray[*it]->showInfo();
				}
			}
			else
			{
				cout << "δ�ҵ�����Ϊ " << name << " ��ְ����Ϣ" << endl;
			}
		}
		default:
			break;
		}
	}

	system("pause");
	system("cls");
}

// ����Ա����Ϣ
void WorkerManager::sortEmpInfo()
{
	// ����Ƿ����ְ����Ϣ
	if (this->m_fileIsEmpty)
	{
		cout << "������ְ����Ϣ" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int sortType = -1;
		while (true)
		{
			cout << "��ѡ������ʽ��\n"
				<< "1.����\n"
				<< "2.����" << endl;
			cin >> sortType;
			if (sortType == 1 || sortType == 2)
			{
				break;
			}
			else
			{
				cout << "����ʽѡ���������������" << endl;
			}
		}

		// ����ѡ�������㷨��������
		for (int i = 0; i < m_empNum; i++)
		{
			// ѡ�����ֵ����Сֵ
			int minOrMax = i;
			for (int j = i+1; j < m_empNum; j++)
			{
				if (sortType == 1)	// ����
				{
					if (this->m_empArray[minOrMax]->m_Id > this->m_empArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else // ����
				{
					if (this->m_empArray[minOrMax]->m_Id < this->m_empArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				if (i != minOrMax)
				{
					Worker *temp = this->m_empArray[i];
					this->m_empArray[i] = this->m_empArray[minOrMax];
					this->m_empArray[minOrMax] = temp;
				}
			}
		}

		// ���½��������
		this->save();
		
		// ��ʾ������
		this->showEmpInfo();
	}
}

// ���������Ϣ
void WorkerManager::claenAllInfo()
{
	cout << "ȷ���������ְ����Ϣ��\n"
		<< "0.ȡ��"
		<< "1.ȷ��" << endl;
	bool confirm = false;
	cin >> confirm;

	if (confirm)
	{
		// ɾ��ԭ�ļ����½�
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		// �ͷ��ڴ�ռ�
		if (this->m_empArray != NULL)
		{
			// �������ָ��
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArray[i] != NULL)
				{
					delete this->m_empArray[i];
					this->m_empArray[i] = NULL;
				}
			}
			// ���¼�����
			this->m_empNum = 0;
			// ����һ��ָ��
			delete[] this->m_empArray;
			this->m_empArray = NULL;
			this->m_fileIsEmpty = true;
		}

		// ��ʾ
		cout << "��������ɹ���" << endl;
	}
	else
	{
		cout << "������ȡ����" << endl;
	}

	system("pause");
	system("cls");
}
