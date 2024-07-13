#include "Aggregator.h"
#include <map>

Aggregator::Aggregator() {};

std::vector<Candlestick> Aggregator::aggregateYearly(std::vector<TemperatureEntry> entries)
{

  std::vector<Candlestick> candlesticks;

  // store entries in a dictionary based on year
  std::map<std::string, std::vector<TemperatureEntry>> dict;
  for (int i = 0; i < entries.size(); i++)
  {
    TemperatureEntry entry = entries[i];
    std::string year = entry.date.substr(0, 4);
    dict[year].push_back(entry);
  }

  // iterate through the dictionary and compute candlesticks
  for (auto const &pair : dict)
  {
    std::string year = pair.first;
    std::vector<TemperatureEntry> yearEntries = pair.second;

    // get previous candlestick close
    // because it is the open of the current candlestick
    // initiate to the first temperature value if it is the first candlestick
    double prevClose = yearEntries[0].temperature;
    if (candlesticks.size() > 0)
    {
      prevClose = candlesticks[candlesticks.size() - 1].close;
    }

    // create a candlestick
    Candlestick candlestick;
    candlestick.date = year;
    candlestick.open = prevClose;
    candlestick.close = computeAverage(yearEntries);
    candlestick.high = computeHigh(yearEntries);
    candlestick.low = computeLow(yearEntries);

    // add the candlestick to vector
    candlesticks.push_back(candlestick);
  }

  return candlesticks;
};

double Aggregator::computeIntervals(std::vector<TemperatureEntry> entries)
{
  double interval = 0.0;
  double max = computeHigh(entries);
  double min = computeLow(entries);
  interval = (max - min) / 10;
  return interval;
}

double Aggregator::computeAverage(std::vector<TemperatureEntry> entries)
{
  double sum = 0;
  for (TemperatureEntry entry : entries)
  {
    sum += entry.temperature;
  }
  return sum / entries.size();
};

double Aggregator::computeHigh(std::vector<TemperatureEntry> entries)
{
  double max = entries[0].temperature;
  for (TemperatureEntry entry : entries)
  {
    if (entry.temperature > max)
    {
      max = entry.temperature;
    }
  }
  return max;
};

double Aggregator::computeLow(std::vector<TemperatureEntry> entries)
{
  double min = entries[0].temperature;
  for (TemperatureEntry entry : entries)
  {
    if (entry.temperature < min)
    {
      min = entry.temperature;
    }
  }
  return min;
};