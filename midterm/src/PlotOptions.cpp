#include "PlotOptions.h"

#include "Aggregator.h"

// generate default plot options
PlotOptions::PlotOptions(std::vector<TemperatureEntry> entries) : displayValues(false), intervalSize(calcInterval(entries)), dateUnit(DateUnit::Year), dateRange("1980-2020")
{
}

// set plot options
PlotOptions::PlotOptions(bool displayValues, double intervalSize, DateUnit dateUnit, const std::string &dateRange) : displayValues(displayValues), intervalSize(intervalSize), dateUnit(dateUnit), dateRange(dateRange)
{
}

PlotOptions PlotOptions::setOptions()
{
  // print menu

  // get user input

  // set options
  return PlotOptions(false, 0.0, DateUnit::Year, "1980-2020");
};

double PlotOptions::calcInterval(std::vector<TemperatureEntry> entries)
{
  double interval = Aggregator::computeIntervals(entries);
  return interval;
}