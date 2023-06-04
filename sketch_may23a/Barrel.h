#ifndef DK_REPO_BARREL_H
#define DK_REPO_BARREL_H

class Barrel
{
private:
	int barrelSize;
	int barrelPosX;
	int barrelPosY;
	int barrelSpeed;
	int barrelTimeOffset;
public:
	Barrel(int barrelSize, int barrelPosX, int barrelPosY, int barrelSpeed, int barrelTimeOffset);
	void draw();
	void update();
	int getX();
	int getY();
	int getSize();
	int getSpeed();
	void setX(int x);
	void setY(int y);
};

Barrel::Barrel(int barrelSize, int barrelPosX, int barrelPosY, int barrelSpeed, int barrelTimeOffset) : barrelPosX(barrelPosX), barrelPosY(barrelPosY), barrelSize(barrelSize), barrelSpeed(barrelSpeed), barrelTimeOffset(barrelTimeOffset) {}

void Barrel::draw() {
	gb.display.setColor(BROWN);
	gb.display.fillRect(barrelPosX, barrelPosY, barrelSize, barrelSize);
}

void Barrel::update() {
	if (barrelTimeOffset > 0) {
		barrelTimeOffset--;
	}
	else {
		barrelPosY += barrelSpeed;
		if (barrelPosY > 63) {
			barrelPosY = 0;
		}
	}
}

int Barrel::getX() {
	return barrelPosX;
}

int Barrel::getY() {
	return barrelPosY;
}

int Barrel::getSize() {
	return barrelSize;
}

int Barrel::getSpeed() {
	return barrelSpeed;
}

void Barrel::setX(int x) {
	barrelPosX = x;
}

void Barrel::setY(int y) {
	barrelPosY = y;
}

#endif // !DK_REPO_BARREL_H