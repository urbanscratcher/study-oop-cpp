#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown,
    sale
};

/**
 * OrderBookEntry class represents an entry in the order book. An order book entry is defined by a price, an amount, a timestamp, a product and an order type.
 */
class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);

    static OrderBookType stringToOrderBookType(std::string s);

    static bool compareByTimestamp(OrderBookEntry &e1, OrderBookEntry &e2);
    static bool compareByPriceAsc(OrderBookEntry &e1, OrderBookEntry &e2);
    static bool compareByPriceDesc(OrderBookEntry &e1, OrderBookEntry &e2);

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
