#pragma once
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <iostream>
#include <fstream>
#include <vector>

// �궨��������λ��
#define FILENAME "empInfo.txt"

using namespace std;

class WorkerManager {
public:
  WorkerManager();
  ~WorkerManager();

  // ��ȡְ������
  int getEmpNum();

  // ��ȡ�ļ�״̬
  bool getFileIsEmptyFlag();

  // չʾ�˵�
  void Show_Menu();

  // �˳�����
  void ExitSystem();

  // ���ְ��
  void addEmp();

  // ����ְ����Ϣ������
  void save();

  // �ӱ��ض�ȡְ������
  int getLocalEmpNum();

  // �ӱ��س�ʼ��ְ����Ϣ
  void initEmpInfoFromLocal();

  // ��ʾְ����Ϣ
  void showEmpInfo();

  // ɾ��ְ����Ϣ
  void delEmpInfo();

  // �ж�ְ���Ƿ����
  int isEmpExist(int id);		// ͨ��ID�ж�
  int isEmpExist(string name, vector<int> &dstIndex);	// ͨ����������

  // �޸�ְ����Ϣ
  void modEmpInfo();

  // ����Ա����Ϣ
  void findEmpInfo();

private:
  // ��¼�ļ��е�����
  int m_empNum;

  // Ա������ָ��
  Worker* * m_empArray;

  // �ļ��Ƿ�Ϊ�ձ�־
  bool m_fileIsEmpty;
};
