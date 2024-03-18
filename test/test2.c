#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>


#define auto __auto_type

void write_ui(){
  
  bool on = true;
  char a = {0};
  while(on){
    a = getch();
    
    switch (a){
      case 'q':
        printw("exiting the editor\n");
        refresh();
        endwin();
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
  raw();
  keypad(stdscr,TRUE);
  noecho();
  int x,y;
  bool on = true;
  char a;

  while(on){
    a = getch();
    if(a == 'q'){
      printw("ending the terminal in here");
      refresh();
      exit(EXIT_FAILURE);
    }
    getyx(stdscr,y,x);
    printw("%d %d -> \n",x,y);
    refresh();
  }

  endwin();
  return 0;
}






