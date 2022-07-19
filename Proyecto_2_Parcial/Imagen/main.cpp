#include <iostream>
#include "Imagen.h"

using namespace std;


int main() {
	hConWnd = GetConsoleWndHandle();
	if (hConWnd) {
			//nombre de la imagen, handle, ID, ubicacion x, ubicacio Y, ancho, altura,0 ajuste auyomatico
			BCX_Bitmap("logo.bmp", hConWnd, 201, 160, 60, 0, 0);
			Sleep(5557);		
		}
	//delete hConWnd;
	system("pause");
	return 0;
}

