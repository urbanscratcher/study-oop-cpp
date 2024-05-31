#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

/**
 * OrderBook class represents a collection of OrderBookEntry objects. It is responsible for reading a CSV file and storing the data in a vector of OrderBookEntry objects. It also provides methods to query the data.
 */
class OrderBook
{
public:
  /** construct, reading a csv data file */
  OrderBook(std::string filename);

  /** return vector of all known products in the dataset */
  std::vector<std::string> getKnownProducts();

  /** return vector of Orders according to the sent filters */
  std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);

  /** returns the earliest time in the orderbook */
  std::string getEarliestTime();

  /** returns the next time after the sent time in the orderbook
   *  If there is no next time, wraps around to the start
   */
  std::string getNextTime(std::string timestamp);

  /**
   * returns the previous time before the sent time in the orderbook
   * If there is no previous time, wraps around to the end
   */
  std::string getPreviousTime(std::string timestamp);

  static double getHighPrice(std::vector<OrderBookEntry> &orders);
  static double getLowPrice(std::vector<OrderBookEntry> &orders);
  static double getMeanPrice(std::vector<OrderBookEntry> &orders);
  static double getMedianPrice(std::vector<OrderBookEntry> &orders);

  /**
   * Change in mean price since the previous timeframe
   */
  static double getMeanPriceChange(std::vector<OrderBookEntry> &prevOrders, std::vector<OrderBookEntry> &currentOrders);

  /**
   * Change in mean price since the previous timeframe
   */
  static double getMedianPriceChange(std::vector<OrderBookEntry> &prevOrders, std::vector<OrderBookEntry> &currentOrders);

  /**
   * Total amount of all orders in the orderbook
   */
  static double getTotalAmount(std::vector<OrderBookEntry> &orders);

  /**
   * VWAP( Volume Weighted Average Price) is the average price weighted by volume, meaning the intensity of the trade.
   * It is calculated by taking the average price of all the trades over a particular time frame, weighted by the volume of each trade.
   * If a price is lower than vwap, it is considered a good price.
   * If a price is higher than vwap, it is considered a bad price.
   * High vwap means that many trades happened at a high price.
   * Low vwap means that many trades happened at a low price.
   * returns 0 if no trades
   */
  static double getVWAP(std::vector<OrderBookEntry> &orders);

  /**
   * get change in vwap since the previous timeframe
   */
  static double getVWAPChange(std::vector<OrderBookEntry> &prevOrders, std::vector<OrderBookEntry> &currentOrders);

  void insertOrder(OrderBookEntry &order);

private:
  std::vector<OrderBookEntry> orders;
};