#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();
    cbreak(); // реагирует на ctrl + c
    // raw(); // не реагирует на ctrl + c
    noecho();

    if (!has_colors())
    {
        printw("Terminal doesn't support colors");
        getch();
        return -1;
    }
    start_color();

    // COLOR_PAIR(n)
    // COLOR_BLACK   0
    // COLOR_RED     1
    // COLOR_GREEN   2
    // COLOR_YELLOW  3
    // COLOR_BLUE    4
    // COLOR_MAGENTA 5
    // COLOR_CYAN    6
    // COLOR_WHITE   7

    init_pair(1, COLOR_CYAN, COLOR_WHITE);

    init_pair(2, COLOR_YELLOW, COLOR_MAGENTA);

    // if (can_change_color())
    // {
    //     printw("can change color");
    //     init_color(COLOR_CYAN, 5, 5, 255);
    // }

    // A_NORMAL
    // A_STANDOUT
    // A_REVERSE
    // A_BLINK
    // A_DIM
    // A_BOLD
    // A_PROTECT
    // A_INVIS
    // A_ALTCHARSET
    // A_CHARTEXT

    attron(COLOR_PAIR(2));
    printw("This is some text");
    attroff(COLOR_PAIR(2));

    getch();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}