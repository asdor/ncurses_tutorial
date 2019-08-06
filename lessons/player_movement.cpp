#include <algorithm>
#include <string>

#include <ncurses.h>

class Player
{
public:
    Player(WINDOW* win, int y, int x, char ch)
        : cur_win(win), y_loc(y), x_loc(x), ch_(ch)
    {
        getmaxyx(cur_win, y_max, x_max);
        keypad(cur_win, true);
    }

    void mv_up()
    {
        mvwaddch(cur_win, y_loc, x_loc, '.');
        y_loc = std::max(1, y_loc - 1);
    }

    void mv_down()
    {
        mvwaddch(cur_win, y_loc, x_loc, '.');
        y_loc = std::min(y_max - 2, y_loc + 1);
    }

    void mv_left()
    {
        mvwaddch(cur_win, y_loc, x_loc, '.');
        x_loc = std::max(1, x_loc - 1);
    }

    void mv_right()
    {
        mvwaddch(cur_win, y_loc, x_loc, '.');
        x_loc = std::min(x_max - 2, x_loc + 1);
    }

    int get_mv()
    {
        int choice = wgetch(cur_win);
        switch (choice)
        {
            case KEY_UP:
                mv_up();
                break;
            case KEY_DOWN:
                mv_down();
                break;
            case KEY_LEFT:
                mv_left();
                break;
            case KEY_RIGHT:
                mv_right();
                break;
            default:
                break;
        }

        return choice;
    }
    void display()
    {
        mvwaddch(cur_win, y_loc, x_loc, ch_);
    }

private:
    int y_loc;
    int x_loc;
    int y_max;
    int x_max;
    char ch_;
    WINDOW* cur_win;

};

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
    WINDOW* play_win = newwin(6, x_max - 12, y_max - 8, 5);
    box(play_win, 0, 0);
    refresh();
    wrefresh(play_win);

    Player* p = new Player(play_win, 1, 1, '@');
    do
    {
        p->display();
        wrefresh(play_win);
    } while (p->get_mv() != 'x');

    endwin();

    return 0;
}
