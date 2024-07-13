#pragma once

#include <string>
#include <vector>
#include "TemperatureEntry.h"

class PlotOptions
{
public:
  PlotOptions();

  std::string countryCode;
  std::string dateRange;
  std::string temperatureRange;

  double maxTemperature;
  double minTemperature;

  int earliestYear;
  int latestYear;

  void printMenu();

private:
  void setOptions(std::string countryCode, std::string dateRange, std::string temperatureRange);
};