#include "Funciones.h"

void main(void){  // Void = Vacío  =>  int main(void) = int main()
	srand (time(NULL)); //Basado en la hora del ordenador.
	printf("Bienvenido a Buscaminas! \n");
	RecibirVariables();
	ConfirmarDatos();
	if(r == 'S' || r == 's'){ // Se restringirá a dos intentos.
			PrimeraJugada();
	}
	else{
			printf("Por favor vuelva a ingresar los datos\n");
			ConfirmarDatos(&r);
			if(r == 'S' || r == 's'){
				PrimeraJugada();

			}
			else{
				printf("Lo lamento humano, todas las minas explotaron y has perdido\n");
			}
	}
	return;
}
