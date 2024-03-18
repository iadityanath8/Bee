#include <stdlib.h>
#include <ncurses.h>


#define auto __auto_type

void test();
void test2();

void write_ui(){
  char a;
  
  bool on = true;

  while(on){
    a = getch();

    switch(a){
      case ':':
        char t = getch();
	if(t=='q'){
        refresh();
        on = false;}
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
