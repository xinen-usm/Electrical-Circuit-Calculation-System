/* Mini Project: Electrical Circuit Calculation System
 Purpose: Develop a system that allows users to perform circuit calculations, store and manage calculation records, and retrieve previous results for future reference.
 Project Assumptions:
 1. The system performs six basic electrical calculations only.
 2. All electrical input values must be greater than zero.
 3. Capacitance is entered in microfarads (uF).
 4. Inductance is entered in millihenry (mH).
 5. Calculations are based on standard formulas for ideal components.
 6. Updating a record changes only its calculated result.
 7. Records can be sorted in ascending or descending order by calculated result.
 8.Records are stored in a local text file.
 9.The system uses a command-line interface without a GUI.
 Programmer's Name:
 1. TAN ISSEY                              | 26103162
 2. LIM XIN EN                             | 26104879
 3. MOHAMMAD HAZMER FARIHIN BIN MOHD MAJID | 26103651
 4. MOHD ADAM HAIKAL BIN ROSLI             | 26104652
*/
#include "Calculation.hpp"
#include "RecordManager.hpp"
#include "FileManager.hpp"
#include "Input.hpp"
#include <iostream>
#include <vector>
#include <string>
void displayMenu();

// Programmer's Name: TAN ISSEY | 26103162
// Purpose: Runs the main menu loop and dispatches user choices to functions.
int main(int argc, char* argv[]) 
{
    std::string filename = (argc > 1) ? argv[1] : "data/circuit_records.txt";
    std::vector<CircuitRecord> records;
    int nextId = 1;
    int choice;
    do {
        displayMenu();
        choice = readInteger("Enter your choice: ");
        switch (choice) 
        {
            case 1: calculateVoltage(records, nextId); 
            break;
            case 2: calculateCurrent(records, nextId); 
            break;
            case 3: calculateResistance(records, nextId); 
            break;
            case 4: calculatePower(records, nextId); 
            break;
            case 5: calculateCapacitiveReactance(records, nextId); 
            break;
            case 6: calculateInductiveReactance(records, nextId); 
            break;
            case 7: viewRecords(records); 
            break;
            case 8: searchRecord(records); 
            break;
            case 9: updateRecord(records); 
            break;
            case 10: deleteRecord(records); 
            break;
            case 11: sortRecords(records); 
            break;
            case 12: 
            {
                int fileChoice = readInteger("1. Save records\n2. Load records\nChoose: ");
                if (fileChoice == 1) 
                saveRecords(records, filename);
                else if (fileChoice == 2) 
                loadRecords(records, nextId, filename);
                else 
                std::cout << "Invalid file option.\n";
                break;
            }
            case 0:
            
std::cout << "Exiting program. Goodbye!\n"; 
            break;
            default: std::cout << "Invalid menu choice. Please choose 0-13.\n";
        }
    } while (choice != 0);
    return 0;
}
