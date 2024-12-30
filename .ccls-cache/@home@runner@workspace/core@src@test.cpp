#include <iostream>
#include <vector>
#include "../headers/CLI11.hpp"
#include <termios.h>
#include <unistd.h>
// Function to get a single key press (including arrow keys)
char getKeyPress() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void handleArrowKey(std::vector<std::string>& menuItems, int& currentSelection) {
    // Handle arrow key input
    while (true) {
        char ch = getKeyPress();
        if (ch == 27) {  // Arrow key escape sequence
            char arrow = getKeyPress();  // Skip the '['
            char direction = getKeyPress(); // Get the direction
            if (direction == 'A') {  // Up arrow
                currentSelection = (currentSelection - 1 + menuItems.size()) % menuItems.size();
            } else if (direction == 'B') {  // Down arrow
                currentSelection = (currentSelection + 1) % menuItems.size();
            }
            break;
        }
    }
}

void displayMenu(const std::vector<std::string>& menuItems, int currentSelection) {
    std::cout << "\033[2J\033[1;1H";  // Clear screen and move cursor to top
    for (int i = 0; i < menuItems.size(); ++i) {
        if (i == currentSelection) {
            std::cout << "> " << menuItems[i] << " <\n";  // Highlight current selection
        } else {
            std::cout << "  " << menuItems[i] << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    CLI11::App app{"Interactive menu with arrow key navigation"};

    // Define command line options with CLI11
    std::string inputOption;
    app.add_option("-i,--input", inputOption, "Input file");

    // Parse command line arguments
    CLI11_PARSE(app, argc, argv);

    std::vector<std::string> menuItems = {"Option 1", "Option 2", "Option 3", "Exit"};
    int currentSelection = 0;

    while (true) {
        displayMenu(menuItems, currentSelection);
        handleArrowKey(menuItems, currentSelection);

        if (menuItems[currentSelection] == "Exit") {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
    }

    return 0;
}
