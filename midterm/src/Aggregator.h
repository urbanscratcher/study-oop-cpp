#pragma once

#include <vector>
#include "TemperatureEntry.h"
#include "Candlestick.h"

// Purpose: aggregate temperature entries
class Aggregator
{
public:
  Aggregator();

  static std::vector<Candlestick> aggregateYearly(std::vector<TemperatureEntry> entries);

  static double computeIntervals(std::vector<TemperatureEntry> entries);

private:
  static double computeAverage(std::vector<TemperatureEntry> entries);
  static double computeHigh(std::vector<TemperatureEntry> entries);
  static double computeLow(std::vector<TemperatureEntry> entries);
};