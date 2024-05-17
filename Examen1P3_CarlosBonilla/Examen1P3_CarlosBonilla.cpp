
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include "Soldado.h"
#include <vector>
using namespace std;

void MostrarSoldado(Soldado *soldado,int num) {
	cout << "Soldado #" << num << endl;
	cout << "tipo: " << soldado->getTipo() << endl;
	cout << "danio: " << soldado->getDanio() << endl;
	cout << "velocidad: " << soldado->getVelocidad() << endl;
	cout << "fuerza: " << soldado->getFuerza() * 10 << "%" << endl;
	cout << "salud: " << soldado->getSalud() << endl;
	cout << "ataque 1: " << soldado->getAtaque1() << endl;
	cout << "ataque 2: " << soldado->getAtaque2() << endl << endl << endl;
}
void batallaDeSoldados(Soldado *soldado1, Soldado *soldado2) {//impresor de la batalla
	int danio1atkp1 = (soldado1->getDanio() + soldado1->getVelocidad()) + soldado1->getConst1();
	int danio2atkp1 = (soldado1->getDanio() + soldado1->getVelocidad()) + soldado1->getConst2();
	double daniop1 = double((danio1atkp1 + danio2atkp1)) * soldado1->getFuerza();
	int danio1atkp2 = (soldado2->getDanio() + soldado2->getVelocidad()) + soldado2->getConst1();
	int danio2atkp2 = (soldado2->getDanio() + soldado2->getVelocidad()) + soldado2->getConst2();
	double daniop2 = double((danio1atkp2 + danio2atkp2)) * soldado1->getFuerza();
	do
	{
		cout << "soldado " << soldado1->getTipo() << " a usado " << soldado1->getAtaque1() << ": " <<danio1atkp1 <<endl ;
		cout << "seguido de " << soldado1->getAtaque2() << ": " <<danio2atkp1 <<endl ;
		cout << "Ataque total de soldado " << soldado1->getTipo() << ": " << daniop1<<endl;
		soldado2->setSalud(soldado2->getSalud()- daniop1);
		if (soldado2->getSalud()<=0)
		{
			soldado2->setSalud(0);
		}
		cout << "Salud Actual del soldado " << soldado2->getTipo()<<": "<<soldado2->getSalud()<<endl<<endl;
		if (soldado2->getSalud() <= 0)
		{
			break;
		}
		cout << "soldado " << soldado2->getTipo() << " a usado " << soldado2->getAtaque1() << ": " << danio1atkp2 << endl;
		cout << "seguido de " << soldado2->getAtaque2() << ": " << danio2atkp2 << endl;
		cout << "Ataque total de soldado " << soldado2->getTipo() << ": " << daniop2<<endl;
		soldado1->setSalud(soldado1->getSalud() - daniop1);
		if (soldado1->getSalud() <= 0)
		{
			soldado1->setSalud(0);
		}
		cout << "Salud Actual del soldado " << soldado1->getTipo() << ": " << soldado1->getSalud() << endl << endl;
		if (soldado1->getSalud() <= 0)
		{
			break;
		}
	} while (soldado1->getSalud()>0 && soldado2->getSalud()>0);

	if (soldado1->getSalud() == 0)
	{
		cout << "Ha ganado el soldado " << soldado1->getTipo() << endl;
	}
	else
	{
		cout << "Ha ganado el soldado " << soldado2->getTipo() << endl;
	}
	cout << endl;
}

void CrearSoldadoAleatorio(Soldado *&soldado) {//creador de soldados usando funciones de aleatoriedad
	
	int tipo= (rand() % 3) + 1;
	string type = " ";
	int danio = 1;
	int velocidad = 1;
	double fuerza =1;
	string ataque1 = " ";
	string ataque2=" ";
	int const1 = 0;
	int const2 = 0;
	soldado = new Soldado(type, danio, velocidad, fuerza, 100, ataque1, ataque2,const1,const2);
	if (tipo == 1)
	{
		type = "Marine";
		danio = (rand() % 15) + 12;
		velocidad = (rand() % 10) + 8;
		fuerza = double((rand() % 65) + 45) * 0.1;
		ataque1 = "Bola de Fuego";
		ataque2 = "Volcan";
		const1 = 10;
		const2 = 5;
	}
	else if(tipo==2){
		type = "Naval";
	danio = (rand() % 15) + 10;
	velocidad = (rand() % 10) + 5;
	fuerza = double((rand() % 6) + 4) * 0.1;
	ataque1 = "Avalancha";
	ataque2 = "Tsunami"; (tipo == 2);
	const1 = 8;
	const2 = 12;
	}
	else {
		type = "Army";
		danio = (rand() % 15) + 8;
		velocidad = double((rand() % 10) + 3);
		fuerza = double((rand() % 5) + 3)*0.1;
		ataque1 = "Contaminacion";
		ataque2 = "Derrumbe";
		const1 = 7;
		const2 = 15;
	}
	soldado = new Soldado(type, danio, velocidad,fuerza, 100, ataque1, ataque2,const1,const2);
}

void menu() {//menu principal
	Soldado *soldado1 = new Soldado("type", 9, 9, 9, 101, " ", " ",0,0);
	Soldado *soldado2 = new Soldado("type", 9, 9, 9, 101, " ", " ",0,0);
	srand((unsigned)time(0));
	int menu = 0;
	do
	{
		cout << "1. Crear Soldados" << endl;
		cout << "2. Listar Soldados" << endl;
		cout << "3. Batalla de Soldados" << endl;
		cout << "4. Salir" << endl;
		cin >> menu;
		cout << endl;
		if (menu==1)
		{
			CrearSoldadoAleatorio(soldado1);
			CrearSoldadoAleatorio(soldado2);
			cout << endl << "Nuevo recruta " << soldado1->getTipo() << " creado"<<endl;
			cout << endl << "Nuevo recruta " << soldado2->getTipo() << " creado" << endl<<endl;
		}
		else if (menu == 2) {
			if (soldado1->getSalud()>100){}
			else {
				MostrarSoldado(soldado1, 1);
			}
			if (soldado2->getSalud() > 100) {}
			else {
				MostrarSoldado(soldado2, 2);
			}
			
		}
		else if (menu == 3) {
			batallaDeSoldados(soldado1, soldado2);
			CrearSoldadoAleatorio(soldado1);
			CrearSoldadoAleatorio(soldado2);
			cout << endl << "Nuevo recluta " << soldado1->getTipo() << " creado" << endl;
			cout << endl << "Nuevo recluta " << soldado2->getTipo() << " creado" << endl << endl;
		}
		else if (menu == 4) {
			cout << "Gracias por jugar!" << endl;
		}
		else{
			cout << "elija una opcion valida"<<endl;
		}

	} while (menu!=4);
}
int main()
{
	menu();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
