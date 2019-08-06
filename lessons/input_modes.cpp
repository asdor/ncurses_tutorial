#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();
    noecho();

    // cbreak();
    // halfdelay(5);
    // nodelay(stdscr, true);
    timeout(500);


    int c = 0;
    while ((c = getch()) != 'x')
        printw("%d\n", c);

    endwin();
    return 0;
}
