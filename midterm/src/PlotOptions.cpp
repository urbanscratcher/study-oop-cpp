#include "PlotOptions.h"
#include "Aggregator.h"
#include <iostream>
#include <string>

// generate default plot options
PlotOptions::PlotOptions() : countryCode("GB"), dateRange("1980,2020"), temperatureRange("0,60")
{
}

// set plot options
void PlotOptions::setOptions(std::string countryCode, std::string dateRange, std::string temperatureRange)
{
  this->countryCode = countryCode;
  this->dateRange = dateRange;
  this->temperatureRange = temperatureRange;

  // set max and min temperature
  this->minTemperature = std::stod(temperatureRange.substr(0, temperatureRange.find(",")));
  this->maxTemperature = std::stod(temperatureRange.substr(temperatureRange.find(",") + 1));

  // set earliest and latest date
  this->earliestYear = std::stoi(dateRange.substr(0, dateRange.find(",")));
  this->latestYear = std::stoi(dateRange.substr(dateRange.find(",") + 1));
}

void PlotOptions::printMenu()
{
  std::cout << "Please enter the following options:" << std::endl;
  std::cout << "Country code (e.g. GB): ";
  std::string countryCode;
  std::cin >> countryCode;
  // change countrycode to uppercase
  for (int i = 0; i < countryCode.size(); i++)
  {
    countryCode[i] = toupper(countryCode[i]);
  }

  std::cout << "Date range (e.g. 1980,2020): ";
  std::string dateRange;
  std::cin >> dateRange;
  // throw error if , is not found
  if (dateRange.find(",") == std::string::npos)
  {
    throw std::invalid_argument("Invalid date range");
  }

  std::cout << "Temperature range (e.g. -7,60): ";
  std::string temperatureRange;
  std::cin >> temperatureRange;
  // throw error if , is not found
  if (temperatureRange.find(",") == std::string::npos)
  {
    throw std::invalid_argument("Invalid temperature range");
  }

  // set options
  setOptions(countryCode, dateRange, temperatureRange);
};
