#pragma once

#include <string>
#include <vector>
#include "TemperatureEntry.h"

// Purpose: read a CSV file and return a vector of TemperatureEntry objects
class CSVReader
{
public:
  CSVReader();

  static std::vector<TemperatureEntry> readCSV(std::string &csvFile, std::string &countryCode, double minTemperature, double maxTemperature, int earliestYear, int latestYear);

  static std::vector<std::string> tokenise(std::string csvLine, char separator);

private:
  static TemperatureEntry stringsToTE(std::vector<std::string> strings, int dateIndex, int temperatureIndex);
};