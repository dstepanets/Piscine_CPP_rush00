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

void		ball(Game *g)
{
	static int x = 2, y = 38;
//	int max_y = 0, max_x = 0;
	static	int next_x = 0;
	static int direction = 1;

	mvprintw(y - 3, x, " @@ ");
	mvprintw(y - 2, x, " || ");
	mvprintw(y - 1, x, " || ");
	mvprintw(y, x, "O||O");

	usleep(30000);

	next_x = x + direction;
	if (next_x >= (g->getMapw() - 4) || next_x < 1) 
		direction*= -1;
	else 
		x += direction;

}


int			main(void)
{
	Game *g = new Game(40, 100);

	g->init_colors();

	unsigned int		count = 0;
	while (1) 
	{
		count++;
		wattron(g->win, COLOR_PAIR(1));
		box(g->win, 0, 0);
		wattroff(g->win, COLOR_PAIR(1));


		int		key;
		keypad(stdscr, 1);
		nodelay(stdscr, TRUE);
//		if (count >= 13550 && count % 13550 == 0)
			ball(g);
//		wprintw(g->win, "<O>");

		wrefresh(g->win);
		key = getch();

		if (key == ESC)		//ESC
			delete g;

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