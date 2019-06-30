/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:00:17 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/29 22:00:19 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"
# include "Game.hpp"

void		draw_palyer(Game *g, Player *p)
{
	// wattron(g->win, COLOR_PAIR(3));
	// mvwaddch(g->win, p->y, p->x,'M');
	// mvwaddch(g->win, p->y, X(p->x - 1),'<');
	// mvwaddch(g->win, p->y, X(p->x + 1),'>');
	// wattroff(g->win, COLOR_PAIR(3));

	//	mvprintw(p->y, p->x, "<H>");
		attron(COLOR_PAIR(7));
		attron(A_BOLD);
		mvprintw(p->y - 2, p->x, " @@ ");
		mvprintw(p->y - 1, p->x, " || ");
		mvprintw(p->y, p->x, "O||O");
		attroff(COLOR_PAIR(7));
		attroff(A_NORMAL);
	(void)g;
	usleep(10000);
}

void		starField(Game *g)
{
	for(int y = (MAPH); y > 0; y--)
	{
		for (int x = 0; x < (MAPW); x++)
		{
			if (g->map[y][x] == '.')
			{
				wattron(g->win, A_DIM);
				g->map[y][x] = ' ';
				// mvprintw(y, x, " ");
				mvwaddch(g->win, y, x, ' ');
				if ((y + 1) < (MAPH))
				{
					g->map[y + 1][x] = '.';
					// mvprintw(y + 1, x, ".");
					mvwaddch(g->win, y + 1, x, '.');
				}
				wattroff(g->win, A_DIM);
			}
		}
	}
	for(int i = 0; i < 2; i++)
		g->map[1][(rand() % (MAPW - 1) + 1)] = '.';
}


int			main(void)
{
	Game *g = new Game(WINH, WINW);
		g->p = new Player;
		g->p->y = (MAPH);
		g->p->x = (MAPW) / 2;

	g->init_map();
	g->init_colors();

	nodelay(stdscr, TRUE);
	srand(time(0));

	int	key;
	size_t	 tick = 0;
	while (!g->gameOver) 
	{
//		werase(g->win);
		wattron(g->win, COLOR_PAIR(1));
		box(g->win, 0, 0);
		wattroff(g->win, COLOR_PAIR(1));

			keypad(stdscr, 1);
			if ((key = getch()) != ERR)
				g->key_events(key);
	
			if (tick % 7 == 0)
				starField(g);
			if (tick % 5 == 0)
				g->moveBullets();
			if (tick % 30 == 0)
				g->moveEnemies();
			g->detectCollision();



		draw_palyer(g, g->p);
		wrefresh(g->win);
//		refresh();

		tick++;


	}
	werase(g->win);
	erase();
	mvprintw((WINH) / 2, (WINW) / 2, "GAME OVER");
	wrefresh(g->win);
	refresh();
	sleep(5);

	g->exit_game();
}





// mvprintw(windod, y, x ) - for put your info in loop 
/*
    printw(string);        				// Print on stdscr at present cursor position 
    mvprintw(y, x, string);   			// Move to (y, x) then print string     
    wprintw(win, string); 				// Print on window win at present cursor position 
                           				//in the window 
    mvwprintw(win, y, x, string);  		// Move to (y, x) relative to window 
                                    	//co-ordinates and then print        
*/