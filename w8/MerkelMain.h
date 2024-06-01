#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

/**
 * MerkelMain class is the main class of the Merkel Market simulation. It is responsible for the user interface and for calling the other classes.
 */
class MerkelMain
{
public:
    MerkelMain();
    /** Call this to start the sim */
    void init();

private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);

    std::string currentTime;
    // OrderBook orderBooks{"20200317.csv"};
    OrderBook orderBooks{"test.csv"};
};
