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
# include "../inc/game.hpp"
# include "../inc/Player.hpp"


void		starField(Game *g)
{
	for(int y = (MAPH); y > 0; y--)
	{
		for (int x = 0; x < (MAPW); x++)
		{
			if (g->map[y][x] == '.')
			{
				wattron(g->win, A_DIM);
				g->map[y][x] = ' ';
				mvwaddch(g->win, y, x, ' ');
				if ((y + 1) < (MAPH))
				{
					g->map[y + 1][x] = '.';
					mvwaddch(g->win, y + 1, x, '.');
				}
				wattroff(g->win, A_DIM);
			}
		}
	}
	for(int i = 0; i < 2; i++)
		g->map[1][(rand() % (MAPW - 1) + 1)] = '.';
}


int			main(void)
{
	Game *g = new Game(WINH, WINW);
	Player p(MAPH, MAPH / 2);
		//g->p->y = (MAPH);
		//g->p->x = (MAPW) / 2;

	// Player player = new Player();
	g->init_map();
	g->init_colors();

	nodelay(stdscr, TRUE);
	srand(time(0));

	int	key;
	size_t	 tick = 0;
	while (!g->gameOver || getch() != 27) 
	{
		wattron(g->win, COLOR_PAIR(1));
		box(g->win, 0, 0);
		wattroff(g->win, COLOR_PAIR(1));
		keypad(stdscr, 1);
		if ((key = getch()) != ERR)
			p.key_events(key);
		if (tick % 7 == 0)
			starField(g);
		if (tick % 5 == 0)
			p.moveBullets(g->win);
		if (tick % 30 == 0)
			g->moveEnemies();
		p.detectCollision(g->enemies);
		p.draw_player();
		wrefresh(g->win);
		tick++;
	}
	werase(g->win);
	erase();
	mvprintw((WINH) / 2, (WINW) / 2, "GAME OVER");
	wrefresh(g->win);
	refresh();
	sleep(5);
	g->exit_game();
}

// void			Player::detectCollision(void)
// {
// 	for(int y = (MAPH); y > 0; y--)
// 	{
// 		for (int x = 0; x <= (MAPW); x++)
// 		{
// 			if (enemies[y][x] == 'X' && missiles[y][x])
// 			{
// 				enemies[y][x] = ' ';
// 				curEnemies--;
// 			}
// 			if (enemies[y][x] == 'X')
// 			{
// 				if ((y == this->y && x == this->x) || (y == this->y && x == this->x + 1 ) ||
// 					(y == this->y && x == this->x +2) || (y == this->y && x == this->x + 3) ||
// 													 (y == y - 1 && x == this->x + 1) ||
// 					(y == this->y - 1 && x == this->x + 2) ||
// 													(y == this->y - 2 && x == this->x + 1) ||
// 					(y == this->y - 2 && x == this->x + 2))
// 				gameOver = true;
// 			}
// 		}
// 	}
// }



// mvprintw(windod, y, x ) - for put your info in loop 
/*
    printw(string);        				// Print on stdscr at present cursor position 
    mvprintw(y, x, string);   			// Move to (y, x) then print string     
    wprintw(win, string); 				// Print on window win at present cursor position 
                           				//in the window 
    mvwprintw(win, y, x, string);  		// Move to (y, x) relative to window 
                                    	//co-ordinates and then print        
*/