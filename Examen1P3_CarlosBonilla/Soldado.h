#pragma once
#include <iostream>
#include <string>
using namespace std;
class Soldado {
	string m_tipo;
	int m_danio;
	int m_velocidad;
	double m_fuerza;
	double m_salud;
	string m_ataque1;
	string m_ataque2;
	int m_const1;
	int m_const2;
public:
	Soldado(string tipo,int danio, int velocidad, double salud, double fuerza, string ataque1, string ataque2,int const1, int const2);
	~Soldado();
	void setSalud(double salud);
	string getTipo();
	int getDanio();
	int getVelocidad();
	double getFuerza();
	double getSalud();
	string getAtaque1();
	string getAtaque2();
	int getConst1();
	int getConst2();
};