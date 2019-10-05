Enemy::Enemy(int x, int y): super(MapObject::Enemy, x, y) {}

Enemy::~Enemy() {}

void move(Map map) {
	MapObject *obj = map.get(this.x, this.y);
	if (map.get(this.x, this.y) == this) {
		map.set(this.x, this.y, NULL);
	}
	this.x += (rand() % 2) ? 1 : -1;
	this.y++;
	if (this.y < map.h) {
		obj = map.get(this.x, this.y);
		if (obj.type == Star) {
			obj.alive = false;
			map.set(this.x, this.y, this);
		}
	} else {
		this.alive = false;
	}
}

char Star::getSprite() {
	return 'X';
}
