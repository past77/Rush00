/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:01:53 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/30 12:01:56 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Player.hpp"

	Player::Player(){}

	Player::Player(int y, int x): y(y), x(x) {}

	Player::Player(Player const &src){
		*this = src;
	}

	Player::~Player(void){

	}

	int	Player::getX(){
		return this->x;
	}
	int Player::getY(){
		return this->y;
	}
	void Player::setX(int x){
		this->x = x;
	}
	void Player::setY(int y){
		this->y = y;
	}

	void		Player::draw_player()
{
		attron(COLOR_PAIR(7));
		attron(A_BOLD);
		mvprintw(this->y - 2, this->x, "/--\\ ");
		mvprintw(this->y - 1, this->x, " || ");
		mvprintw(this->y, this->x, "O||O");
		attroff(COLOR_PAIR(7));
		attroff(A_NORMAL);
	usleep(10000);
}

void		Player::moveBullets(WINDOW *win)
{
	for(int y = 0; y < (MAPH); y++)
	{
		for (int x = 0; x < (MAPW); x++)
		{
			if (missiles[y][x] == '!')
			{
				wattron(win, A_BOLD);
				missiles[y][x] = ' ';
				mvwaddch(win, y, x, ' ');
				if ((y - 1) > 0)
				{
					missiles[y - 1][x] = '!';
					mvwaddch(win, y - 1, x, '!');
				}
				wattroff(win, A_BOLD);
			}
		}
	}
}

int				abs(int x) {
	return x < 0 ? -x : x;
}


void			Player::detectCollision(char enemies[MAPH][MAPW])
{
	for(int y = (MAPH); y > 0; y--)
	{
		for (int x = 0; x <= (MAPW); x++)
		{
			if (enemies[y][x] == 'X' && missiles[y][x])
			{
				enemies[y][x] = ' ';
				curEnemies--;
			}
			if (enemies[y][x] == 'X')
			{
				if (abs(this->y - y) <= 3 && (abs(this->x - x) <= 3)) {
							gameOver = true;
				}
			}
		}
	}
}
