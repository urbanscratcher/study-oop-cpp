#include "WeatherMain.h"
#include <iostream>
#include "TemperatureEntry.h"
#include "CSVReader.h"
#include "Aggregator.h"
#include "Candlestick.h"
#include "PlotOptions.h"
#include "Axis.h"
#include "CandlesticksPlot.h"
#include <string>

WeatherMain::WeatherMain()
{
}

void WeatherMain::init()
{

  // Task 3 //////////////////////////////////
  PlotOptions plotOptions = PlotOptions();
  plotOptions.printMenu();

  // Task 1 //////////////////////////////////
  // read entries from csv file
  std::string csvFilename = "data.csv";

  // Task 3 - read entries with filter
  std::vector<TemperatureEntry> entries = CSVReader::readCSV(csvFilename, plotOptions.countryCode, plotOptions.minTemperature, plotOptions.maxTemperature, plotOptions.earliestYear, plotOptions.latestYear);

  // aggregate & compute data from temperature entries (conversion to candlesticks)
  std::vector<Candlestick> candlesticks = Aggregator::aggregateYearly(entries);

  // Task 2 //////////////////////////////////
  // print a title
  std::cout << "===================================================" << std::endl;
  std::cout << "[Weather Plot" << " (" << plotOptions.countryCode << ", " << plotOptions.earliestYear << "-" << plotOptions.latestYear << ")]" << std::endl;
  // inatantiate X axis ------------
  Axis xAxis = Axis('_', "Temperature");

  // set interval size
  std::vector<double> temperatures;
  for (int i = 0; i < entries.size(); i++)
  {
    temperatures.push_back(entries[i].temperature);
  }

  xAxis.setMinMaxInterval(temperatures);
  xAxis.tickLabels = xAxis.generateLabels(temperatures);

  // inatantiate Y axis -----------
  Axis yAxis = Axis('|', "Year");
  yAxis.intervalSize = 1;

  // get years
  std::vector<std::string> years;
  for (int i = 0; i < candlesticks.size(); i++)
  {
    // year: 1980-01-01T02:00:00Z
    // get 1980 part only
    std::string year = candlesticks[i].date.substr(0, 4);
    years.push_back(year);
  }
  yAxis.tickLabels = years;

  // instantiate candlestick plot
  CandlesticksPlot candlesticksPlot = CandlesticksPlot(xAxis, yAxis, plotOptions, candlesticks);

  // plot candlesticks
  candlesticksPlot.plot();

  // Task 4 //////////////////////////////////
  // predict temperature
  std::cout << "Predicted Average temperature for Next Year: " << candlesticksPlot.predictTemperature(2021) << std::endl;
}