#pragma once

#include <string>

// Purpose: represent a temperature entry of the weather data set
class TemperatureEntry
{
public:
  TemperatureEntry(std::string date, double temperature);

  std::string date;
  double temperature;
};