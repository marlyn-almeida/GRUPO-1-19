#pragma once
#pragma warning(disable : 4996)
#include <thread>
#include <iostream>
#include <Windows.h>
#include <string>
#include "Utils.h"

using namespace Utils;

class Marquee{
private:
	const char* content;
	int lenght;
	COORD coord = { 0,0 };
public:
	//Marquee() = default;
	Marquee(const char*, int);
	char* marquee(int);
	void print_to(int x, int y);
	void show();
	void animation();
};

/**
 * @brief constructor  
 * @param 

 */
Marquee::Marquee(const char* _content, int _lenght) {
	this->content = _content;
	this->lenght = _lenght;
}
/**
 * @brief genera marquesina  
 * @param display

 */
char* Marquee::marquee(int position) {
	// contador para caminar a través de la cadena
	int counter = 0; 
	//La pantallava a tener  17 caracteres de la frase + 1 del nulo
	char* display = (char*)malloc(sizeof(char) * (lenght + 1));
	//recorre la cadena por nosotros
	// Por ejemplo: "Hola" luego "ello" luego "llo H", etc.
	// 255 por los carateres ascii de la frase +1 del nulo=256
	char* travel = (char*)malloc(sizeof(char) * 256);
	//Este puntero es para concatenar la cadena que se mueve fuera de la pantalla hasta el final del recorrido.
	//Esto es necesario para el efecto de marquesina. * /
	// *Por ejemplo : "¡¡Hola mundo !!", luego "ello World !! H" luego "¡llo World !! He
	char* temp = (char*)malloc(sizeof(char) * (strlen(content) + 1));
	// *El viaje debe comenzar al principio de la cadena * /
	// *Por ejemplo : viajar = "¡¡Hola, mundo !!" * /
	Utils::String::strcpy(travel, content);
	//recorre la cadena
	while (counter < position) {
		///La primera letra de viaje debe ser igual a la temperatura 
		//Por ejemplo: 
		//Primera pasada : viaje[0] = 'H' temp[0] = 'H' 
		//Segundo pase : viaje[0] = 'e' temp[1] = 'e' 
		//Tercer pase : viaje[0] = 'l' temp[2] = 'l' 
		//etc ... 
		temp[counter] = travel[0];
		//camina por la cadena
		//Por ejemplo : viajar = "¡¡Hola, mundo !!", luego "¡¡Hola, mundo !!", luego "¡¡llo, mundo !!"  etc. * /
		travel++;
		//Incremento del contador para recorrer la cadena
		counter = counter + 1;
	}
	//agregamos nuloal final
	temp[counter + 1] = '\0';
	//Si no agregamos un espacio al final,
	//obtenemos un "ello, World !! H" en la siguiente línea * /
	Utils::String::strcat(travel, " ");
	//Segundo pase : "ello, World !! H" Tercer pase : "¡¡llo, World !! He", etc.* /
	Utils::String::strcat(travel, temp);
	// *Display = "Hola", luego "ello", luego "llo H", etc.* /
	Utils::String::strncpy(display, travel, lenght);
	//agregamos nulo al final
	display[lenght] = '\0';
	return display;
}
/**
 * @brief genera marquesina  
 * @param void

 */
void Marquee::show() {
	char* singboard;
	//bucle infinito
	while (1) {
		//Recorre toda la longitud de la cadena 
		for (int i = 0; i < lenght; i++) {
			// Obtener una cadena de 17 caracteres de la función de marquesina
			singboard = marquee(i);
			print_to(20, 1); 
			std::cout << singboard;
			print_to(27, 3);
			std::cout<< std::endl;
			//delete(singboard);
			Sleep(600);
			//system("@cls||clear");
		}
	}
}

/**
 * @brief genera coordenas marquesina  
 * @param void

 */
void Marquee::print_to(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	fflush(stdout);
}
/**
 * @brief genera animacion marquesina  
 * @param void

 */
void Marquee::animation() {
	std::thread first(&Marquee::show, this);
	//system("pause");
	fflush(stdout);
	//first.join();
	first.detach();
}
//void Marquee::print() {
//	int lenght = content.length();
//	while (1) {
//		const char* format = content.c_str();
//		for (int i = 0; i < lenght; i++) {
//			char dest[1024 * 16];
//			va_list argptr;
//			va_start(argptr, format);
//			vsprintf(dest, format, argptr);
//			va_end(argptr);
//			printf("\n");
//		}
//	}
//}
