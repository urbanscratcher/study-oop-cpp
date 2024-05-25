#include "OrderBookEntry.h"

// the implementation
// needs namespace to be specified
OrderBookEntry::OrderBookEntry(double _price,
                               double _amount,
                               std::string _timestamp,
                               std::string _product,
                               OrderBookType _orderType) : price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType)
{
}
