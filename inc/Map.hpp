/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 10:53:17 by dstepane          #+#    #+#             */
/*   Updated: 2019/06/30 10:53:19 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "main.hpp"

class Map;

# include "MapObject.hpp"

class					Map
{
	public:
		Map(int h, int w);
		~Map(void);

		MapObject*		get(int x, int y);
		void			set(int x, int y, MapObject *obj);

	private:
		Map(Map const &src);
		Map &	operator = (const Map &rhs);

		MapObject		field[MAPH][MAPW];
};

#endif
