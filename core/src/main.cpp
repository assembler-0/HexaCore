#include "../headers/CLI11.hpp"
#include "../headers/exprtk.hpp"
#include "../headers/tabulate.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
typedef double db;
using namespace std;
int main() {
    tabulate::Table table;

    table.add_row({"Name", "Age", "Occupation"});
    table.add_row({"Alice", "25", "Engineer"});
    table.add_row({"Bob", "30", "Doctor"});
    table.add_row({"Charlie", "35", "Teacher"});

    std::cout << table << std::endl;
    return 0;
}
