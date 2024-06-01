#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "OrderBook.h"

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    currentTime = orderBooks.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats()
{

    for (std::string const p : orderBooks.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBooks.getOrders(OrderBookType::ask, p, currentTime);

        std::cout << " Asks seen: " << entries.size() << std::endl;
        // basic ranges
        std::cout << " Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << " Min ask: " << OrderBook::getLowPrice(entries) << std::endl;

        // different average measures
        std::cout << " Mean ask: " << OrderBook::getMeanPrice(entries) << std::endl;
        std::cout << " Median ask: " << OrderBook::getMedianPrice(entries) << std::endl;
        std::cout << " VWAP ask: " << OrderBook::getVWAP(entries) << std::endl;

        // get previous orderbooks and compare to current
        std::string previousTime = orderBooks.getPreviousTime(currentTime);
        std::vector<OrderBookEntry> previousEntries = orderBooks.getOrders(OrderBookType::ask, p, previousTime);

        std::cout << " Mean change ask: " << OrderBook::getMeanPriceChange(previousEntries, entries) << std::endl;
        std::cout << " Median change ask: " << OrderBook::getMedianPriceChange(previousEntries, entries) << std::endl;
        std::cout << " VWAP change ask: " << OrderBook::getVWAPChange(previousEntries, entries) << std::endl;

        // total orders
        std::cout << " Total amount ask: " << OrderBook::getTotalAmount(entries) << std::endl;
    }
}

void MerkelMain::enterAsk()
{
    std::cout << "Mark and ask - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;

    std::string input;
    // When using getline() and cin() together...
    // getline returns immediately, instead of waiting until the user typed in a line of text
    // because the input buffer contains the newline character from the previous input
    // so cin should ignore the maximum size of string
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "Invalid input. Please enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
            orderBooks.insertOrder(obe);
        }
        catch (const std::exception &e)
        {
            std::cout << "MerkelMain::enterAsk Bad input " << std::endl;
        }
    }

    std::cout
        << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
    for (std::string &p : orderBooks.getKnownProducts())
    {
        std::cout << "matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBooks.matchAsksToBids(p, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        for (OrderBookEntry &sale : sales)
        {
            std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
        }
    }
    currentTime = orderBooks.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try
    {
        userOption = std::stoi(line);
    }
    catch (const std::exception &e)
    {
        //
    }

    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
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
        enterAsk();
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
