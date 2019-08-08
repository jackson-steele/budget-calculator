#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>

#include "BudgetItem.h"

class Budget
{
public:
  Budget();
  void CreateBudget();
  void ImportBudget(std::string fileName);
  void CalculatePaycheck(double paycheckAmount);
  void Save(std::string budgetName);
private:
  std::vector<BudgetItem> m_budget;
};
