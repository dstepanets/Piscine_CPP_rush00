/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:10:47 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/29 22:10:49 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <ncurses.h>
# include <iostream>
# include <unistd.h>
# include <cmath>

# define ESC 27

# define WINH 40
# define WINW 100
# define MAPH WINH - 2
# define MAPW WINW - 2

# define Y(y) ((y < 1) ? 1 : (y > MAPH) ? MAPH : y)
# define X(x) ((x < 1) ? 1 : (x > MAPW) ? MAPW : x)


#endif