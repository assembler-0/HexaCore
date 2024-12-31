#include "../include/CLI11.hpp"
#include "../include/exprtk.hpp"
#include "../include/termcolor.hpp"
#include <iomanip>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using namespace termcolor;
string version ("alpha 0.1");
string expression;
char mode1;
void scientific_compute(string op){

}
void extra_compute(string op){

}
void scientific_display(void){
    cout<< setw(0) <<bold << bright_green << "Trigonometric" << reset
        << setw(14) << bold << bright_green << "Hyperbolic" << reset
        << setw(21) << bold << bright_green << "Power" << reset << '\n';
    cout << bold << bright_green << string(55, '-') << reset << '\n';
    return;
    
}
void extra_display(void){
    
}
int main(int argc, char** argv) {
    cout << setw(23) <<red << bold << underline << "HexaCore " << version << reset << '\n';
    cout << bright_blue << bold << "Please choose mode SCIENTIFIC [s] EXTRA [e]: " << reset;
    cin >> mode1;
    switch(mode1){
        case('s'): scientific_display(); break;
        case('e'): extra_display(); break;
        default: break;
    }
    cout << "enter expression: ";
    cin >> expression;
    exprtk::expression<double> expr;
    exprtk::parser<double> parser;
    if (!parser.compile(expression, expr)) {
        std::cerr << "Error: " << parser.error() << "\n";
        return 1;
    }
    double result = expr.value();
    cout << result;
    return 0; 

}
 