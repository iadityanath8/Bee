#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
/* This is done only for easiness soon may be removed from the production build 
 *This programming style for now i am calling meow meow programming style */

#define auto __auto_type

int main(){
  int ch;
  initscr();
  raw();   /*Line buffering disabled*/
  keypad(stdscr,TRUE);   // Should write bug TRUE because of the ncurses library shit
  noecho();  // Don't echo means screen will not show any thing until typed 
  
  printw("Type any character to see in bold -> \n");
  
  while (true){
    ch = getch();
  
    if(ch == KEY_F(1)){
      printw("f1 key is pressed\n");
    }else if(ch == 'q'){
      exit(EXIT_FAILURE);
    }else{
      attron(A_ITALIC);
      printw("%c",ch);
      attroff(A_ITALIC);
    }
      refresh();  // updating ui by refreshing the full terminal UI
  }
  endwin();
  return 0;
}
