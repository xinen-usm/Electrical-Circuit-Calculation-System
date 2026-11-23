#ifndef CIRCUIT_RECORD_HPP
#define CIRCUIT_RECORD_HPP
#include <string>

// Programmer's Name: MOHD ADAM HAIKAL BIN ROSLI | 26104652
// Purpose: Stores the details of one electrical calculation record.
class CircuitRecord 
{
private:
    int id;
    std::string calculationType;
    double input1, input2, result;
    std::string unit;
public:
    CircuitRecord(int recordId, const std::string& type, double a, double b, double value, const std::string& resultUnit);
    int getId() const;
    std::string getType() const;
    double getInput1() const;
    double getInput2() const;
    double getResult() const;
    std::string getUnit() const;
    void setResult(double value);
};

#endif
