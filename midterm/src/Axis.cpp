
#include "Axis.h"

Axis::Axis(char divider, char tick, std::string axisLabel, double intervalSize) : divider(divider), tick(tick), axisLabel(axisLabel)
{
  generateLabels(intervalSize);
};

void Axis::generateLabels(double intervalSize)
{
  tickLabels.clear();
  for (int i = 0; i < 10; i++)
  {

    double tickValue = i * intervalSize;

    // convert tickValue to fixed 2 decimal places
    std::string tickValueStr = std::to_string(tickValue);
    tickValueStr = tickValueStr.substr(0, tickValueStr.find(".") + 3);

    tickLabels.push_back(tickValueStr);
  }
};