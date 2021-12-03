#pragma once
#include "Jugador.h"
#include "Pared.h"
#include "Planta.h"
#include "Star.h"
#include "File.h"
#include <vector>
#include <ctime>

using namespace std;

class Controller {
private:
	Jugador* player;
	vector<Pared*>par;
	vector<Planta*>planta;
	vector<Star*>star;
	time_t buff;
	bool velocidad;
	bool invencible;
	time_t tiempo = time(0);
	File* file;
public:
	Controller(Bitmap^ juga, Bitmap^ pared, Bitmap^ plant, Bitmap^ star){
		velocidad = false;
		invencible = false;
		player = new Jugador(juga->Width / 4, juga->Height / 4);
		for (int i = 0;i < 2;i++) {
			agregarPlanta(plant);
		}
		for (int i = 0;i <5;i++) {
			agregarStar(star);
		}
		file = new File(par);
	}

	~Controller() {}


	void agregarPared(Bitmap^ pared) {
		par.push_back(new Pared(rand()%500+100, rand()%300+50, pared->Width, pared->Height));
	}

	void agregarPlanta(Bitmap^ plant) {
		int r = rand() % 8;
		planta.push_back(new Planta(89, 96, r));
	}

	void agregarStar(Bitmap^ st) {
		star.push_back(new Star(st->Width,st->Height));
	}

	void drawEverything(Graphics^ g, Bitmap^ juga, Bitmap^ pared, Bitmap^ plant, Bitmap^ st) {
		player->draw(g, juga);
		for (int i = 0;i < par.size();i++) {
			par[i]->draw(g, pared);
		}
		for (int i = 0;i < planta.size();i++) {
			planta[i]->draw(g, plant);
		}
		for (int i = 0;i < star.size();i++) {
			star[i]->drawStar(g, st);
		}
	}

	void moveEverything(Graphics^ g, Jugador* player) {
		for (int i = 0;i < planta.size();i++) {
			planta[i]->move(g, player);
		}
	}

	void unbuff() {
		if (velocidad) {
			player->setdX(10);
			player->setdY(10);
			invencible = true;
			if (difftime(time(0), buff) > 5) {
				velocidad = false;
				invencible = false;
			}
		}
		else if (!velocidad) {
			player->setdX(5);
			player->setdY(5);
		}
	}

	void colision() {
		for (int i = 0;i < planta.size();i++) {
			if (player->getRectangle().IntersectsWith(planta[i]->getRectangle()) && this->invencible==false) {
				player->setX(0);
				player->setY(0);
				player->bajarhp();
			}
		}

		for (int i = 0;i < star.size();i++) {
			if (player->getRectangle().IntersectsWith(star[i]->getRectangleStar())) {
				star.erase(star.begin() + (i));
				velocidad = true;
				buff = time(0);
			}
		}
		unbuff();
	}

	Jugador* getplayer() { return player; }
	vector<Pared*> getMyRectangles() { return par; }
	bool getVelocidad() { return velocidad; }
	bool getInvencible() { return invencible; }

};