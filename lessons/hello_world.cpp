#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();

    noecho();

    // print a string(const char*) to a window
    printw("Hello World!");

    // refreshes the screen to match in memory
    refresh();

    // whaits for user input, returns int value of that key
    int ch = getch();

    printw("%d\n", ch);
    getch();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}
