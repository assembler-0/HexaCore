#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../include/exprtk.hpp"

using namespace std;

// Function to evaluate the mathematical expression for a given x
double evaluateExpression(const std::string& expressionStr, double x) {
    exprtk::symbol_table<double> symbol_table;
    symbol_table.add_variable("x", x);

    exprtk::expression<double> expression;
    expression.register_symbol_table(symbol_table);

    exprtk::parser<double> parser;
    if (!parser.compile(expressionStr, expression)) {
        cerr << "Error parsing expression: " << parser.error() << endl;
        return NAN;
    }

    return expression.value();
}

// Function to plot the graph in ASCII
void plotGraph(const string& expressionStr, int width, int height) {
    vector<string> canvas(height, string(width, ' '));

    const double xMin = -10.0, xMax = 10.0; // Range of x
    const double yMin = -1.5, yMax = 1.5;   // Range of y

    const double xStep = (xMax - xMin) / width;
    const double yStep = (yMax - yMin) / height;

    // Draw axes
    int xAxis = height / 2;
    int yAxis = width / 2;
    for (int x = 0; x < width; ++x) canvas[xAxis][x] = '-';
    for (int y = 0; y < height; ++y) canvas[y][yAxis] = '|';
    canvas[xAxis][yAxis] = '+'; // Origin

    // Plot points
    for (double x = xMin; x <= xMax; x += xStep) {
        double y = evaluateExpression(expressionStr, x);
        if (!std::isnan(y)) {
            int plotX = static_cast<int>((x - xMin) * (width - 1) / (xMax - xMin));
            int plotY = static_cast<int>((yMax - y) * (height - 1) / (yMax - yMin));
            if (plotX >= 0 && plotX < width && plotY >= 0 && plotY < height) {
                canvas[plotY][plotX] = '*';
            }
        }
    }

    // Print the canvas
    for (const auto& row : canvas) {
        cout << row << endl;
    }
}

int main() {
    cout << "Enter the function you want to graph (e.g., x^2 - 2): ";
    string expressionStr;
    getline(cin, expressionStr);

    const int width = 85;  // Width of the graph (number of columns)
    const int height = 30; // Height of the graph (number of rows)

    plotGraph(expressionStr, width, height);

    return 0;
}
