#pragma once
#include "Character.h"
using namespace System::Drawing;

class Star:public Character {
public:
	Star(int width, int height):Character(width,height) {
		x = rand() % 600;
		y = rand() % 400;
		this->width = width;
		this->height = height;
		idx = 0;
		idy = 0;
	}

	void drawStar(Graphics^ g, Bitmap^ bmp) {
		//Pen^ p = gcnew Pen(Color::Red, 3);
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 0.5, height * 0.5);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		//g->DrawRectangle(p, x, y, width, height);
	}

	Rectangle getRectangleStar() {
		return Rectangle(x, y, width * 0.5, height * 0.5);
	}

	~Star() {}

};
