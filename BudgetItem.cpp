#include "BudgetItem.h"

BudgetItem::BudgetItem(int amount, std::string name, std::string type)
{
  m_type = type;
  m_name = name;
  if (type == "percent")
  {
    m_amount = amount / PERCENT;
  }
  else
  {
    m_amount = amount;
  }
}

int BudgetItem::GetAmount() const
{
  return m_amount;
}

std::string BudgetItem::GetName() const
{
  return m_name;
}

std::string BudgetItem::GetType() const
{
  return m_type;
}

double BudgetItem::CalculateAmount(double paycheckAmount)
{
  if (m_type == "percent")
  {
    return (paycheckAmount * m_amount);
  }
  else
  {
    return m_amount;
  }
}

std::string BudgetItem::ToString(double amount)
{
  std::ostringstream ss;
  ss << "  " << m_name << ": $" << std::fixed << std::setprecision(2) << amount << std::endl;
  return ss.str();
}
