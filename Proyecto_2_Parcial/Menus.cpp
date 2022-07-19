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
	void Menus::menuTeclas(string opciones[], int num, int tam/*, ListaPerson lista,	ListaCircularDoble lis_a*/ )
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
		
		
		
	    string orden = "\n\n\n\t\t======Arbol =======\n";
	    int cursor = menu(opciones, orden, num, tam);
	    int op, nod = 0, x = 0;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	    switch (cursor){
	    case 0: { //Ingresar informacion
	        system("cls");
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        cout<<"\n\tInsertar valor en el arbol\n"<<endl;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        
	        //TODO
	        
	        system("pause");
	        //menuTeclas(opciones, num, tam, lista, lis_a);
	        
	    } break;
	    case 1: {//Buscar informacion por placa
	        system("cls");
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        cout<<"\n\t\tBuscar valor en el arbol\n"<<endl;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        
	        //TODO
	        
	       	printf("pause");
	        //menuTeclas(opciones, num, tam, lista, lis_a);
	        break;
	    }
	    case 2: {//Imprimir Todo el reporte
	        system("cls");
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        cout<<"\n\t\tEliminar valor en el arbol\n"<<endl;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        system("\npause");
	        system("cls");
	        //TODO
	        
			system("\npause");
	        //menuTeclas(opciones, num, tam, lista, lis_a);
	        break;
		}
	    case 3: {//Eliminar  un reporte
	        system("cls");
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        cout<<"\n\t\tExtra:Foto\n"<<endl;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        
	        //C:\Users\George\Desktop\Proyecto_2_Parcial\App_Imag
	        system("C:\\Users\\George\\Desktop\\Proyecto_2_Parcial\\Proyecto_1.exe");
			
			system("pause");
	    	menuTeclas(opciones, num, tam/*, lista, lis_a*/);
	        break;
		}
		case 4: {//Salir
	        system("cls");
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        cout<<"\n\t\tExtra:Generar Reporte\n"<<endl;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        
	        //TODO
	        
	        
	        system("pause");
			//menuTeclas(opciones, num, tam, lista, lis_a);
	        break;
		}
	    case 5: {//Salir
	        system("cls");
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        cout<<"\n\t\t...Gracias por usar mi programa...\n"<<endl;
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        system("pause");
	        exit(1);
	        break;
	
	    }
	
	}
}
