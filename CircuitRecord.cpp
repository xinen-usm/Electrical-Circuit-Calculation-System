#include "CircuitRecord.hpp"

// Programmer's Name: MOHD ADAM HAIKAL BIN ROSLI | 26104652
// Purpose: Initializes a calculation record.
CircuitRecord::CircuitRecord(int recordId, const std::string& type, double a, double b, double value, const std::string& resultUnit) : id(recordId), calculationType(type), input1(a), input2(b), result(value), unit(resultUnit) {}

// Programmer's Name: MOHD ADAM HAIKAL BIN ROSLI | 26104652
// Purpose: Returns record ID.
int CircuitRecord::getId() const 
{ 
    return id; 
}

// Programmer's Name: MOHD ADAM HAIKAL BIN ROSLI | 26104652
// Purpose: Returns calculation name.
std::string CircuitRecord::getType() const 
{
    return calculationType; 
}

// Programmer's Name: MOHD ADAM HAIKAL BIN ROSLI | 26104652
// Purpose: Returns first input value.
double CircuitRecord::getInput1() const
{ 
    return input1; 
}

// Programmer's Name: MOHD ADAM HAIKAL BIN ROSLI | 26104652
// Purpose: Returns second input value.
double CircuitRecord::getInput2() const 
{ 
    return input2; 
}

// Programmer's Name: MOHAMMAD HAZMER FARIHIN BIN MOHD MAJID | 26103651
// Purpose: Returns calculated result.
double CircuitRecord::getResult() const 
{ 
    return result; 
}

// Programmer's Name: MOHAMMAD HAZMER FARIHIN BIN MOHD MAJID | 26103651
// Purpose: Returns result unit.
std::string CircuitRecord::getUnit() const 
{ 
    return unit; 
}

// Programmer's Name: MOHAMMAD HAZMER FARIHIN BIN MOHD MAJID | 26103651
// Purpose: Updates stored calculation result.
void CircuitRecord::setResult(double value) 
{ 
    result = value; 
}
