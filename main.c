#include <stdlib.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define auto __auto_type


void insert_call(WINDOW *w){
    wclear(w);
    waddstr(w,"---INSERT---");
    wrefresh(w);
}


void normal_call(WINDOW *w){
    wclear(w);
    waddstr(w,"---NORMAL---");
    wrefresh(w);
}


void write_ui(WINDOW *down_window) {
    int a;
    bool on = true;
    int x, y;

    while(on) {
        a = getch();
        switch(a) {
            case 27:
                on = false;
                break;

            case KEY_BACKSPACE:
            case 127:
            case 8:
                getyx(stdscr, y, x);
                if (x == 0) {
                    if (y > 0) {
                        move(y - 1, getmaxx(stdscr));
                        clrtobot();
                        move(y - 1, getmaxx(stdscr) - 1);
                        while ((a = inch()) == ' ' && getcurx(stdscr) > 0) {
                          move(y - 1, getcurx(stdscr) - 1);
                        }
                        delch();
                    }
                } else {
                    move(y, x - 1);
                    delch();
                }
                break;

            default:
                printw("%c", a);
                break;
        }
        refresh();
    }

    wclear(down_window);
    normal_call(down_window);
    wrefresh(down_window);
}


void control(){
  int x,y;
  bool on = true;
  getmaxyx(stdscr,y,x);
  auto down_window = newwin(3,x,y - 1,0); 
  normal_call(down_window);

  while(on){
  int ch = wgetch(down_window);
  wclear(down_window);
  wprintw(down_window,"%c",ch);
  wrefresh(down_window);

   switch(ch){
      case 105:
        write_ui(down_window);
        normal_call(down_window);
        break;

      case 58:
        ch = wgetch(down_window);
	      wprintw(down_window,"%c",ch);
        if(ch == 113){
	      ch = wgetch(down_window);
        if(ch == 10){
	          on = false;
            }
        }
        break;      
    }
}
}

int main(){
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  control();
  endwin();
  return 0;
}