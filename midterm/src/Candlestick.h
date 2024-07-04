#pragma once

#include <string>

// Purpose: represent a candlestick
class Candlestick
{
public:
  Candlestick();

  // Current date (unit can be year, month, and day)
  std::string date;

  // Opening price (the average mean temperature in the previous year)
  double open;

  // Closing price (the average mean temperature in the current year)
  double close;

  // Highest price (the highest temperature in the current year)
  double high;

  // Lowest price (the lowest temperature in the current year)
  double low;
};