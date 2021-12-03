#pragma once

using namespace System::Drawing;

class Pared {
private:
	int x, y;
	int width, height;
	int idx, idy;
public:

	Pared(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		idx = 0;
		idy = 0;
	}


	~Pared() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		//Pen^ p = gcnew Pen(Color::Red, 3);
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		//g->DrawRectangle(p, x, y, width, height);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width*1.0, height*1.0);
	}
};