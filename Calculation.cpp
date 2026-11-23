#include "Calculation.hpp"
#include "Input.hpp"
#include <iostream>
#include <cmath>

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Calculates voltage using current and resistance, then records the result.
void calculateVoltage(std::vector<CircuitRecord>& records, int& nextId)
{
    double current = readPositiveNumber("Enter current (A): ");
    double resistance = readPositiveNumber("Enter resistance (ohm): ");
    double result = current * resistance;
    std::cout << "Voltage = " << result << " V\n";
    records.emplace_back(nextId++, "Voltage", current, resistance, result, "V");
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Calculates current using voltage and resistance, then records the result.
void calculateCurrent(std::vector<CircuitRecord>& records, int& nextId)
{
    double voltage = readPositiveNumber("Enter voltage (V): ");
    double resistance = readPositiveNumber("Enter resistance (ohm): ");
    double result = voltage / resistance;
    std::cout << "Current = " << result << " A\n";
    records.emplace_back(nextId++, "Current", voltage, resistance, result, "A");
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Calculates resistance using voltage and current, then records the result.
void calculateResistance(std::vector<CircuitRecord>& records, int& nextId) 
{
    double voltage = readPositiveNumber("Enter voltage (V): ");
    double current = readPositiveNumber("Enter current (A): ");
    double result = voltage / current;
    std::cout << "Resistance = " << result << " ohm\n";
    records.emplace_back(nextId++, "Resistance", voltage, current, result, "ohm");
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Calculates electrical power using voltage and current, then records the result.
void calculatePower(std::vector<CircuitRecord>& records, int& nextId)
{
    double voltage = readPositiveNumber("Enter voltage (V): ");
    double current = readPositiveNumber("Enter current (A): ");
    double result = voltage * current;
    std::cout << "Power = " << result << " W\n";
    records.emplace_back(nextId++, "Power", voltage, current, result, "W");
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Calculates capacitive reactance and stores the result.
void calculateCapacitiveReactance(std::vector<CircuitRecord>& records, int& nextId) 
{
    const double pi = std::acos(-1.0);
    double frequency = readPositiveNumber("Enter frequency (Hz): ");
    double capacitanceMicro = readPositiveNumber("Enter capacitance (microfarad, uF): ");
    double capacitance = capacitanceMicro * 1e-6;
    double result = 1.0 / (2.0 * pi * frequency * capacitance);
    std::cout << "Capacitive Reactance = " << result << " ohm\n";
    records.emplace_back(nextId++, "CapacitiveReactance", frequency, capacitanceMicro, result, "ohm");
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Calculates inductive reactance and stores the result.
void calculateInductiveReactance(std::vector<CircuitRecord>& records, int& nextId) 
{
    const double pi = std::acos(-1.0);
    double frequency = readPositiveNumber("Enter frequency (Hz): ");
    double inductanceMilli = readPositiveNumber("Enter inductance (millihenry, mH): ");
    double inductance = inductanceMilli * 1e-3;
    double result = 2.0 * pi * frequency * inductance;
    std::cout << "Inductive Reactance = " << result << " ohm\n";
    records.emplace_back(nextId++, "InductiveReactance", frequency, inductanceMilli, result, "ohm");
}
