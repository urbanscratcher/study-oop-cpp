#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
  orders = CSVReader::readCSV(filename);
};

/** return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
  std::vector<std::string> products;

  std::map<std::string, bool> prodMap;
  for (OrderBookEntry &o : orders)
  {
    prodMap[o.product] = true;
  }

  // flatten the map to a vector of strings
  for (const auto &m : prodMap)
  {
    products.push_back(m.first);
  }

  return products;
};

/** return vector of Orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
  std::vector<OrderBookEntry> orders_sub;

  for (OrderBookEntry &o : orders)
  {
    if (o.orderType == type &&
        o.product == product &&
        o.timestamp == timestamp)
    {
      orders_sub.push_back(o);
    }
  }

  return orders_sub;
};

void OrderBook::insertOrder(OrderBookEntry &order)
{
  orders.push_back(order);
  std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
};

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
  double max = orders[0].price;

  for (int i = 1; i < orders.size(); ++i)
  {
    if (orders[i].price > max)
    {
      max = orders[i].price;
    }
  }

  return max;
};

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
  double min = orders[0].price;

  for (int i = 1; i < orders.size(); ++i)
  {
    if (orders[i].price < min)
    {
      min = orders[i].price;
    }
  }

  return min;
};

double OrderBook::getMeanPrice(std::vector<OrderBookEntry> &orders)
{
  double mean = 0;
  double sum = 0;

  // Calculate sum of all prices
  for (OrderBookEntry &o : orders)
  {
    sum += o.price;
  }

  // Calculate mean if there are orders
  if (orders.size() > 0)
  {
    mean = sum / orders.size();
  }

  return mean;
}

double OrderBook::getMedianPrice(std::vector<OrderBookEntry> &orders)
{
  double median = 0;

  // sort by price in ascending order
  // store in a new vector to avoid modifying the original
  std::vector<OrderBookEntry> sortedOrders = orders;
  std::sort(sortedOrders.begin(), sortedOrders.end(), [](OrderBookEntry &a, OrderBookEntry &b)
            { return a.price < b.price; });

  int n = sortedOrders.size();

  // if no orders, return 0
  if (n == 0)
  {
    return median;
  }

  // calculate median
  // if even number of elements, average the middle two
  // if odd number of elements, take the middle one
  if (n % 2 == 0)
  {
    median = (sortedOrders[n / 2].price + sortedOrders[n / 2 - 1].price) / 2;
  }
  else
  {
    median = sortedOrders[n / 2].price;
  }

  return median;
};

double OrderBook::getMeanPriceChange(std::vector<OrderBookEntry> &prevOrders, std::vector<OrderBookEntry> &currentOrders)
{
  double change = getMeanPrice(currentOrders) - getMeanPrice(prevOrders);
  return change;
};
double OrderBook::getMedianPriceChange(std::vector<OrderBookEntry> &prevOrders, std::vector<OrderBookEntry> &currentOrders)
{
  double change = getMedianPrice(currentOrders) - getMedianPrice(prevOrders);
  return change;
};

double OrderBook::getTotalAmount(std::vector<OrderBookEntry> &orders)
{
  double total = 0;
  for (OrderBookEntry &o : orders)
  {
    total += o.amount;
  }
  return total;
};

double OrderBook::getVWAP(std::vector<OrderBookEntry> &orders)
{
  double vwap = 0;
  double priceAmount = 0;
  double totalAmount = 0;

  for (OrderBookEntry &o : orders)
  {
    priceAmount += o.price * o.amount;
    totalAmount += o.amount;
  }

  if (totalAmount != 0)
  {
    vwap = priceAmount / totalAmount;
  }

  return vwap;
};

double OrderBook::getVWAPChange(std::vector<OrderBookEntry> &prevOrders, std::vector<OrderBookEntry> &currentOrders)
{
  double change = getVWAP(currentOrders) - getVWAP(prevOrders);
  return change;
};

std::string OrderBook::getEarliestTime()
{
  return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
  std::string next_timestamp = "";

  for (OrderBookEntry &o : orders)
  {
    if (o.timestamp > timestamp)
    {
      next_timestamp = o.timestamp;
      break;
    }
  };

  if (next_timestamp == "")
  {
    next_timestamp = orders[0].timestamp;
  }

  return next_timestamp;
}

std::string OrderBook::getPreviousTime(std::string timestamp)
{
  std::string prev_timestamp = "";

  for (int i = orders.size() - 1; i >= 0; --i)
  {
    if (orders[i].timestamp < timestamp)
    {
      prev_timestamp = orders[i].timestamp;
      break;
    }
  };

  if (prev_timestamp == "")
  {
    prev_timestamp = orders[orders.size() - 1].timestamp;
  }

  return prev_timestamp;
}