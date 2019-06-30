
#ifndef Game_HPP
# define Game_HPP

# include "main.hpp"

# define ESC 27

class					Game
{
	public:
		Game(void);
		Game(int maph, int mapw);
		Game(Game const &src);
		~Game(void);

		Game &	operator = (const Game &rhs);

		int				getMaph(void) const;
		int				getMapw(void) const;
//		void			setVar(int var);
		
		void			init_colors(void);
		void			key_events(void);

		WINDOW 			*win;

	private:
		int				_maph;
		int				_mapw;	


};

#endif
