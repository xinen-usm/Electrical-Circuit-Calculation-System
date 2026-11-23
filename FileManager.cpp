#include "FileManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Programmer's Name: MOHAMMAD HAZMER FARIHIN BIN MOHD MAJID | 26103651
// Purpose: Writes all current records to a delimited text file.
void saveRecords(const std::vector<CircuitRecord>& records, const std::string& filename) 
{
    std::ofstream out(filename);
    if (!out) 
    { 
        std::cout << "Unable to open file for saving.\n"; 
        return; 
    }
    for (const auto& r : records)
        out << r.getId() << '|' << r.getType() << '|' << r.getInput1() << '|' << r.getInput2() << '|' << r.getResult() << '|' << r.getUnit() << '\n';
    std::cout << "Saved " << records.size() << " record(s) to " << filename << "\n";
}

// Programmer's Name: MOHAMMAD HAZMER FARIHIN BIN MOHD MAJID | 26103651
// Purpose: Loads records from a text file, replacing current records and setting next ID.
void loadRecords(std::vector<CircuitRecord>& records, int& nextId, const std::string& filename) 
{
    std::ifstream in(filename);
    if (!in) 
    { 
        std::cout << "File not found or cannot be opened.\n";
        return; 
    }
    std::vector<CircuitRecord> loaded;
    std::string line;
    int maxId = 0;
    while (std::getline(in, line)) 
    {
        std::stringstream ss(line);
        int id; 
        std::string type, unit; 
        double a, b, result; 
        char sep;
        if (ss >> id >> sep && sep == '|' && std::getline(ss, type, '|') && (ss >> a >> sep) && sep == '|' && (ss >> b >> sep) && sep == '|' && (ss >> result >> sep) && sep == '|' && std::getline(ss, unit)) 
        {
            loaded.emplace_back(id, type, a, b, result, unit);
            if (id > maxId) maxId = id;
        }
    }
    records = loaded;
    nextId = maxId + 1;
    std::cout << "Loaded " << records.size() << " record(s) from " << filename << "\n";
}
