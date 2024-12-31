#include "../include/termbox.h"  // Include the header file

int main() {
    tb_init();  // Initialize termbox
    tb_change_cell(0, 0, 'H', TB_WHITE, TB_BLUE);  // Change a cell
    tb_change_cell(1, 0, 'e', TB_WHITE, TB_BLUE);
    tb_change_cell(2, 0, 'l', TB_WHITE, TB_BLUE);
    tb_change_cell(3, 0, 'l', TB_WHITE, TB_BLUE);
    tb_change_cell(4, 0, 'o', TB_WHITE, TB_BLUE);
    tb_present();  // Present the changes on screen
    tb_wait_event(NULL);  // Wait for an event (e.g., key press)
    tb_shutdown();  // Shutdown termbox
    return 0;
}
