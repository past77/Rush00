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
 //# include "Player.hpp"

# define ESC 27

# define WINH 40
# define WINW 100
# define MAPH WINH - 2
# define MAPW WINW - 2

# define Y(y) ((y < 1) ? 1 : (y > MAPH) ? MAPH : y)
# define X(x) ((x < 1) ? 1 : (x > MAPW) ? MAPW : x)
#define MAX_ENEMIES 20
#define MAX_STARS 27

class					Game
{

	public:
		Game(void);
		Game(int maph, int mapw);
		Game(Game const &src);
		~Game(void);

		Game &	operator = (const Game &rhs);

		void			draw_player();
		int				getMaph(void) const;
		int				getMapw(void) const;

		void			exit_game(void);
		void			init_map(void);
		void			init_colors(void);
		void			key_events(int key);

		void			detectCollision(void);

		WINDOW			*win;
		Map*			map;
		Player*			player;
		Star*			stars;
		Enemy*			enemies;
		bool			gameOver;


	private:
		int				_maph;
		int				_mapw;	

};

#endif
