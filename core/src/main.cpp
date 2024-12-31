#include "../headers/CLI11.hpp"
#include "../headers/exprtk.hpp"
#include "../headers/tabulate.hpp"
#include "../headers/table.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
typedef double db;
using namespace std;
using namespace tabulate;

int main() {
    Table table;

    // Add header
    table.add_row({"Name", "Age", "Occupation"});

    // Add rows
    table.add_row({"Alice", "25", "Engineer"});
    table.add_row({"Bob", "30", "Doctor"});
    table.add_row({"Charlie", "35", "Teacher"});

    // Format table
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align(FontAlign::center);

    std::cout << table << std::endl;
    return 0;
}
