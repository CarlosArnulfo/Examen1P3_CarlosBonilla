#include "Soldado.h"

Soldado::Soldado(string tipo,int danio, int velocidad,double fuerza, double salud,string ataque1,string ataque2, int const1,int const2 ) {
	m_tipo = tipo;
	m_danio = danio;
	m_velocidad = velocidad;
	m_salud = salud;
	m_fuerza = fuerza;
	m_ataque1 = ataque1;
	m_ataque2 = ataque2;
	m_const1 = const1;
	m_const2 = const2;
}
void Soldado::setSalud(double saludNueva) {
	m_salud = saludNueva;
}
string Soldado::getTipo(){
	return m_tipo;
}
int Soldado::getDanio() {
	return m_danio;
}
int Soldado::getVelocidad() {
	return m_velocidad;
}
double Soldado::getFuerza() {
	return m_fuerza;
}
double Soldado::getSalud() {
	return m_salud;
}
string Soldado::getAtaque1() {
	return m_ataque1;
}
string Soldado::getAtaque2() {
	return m_ataque2;
}
int Soldado::getConst1() {
	return m_const1;
}
int Soldado::getConst2() {
	return m_const2;
}
Soldado::~Soldado() {
	m_tipo = " ";
	m_danio = 0;
	m_velocidad = 0;
	m_salud = 0;
	m_fuerza = 0;
	m_ataque1 = " ";
	m_ataque2 = " ";
}