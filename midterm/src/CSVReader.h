#pragma once

#include <string>
#include <vector>
#include "TemperatureEntry.h"

// Purpose: read a CSV file and return a vector of TemperatureEntry objects
class CSVReader
{
public:
  CSVReader();

  static std::vector<TemperatureEntry> readCSV(std::string csvFile);

  static std::vector<std::string> tokenise(std::string csvLine, char separator);

private:
  static TemperatureEntry stringsToTE(std::vector<std::string> strings, int dateIndex, int temperatureIndex);
};