/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:02:04 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/30 12:02:07 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

#ifndef PLAYER_HPP
# define PALYER_HPP

class					Player
{
	public:
		// Player(void);
		// Player(int const var);
		// Player(Player const &src);
		// ~Player(void);

	// Player &	operator = (const Player &rhs);

	// 	int		getVar(void) const;
	//	void	setVar(int var);

		int			y;
		int			x;
		char		missiles[MAPH][MAPW];

};

#endif