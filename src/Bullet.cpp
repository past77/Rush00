Bullet::Bullet(int x, int y): super(MapObject::Bullet, x, y) {}

Bullet::~Bullet() {}

void move(Map map) {
	MapObject *obj = map.get(this.x, this.y);
	if (map.get(this.x, this.y) == this) {
		map.set(this.x, this.y, NULL);
	}
	this.y--;
	if (this.y > 0) {
		obj = map.get(this.x, this.y);
		if (obj.type != MapObjectType.Player) {
			obj.alive = false;
			map.set(this.x, this.y, this);
		} else {
			this.alive = false;
		}
	} else {
		this.alive = false;
	}
}

char Bullet::getSprite() {
	return '!';
}
