#include <iostream>

void printMenu()
{
  // 1 print help
  std::cout << "1: Print help" << std::endl;

  // 2 print eschange stats
  std::cout << "2: Print exchange stats" << std::endl;

  // 3 make an offer
  std::cout << "3: Make an offer" << std::endl;

  // 4 make a bid
  std::cout << "4: Make a bid" << std::endl;

  // 5 print wallet
  std::cout << "5: Print wallet" << std::endl;

  // 6 continue
  std::cout << "6: Continue" << std::endl;

  std::cout << "=================" << std::endl;
}

void printHelp()
{
  std::cout << "Help - your aim is to make money, Analyze the market and make bids and offers" << std::endl;
}

void printMarketStats()
{
  std::cout << "Market looks good" << std::endl;
}
void printWallet()
{
  std::cout << "Mark and offer - enter the amount" << std::endl;
}
void enterBid()
{
  std::cout << "Make a bid - enter the amount" << std::endl;
}
void printWallet()
{
  std::cout << "Your wallet is empty" << std::endl;
}
void gotoNextTimeframe()
{
  std::cout << "Going to next time frame" << std::endl;
}

int getUserOption()
{
  int userOption;

  std::cout << "Type in 1-6: ";
  std::cin >> userOption;
  std::cout << "You chose: " << userOption << std::endl;

  return userOption;
}

void processUserOption(int userOption)
{
  if (userOption == 0) // bad input
  {
    std::cout << "Invalid choice. Choose 1-6" << std::endl;
  }
  if (userOption == 1)
  {
    printHelp();
  }
  if (userOption == 2)
  {
    printMarketStats();
  }
  if (userOption == 3)
  {
    printWallet();
  }
  if (userOption == 4)
  {
    enterBid();
  }
  if (userOption == 5)
  {
    printWallet();
  }
  if (userOption == 6)
  {
    gotoNextTimeframe();
  }
}

// Problem: every function after main() was not declared in the scope
// Solution: declare the functions before main()
int main()
{
  while (true)
  {
    printMenu();
    int userOption = getUserOption();
    processUserOption(userOption);
  }
  return 0;
}
