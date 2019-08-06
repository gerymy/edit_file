#include<termios.h>
#include<sys/ioctl.h>
#include<signal.h>
#include<stdlib.h>
#include<curses.h>
void sig_winch(int signo)
{
	struct winsize size;
	ioctl(fileno(stdout),TIOCGWINSZ, (char *) &size);
	resizeterm(size.ws_row, size.ws_col);
}
int main()
{
	WINDOW * head;
	WINDOW * leftwindow;
	WINDOW * rightwindow;
	initscr();
	signal (SIGWINCH, sig_winch);
	curs_set(0);
	refresh();
	head=newwin(4,COLS,0,0);
	box(head,'|','_');
	wmove (head,2, 10);
	wrefresh(head);
	wprintw(head,"Wellcome to best file editor tipe: TAB and change window F6 and go away, press ctrl+e and open txt file gl hf");
	wrefresh(head);
	refresh();
	leftwindow=newwin(LINES-3,50,6,2);
	rightwindow=newwin(LINES-3,50,6,54);
	box(leftwindow,'|',' ');
	box(rightwindow,'|',' ');
	wrefresh(rightwindow);
	wrefresh(leftwindow);
	//delwin(head);
	//wprintw(stdscr, "Wellcome to best file editor tipe: TAB and change window\n F6 and go away, press ctrl+e and open txt file gl hf");
	refresh();
	getch();
	endwin();
	exit(EXIT_SUCCESS);
}
