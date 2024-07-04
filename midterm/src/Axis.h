#pragma once

#include <string>
#include <vector>

class Axis
{

public:
  Axis(char divider, char tick, std::string axisLabel, double intervalSize);

  char divider;
  char tick;
  std::string axisLabel;
  std::vector<std::string> tickLabels;

private:
  void generateLabels(double intervalSize);
};