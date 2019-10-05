Star::Star(int x, int y): super(MapObject::Star, x, y) {}

~Star() {}

void move(Map map) {
	if (map.get(this.x, this.y) == this) {
		map.set(this.x, this.y, NULL);
	}
	this.y++;
	if (this.y < map.h && map.get(this.x, this.y) == NULL) {
		map.set(this.x, this.y, this);
	}
}

char Star::getSprite() {
	return '.';
}
