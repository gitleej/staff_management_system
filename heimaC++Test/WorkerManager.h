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

  // 展示菜单
  void Show_Menu();

  // 退出程序
  void ExitSystem();

  // 添加职工
  void addEmp();

  // 记录文件中的人数
  int m_empNum;

  // 员工数组指针
  Worker* * m_empArray;
};
