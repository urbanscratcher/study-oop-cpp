#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown
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

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
