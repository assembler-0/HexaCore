#include "../include/CLI11.hpp"
#include "../include/exprtk.hpp"
#include "../include/termcolor.hpp"
#include <iomanip>
#include <cmath>            //headers, includes
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using namespace termcolor;
string version ("alpha 0.1"); //version
string expression;
char mode;
double exprtk_cbrt(double x){
    return cbrt(x);
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
    cout << bold << bright_green << setw(3) << "exp()" << setw(25) << "floor()" << setw(27) << "abs()\n" << reset;
    cout << bold << bright_green << setw(3) << "log()" << setw(25) << "ceil()" << setw(27) << "min()\n" << reset;
    cout << bright_green <<"#NOTE: if you want to calculate normal expression, just type like: 5+4*8-sin(90)+pow(2,3)\n" << reset;
    exprtk::symbol_table<double> symbol_table; 
    symbol_table.add_function("cbrt", exprtk_cbrt);
    cout << bold << bright_blue << "Pleases enter operation you want to perform: " << reset;
    cin >> expression;
    exprtk::expression<double> expr;
    expr.register_symbol_table(symbol_table);
    exprtk::parser<double> parser;
    if (!parser.compile(expression, expr)) {
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
    return;
}
int main(int argc, char** argv) {
    cout << setw(23) <<red << bold << underline << "HexaCore " << version << reset << '\n';
    cout << bright_blue << bold << "Please choose mode SCIENTIFIC [s] EXTRA [e] GRAPHING [g]: " << reset;
    cin >> mode;
    switch(mode){
        case('s'): scientific();
        case('e'): extra(); //modes
        case('g'): graph();
        default: cout << "invalid\n"; break;
    }
    return 0; 
}
 