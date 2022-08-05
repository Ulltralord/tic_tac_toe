#include <ncurses.h>

int flag = 0;

bool ful(char a)
{
    if (a == ' ')
    {
		return true;
    }
    else
    {
		return false;
    }
}

void draw_game(char a[3][3])
{
	{
		clear();
		attron(COLOR_PAIR(2));
		mvwprintw(stdscr, 4, 0,"Welcome to TIC TAC TOE game! Use Q, W, E, A, S, D, Z, X and C keys to insert the symbol to the selected place.");
		attroff(COLOR_PAIR(2));
		
		for(int t=0, r = 1; t<3; t++, r++)
		{
			mvwprintw(stdscr, (LINES / 2)+t+r, (COLS/2)-4,"| %c | %c | %c |", a[t][0], a[t][1], a[t][2]);
			mvwprintw(stdscr, (LINES / 2)+t+r-1, (COLS/2)-4,"-------------");
		}
		mvwprintw(stdscr, (LINES / 2)+6, (COLS/2)-4,"-------------");
	}
}

char draw()
{
	char symbol;
	if (flag == 1)
	{
		symbol = 'x';
		flag = 0;
	}
	else
	{
		symbol = 'o';
		flag = 1;
	}
	return symbol;	
}

int main(int argc, char* argv[])
{
    char place;
    
	initscr();
	
	start_color();
	use_default_colors();
	curs_set(0);
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_YELLOW, -1);

	while ( true ) 
	{  
		char game[3][3] = 
		{

        {' ',' ', ' '},

        {' ',' ', ' '},

        {' ',' ', ' '}

		};	
     
		draw_game(game);
     
		for (int i = 0; i < 9; i++)
		{
			place = getch();
			switch (place)
				{
				case 'q':
				if (ful(game[0][0]))
				game[0][0] = draw();
				else i--;
				break;
				case 'w':
				if (ful(game[0][1]) == true)
				game[0][1] = draw();
				else i--;
				break;
				case 'e':
				if (ful(game[0][2]))
				game[0][2] = draw();
				else i--;
				break;
				case 'a':
				if (ful(game[1][0]))
				game[1][0] = draw();
				else i--;
				break;
				case 's':
				if (ful(game[1][1]))
				game[1][1] = draw();
				else i--;
				break;
				case 'd':
				if (ful(game[1][2]))
				game[1][2] = draw();
				else i--;
				break;
				case 'z':
				if (ful(game[2][0]))
				game[2][0] = draw();
				else i--;
				break;
				case 'x':
				if (ful(game[2][1]))
				game[2][1] = draw();
				else i--;
				break;
				case 'c':
				if (ful(game[2][2]))
				game[2][2] = draw();
				else i--;
				break;
				default:
				i--;
				break;
			}
			draw_game(game);
		}
			
		attron(A_BLINK);
		attron(COLOR_PAIR(3));

		if (((game[0][0]==game[0][1]) && (game[0][0]==game[0][2])) ||
			((game[0][0]==game[1][1]) && (game[0][0]==game[2][2])) ||
			((game[0][0]==game[2][0]) && (game[0][0]==game[1][0])))
			{
				mvwprintw(stdscr, (LINES / 2)-3, COLS/2-2,"%c  %s ", game[0][0], "win!");
			}
		else if(((game[0][2]==game[1][1]) && (game[0][2]==game[3][0])) ||
			((game[0][2]==game[1][2]) && (game[0][2]==game[2][2])))
			{
				mvwprintw(stdscr, (LINES / 2)-3, COLS/2-2,"%c  %s ", game[0][2], "win!");
			}
		else if(((game[0][1]==game[1][1]) && (game[0][1]==game[2][1])) ||
			((game[1][0]==game[1][1]) && (game[1][0]==game[1][2])))
			{
				mvwprintw(stdscr, (LINES / 2)-3, COLS/2-2,"%c  %s ", game[1][1], "win!");
			}	
		else if((game[2][0]==game[2][1]) && (game[2][2]==game[2][1]))
			{
				mvwprintw(stdscr, (LINES / 2)-3, COLS/2-2,"%c  %s ", game[2][1], "win!");
			}		
		else mvwprintw(stdscr, (LINES / 2)-3, COLS/2-2,"Nobody win");
		
		attroff(A_BLINK);
		attroff(COLOR_PAIR(3));
	
		attron(COLOR_PAIR(1));
		mvwprintw(stdscr, (LINES / 2)+8, COLS/2-14,"Press any key to restart the game");
		attroff(COLOR_PAIR(1));
		
		getch();
		clear();
	  }
	refresh();
	getch();
	clear();
	endwin();
	return 0;
}
