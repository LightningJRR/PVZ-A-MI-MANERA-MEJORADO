#pragma once
#include "Character.h"
#include "Pared.h"
#include <vector>
using namespace System::Drawing;
using namespace std;

class Jugador : public Character {
private:
	int hp;
	int indexRec;
public:
	Jugador(int width, int height) : Character(width, height) {
		x = 0;
		y = 100;
		dx = dy = 5;
		idx = 0;
		idy = 3;
		hp = 4;
		indexRec = -1;
	}

	~Jugador() {}

	int gethp() { return hp; }
	int bajarhp() { return hp--; }

	void move(Graphics^ g, char i, vector<Pared*> obstacles) {
		switch (i)
		{
		case 'A':
			idy = 1;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangleChoque(x - dx, y).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (x > 0 && !this->getRectangleChoque(x - dx, y).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					x -= dx;
				}
			}
			else {
				if (x > 0) {
					x -= dx;
				}
			}
			break;

		case 'D':
			idy = 2;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangleChoque(x + dx, y).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (x + width * 1.0 < g->VisibleClipBounds.Width && !this->getRectangleChoque(x + dx, y).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					x += dx;
				}
			}
			else {
				if (x + width * 1.0 < g->VisibleClipBounds.Width) {
					x += dx;
				}
			}
			break;

		case 'W':
			idy = 3;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangleChoque(x, y - dy).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (y > 0 && !this->getRectangleChoque(x, y - dy).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					y -= dy;
				}
			}
			else {
				if (y > 0) {
					y -= dy;
				}
			}
			break;

		case 'S':
			idy = 0;
			for (int i = 0; i < obstacles.size(); i++) {
				if (this->getRectangleChoque(x, y + dy).IntersectsWith(obstacles[i]->getRectangle())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (y + height * 1.0 < g->VisibleClipBounds.Height && !this->getRectangleChoque(x, y + dy).IntersectsWith(obstacles[indexRec]->getRectangle())) {
					y += dy;
				}
			}
			else {
				if (y + height * 1.0 < g->VisibleClipBounds.Height) {
					y += dy;
				}
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}

};

