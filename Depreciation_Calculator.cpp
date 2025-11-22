#include <iostream>
#include <print>
#include <string>
#include <cmath>

const int kMaxSize{50};
int Print_Menu();
void Get_Info(std::string &asset, double &cost, double &salvage, int &life);
void Units_of_Production(int &total_units, int units[], int life);
void print_outline(std::string asset, double cost, double salvage);
void print_straightline(double straight_line, int life, double cost);
void Declining_Balance(double expense[], double accumulated[], double cost, double salvage, int life);
void Print_Declining(double expense[], double accumulated[], double cost, int life);

int main(){

    std::println("\n------------ Welcome to the Depreciation Calculator! ------------");
    std::println("You can calculate the depreciation of your plant assets over time\n");
    // prompt the user for cost, estimated salvage value, and estimated useful life
    
    Menu:
    int choice = Print_Menu();
    
    std::string asset;
    double cost{};
    double salvage{};
    int life{};

    if (choice == 4){
        std::println("Thank you for using the Depreciation Calculator, Bye!!!");
        return 0;
    }
    
    Get_Info(asset, cost, salvage, life); // gather info for calculations
    
    if (choice == 1){
     double straight_line = static_cast<double>(cost - salvage) * (1.0 / life); // calculate straight line depreciation and
     // output a timeline for over the years
     print_outline(asset, cost, salvage);
     print_straightline(straight_line, life, cost);
    }

    int total_units; // store in variables
    int units[kMaxSize];
    if (choice == 2){
    print_outline(asset, cost, salvage);
    Units_of_Production(total_units, units, life);
    // Print_Production();
    }
    
    
    int size = std::ceil(life); // create size for other arrays
    double accumulated[size]{};
    double expense[size]{};
    
    if (choice == 3){
    print_outline(asset, cost, salvage);
    Declining_Balance(expense, accumulated, cost, salvage, life); // calculate double declining balance and
    Print_Declining(expense, accumulated, cost, life); // output a timeline for over the years
    }

    // calculate units of production depreciation
    // output a timeline showcasing it

    goto Menu;
}

void Units_of_Production(int &total_units, int units[], int life){
   
    std::print("How many units can this asset produce over its lifetime?: "); // prompt for units of production throughout the years
    std::cin >> total_units;
    for(int i{1}; i <= life; ++i){
        std::print("How many units produced during year {}?: ", i);
        std::cin >> units[i];
    }
    return;
}

void print_outline(std::string asset, double cost, double salvage){
    static int count{};
    if (count == 1){
        return;
    }
    ++count;

    std::println("Asset: {}", asset);
    std::println("Original Cost: ${}", cost);
    std::println("Depreciable Cost: ${:.2f}\n", cost - salvage);
    std::println("  Year  |  Depreciation Expense |  Accumulated Depreciation |  Book Value");
    std::println("-------------------------------------------------------------------------");
    return;
}

void Get_Info(std::string &asset, double &cost, double &salvage, int &life){
        static int count{};
    if (count == 1){
        return;
    }
    ++count;

    std::string answer;
    
    std::print("What is the name of this asset?: ");
    std::getline(std::cin, asset);
    
    std::print("What is the total cost of the asset?: $");
    std::cin >> cost;
    
    std::println("What is the estimated salvage value?:");
    
    std::print("(For a defintion of salvage value, type yes): $");
    std::cin >> answer;
    
    if ( answer == "yes" || answer == "Yes" ){
        std::println("\nSalvage Value: Estimated value of an asset when it is expected to be disposed (done being used)");
        std::print("What is the estimated salvage value?: $");
        std::cin >> salvage;
    } else { 
        salvage = std::stod(answer);
    }
    answer.clear();
    
    
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
    std::println();
    
    return;
}

void print_straightline(double straight_line, int life, double cost){
    for (int i{1}; i <= life; ++i){
        std::println("  {:^4}  |  ${:>18.2f}  |  ${:>22.2f}  |  ${:>9.2f}", i, straight_line, straight_line * i, cost - (straight_line * i));
        std::println("-------------------------------------------------------------------------");
    }
    return;
}

void Declining_Balance(double expense[], double accumulated[], double cost, double salvage, int life){
    double rate = ( 1 / static_cast<double>(life)) * 2;
    double accumulation{};
    
    for (int i{}; i < life; ++i){// for each year
        expense[i] = (cost - accumulation) * rate; // calculate expense for that year and store in array
        accumulation += expense[i]; // add to accumulation and store in array
        if ( (cost - accumulation) < salvage ){
            accumulated[i] = cost - salvage;
            expense[i] = accumulation - salvage;
        } else {
            accumulated[i] = accumulation;
        }
    }

    return;
}

void Print_Declining(double expense[], double accumulated[], double cost, int life){
    for (int i{1}; i < life; ++i){
        std::println("  {:^4}  |  ${:>18.2f}  |  ${:>22.2f}  |  ${:>9.2f}", i, expense[i], accumulated[i] , cost - accumulated[i]);
        std::println("-------------------------------------------------------------------------");
    }
    std::println("  {:^4}  |  ${:>18.2f}  |  ${:>22.2f}  |  ${:>9.2f}", life, expense[life], accumulated[life] , cost - accumulated[life]);
    std::println("-------------------------------------------------------------------------");


    return;
}

int Print_Menu(){
    std::println("Which method of depreciation would you like to use?");
    std::println("1. Straight Line Depreciation");
    std::println("2. Units of Production Method");
    std::println("3. Double-Declining Balance");
    std::println("4. Quit");
    int choice{};
    std::cin >> choice;
    std::cin.ignore();
    std::println();

    return choice;
}