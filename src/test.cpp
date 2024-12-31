#include <ncurses.h>

int main() {
    initscr();            // Initialize the ncurses screen
    printw("Hello, ncurses!"); // Print a message
    refresh();            // Refresh the screen to show the message
    getch();              // Wait for a key press
    endwin();             // End ncurses mode
    return 0;
}
