#include <algorithm>
#include <string>

#include <ncurses.h>
int main()
{
    // init screen and clean it
    initscr();
    noecho();
    cbreak();

    // get screen size
    int y_max = 0;
    int x_max = 0;
    getmaxyx(stdscr, y_max, x_max);

    // create a window for input
    WINDOW* menu_win = newwin(6, x_max - 12, y_max - 8, 5);
    box(menu_win, 0, 0);
    refresh();
    wrefresh(menu_win);

    // makes it so we can use arrow keys
    keypad(menu_win, true);

    std::string choices[3] = {"Walk", "Jog", "Run"};
    int choice = 0;
    int highlight = 0;

    while (true)
    {
        for (size_t i = 0; i < 3; ++i)
        {
            if (i == highlight)
                wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i + 1, 1, choices[i].c_str());
            wattroff(menu_win, A_REVERSE);
        }
        choice = wgetch(menu_win);

        switch (choice)
        {
            case KEY_UP:
                highlight = std::max(0, highlight - 1);
                break;
            case KEY_DOWN:
                highlight = std::min(2, highlight + 1);
                break;
            default:
                break;
        }
        if (choice == 'q')
            break;
    }

    printw("Your choice was: %s", choices[highlight].c_str());

    getch();
    endwin();

    return 0;
}
