#pragma once
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <iostream>

using namespace std;

class WorkerManager {
public:
  WorkerManager();
  ~WorkerManager();

  // չʾ�˵�
  void Show_Menu();

  // �˳�����
  void ExitSystem();

  // ���ְ��
  void addEmp();

  // ��¼�ļ��е�����
  int m_empNum;

  // Ա������ָ��
  Worker* * m_empArray;
};
