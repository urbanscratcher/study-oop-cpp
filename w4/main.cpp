#include <iostream>
#include <vector>
#include <string>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

int main()
{
    MerkelMain app{}; // 객체 초기화(c++11)
    app.init();
    // app.printMenu(); // not allowed to use private fn
}

// std::vector<OrderBookEntry> orders;

//     orders.push_back(OrderBookEntry{1000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask});
//     orders.push_back(OrderBookEntry{2000, 0.04, "2020/04/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});

//     // 1. call by reference
//     for (OrderBookEntry &order : orders)
//     {
//         std::cout << "The price is " << order.price << std::endl;
//     }

//     // 2. use index
//     for (unsigned int i = 0; i < orders.size(); ++i)
//     {
//         std::cout << "The price is " << orders[i].price << std::endl;
//     }

//     // 3. more object style
//     for (unsigned int i = 0; i < orders.size(); ++i)
//     {
//         std::cout << "The price is " << orders.at(i).price << std::endl;
//     }

//     return 0;