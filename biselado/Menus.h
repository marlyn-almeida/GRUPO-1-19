#include "Menus.h"

/**
 * @brief Menu de opciones del programa utilizando el teclado para desplazarse
 * @param opciones Arreglo de mensajes para mostrar en pantalla las opciones
 * @param persona Arreglo de tipo Persona donde se encuentran los atributos
 * @param num Numero de opciones
 * @param cont Contador
 */
int Menus::menu(string opciones[], string orden, int num, int tam)
{
    int cursor = 0;
	char tecla;
	int opcion;
	system("cls");
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << orden << endl;
		for (int i = 0; i < num; i++){
			if (cursor == i){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t> " <<opciones[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				cout << "\t\t" <<opciones[i] << endl;
			}
		}
		for (;;){
			tecla = _getch();
			if (tecla == 80){
				cursor++;
				if (cursor == num){
					cursor = 0;
				}
				break;
			}
			if (tecla == 72){
				cursor--;
				if (cursor == -1){
					cursor = num-1;
				}
				break;
			}
			if (tecla == 13){
			    return cursor;
			}
		}
	}
}

/**
 * @brief Menu para seleccion de opciones
 * @param opciones Arreglo de mensajes para mostrar en pantalla las opciones
 * @param persona Arreglo de tipo Persona donde se encuentran los atributos
 * @param num Numero de opciones
 * @param cont Contador
 */
void Menus::menuTeclas(string opciones[], int num, int tam)
{
	typedef int (WINAPI *Validar_int_P)(char*);//Tipo de dato que ingresa, tipo de dato que sale
	typedef int (WINAPI *Validar_int_NP)(char*);
	typedef float (WINAPI *Validar_float)(char*);
	typedef float (WINAPI *Validar_float_N)(char*);
	typedef char* (WINAPI *Validar_char)(char*);
	typedef string (WINAPI *Validar_string)(char*);
	typedef char* (WINAPI *Validar_char_Num)(char*);
	
	Validar_int_P validar_int_P;
	Validar_int_NP validar_int_NP;
	Validar_float validar_float;
	Validar_float_N validar_float_N;
	Validar_char validar_char;
	Validar_string validar_string;
	Validar_char_Num validar_char_Num;

	HINSTANCE libDLL=NULL;// inicializamos la libreria con Null
	libDLL = LoadLibrary ("Proyecto 1.dll"); //Cargamos la libreria

	validar_int_P=(Validar_int_P)GetProcAddress(libDLL,"ingresarDatos_Int_P");
	validar_int_NP=(Validar_int_NP)GetProcAddress(libDLL,"ingresarDatos_Int_N_P");
	validar_float_N=(Validar_float_N)GetProcAddress(libDLL,"ingresarDatos_Float_N");
	validar_float=(Validar_float)GetProcAddress(libDLL,"ingresarDatos_Float");
	validar_char=(Validar_char)GetProcAddress(libDLL,"ingresarDatos_Char");
	validar_string=(Validar_string)GetProcAddress(libDLL,"ingresarDatos_String");// Fin Validacion
	validar_char_Num=(Validar_char_Num)GetProcAddress(libDLL,"ingresarDatos_Num_Char");

	Persona person;
	List lista;
	//ListaDobleEnlazada<Persona> partes;
	
	
	
	
    string orden = "\t\t======ARBOL BISCELADO =======\n";
    int cursor = menu(opciones, orden, num, tam);
    int op, nod = 0, x = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    switch (cursor){
    case 0: //Agregar nodo al inicio
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\tAgregar Informacion del Usuario\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        
        person.setNombre(validar_char("\nNombre: "));
        person.setApellido(validar_char_Num("\n\nApellido: "));
        person.setDireccion(validar_string("\n\nDireccion: "));
        person.setTelefono(validar_int_P("\nTelefono: "));
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\tAgregar Informacion del Auto\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		
		person.setMarca(validar_char("\n\nMarca: "));
		person.setModelo(validar_char_Num("\n\nModelo: "));
		person.setColor(validar_char("\n\nColor: "));
		person.setKilometraje(validar_float("\n\nKilometraje: "));
		person.setAnio(validar_int_P("\n\nAnio: "));
		person.setPlaca(validar_char_Num("\n\nPlaca: "));
		
		lista->add_head(person.to_string());
        
        system("pause");
        menuTeclas(opciones, num, tam);
        
        break;
    case 1: 
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\t Buscar Informacion \n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        
        
        //lista.(validar_char_Num("\nIngrese la Placa del Vehiculo: "));
        
        system("pause");
        menuTeclas(opciones, num, tam);
        break;
    case 2: //Agregar nodo antes de un nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\t Mostrar Reporte Del Taller\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        
        //lista.print();
		
		system("pause");
        menuTeclas(opciones, num, tam);
        break;
    case 3: //Agregar nodo despues de un nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\t Eliminar Dato del Cliente \n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        
		
		
		system("pause");
        menuTeclas(opciones, num, tam);
        break;
    case 4://Eliminar primer nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\tEliminar Toda la Informacion\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        
        
    
        system("pause");
        menuTeclas(opciones, num, tam);
        break;
    case 5://Eliminar ultimo nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\tEliminar ultimo nodo\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
       
       
       
        system("pause");
        menuTeclas(opciones, num, tam);
        break;
    case 6://Eliminar un nodo X
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\tEliminar un nodo X\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        
    case 7:
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"\n\t\t...Gracias por usar mi programa...\n"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        exit(1);
        break;
    }
}
