

#include "../inc/main.hpp"

/*==============================CONSTRUCTORS=================================*/

Game::Game(void) : _maph(30), _mapw(100)
{
	initscr();			// Initialize the window
	cbreak();			// Line buffering disabled, Pass on everty thing to me
	noecho(); 			// Don't echo any keypresses
	curs_set(FALSE); 	// Don't display a cursor
	clear();

	this->win = newwin(_maph, _mapw, 0, 0);
	wrefresh(win);
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

void		Game::init_colors(void)
{
	start_color();							//for using colors 
	init_pair(1, COLOR_BLACK, COLOR_BLUE); 	// create color 
}

void		Game::key_events(void)
{

}
