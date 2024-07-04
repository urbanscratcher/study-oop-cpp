#include "TemperatureEntry.h"

#include <vector>
#include <string>
#include "CSVReader.h"

TemperatureEntry::TemperatureEntry(std::string _date, double _temperature) : date(_date), temperature(_temperature)
{
}
