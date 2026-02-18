# Depreciation_Calculator
A project that will prompt the user for some basic information about a plant asset and then calculate the depreciation schedules for different methods of depreciation.

## Features
- Prompts the user for asset cost, salvage value, useful life, and usage (when applicable)
- Supports multiple depreciation methods:
  - Straight-Line
  - Double-Declining Balance
  - Units of Production
- Outputs depreciation schedules in a formatted table

## Example Usage
### Inputs
Choice: 3  
Asset: Computing Equipment  
Asset Cost: 650000  
Salvage Value: 25000  
Useful Life (years): 6  
<img width="537" height="495" alt="image" src="https://github.com/user-attachments/assets/89c8a7f6-a0d8-4e9b-98d9-68afac87e9ca" />
### Same run, additional inputs
Choice: 2  
Total Units: 100000  
Years in Use: 4  
Year 1: 22000  
Year 2: 13000  
Year 3: 37800  
Year 4: 27500  
<img width="552" height="380" alt="image" src="https://github.com/user-attachments/assets/67e864d4-c934-4be2-94ac-7c98b873bceb" />

 


## Future Improvements
- Handle invalid inputs from the user
- Receive input from a file and output results to another file
- Give a recommendation as for which accounting method the user should choose based on questions asked to the user

## What I learned
- Implementing user-driven control flow
- Using arrays and parallel arrays to store structured data
- Formatting output using std::format and C++23 print functions

## How to Run
Requires a C++23 compatible compiler  
Compile and run using any C++ compiler:  
```bash
g++ -std=c++23 Depreciation_Calculator.cpp -o Depreciation  
./Depreciation
```
