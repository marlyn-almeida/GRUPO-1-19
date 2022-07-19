// Proyecto.cpp: define el punto de entrada de la aplicacion.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
#include "Menus.h"
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
#include "Utils.h"
#include "Marquee.h"
#include "Options.h"
//#include "Imagen.h"


using namespace std;

int main()
{
	
	
	//Marquesina
	
	std::string marqueeText = "GRUPO 1 - GRUPO 9 - PROYECTO #2  ";
	std::thread t2(marquee, marqueeText);
	t2.detach();
	
	//imagen
//===================== quitar los // para que imprima imagen
//	hConWnd = GetConsoleWndHandle();
//	if (hConWnd) {
//			//nombre de la imagen, handle, ID, ubicacion x, ubicacio Y, ancho, altura,0 ajuste auyomatico
//			BCX_Bitmap("logo.bmp", hConWnd, 201, 160, 60, 0, 0);
//			Sleep(5555);		
//		}
//=======================
	
	
//	delete hConWnd;
	
	//Loguin
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("admi");
    // Se añaden claves al vector
    claves.push_back("123");
    
    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do{
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);
        char caracter;
        cout << "\tPassword: ";
        caracter = getch();
        password = "";
        while (caracter != ENTER){
            if (caracter != BACKSPACE){
                password.push_back(caracter);
                cout << "*";
            }
            else{
                if (password.length() > 0){
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++){
            if (usuarios[i] == usuario && claves[i] == password){
                ingresa = true;
                break;
            }
        }

        if (!ingresa){
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false){
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else{
        cout << "\n\n\tBienvenido al sistema" << endl;
        Menus menu_Principal;
		int tam = 0;
    	string opciones[] = { "Insertar valor en el arbol",
                          	   "Buscar valor en el arbol",
                               "Eliminar valor en el arbol",
                               "Extra:Foto ",
                               "Extra:Generar Reporte ",
                               "Salir",};
   		 menu_Principal.menuTeclas(opciones, 6, tam);			
    }
    
//	system("cls");
    cin.get();
    return 0;
}
