#include "../include/CLI11.hpp"
#include "../include/exprtk.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
typedef double db;
using namespace std;
using namespace CLI;
int main(int argc, char **argv) {
    CLI::App app{"A simple CLI11 example"};

    // Define command-line options and arguments
    std::string name;
    int age;
    app.add_option("-n,--name", name, "Your name")->required();
    app.add_option("-a,--age", age, "Your age");

    // Parse the command-line arguments
    CLI11_PARSE(app, argc, argv);

    // Output the parsed data
    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}
