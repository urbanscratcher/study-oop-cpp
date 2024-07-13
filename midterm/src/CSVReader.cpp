#include "CSVReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "TemperatureEntry.h"

CSVReader::CSVReader()
{
}

std::vector<TemperatureEntry> CSVReader::readCSV(std::string &csvFilename, std::string &countryCode, double minTemperature, double maxTemperature, int earlistYear, int latestYear)
{

  std::vector<TemperatureEntry> entries;
  std::ifstream csvFile(csvFilename);
  std::string line;

  if (csvFile.is_open())
  {
    // find index of date and temperature columns from header
    //////////////////////////////////////////////
    // read the header line
    std::getline(csvFile, line);

    // tokenise the header line
    std::vector<std::string> header = tokenise(line, ',');
    std::string temperatureColumnName = countryCode + "_temperature";

    // find the index of the date and temperature columns
    int dateIndex = -1;
    int temperatureIndex = -1;
    for (int i = 0; i < header.size(); i++)
    {
      if (header[i] == "utc_timestamp")
      {
        dateIndex = i;
      }
      if (header[i] == temperatureColumnName)
      {
        temperatureIndex = i;
      }
    }

    // if the date or temperature columns are missing, throw an exception
    if (dateIndex == -1 || temperatureIndex == -1)
    {
      throw std::invalid_argument("CSVReader::readCSV: CSV file is missing date or temperature columns");
    }

    // proceed to read the data after the header
    ////////////////////////////////////////////
    while (std::getline(csvFile, line))
    {
      try
      {
        // convert the line into a TemperatureEntry
        TemperatureEntry entry = stringsToTE(tokenise(line, ','), dateIndex, temperatureIndex);

        // add the TemperatureEntry to the vector if it is within the temperature range and the date range
        if (entry.temperature >= minTemperature && entry.temperature <= maxTemperature && entry.date.substr(0, 4) >= std::to_string(earlistYear) && entry.date.substr(0, 4) <= std::to_string(latestYear))
        {
          entries.push_back(entry);
        }
      }
      catch (const std::exception &e)
      {
        std::cout << "CSVReader::readCSV bad data" << std::endl;
      }
    } // end of while
  }

  std::cout << entries.size() << " entries read" << std::endl;

  return entries;
}

TemperatureEntry CSVReader::stringsToTE(std::vector<std::string> tokens, int dateIndex, int temperatureIndex)
{
  std::string date = tokens.at(dateIndex);
  std::string temperature = tokens.at(temperatureIndex);
  return TemperatureEntry(date, std::stod(temperature));
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
  std::vector<std::string> tokens;
  signed int start, end;
  std::string token;
  start = csvLine.find_first_not_of(separator, 0);
  do
  {
    end = csvLine.find_first_of(separator, start);
    if (start == csvLine.length() || start == end)
      break;
    if (end >= 0)
      token = csvLine.substr(start, end - start);
    else
      token = csvLine.substr(start, csvLine.length() - start);
    tokens.push_back(token);
    start = end + 1;
  } while (end > 0);

  return tokens;
}