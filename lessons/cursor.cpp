#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();

    int x = 10;
    int y = 10;

    // moves the cursor to the specified location
    move(y, x);

    noecho();

    // print a string(const char*) to a window
    printw("Cursor!");

    // whaits for user input, returns int value of that key
    int ch = getch();
    // clears the screen
    clear();

    mvprintw(0, 0, "%d", ch);
    refresh();

    getch();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}
