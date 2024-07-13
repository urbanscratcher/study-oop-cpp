
#include "Axis.h"
#include <iomanip> // for std::setprecision and std::fixed
#include <sstream> // for std::ostringstream
#include <iostream>

Axis::Axis(char divider, std::string axisLabel) : divider(divider), axisLabel(axisLabel)
{
}

void Axis::setMinMaxInterval(std::vector<double> items)
{
  // get min max
  double min = items[0];
  double max = 0;
  for (int i = 0; i < items.size(); i++)
  {
    if (items[i] < min)
    {
      min = items[i];
    }
    if (items[i] > max)
    {
      max = items[i];
    }
  }

  this->min = std::floor(min) - 2;
  this->max = std::ceil(max) + 2;
  this->intervalSize = 1;
}

std::vector<std::string> Axis::generateLabels(std::vector<double> items)
{
  std::vector<std::string> tickLabels;

  // ticks should be printed as min 1 2 3 ... max
  for (int i = static_cast<int>(this->min); i <= static_cast<int>(this->max); i++)
  {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << i;
    tickLabels.push_back(oss.str());
  }

  return tickLabels;
};
