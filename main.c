#include <stdlib.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define auto __auto_type
#define ESCAPE 27
#define ENTER 10


void test();
void test2();

void write_ui(bool* on){
  int a;
  char t;

  while(*on){
    a = getch();

    switch(a){
      case 58:
        t = getch();
	    
        if(t == 113){
          refresh();
          *on = false;
        }
        break;
      
      case 263:
    	  printw("\b \b");
	      refresh();
	      break;

      default:
        printw("%c",a);
        refresh();
        break;
    }
  }

}

void normal_mode(){
  bool on = true;
  char a = {0};
  char t = {0};
  int y;

  while(on){
    a = getch();
    
    switch (a){ 
      case 'i':
        write_ui(&on);
        break;
      
      case ':':
        t = getch();
        if(t == 'q') on = false;
        break;
 
      default:
        y = getmaxy(stdscr); 
        printw("%d\n",y);
        refresh();
        break;
    }
  }
}

void mode_switcher(){
  int x,y;
  char ch = {0};
  char t = {0};
  bool on = true;
  int first_time = 0;
  getmaxyx(stdscr,y,x);
  auto down_window = newwin(3,x,y - 1,0);
  
  waddstr(down_window,"---NORMAL---");

  while(on){
    ch = wgetch(down_window);
    if(first_time == 0){
      wclear(down_window);
      wrefresh(down_window);   // unncessary thing in here 
    }
    wprintw(down_window,"%c",ch);
    wrefresh(down_window);
    
    switch(ch){
      case ':':
        t = wgetch(down_window);
        if(t == 'q') on = false;
        break;
      case 'i':
        write_ui(&on);
        break;
    }
  }

  wrefresh(down_window);
}

int main(){
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  
  mode_switcher();
  endwin();
  return 0;
}
