#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();
    noecho();
    cbreak();

    int y_max = 0;
    int x_max = 0;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW* input_win = newwin(3, x_max - 12, y_max - 5, 5);
    box(input_win, 0, 0);
    refresh();
    wrefresh(input_win);

    keypad(input_win, true);

    int c = wgetch(input_win);
    if (c == KEY_UP)
    {
        mvwprintw(input_win, 1, 1, "You pressed up!");
        wrefresh(input_win);
    }

    getch();
    endwin();
    return 0;
}
