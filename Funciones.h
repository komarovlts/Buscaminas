#include <stdio.h>
#include <stdlib.h>	// Uso de funciones srand() y rand(), para aleatoriedad.
#include <time.h> // Uso de la función time()


#ifndef _FUNCIONES_H
#define _FUNCIONES_H

int f,c,m,validador; 	//Variables globales.
	char r,jugada;
	char ** Matriz1;
	char ** Matriz2;

void RecibirVariables();

void ConfirmarDatos();

char** CrearMatriz1();

int ContadorMinas(int fila, int columna);

void Pistas(int fila, int columna, int count);

void ColocarPistas();

int CantidadMinas();

void ColocarMinas(int f, int c, int m);

int CantidadBlanco();

int DetGanador();

char** CrearMatriz2(int f, int c,int m);

void ValidadorEspacios(int fila, int columna);

void Abrir(int fila, int columna);

void Espacios(int fila, int columna);

int Errores(int fila, int columna);

void Jugadas();

void PrimeraJugada();

#endif
