#pragma once

#include <string>
#include <vector>
#include "TemperatureEntry.h"

enum class DateUnit
{
  Year,
  Month,
  Day
};

class PlotOptions
{
public:
  PlotOptions(std::vector<TemperatureEntry> entries);
  PlotOptions(bool displayValues, double intervalSize, DateUnit dateUnit, const std::string &dateRange);

  bool displayValues;
  double intervalSize;
  DateUnit dateUnit;
  std::string dateRange;

  void printMenu();
  PlotOptions setOptions();

private:
  static double calcInterval(std::vector<TemperatureEntry> entries);
};