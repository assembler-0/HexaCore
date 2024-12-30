#include "../headers/CLI11.hpp"
#include "../headers/exprtk.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
typedef double db;
using namespace std;
string file_display_menu ("extras/menu.txt");
void displayFileContent(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
int main(int argc, char *argv[]) {
  cout << "HexaCore " << version << endl;
  displayFileContent(file_display_menu);
  return 0;
}