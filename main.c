#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#define auto __auto_type

void write_ui(){
  
  bool on = true;

  while(on){
    char a = getch();
    
    switch (a){
      case 'q':
        printw("exiting the editor\n");
        refresh();
        exit(EXIT_SUCCESS);
        break;

      default:
        printw("%c",a);
        refresh();
    }
  }
}

int main(){
  initscr();
  cbreak();
  noecho();
  keypad(stdscr,TRUE);
  
  write_ui();

  endwin();
  return 0;
}
