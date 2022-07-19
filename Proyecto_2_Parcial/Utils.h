#pragma once
#include <iostream>
#include <conio.h>
#include<cstring>
#include <math.h>
#include <string>
#include <vector>
#include <random>

namespace Utils {
	class Validation
	{
	public:
		//numbers o.o
		static bool isNumericChar(char);
		static int atoi(char*);
		static int* data_expand(int, int*);
		static int lenght(int);
		static int random_numbers(int, int);
		static int lenght_array(int*);
		static int summation_array(int*);

		//template <typename T>
		//static T summation_array(T*);
		


		//string uwu
		static int lenght_char(char*);
		static int lenght_str(std::string);
		static std::string* split(std::string, std::string[], std::string);
		static std::string upper(std::string);
		static std::string lower(std::string);
		
		//comprobation / evalue :·)
		static void integer(char*, int);
		static void natural_numbers(char*, int);
		static void letters(char*, int);
		static int input_number(int);
		static std::string input_phone(int);
		static bool phone_validation(int, int);
		static int comprobation_values(int, int, int);



	};
	class String {
	public:
		static char* strcpy(char*, const char*);
		static char* strcat(char*, const char*);
		static char* strncpy(char*, const char*, size_t);
	};

	class Math {
	public:
		//Funciones
		static double factorial(double);
		static double pow(double, int);
		static double pi(int number = 99);
		static double radians(double);
		static double sqrt(float);

		//Funciones trigonométricas
		//static double sin(double);
		//static double cos(double);
		//static double tan(double);
		//static double cot(double);
		//static double sec(double);
		//static double csc(double);

		//min max
		template <typename T>
		static T max(T, T);

		template <typename T>
		static T min(T, T);

		//float owo
		static float avarage(int[]);
	};

	template<typename T>
	T Math::max(T num1, T num2) {
		return (num1 > num2 ? num1 : num2);
	}

	template<typename T>
	T Math::min(T num1, T num2) {
		return (num1 < num2 ? num1 : num2);
	}

}
