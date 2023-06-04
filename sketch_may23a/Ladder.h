#ifndef DK_REPO_LADDER_H
#define DK_REPO_LADDER_H

class Ladder
{
private:
	int x;
	int y;
	int height;
	int width;
public:
	Ladder(int ladX, int ladY, int ladWidth, int ladHeight);
	void draw();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
};

Ladder::Ladder(int ladX, int ladY, int ladWidth, int ladHeight) : x(ladX), y(ladY), width(ladWidth), height(ladHeight) {}

void Ladder::draw() {
	gb.display.setColor(WHITE);
	gb.display.fillRect(x, y, width, height);
}

int Ladder::getX() {
	return x;
}
int Ladder::getY() {
	return y;
}
int Ladder::getWidth() {
	return width;
}
int Ladder::getHeight() {
	return height;
}

#endif // !DK_REPO_LADDER_H