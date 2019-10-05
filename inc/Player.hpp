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

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "main.hpp"
# include "game.hpp"

class					Player : public Game
{
	public:
		 void		draw_player();
		Player(void);
		Player(int y, int x);
		//Player(int const var);
		Player(Player const &src);
		~Player(void);

		int	getX();
		int getY();
		void setX(int x);
		void setY(int y);

		void		key_events(int key);
		void		detectCollision(char enemies[MAPH][MAPW]);
		void		moveBullets(WINDOW *win);

	// Player &	operator = (const Player &rhs);

	// 	int		getVar(void) const;
	//	void	setVar(int var);
	protected:
		int			y;
		int			x;
		char		missiles[MAPH][MAPW];

};

#endif