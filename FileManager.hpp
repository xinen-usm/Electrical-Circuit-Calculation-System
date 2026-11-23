#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <vector>
#include "CircuitRecord.hpp"
void saveRecords(const std::vector<CircuitRecord>& records, const std::string& filename);
void loadRecords(std::vector<CircuitRecord>& records, int& nextId, const std::string& filename);
#endif
