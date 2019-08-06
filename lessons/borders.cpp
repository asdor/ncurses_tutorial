#include <ncurses.h>

int main()
{
    // init screen and clean it
    initscr();
    cbreak(); // реагирует на ctrl + c
    // raw(); // не реагирует на ctrl + c
    noecho();

    int height = 10;
    int width = 20;
    int start_y = 10;
    int start_x = 10;

    WINDOW*  win = newwin(height, width, start_y, start_x);
    refresh();

    char c = 'g';

    // box(win, left and right char, top and bottom);
    box(win, c, 104);
    int left = 103;
    int right = left;
    int top = 104;
    int bottom = ' ';
    int tlc = 'a';
    int trc = 'b';
    int blc = 'c';
    int brc = 'd';

    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);

    // wprintw(win, "this is my box");
    mvwprintw(win, 1, 1, "this is my box");
    wrefresh(win);

    // whaits for user input, returns int value of that key
    getch();
    getch();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}
