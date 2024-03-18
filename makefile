CC = cc

run:
	$(CC) -o main main.c -lncurses && ./main

install_linux:
	sudo apt-get install libncurses5-dev libncursesw5-dev

comp:
	$(CC) -o main main.c

clean:
	rm -rf ./main
