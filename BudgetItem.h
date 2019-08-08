#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class BudgetItem
{
public:
  BudgetItem(int amount, std::string name, std::string type);
  int GetAmount() const;
  std::string GetName() const;
  std::string GetType() const;
  double CalculateAmount(double paycheckAmount);
  std::string ToString(double amount);
private:
  int m_amount;
  std::string m_name;
  std::string m_type;
  int const PERCENT = 100;
};
