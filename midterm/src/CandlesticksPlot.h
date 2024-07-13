#pragma once

#include <vector>
#include "Axis.h"
#include "PlotOptions.h"
#include "Candlestick.h"

class CandlesticksPlot
{
public:
  Axis xAxis;
  Axis yAxis;
  PlotOptions options;
  std::vector<Candlestick> candlesticks;

  CandlesticksPlot(Axis xAxis, Axis yAxis, PlotOptions options, std::vector<Candlestick> candlesticks);

  void plot();

  double predictTemperature(int year);

private:
  std::string drawCandlestick(const Candlestick &candlestick);
};