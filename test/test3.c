#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#define auto __auto_type
#define ESCAPE 27
#define ENTER 10


WINDOW* create_newwin(int height,int width,int starty,int startx){
  auto local_win = newwin(height,width,startx,starty);
  box(local_win,0,0);

  wrefresh(local_win);

  return local_win;
}

void destroy_win(WINDOW* local_win){
  wrefresh(local_win);
  delwin(local_win);
}

int main(){
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  int x,y;

  getmaxyx(stdscr,y,x);
  auto down_window = newwin(3,108,y - 1,0);
  waddstr(down_window,"--- NORMAL ---");
  
  wrefresh(down_window);
  
  bool on = true;
  char ch = {0};
  int first_time = 0;

  while(on){
    ch = wgetch(down_window);
    if (first_time == 0){
      wclear(down_window);
      first_time++;
    }
    wprintw(down_window,"%c",ch);
    wrefresh(down_window);

    switch(ch){
      case 'q':
        on = false;
        break;
   }
  }

  endwin();
 
  return 0;
}
