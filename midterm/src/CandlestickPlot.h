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
  std::vector<PlotOptions> options;
  std::vector<std::vector<Candlestick>> candlesticks;

  CandlesticksPlot(Axis xAxis, Axis yAxis, std::vector<PlotOptions> options, std::vector<std::vector<Candlestick>> candlesticks);

  void plot();
  void plotCandlesticks();
  void plotAxes();
};