#include "RecordManager.hpp"
#include "Input.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Displays all saved calculation records in a readable table.
void viewRecords(const std::vector<CircuitRecord>& records) 
{
    if (records.empty()) 
    { 
        std::cout << "No records available.\n"; 
        return;
    }
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nID | Calculation | Input 1 | Input 2 | Result | Unit\n";
    for (const auto& r : records)
        std::cout << r.getId() << " | " << r.getType() << " | " << r.getInput1() << " | " << r.getInput2() << " | " << r.getResult() << " | " << r.getUnit() << '\n';
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Searches and displays a record by its ID.
void searchRecord(const std::vector<CircuitRecord>& records) 
{
    int id = readInteger("Enter record ID to search: ");
    for (const auto& r : records) if (r.getId() == id) 
    {
        std::cout << "Found: ID " << r.getId() << ", " << r.getType() << ", result " << r.getResult() << " " << r.getUnit() << '\n'; 
        return;
    }
    std::cout << "Record not found.\n";
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Updates only the result value of a selected record.
void updateRecord(std::vector<CircuitRecord>& records) 
{
    int id = readInteger("Enter record ID to update: ");
    for (auto& r : records) if (r.getId() == id)
    {
        double newValue = readPositiveNumber("Enter replacement result value: ");
        r.setResult(newValue);
        std::cout << "Result updated. Original inputs and calculation type remain unchanged.\n"; 
        return;
    }
    std::cout << "Record not found.\n";
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose: Removes a selected record from the record list.
void deleteRecord(std::vector<CircuitRecord>& records) 
{
    int id = readInteger("Enter record ID to delete: ");
    auto it = std::find_if(records.begin(), records.end(), [id](const CircuitRecord& r)
    { 
        return r.getId() == id; 
    });
    if (it == records.end()) 
    { 
        std::cout << "Record not found.\n"; 
        return; 
    }
    records.erase(it);
    std::cout << "Record deleted.\n";
}

// Programmer's Name: LIM XIN EN | 26104879
// Purpose：Sorts calculation records in ascending order by result value.
void sortRecords(std::vector<CircuitRecord>& records)
{
    int choice;

    std::cout << "\nSort Records By Result:\n";
    std::cout << "1. Ascending\n";
    std::cout << "2. Descending\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1)
    {
        std::sort(records.begin(), records.end(),
            [](const CircuitRecord& a, const CircuitRecord& b)
            {
                return a.getResult() < b.getResult();
            });

        std::cout << "\nRecords sorted by result (ascending).\n";
    }
    else if (choice == 2)
    {
        std::sort(records.begin(), records.end(),
            [](const CircuitRecord& a, const CircuitRecord& b)
            {
                return a.getResult() > b.getResult();
            });

        std::cout << "\nRecords sorted by result (descending).\n";
    }
    else
    {
        std::cout << "\nInvalid choice. Please select 1 or 2.\n";
        return;
    }

    viewRecords(records);
}
