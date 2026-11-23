#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP
#include <vector>
#include "CircuitRecord.hpp"
void calculateVoltage(std::vector<CircuitRecord>& records, int& nextId);
void calculateCurrent(std::vector<CircuitRecord>& records, int& nextId);
void calculateResistance(std::vector<CircuitRecord>& records, int& nextId);
void calculatePower(std::vector<CircuitRecord>& records, int& nextId);
void calculateCapacitiveReactance(std::vector<CircuitRecord>& records, int& nextId);
void calculateInductiveReactance(std::vector<CircuitRecord>& records, int& nextId);
#endif
