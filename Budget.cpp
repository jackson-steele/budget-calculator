#include "Budget.h"

Budget::Budget()
{

}

void Budget::CreateBudget()
{
  std::string name;
  std::string amount;
  std::string type;
  std::string temp;
  std::string skip;

  std::cout << "Enter your budget in the format \"Item name, amount amount type\" (for example: \"Food, 10 dollars\" or \"Savings, 30 percent\"), with one entry per line. Type \"Done\" when done.\n";

  while (name != "Done" && name != "done")
  {
    getline(std::cin, temp);
    std::istringstream iss(temp);
    getline(iss, name, ',');
    if (name == "done" || name == "Done")
    {
      break;
    }
    getline(iss, skip, ' ');
    getline(iss, amount, ' ');
    getline(iss, type, '\n');
    BudgetItem newItem = BudgetItem(stod(amount), name, type);
    m_budget.push_back(newItem);
  }

  std::cout << "\nBudget entered successfully\n\n";
}

void Budget::ImportBudget(std::string fileName)
{
  std::ifstream ifs;
  std::string fileLocation = "_budgets/" + fileName + ".csv";

  std::string temp;
  std::string amount;
  std::string name;
  std::string type;

  ifs.open(fileLocation);
  if (!ifs.is_open())
  {
    std::cout << "Error: file not found\n";
    Budget();
  }
  else
  {
    while (getline(ifs,temp))
    {
      std::istringstream iss(temp);
      std::getline(iss, name, ',');
      std::getline(iss, amount, ',');
      std::getline(iss, type, '\n');

      BudgetItem newBudgetItem = BudgetItem(stod(amount), name, type);
      m_budget.push_back(newBudgetItem);
    }

    std::cout << "Budget entered successfully\n";
  }
}

void Budget::CalculatePaycheck(double paycheckAmount)
{
  double remainingBalance = paycheckAmount;
  std::ostringstream ss;

  ss << "Calculating paycheck allocation for $" << std::fixed << std::setprecision(2) << paycheckAmount << std::endl;

  for (unsigned i = 0; i < m_budget.size(); i++)
  {
    double currentAmount = m_budget.at(i).CalculateAmount(paycheckAmount);
    ss << m_budget.at(i).ToString(currentAmount);
    remainingBalance -= currentAmount;
  }

  ss << "After totaling all expenses, the remaining balance is: $" << std::fixed << std::setprecision(2) << remainingBalance << std::endl;

  std::cout << ss.str();
}

void Budget::Save(std::string budgetName)
{
  std::string fileName = "_budget/" + budgetName + ".csv";
  std::ofstream ofs(fileName);

  //ofs.open(fileName);
  if (!ofs.is_open())
  {
    std::cout << "Error writing to file\n";
  }
  else
  {
    for (unsigned i = 0; i < m_budget.size(); i++)
    {
      ofs << m_budget.at(i).GetName() << "," << std::to_string(m_budget.at(i).GetAmount()) << "," << m_budget.at(i).GetType() << std::endl;
    }
  }
}
