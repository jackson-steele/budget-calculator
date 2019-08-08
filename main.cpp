#include <iostream>

#include "Budget.h"

int main()
{
  //Get Budget
  Budget userBudget;
  std::cout << "If you want to use a previously created budget, enter the budget name below. Otherwise, enter \"new\"\n";

  std::string temp;
  getline(std::cin, temp);
  if (temp == "new" || temp == "New")
  {
    userBudget.CreateBudget();
  }
  else
  {
    userBudget.ImportBudget(temp);
  }

  //Get paycheck
  std::string paycheckAmount;
  std::cout << "\nEnter your paycheck amount:\n$";
  getline(std::cin, paycheckAmount);
  userBudget.CalculatePaycheck(stod(paycheckAmount));

  //Write out budget
  if (temp == "new" || temp == "New")
  {
    std::cout << "\nWould you like to save today's budget? (Y or N)\n";
    std::string saveBudget;
    getline(std::cin, saveBudget);
    if (saveBudget == "y" || saveBudget == "Y")
    {
      std::cout << "\nEnter a name for this budget:\n";
      std::string budgetName;
      getline(std::cin, budgetName);
      userBudget.Save(budgetName);
    }
  }
  return 0;
}
