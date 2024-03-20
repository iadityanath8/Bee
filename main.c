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


void write_ui(WINDOW *down_window){ 
int a;
int c = 0;
bool on = true;
  while(on){
    a = getch();
    switch(a){

      case 27:
        return;

      case 263:
    	  printw("\b \b");
				refresh();
	      break;

      default:
				printw("%c",a);
				refresh();
        break;
    }

    if(c == 0){
      insert_call(down_window);
      c = 1;
    }
  }

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
