#include "Map.h"

enum MapObjectType {
	Star, Enemy, Player, Bullet
}

class MapObject
{
public:
	MapObject();
	~MapObject();

	virtual void move(Map map);
	virtual char getSprite();

	bool		alive;
	MapObjectType type;

private:
	int		x;
	int		y;
};
