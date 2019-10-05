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
# include "../inc/game.hpp"
# include "../inc/Player.hpp"


// Initialization
Game::Game(void) : _maph(MAPH), _mapw(MAPW), curStars(0),
					map(new Map(MAPH, MAPW)), enemies(new Enemy[maxEnemies]()), stars(new Stars[maxStars])
{
	initscr();			// Initialize the window
	cbreak();			// Line buffering disabled, Pass on everty thing to me
	noecho(); 			// Don't echo any keypresses
	curs_set(FALSE); 	// Don't display a cursor
	clear();

	this->win = newwin(_maph, _mapw, 0, 0);
	wrefresh(win);

	for(int i = 0; i < maxStars; i++) {
		enemies[i] = spawnObject(MapObjectType.Star);
	}
	for(int i = 0; i < maxEnemies; i++) {
		enemies[i] = spawnObject(MapObjectType.Enemy);
	}
}

MapObject Game::spawnObject(MapObjectType type) {
	if (type == MapObjectType.Star) {
		return new Star(1, (rand() % (MAPW - 1) + 1));
	} else if (type == MapObjectType.Enemy) {
		return new Enemy(1, (rand() % (MAPW - 1) + 1));
	} else if (type == MapObjectType.Bullet) {
		return new Bullet(player.getY() - 3, player.getX() + 1);
	} else {
		return NULL;
	}
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
}

void		Game::init_colors(void)
{
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
}

// End
void		Game::exit_game(void) {
	delete this;
}

Game::~Game(void)
{
	endwin();
	exit(0);
}

// Game
void		Game::gameLoop() {
	while (!gameOver || getch() != 27) 
	{
		wattron(g->win, COLOR_PAIR(1));
		box(g->win, 0, 0);
		wattroff(g->win, COLOR_PAIR(1));
		keypad(stdscr, 1);
		if ((key = getch()) != ERR)
			key_events(key);
		if (tick % 7 == 0)
			moveObject(stars, MapObjectType.Star, maxStars);
		if (tick % 5 == 0)
			p.moveBullets(g->win);
		if (tick % 30 == 0)
			moveObject(enemies, MapObjectType.Enemy, maxEnemy);
		p.detectCollision(g->enemies);
		p.draw_player();
		wrefresh(g->win);
		tick++;
	}
}

void		Game::key_events(int key)
{
	switch(key)
	{
		case KEY_LEFT:
			player.move(map, -1, 0);
		case KEY_UP:
			player.move(map, 1, 0);
		case KEY_DOWN:
			player.move(map, 0, -1);
		case KEY_RIGHT:
			player.move(map, 0, 1);
		case ' ':
			shoot();
			break;
		case ESC:
			endwin();
			exit(0); ///ATTENTION
	}
}

void		Game::shoot() {
	for(int i = 0; i < maxMissiles; i++) {
		if (missiles[i] == NULL) {
			missiles[i] = spawnObject(MapObjectType.Bullet)
			return;
		}
	}
}

MapObject*	Game::moveObject(MapObject* list, MapObjectType type, int max) {
	for(int i = 0; i < max; i++) {
		MapObject obj = list[i];
		if (obj == NULL) {
			list[i] = spawnObject(type);
		} else if (!obj.alive) {
			delete obj;
			list[i] = spawnObject(type);
		} else {
			obj.move();
		}
	}
	return list;
}

void		Game::refresh() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			MapObject obj = map.get(i, j);
			char c;
			if (obj == NULL) {
				c = ' ';
			} else {
				c = obj.getSprite();
			}
			mvprintw(i, j, c);
		}
	}
}