#pragma once

#include <string>
#include <vector>
#include "TemperatureEntry.h"

class Axis
{
public:
  Axis(char divider, std::string axisLabel);

  char divider;
  double intervalSize;
  std::string axisLabel;
  std::vector<std::string> tickLabels;

  std::vector<std::string> generateLabels(std::vector<double> intervalSize);

  double min;
  double max;
  void setMinMaxInterval(std::vector<double> items);
};