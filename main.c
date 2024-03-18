#include <stdlib.h>
#include <ncurses.h>


#define auto __auto_type

void test();

void write_ui(){
  char a;
  
  bool on = true;

  while(on){
    a = getch();

    switch(a){
      case 'q':
        printw("exiting the terminal");
        refresh();
        on = false;
        break;
      
      default:
        printw("%c",a);
        refresh();
        break;
    }
  }

}


int main(){
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  
  write_ui();

  endwin();
  return 0;
}
