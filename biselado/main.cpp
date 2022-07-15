// Proyecto.cpp: define el punto de entrada de la aplicacion.
//
#include "Menus.h"
#include <iostream>

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;

int main()
{
	Menus menu_Principal;
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("admi");


    // Se añaden claves al vector
    claves.push_back("123");


    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
        Menus menu_Principal;
        int tam = 0;
        string opciones[] = { "Agregar Informacion del Usuario",
                          "Buscar Informacion",
                          "Mostrar Reporte De un Usuario",
                          " ",
                          " ",
                          " ",
                          "Salir",};
       menu_Principal.menuTeclas(opciones, 7, tam);
	
    }

    cin.get();

    return 0;
}


