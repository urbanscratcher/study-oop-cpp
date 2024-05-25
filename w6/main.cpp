#include <iostream>
#include <vector>
#include <string>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"

int main()
{
    MerkelMain app{};
    app.init();
}

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