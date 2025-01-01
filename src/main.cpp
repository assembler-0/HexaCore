#include "../include/CLI11.hpp"
#include "../include/exprtk.hpp"
#include "../include/termcolor.hpp"
#include <iomanip>
#include <cmath>            //headers, includes
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using namespace termcolor;
string version ("alpha 0.1"); //version
string expressionStr;
signed int precision;
double maxY, minY;
char mode;
double exprtk_cbrt(double x){
    return cbrt(x);
}
double evaluateExpression_graph(const std::string& expressionStr, double x) {
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
void cMaxMin(const string& expressionStr, double xMin, double xMax, double& maxY, double& minY) {
    const double step = 0.01; // Small step for accurate results
    maxY = -INFINITY;
    minY = INFINITY;

    for (double x = xMin; x <= xMax; x += step) {
        double y = evaluateExpression_graph(expressionStr, x);
        if (!std::isnan(y)) {
            if (y > maxY) maxY = y;
            if (y < minY) minY = y;
        }
    }
}

void plotGraph(const string& expressionStr, int width, int height) {
    vector<string> canvas(height, string(width, ' '));

    const double xMin = -10.0, xMax = 10.0; // Range of x
    const double yMin = -1.5, yMax = 1.5;   // Range of y

    const double xStep = (xMax - xMin) / (width*precision);
    const double yStep = (yMax - yMin) / (height*precision);

    // Draw axes
    int xAxis = height / 2;
    int yAxis = width / 2;
    for (int x = 0; x < width; ++x) canvas[xAxis][x] = '-';
    for (int y = 0; y < height; ++y) canvas[y][yAxis] = '|';
    canvas[xAxis][yAxis] = '+'; // Origin

    // Plot points
    for (double x = xMin; x <= xMax; x += xStep) {
        double y = evaluateExpression_graph(expressionStr, x);
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
        cout << bold << bright_green << row << endl << reset;
    }
}
void scientific(void){
    cout << bold << bright_green << string(55, '-') << reset << '\n'; 
    cout<< setw(0) <<bold << bright_green << "Trigonometric" << reset
        << setw(14) << bold << bright_green << "Hyperbolic" << reset
        << setw(21) << bold << bright_green << "Power" << reset << '\n';
    cout << bold << bright_green << string(55, '-') << reset << '\n';
    cout << setw(3) << bold << bright_green << "cos()"<< setw(25) << "cosh" << setw(26) << "pow()\n" << reset;
    cout << setw(3) << bold << bright_green << "sin()"<< setw(25) << "sinh" << setw(26) <<"sqrt()\n" << reset;
    cout << setw(3) << bold << bright_green << "tan()"<< setw(25) << "tanh" << setw(26) <<"cbrt()\n" << reset;
    cout << setw(3) << bold << bright_green << "acos()"<< setw(27) << "acosh()\n"<< reset;
    cout << setw(3) << bold << bright_green << "asin()" << setw(27) <<"asinh()\n"<< reset;
    cout << setw(3) << bold << bright_green << "atan()"<<setw(27)<<"atanh()\n"<< reset;
    cout << bold << bright_green << string(55, '-') << reset << '\n';
    cout<< setw(0) <<bold << bright_green << "Exp/Log" << reset
        << setw(22) << bold << bright_green << "Rounding" << reset
        << setw(20) << bold << bright_green << "Abs+Others" << reset << '\n';
    cout << bold << bright_green << string(55, '-') << reset << '\n';
    cout << bold << bright_green << setw(3) << "exp()" << setw(27) << "floor()" << setw(25) << "abs()\n" << reset;
    cout << bold << bright_green << setw(3) << "log()" << setw(26) << "ceil()" << setw(26) << "min()\n" << reset;
    cout << bold << bright_green << setw(3) << "log10()" << setw(25) << "round()" << setw(25) << "max()\n" << reset;
    cout << bold << bright_green << setw(57) << "min()\n" << reset;
    cout << bright_green <<"#NOTE: if you want to calculate normal expression, just type like: 5+4*8-sin(90)+pow(2,3)\n" << reset;
    exprtk::symbol_table<double> symbol_table; 
    symbol_table.add_function("cbrt", exprtk_cbrt);
    cout << bold << bright_blue << "Pleases enter operation you want to perform: " << reset;
    cin >> expressionStr;
    exprtk::expression<double> expr;
    expr.register_symbol_table(symbol_table);
    exprtk::parser<double> parser;
    if (!parser.compile(expressionStr, expr)) {
        std::cerr << "Error: " << parser.error() << "\n";
        return; //if cannot parse
    }
    double result = expr.value();
    cout << bold << underline << red << "Returned value: "<< result << endl << reset;
    return;
}
void extra(void){
    return;
}
void graph(void){
    cout << bold << bright_blue <<"Enter expression (x, x^2, sin(x), ...): " << reset;
    cin >> expressionStr;
    int width = 85;
    int height = 30;
    cout <<bold << bright_blue << "Enter width and height follow this format WIDTH[space]HEIGHT (85 27 recomended): " << reset;
    cin >> width >> height;
    cout << bold << bright_blue << "Please enter precision (beta, 1 for default): " << reset;
    cin >> precision;
    plotGraph(expressionStr, width, height);
    cMaxMin(expressionStr, -10.0, 10.0, maxY, minY);
    cout << bold << red << underline <<"Max Y: " << maxY << endl;
    cout << "Min Y: " << minY << endl << reset;
    return;
}
int main(int argc, char** argv) {
    cout << setw(39) <<red << bold << underline << "HexaCore " << version << reset << '\n';
    cout << bright_blue << bold << "Please choose mode SCIENTIFIC [s] EXTRA [e] GRAPHING [g]: " << reset;
    cin >> mode;
    switch(mode){
        case('s'): scientific();
        case('e'): extra(); //modes
        case('g'): graph();
        default: break;
    }
    return 0; 
}
 