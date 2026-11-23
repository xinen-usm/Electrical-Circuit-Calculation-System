#ifndef RECORD_MANAGER_HPP
#define RECORD_MANAGER_HPP
#include <vector>
#include "CircuitRecord.hpp"

void viewRecords(const std::vector<CircuitRecord>& records);
void searchRecord(const std::vector<CircuitRecord>& records);
void updateRecord(std::vector<CircuitRecord>& records);
void deleteRecord(std::vector<CircuitRecord>& records);
void sortRecords(std::vector<CircuitRecord>& records);

#endif
