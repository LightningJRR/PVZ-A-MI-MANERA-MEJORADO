#pragma once
#include <iostream>

using namespace	System::Drawing;

class Character {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idx, idy;
	bool visible;
public:
	Character(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true;
	}

	~Character() {}
	int getX() { return x; }
	int getY() { return y; }
	int xancho() { return x + width * 1.0; }
	int yalto() { return y + height * 1.0; }
	int getdX() { return dx; }
	int getdY() { return dy; }
	int getIDX() { return idx; }
	int getIDY() { return idy; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setdX(int dx) { this->dx = dx; }
	void setdY(int dy) { this->dy = dy; }
	void setIDX(int idx) { this->idx = idx; }
	void setIDY(int idy) { this->idy = idy; }
	bool getVisible() { return visible; }

	void setVisible(bool visible) { this->visible = visible; }

	void draw(Graphics^ g, Bitmap^ bmp) {
		//Pen^ p = gcnew Pen(Color::Red, 3);
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		//g->DrawRectangle(p, x, y, width, height);
	}

	virtual void move() {}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

	Rectangle getRectangleChoque(int x, int y) {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}
};
