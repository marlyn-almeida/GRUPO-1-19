#include <iostream>
#include <Windows.h>
#include <string>


using namespace std;

class Marquee {
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

Marquee::Marquee(const char* _content, int _lenght) {
	this->content = _content;
	this->lenght = _lenght;
}

char* Marquee::marquee(int position) {
	int counter = 0; 
	char* display = (char*)malloc(sizeof(char) * (lenght + 1));
	char* travel = (char*)malloc(sizeof(char) * 256);
	char* temp = (char*)malloc(sizeof(char) * (strlen(content) + 1));
	strcpy(travel, content);
	while (counter < position) {
		temp[counter] = travel[0];
		travel++;
		counter = counter + 1;
	}
	temp[counter + 1] = '\0';
	strcat(travel, " ");
	strcat(travel, temp);
	strncpy(display, travel, lenght);
	display[lenght] = '\0';
	return display;
}

void Marquee::show() {
	char* singboard;
	while (1) {
		for (int i = 0; i < lenght; i++) {
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

void Marquee::print_to(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	fflush(stdout);
}

void Marquee::animation() {
	first(&Marquee::show, this);
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
