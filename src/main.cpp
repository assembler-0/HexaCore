#include "../include/CLI11.hpp"
#include "../include/exprtk.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
typedef double db;
using namespace std;
int main() {
    // Define a string to hold the mathematical expression
    string expression = "2 * (3 + 5)";

    exprtk::parser<double> parser;

    // Define the expression object
    exprtk::expression<double> expr;

    // Compile the expression from the string
    parser.compile(expression, expr);

    // Evaluate the expression
    double result = expr.value();

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
 