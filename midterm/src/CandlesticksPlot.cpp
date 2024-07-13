#include "CandlesticksPlot.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <algorithm>

CandlesticksPlot::CandlesticksPlot(Axis xAxis, Axis yAxis, PlotOptions options, std::vector<Candlestick> candlesticks)
    : xAxis(xAxis), yAxis(yAxis), options(options), candlesticks(candlesticks) {}

std::string CandlesticksPlot::drawCandlestick(const Candlestick &candlestick)
{

    std::ostringstream oss;

    double open = candlestick.open;
    double close = candlestick.close;
    double high = candlestick.high;
    double low = candlestick.low;

    double interval = xAxis.intervalSize / 4;
    int length = (xAxis.max - xAxis.min + 1) * 4;

    double adjust = xAxis.min - 0.5;

    // set positions
    int lowPosition = static_cast<int>((low - adjust) / interval);
    int highPosition = static_cast<int>((high - adjust) / interval);
    int openPosition = static_cast<int>((open - adjust) / interval);
    int closePosition = static_cast<int>((close - adjust) / interval);

    // check if openPosition is greater than closePosition
    if (openPosition > closePosition)
    {
        std::swap(openPosition, closePosition);
    }

    // print candlestick characters
    for (int i = 0; i < length; ++i)
    {
        if (i < lowPosition)
        {
            oss << " ";
        }

        if (i >= lowPosition && i < openPosition)
        {
            oss << "-";
        }

        if (i >= openPosition && i <= closePosition)
        {
            if (i == openPosition)
            {
                oss << "|";
            }
            else if (i == closePosition)
            {
                oss << "|";
            }
            else if (candlestick.open > candlestick.close)
            {
                oss << "x";
            }
            else
            {
                oss << " ";
            }
        }

        if (i > closePosition && i <= highPosition)
        {
            oss << "-";
        }
    }

    return oss.str();
}

void CandlesticksPlot::plot()
{
    // print x axis graphically ------------
    // print spaces before x labels
    std::cout << std::string(6, ' ');

    // print labels
    for (const auto &label : xAxis.tickLabels)
    {
        // place labels to the center
        int width = 4;
        int padding = (width - label.size()) / 2;
        int extra = (width - label.size()) % 2;

        std::cout << std::setw(padding + label.size()) << std::setfill(' ') << label;
        std::cout << std::setw(padding + extra) << std::setfill(' ') << "";
    }

    // go to next line
    std::cout << std::endl;

    // print spaces before x dividers
    std::cout << std::string(6, ' ');

    // divider(ruler)
    for (const auto &label : xAxis.tickLabels)
    {
        std::cout << std::string(4, xAxis.divider);
    }
    std::cout << " (" << xAxis.axisLabel << ")";
    std::cout << std::endl;

    // print y axis and candlestick graphically ------------
    for (int i = 0; i < candlesticks.size(); i++)
    {
        std::cout << yAxis.tickLabels[i] << " " << yAxis.divider;

        // print candlestick
        try
        {
            std::cout << drawCandlestick(candlesticks[i]);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error drawing candlestick: " << e.what() << std::endl;
        }

        std::cout << std::endl;
    }
    std::cout << "(" << yAxis.axisLabel << ")" << std::endl;
}

double CandlesticksPlot::predictTemperature(int year)
{
    // Ensure there are enough data points to make a prediction
    if (candlesticks.empty())
    {
        throw std::runtime_error("Not enough data to make a prediction.");
    }

    // Find the most recent year's candlestick
    const Candlestick &lastCandlestick = candlesticks.back();
    int lastYear = std::stoi(lastCandlestick.date.substr(0, 4));
    double lastTemperature = lastCandlestick.close; // Use the closing temperature of the last year

    // Calculate the average yearly change in temperature
    double totalChange = 0.0;
    int numberOfYears = candlesticks.size() - 1;

    for (int i = 1; i < candlesticks.size(); ++i)
    {
        int year1 = std::stoi(candlesticks[i - 1].date.substr(0, 4));
        int year2 = std::stoi(candlesticks[i].date.substr(0, 4));
        double tempChange = candlesticks[i].close - candlesticks[i - 1].close;
        int yearDifference = year2 - year1;

        // Avoid division by zero
        if (yearDifference != 0)
        {
            totalChange += tempChange / yearDifference;
        }
    }

    double averageChange = totalChange / numberOfYears;

    // Predict the temperature for the given year
    int yearsSinceLast = year - lastYear;
    double predictedTemperature = lastTemperature + (yearsSinceLast * averageChange);

    return predictedTemperature;
};