/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 10:53:17 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/30 10:53:19 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "main.hpp"
# include "Player.hpp"

# define ESC 27

# define WINH 40
# define WINW 100
# define MAPH WINH - 2
# define MAPW WINW - 2

# define Y(y) ((y < 1) ? 1 : (y > MAPH) ? MAPH : y)
# define X(x) ((x < 1) ? 1 : (x > MAPW) ? MAPW : x)

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

		void			exit_game(void);
		void			init_map(void);
		void			init_colors(void);
		void			key_events(int key);

		void			moveBullets(void);
		void			moveEnemies(void);
		void			detectCollision(void);

		WINDOW 			*win;
		char			map[MAPH][MAPW];
		Player			*p;
		char			stars[MAPH][MAPW];

		char			enemies[MAPH][MAPW];

		int				curEnemies;
		int				maxEnemies;
		bool			gameOver;


	private:
		int				_maph;
		int				_mapw;	

};

#endif
