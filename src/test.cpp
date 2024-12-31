#include <iostream>
#include "../include/termcolor.hpp"

int main() {
    // Foreground colors
 
    std::cout << termcolor::red << "Red Text" << termcolor::reset << std::endl;
    std::cout << termcolor::green << "Green Text" << termcolor::reset << std::endl;
    std::cout << termcolor::yellow << "Yellow Text" << termcolor::reset << std::endl;
    std::cout << termcolor::blue << "Blue Text" << termcolor::reset << std::endl;
    std::cout << termcolor::magenta << "Magenta Text" << termcolor::reset << std::endl;
    std::cout << termcolor::cyan << "Cyan Text" << termcolor::reset << std::endl;
    std::cout << termcolor::white << "White Text" << termcolor::reset << std::endl;

    // Bright foreground colors
    std::cout << termcolor::bright_red << "Bright Red Text" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_green << "Bright Green Text" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_yellow << "Bright Yellow Text" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_blue << "Bright Blue Text" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_magenta << "Bright Magenta Text" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_cyan << "Bright Cyan Text" << termcolor::reset << std::endl;
    std::cout << termcolor::bright_white << "Bright White Text" << termcolor::reset << std::endl;

    // Background colors
   
    std::cout << termcolor::on_red << "Text on Red Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_green << "Text on Green Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_yellow << "Text on Yellow Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_blue << "Text on Blue Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_magenta << "Text on Magenta Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_cyan << "Text on Cyan Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_white << "Text on White Background" << termcolor::reset << std::endl;

    // Bright background colors
  
    std::cout << termcolor::on_bright_red << "Text on Bright Red Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_bright_green << "Text on Bright Green Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_bright_yellow << "Text on Bright Yellow Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_bright_blue << "Text on Bright Blue Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_bright_magenta << "Text on Bright Magenta Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_bright_cyan << "Text on Bright Cyan Background" << termcolor::reset << std::endl;
    std::cout << termcolor::on_bright_white << "Text on Bright White Background" << termcolor::reset << std::endl;

    // Modifiers
    std::cout << termcolor::bold << "Bold Text" << termcolor::reset << std::endl;
    std::cout << termcolor::underline << "Underlined Text" << termcolor::reset << std::endl;
    std::cout << termcolor::reverse << "Reversed Colors" << termcolor::reset << std::endl;

    return 0;
}
