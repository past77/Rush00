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

Map::Map(int w, int h): w(w), h(h), field(new MapObject*[w]) {
	for (int i = 0; i < w; ++i) {
		field[i] = new MapObject[h];
	}
}

Map::~Map() {
	for (int i = 0; i < w; ++i) {
		delete[] field[i];
	}
	delete[] field;
}

MapObject*		Map::get(int x, int y) {
	if (x < w && y < h) {
		return field[x][y];
	} else {
		return NULL;
	}
}
void			set(int x, int y, MapObject *obj);
