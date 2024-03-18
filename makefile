CC = cc

run:
	$(CC) -Wall -Wextra -Werror -o main main.c -lncurses && ./main

install_linux:
	sudo apt-get install libncurses5-dev libncursesw5-dev

comp:
	$(CC) -Wall -Wextra -Werror -o main main.c -lncurses


clean:
	rm -rf ./main
