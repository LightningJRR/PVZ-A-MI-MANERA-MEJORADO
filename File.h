#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Pared.h";

using namespace std;
using namespace System;

class File {
private:
	ofstream salida;
	ifstream entrada;
	string text;
	int size; // S => Tiempo para que aparezca un impostor
	int x;
	int y;
	int width;
	int height;
public:
	File(vector<Pared*>& pared) {
		leer(pared);
	}
	void leer(vector<Pared*>& pared) {
		entrada.open("posiciones.txt", ios::in);
		if (entrada.fail()) {
			entrada.close();
			salida.open("posiciones.txt", ios::out);
			salida << "4" << endl;
			salida << "300" << endl;
			salida << "400" << endl;
			salida << "48" << endl;
			salida << "44" << endl;
			salida << "200" << endl;
			salida << "100" << endl;
			salida << "48" << endl;
			salida << "44" << endl;
			salida << "300" << endl;
			salida << "250" << endl;
			salida << "48" << endl;
			salida << "44" << endl;
			salida << "20" << endl;
			salida << "250" << endl;
			salida << "48" << endl;
			salida << "44" << endl;
			salida.close();
			entrada.open("posiciones.txt", ios::in);
		}
		getline(entrada, text);
		size = stoi(text);
		for (int i = 0; i < size; i++) {
			getline(entrada, text);
			x = stoi(text);
			getline(entrada, text);
			y = stoi(text);
			getline(entrada, text);
			width = stoi(text);
			getline(entrada, text);
			height = stoi(text);
			pared.push_back(new Pared(x, y, width, height));
		}

		entrada.close();
	}
};
