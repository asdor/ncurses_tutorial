#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();

    int height = 10;
    int width = 20;
    int start_y = 10;
    int start_x = 10;

    WINDOW*  win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    // wprintw(win, "this is my box");
    mvwprintw(win, 1, 1, "this is my box");
    wrefresh(win);

    // whaits for user input, returns int value of that key
    int ch = getch();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}
