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

#include <unistd.h>		//

void		ball()
{
	static int x = 2, y = 38;
	static	int next_x = 0;
	static int direction = 1;

	mvprintw(y - 2, x, " @@ ");
	mvprintw(y - 1, x, " || ");
	mvprintw(y, x, "O||O");

	usleep(30000);

	next_x = x + direction;
	if (next_x >= (MAPW - 2) || next_x < 1) 
		direction*= -1;
	else 
		x += direction;

}

void		draw_palyer( Player *p)
{
	mvprintw(p->y, p->x, "<H>");
}


void		exit_game(Game *g, Player *p)
{
	delete p;
	delete g;
}

int			main(void)
{
	Game *g = new Game(WINH, WINW);

	g->init_colors();
	g->init_map();

	unsigned int		count = 0;
	while (1) 
	{
		count++;
		wattron(g->win, COLOR_PAIR(1));
		box(g->win, 0, 0);
		wattroff(g->win, COLOR_PAIR(1));

		// g->redrawMap();
		g->p = new Player;
		g->p->y = MAPH;
		g->p->x = (MAPW / 2);
		draw_palyer(g->p);
//		if (count >= 13550 && count % 13550 == 0)
//			ball();
//		wprintw(g->win, "<O>");
			nodelay(stdscr, TRUE);
			keypad(stdscr, 1);
			int 	key = getch();
			g->key_events(key);
			if (key == ESC)
				exit_game(g, g->p);

		wrefresh(g->win);
	}
	return (0);
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