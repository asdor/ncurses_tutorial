#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();

    WINDOW* win = newwin(10, 30, 0, 0);
    box(win, 0, 0);
    refresh();

    wrefresh(win);

    wgetch(win);

    getch();
    endwin();
    return 0;
}
