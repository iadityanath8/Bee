#include <stdlib.h>
#include <ncurses.h>


#define auto __auto_type

void test();
void test2();

void write_ui(){
  int a;
  
  bool on = true;

  while(on){
    a = getch();

    switch(a){
      case 58:
        char t = getch();
	if(t== 113){
        refresh();
        on = false;}
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


int main(){
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  
  write_ui();

  endwin();
  return 0;
}
