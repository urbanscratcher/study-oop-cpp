#include "Wallet.h"
#include <iostream>
#include "CSVReader.h"

Wallet::Wallet()
{
}

void Wallet::insertCurrency(std::string type, double amount)
{
  double balance;
  if (amount < 0)
  {
    throw std::exception{};
  }

  if (currencies.count(type) == 0)
  { // not there yet
    balance = 0;
  }
  else // is there
  {
    balance = currencies[type];
  }

  balance += amount;
  currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
  double balance;
  if (amount < 0)
  {
    throw false;
  }

  if (currencies.count(type) == 0)
  { // not there yet
    return false;
  }
  else // is there - do we have enough
  {

    if (containsCurrency(type, amount)) // we have enough
      currencies[type] -= amount;
  }

  return false;
}

bool Wallet::containsCurrency(std::string type, double amount)
{
  if (currencies.count(type) == 0)
    return false;
  else
    return currencies[type] >= amount;
}

std::string Wallet::toString()
{
  std::string s;
  for (std::pair<std::string, double> pair : currencies)
  {
    std::string currency = pair.first;
    double amount = pair.second;
    s += currency + " : " + std::to_string(amount) + "\n";
  }
  return s;
}

bool Wallet::canFullfillOrder(OrderBookEntry order)
{

  std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');

  // ask
  if (order.orderType == OrderBookType::ask)
  {
    double amount = order.amount;
    std::string currency = currs[0];
    std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
    return containsCurrency(currency, amount);
  }

  // bid
  if (order.orderType == OrderBookType::bid)
  {
    double amount = order.amount * order.price;
    std::string currency = currs[1];
    std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
    return containsCurrency(currency, amount);
  }

  return false;
};
