#pragma once
#include "Character.h"
#include "Jugador.h"

class Planta : public Character {
private:
	int type;
public:
	Planta(int width, int height, int type) : Character(width, height) {
		this->type = type;
		x = rand() % 300 + 1;
		y = rand() % 30 * 10;
		dx = dy = -10;
	}
	~Planta() {}

	void move(Graphics^ g, Jugador* juga) {
		int r = rand() % 4;
		switch (type)
		{
		case 0:
			idx = 0;
			idy = 0;
			break;
		case 1:
			idx = 1;
			idy = 0;
			break;
		case 2:
			idx = 2;
			idy = 0;
			break;
		case 3:
			idx = 3;
			idy = 0;
			break;
		case 4:
			idx = 4;
			idy = 0;
			break;
		case 5:
			idx = 5;
			idy = 0;
			break;
		case 6:
			idx = 6;
			idy = 0;
			break;
		case 7:
			idx = 7;
			idy = 0;
			break;
		}
		if (x + dx <0 || x + dx + width * 1.0 > g->VisibleClipBounds.Width) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + height * 1.0 > g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
		/* RANDOM
		dx = 10;
		dy = 10;
		switch (r)
		{
		case 0:
			if (x > 0) {
				x -= dx;
				idy = 0;
			}
			break;

		case 1:
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 0;
			}
			break;

		case 2:
			if (y > 0) {
				y -= dy;
				idy = 0;
			}
			break;

		case 3:
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
			break;
		}*/
	}
};


