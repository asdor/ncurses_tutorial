#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();
    cbreak();
    noecho();

    int y;
    int x;
    int y_beg;
    int x_beg;
    int y_max;
    int x_max;

    WINDOW* win = newwin(10, 20, 10, 10);

    getyx(stdscr, y, x);
    getbegyx(win, y_beg, x_beg);
    getmaxyx(stdscr, y_max, x_max);

    mvprintw(y_max / 2, x_max / 2, "%d %d", y_beg, x_beg);

    getch();
    endwin();
    return 0;
}
