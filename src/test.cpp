#include <iostream>
#include "../include/exprtk.hpp"    

// Numerical integration using the Trapezoidal Rule
double integrate_trapezoidal(exprtk::expression<double>& expression, double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = 0.0;

    exprtk::symbol_table<double> symbol_table = expression.get_symbol_table();
    double& x = symbol_table.get_variable("x"); // Access the variable `x`

    // Evaluate the function at the boundaries
    x = a;
    sum += expression.value(); // f(a)
    x = b;
    sum += expression.value(); // f(b)

    // Evaluate the function at interior points
    for (int i = 1; i < n; ++i) {
        x = a + i * h;
        sum += 2.0 * expression.value(); // 2 * f(midpoints)
    }

    return (h / 2.0) * sum; // Final integration result
}

int main() {
    // Define the function to integrate
    std::string function_str = "x^2"; // Example: f(x) = x^2

    // Create the symbol table and register variable
    exprtk::symbol_table<double> symbol_table;
    double x; // The variable for the function
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    // Register the symbol table with the expression
    exprtk::expression<double> expression;
    expression.register_symbol_table(symbol_table);

    // Parse the function string
    exprtk::parser<double> parser;
    if (!parser.compile(function_str, expression)) {
        std::cerr << "Error: " << parser.error() << std::endl;
        return 1;
    }

    // Integration parameters
    double a = 0.0; // Lower limit
    double b = 1.0; // Upper limit
    int n = 100;    // Number of intervals

    // Perform the integration
    double result = integrate_trapezoidal(expression, a, b, n);

    // Print the result
    std::cout << "The integral of " << function_str << " from " << a << " to " << b
              << " is approximately " << result << std::endl;

    return 0;
}
