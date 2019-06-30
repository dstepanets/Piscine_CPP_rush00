/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 10:53:06 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/30 10:53:08 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"
# include "Game.hpp"

/*==============================CONSTRUCTORS=================================*/

Game::Game(void) : _maph(MAPH), _mapw(MAPW)
{
	initscr();			// Initialize the window
	cbreak();			// Line buffering disabled, Pass on everty thing to me
	noecho(); 			// Don't echo any keypresses
	curs_set(FALSE); 	// Don't display a cursor
	clear();

	this->win = newwin(_maph, _mapw, 0, 0);
	wrefresh(win);

//	this->sWin = newwin(_maph, _mapw, 0, 0);
//	wrefresh(sWin);
}

Game::Game(int maph, int mapw) : _maph(maph), _mapw(mapw)
{
	initscr();			// Initialize the window
	cbreak();			// Line buffering disabled, Pass on everty thing to me
	noecho(); 			// Don't echo any keypresses
	curs_set(FALSE); 	// Don't display a cursor
	clear();

	this->win = newwin(_maph, _mapw, 0, 0);
	wrefresh(win);
}

Game::Game(Game const &src)
{
	*this = src;
}

Game::~Game(void)
{
	endwin();
	exit(0);
}

/*================================OPERATORS==================================*/

Game & 			Game::operator = (Game const &rhs)
{
	if (this != &rhs)
	{
		this->win = rhs.win;
		this->_maph = rhs._maph;
		this->_mapw = rhs._mapw;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

int		Game::getMaph(void) const { return (this->_maph) ;}
int		Game::getMapw(void) const { return (this->_mapw) ;}

// void				Game::setVar(int var)
// {
// 	this->_var = var;
// }

/*===========================FUNCTIONS=======================================*/

void		Game::exit_game(void)
{
	delete this->p;
	delete this;
}

void		Game::init_map(void)
{
	for (int y = 0; y < MAPH; y++)
	{
		bzero(map[y], MAPW);
		bzero(stars[y], MAPW);
	}
	maxEnemies = 24;
	gameOver = false;
//	map[MAPH - 1][(MAPW - 1) / 2] = 'S';
}

void		Game::init_colors(void)
{
	start_color();							//for using colors 
	init_pair(1, COLOR_BLACK, COLOR_BLUE); 	// create color 
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
}

void		Game::key_events(int key)
{
	switch(key)
	{	case KEY_LEFT:
			this->p->x--;
			if (this->p->x < 1)
				this->p->x = 1;
			break;
		case KEY_RIGHT:
			this->p->x++;
			if (this->p->x > (MAPW) - 3)
				this->p->x = (MAPW) - 3;
			break;
		case ' ':
			p->missiles[p->y - 3][X(p->x + 1)] = '!';
			p->missiles[p->y - 3][X(p->x + 2)] = '!';
//			mvprintw(p->y - 3,  p->x + 2, "!");
			break;
		case ESC:
			exit_game();

//			refresh();
	}
}

void		Game::moveBullets(void)
{
	for(int y = 0; y < (MAPH); y++)
	{
		for (int x = 0; x < (MAPW); x++)
		{
			if (p->missiles[y][x] == '!')
			{
				wattron(win, A_BOLD);
				p->missiles[y][x] = ' ';
				//mvprintw(y, x, " ");
				mvwaddch(win, y, x, ' ');
				if ((y - 1) > 0)
				{
					p->missiles[y - 1][x] = '!';
				//	mvprintw(y - 1, x, "!");
					mvwaddch(win, y - 1, x, '!');
				}
				wattroff(win, A_BOLD);
			}
		}
	}
}

void		Game::moveEnemies(void)
{
	int 	xShift;
	int		tX = 0;

	for(int y = (MAPH); y > 0; y--)
	{
		for (int x = 0; x <= (MAPW); x++)
		{
			if (enemies[y][x] == 'X')
			{
				enemies[y][x] = ' ';
				// mvprintw(y, x, " ");
				mvwaddch(win, y, x, ' ');
				if ((y + 1) < (MAPH))
				{
					srand(time(0));
					xShift = (rand() % 2) ? 1 : -1;
					tX = 0;
					tX = x + xShift; 
						// if (tX >= MAPW)
						// 	tX -= 2;
						// else if (tX <= 1)
						// 	tX +=2;
					enemies[y + 1][X(tX)] = 'X';
					// mvprintw(y + 1, x, ".");
					wattron(win, A_STANDOUT);		
					wattron(win, COLOR_PAIR(5));
						mvwaddch(win, y + 1, X(tX), 'X');
					wattroff(win, A_STANDOUT);
					wattroff(win, COLOR_PAIR(5));
				}
				if (y == (MAPH) - 1)
					curEnemies--;
			}
		}
	}

	for(int i = curEnemies; i < maxEnemies; i++)
	{
		enemies[1][(rand() % (MAPW - 1) + 1)] = 'X';
		curEnemies++;
	}
}

void			Game::detectCollision(void)
{
	for(int y = (MAPH); y > 0; y--)
	{
		for (int x = 0; x <= (MAPW); x++)
		{
			if (enemies[y][x] == 'X' && p->missiles[y][x])
			{
				enemies[y][x] = ' ';
				curEnemies--;
			}
			if (enemies[y][x] == 'X')
			{
				if ((y == p->y && x == p->x) || (y == p->y && x == p->x + 1 ) ||
					(y == p->y && x == p->x +2) || (y == p->y && x == p->x + 3) ||
													 (y == p->y - 1 && x == p->x + 1) ||
					(y == p->y - 1 && x == p->x + 2) ||
													(y == p->y - 2 && x == p->x + 1) ||
					(y == p->y - 2 && x == p->x + 2))
				gameOver = true;
			}
		}
	}
}