#include "WeatherMain.h"
#include <iostream>
#include "TemperatureEntry.h"
#include "CSVReader.h"
#include "Aggregator.h"
#include "Candlestick.h"
#include "PlotOptions.h"
#include "Axis.h"

WeatherMain::WeatherMain()
{
}

void WeatherMain::init()
{

  // Task 1 //////////////////////////////////
  // read entries from csv file
  std::string csvFilename = "test_data.csv";
  std::vector<TemperatureEntry> entries = CSVReader::readCSV(csvFilename);

  // aggregate & compute data from temperature entries (conversion to candlesticks)
  std::vector<Candlestick> candlesticks = Aggregator::aggregateYearly(entries);

  // Task 2 //////////////////////////////////
  // get user input and set plot options
  PlotOptions plotOptions = PlotOptions(entries);

  // print plot options
  std::cout << "Plot options: " << std::endl;
  std::cout << "Display values: " << plotOptions.displayValues << std::endl;
  std::cout << "Interval size: " << plotOptions.intervalSize << std::endl;
  std::cout << "Date unit: " << static_cast<int>(plotOptions.dateUnit) << std::endl;
  std::cout << "Date range: " << plotOptions.dateRange << std::endl;

  // inatantiate axis
  Axis xAxis = Axis('_', '|', "Temperature", plotOptions.intervalSize);

  // print x axis graphically
  for (int i = 0; i < xAxis.tickLabels.size(); i++)
  {

    std::cout << ' ' << xAxis.tickLabels[i];
  }
  std::cout << std::endl;
  for (int i = 0; i < xAxis.tickLabels.size(); i++)
  {
    std::cout << xAxis.divider << xAxis.divider << xAxis.divider << xAxis.divider << xAxis.tick;
  }
  std::cout << std::endl;
}