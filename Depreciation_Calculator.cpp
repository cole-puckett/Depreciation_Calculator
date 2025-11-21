#include <iostream>
#include <print>
#include <string>
#include <cmath>

const int kMaxSize{50};
void Get_Info(std::string &asset, double &cost, double &salvage, std::string &answer, double &life);
void Units_of_Production(int &, int units[], double);
void print_outline(double life);
void print_straightline( double , double);
void Declining_Balance(double expense[], double accumulated[], double cost, double salvage, double life);
void Print_Declining(double expense[], double accumulated[], double cost, double life);

int main(){

    std::println("\n------------ Welcome to the Depreciation Calculator! ------------");
    std::println("You can calculate the depreciation of your plant assets over time\n");
    // prompt the user for cost, estimated salvage value, and estimated useful life
    std::string asset;
    double cost{};
    double salvage{};
    std::string answer;
    double life{};

    Get_Info(asset, cost, salvage, answer, life);

    int total_units; // store in variables
    int units[kMaxSize];
    
     std::print("Would you like to estimate using the units of production method as well?: "); // ask if user would like to estimate units of production depreciation method as well
        std::cin >> answer;
    
        if (answer == "yes" || answer == "Yes"){
            Units_of_Production(total_units, units, life);
        }

   
    double straight_line = static_cast<double>(cost - salvage) * (1 / life); // calculate straight line depreciation and
    // output a timeline for over the years
    print_outline(life);
    print_straightline(straight_line, life);
    std::println("\n\n Depreciable Cost: {}\n", cost - salvage);

    int size = std::ceil(life);

    double accumulated[size]{};
    double expense[size]{};
    Declining_Balance(expense, accumulated, cost, salvage, life); // calculate double declining balance and
    Print_Declining(expense, accumulated, cost, life); // output a timeline for over the years

    // calculate units of production depreciation
    // output a timeline showcasing it


    return 0;
}

void Units_of_Production(int &total_units, int units[], double life){
   
    std::print("How many units can this asset produce over its lifetime?: "); // prompt for units of production throughout the years
    std::cin >> total_units;
    for(int i{1}; i <= life; ++i){
        std::print("How many units produced during year {}?: ", i);
        std::cin >> units[i];
    }
    return;
}

void print_outline(double life){
    for (int i{1}; i <= life; ++i){
        std::print("    Year {:3}    \t", i);
    }
    std::println();

    for (int i{1}; i <= life; ++i){
        std::print("--------------- \t");
    }
    std::println();

    return;
}

void Get_Info(std::string &asset, double &cost, double &salvage, std::string &answer, double &life){
    std::print("What is the name of this asset?: ");
    std::getline(std::cin, asset);

    std::print("What is the total cost of the asset?: $");
    std::cin >> cost;

    std::println("What is the estimated salvage value?:");
    
    std::print("(For a defintion of salvage value, type yes): $ ");
    std::cin >> answer;
    
    if ( answer == "yes" || answer == "Yes" ){
        std::println("\nSalvage Value: Estimated value of an asset when it is expected to be disposed (done being used)");
        std::print("What is the estimated salvage value?: $");
        std::cin >> salvage;
    } else { 
        salvage = std::stod(answer);
    }


    std::println("What is the estimated useful life? (in years):");
    std::print("(For a definition of useful life, type yes): ");
    std::cin >> answer;
    
    if ( answer == "yes" || answer == "Yes" ){
        std::println("\nUseful Life: Length of time an asset is planned to be used");
        std::print("What is the estimated useful life? (in years): ");
        std::cin >> life;
    } else {
        life = std::stoi(answer);
    }
    return;
}

void print_straightline(double straight_line, double life){
    for (int i{1}; i <= life; ++i){
        std::print("${:^21.2f}", straight_line);
    }
    return;
}

void Declining_Balance( double expense[], double accumulated[], double cost, double salvage, double life){
    double rate = ( 1 / life ) * 2;
    double accumulation{};
    
    
    for (int i{}; i < life; ++i){// for each year
        expense[i] = (cost - accumulation) * rate; // calculate expense for that year and store in array
        accumulation += expense[i]; // add to accumulation and store in array
        if ( (cost - accumulation) < salvage ){
            accumulated[i] = accumulation - salvage;
        } else {
            accumulated[i] = accumulation;
        }
    }
    


    return;
}

void Print_Declining(double expense[], double accumulated[], double cost, double life){
    std::println("Original Cost: {}", cost);
    for(int i{}; i < life; ++i){
        std::println("Expense {}: {:.2f}, Accumulation: {:.2f}", i, expense[i], accumulated[i]);
    }

    return;
}