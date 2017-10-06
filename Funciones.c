#include "Funciones.h"

void RecibirVariables(){
	//	scanf("%d %d %d", &f, &c, &m); // scanf servirá como input. Se usan tantos %d como variables se deseen requerir.
	//	En este caso separaremos el scanf() en tres para una mayor comodidad para el usuario.
	printf("Ingrese el numero de filas: \n");
	scanf("%d", &f);
	fflush( stdin ); // Limpia el Buffer del teclado.
	printf("Ingrese el numero de columnas: \n");
	scanf("%d", &c);
	fflush( stdin ); // Limpia el Buffer del teclado.
	printf("Ingrese la cantidad de minas que desea: \n");
	scanf("%d", &m);
	fflush( stdin ); // Limpia el Buffer del teclado.
	if(m >= (f*c)){
		printf("\n");
	   printf("Lo lamento, la cantidad de minas no puede superar la capacidad del tablero.\n");
	   printf("Ni tampoco cubrir la totalidad de este.\n");
	   printf("Vuelva a ingresar los datos.\n");
	   printf("\n");
	   RecibirVariables();
	}
	return;
}

void ConfirmarDatos(){ // Confirmación de datos.
	printf("El tablero de juego a generar tendra: \n");
	printf("Numero de Filas:%d \n",f);
	printf("Numero de Columnas:%d \n",c);
	printf("Numero de Minas:%d \n",m);
	printf("¿Desea continuar? \n      (S/n) \n");
	scanf(" %c", &r);
	printf("\n"); // Dejar más ordenado el tablero.
	printf("\n");
	return;
}

char** CrearMatriz1(){
	char i, j;
	/* Simbología:
	Espacios vacíos cubiertos = (char) 145
	Espacios vacíos descubiertos = Corchetes vacíos
	Espacios con Minas = *.
	Espacios con Banderas = X.
	Espacios con pistas = 1,2,3,4,5,6,7,8 (según sea correspondiente)

	Creamos una Matriz con las variables "f" y "c" de Fila y Columna respectivamente.
	int Matriz[f][c]; // Esto implica que f y c serán el tamaño máximo de la Fila o Columna, es decir, el largo de nuestro Array.
	Ejemplo de una Matriz de 0: f=3 & c=3;
		int MUsuario[3][3]
		Matriz[3][3]= {(0,0,0)
					      (0,0,0)
					      (0,0,0)}
	*/
	Matriz1= (char **)malloc(f * sizeof(char *));
	for (i = 0; i < f; ++i){
     	Matriz1[i] = (char *)malloc(c * sizeof(char));
		}
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			Matriz1[i][j]= (char) 169;
			printf("[ %c ]", Matriz1[i][j] );
			}
	printf("\n");
	}
	return Matriz1;
}

void ContadorMinas(int fila, int columna){
	int count = 0;
	if((f-1) == (fila-1) && (c-1) == (columna-1)){ // Extremo inferior derecho => Sólo hay Ar, I y DIS.
			if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
				count++;
			}
			if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
				count++;
			}
			if(Matriz2[fila-2][columna-2]=='*'){ //Diagonal Izquierda Superior.
				count++;
			}
		}
	if ((fila-1) == 0 && (columna-1) == 0){ // Extremo superior izquierdo => Sólo hay Ab,D,DDI.
			if(Matriz2[(f-1)][columna-1]=='*'){ //Abajo.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila][columna]=='*'){ //Diagonal Derecha Inferior.
				count++;
			}
		}
	if((fila-1) == 0 && (columna-1) == (c-1)){ // Extremo superior derecho => Sólo hay Ab, I, DII.
			if(Matriz2[fila][columna-1]=='*'){ //Abajo.
				count++;
			}
			if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
				count++;
			}
			if(Matriz2[fila][columna-2]=='*'){ //Diagonal Izquierda Inferior.
				count++;
			}
		}
	if((fila-1) == (f-1) && (columna-1) == 0){ // Extremo superior izquierdo => Sólo hay Ar, D, DDS.
			if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila-2][columna]=='*'){ //Diagonal Derecha Superior.
					count++;
			}

		}
	if((columna-1)<(c-1) && (columna-1)>0 && (f-1) == (fila-1)){
			//Recuadros Centrales Inferiores => Existe Ar,D,I,DIS y DDS.
			if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
				count++;
			}
			if(Matriz2[fila-2][columna-2]=='*'){ //Diagonal Izquierda Superior.
				count++;
			}
			if(Matriz2[fila-2][columna]=='*'){ //Diagonal Derecha Superior.
				count++;
			}
		}
	if((fila-1)<(f-1) && (fila-1)>0 && 0 == (columna-1)){
			//Recuadros Centrales Izquierda => Existe Ar,Ab,D,DDS y DDI.
			if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
				count++;
			}
			if(Matriz2[fila][columna-1]=='*'){ //Abajo.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila-2][columna]=='*'){ //Diagonal Derecha Superior.
				count++;
			}
			if(Matriz2[fila][columna]=='*'){ //Diagonal Derecha Inferior.
				count++;
			}
		}
	if((fila-1)<(f-1) && (fila-1)>0 && (c-1) == (columna-1)){
			//Recuadros Centrales Derecha => Existe Ar,Ab,I,DIS y DII.
			if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
				count++;
			}
			if(Matriz2[fila][columna-1]=='*'){ //Abajo.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila-2][columna-2]=='*'){ //Diagonal Izquierda Superior.
				count++;
			}
			if(Matriz2[fila][columna-2]=='*'){ //Diagonal Izquierda Inferior.
				count++;
			}
		}
	if((columna-1)<(c-1) && (columna-1)>0 && 0 == (fila-1)){
			//Recuadros Centrales Arriba => Existe Ab,I,D,DII y DDI.
			if(Matriz2[fila][columna-1]=='*'){ //Abajo.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
				count++;
			}
			if(Matriz2[fila][columna-2]=='*'){ //Diagonal Izquierda Inferior.
				count++;
			}
			if(Matriz2[fila][columna]=='*'){ //Diagonal Derecha Inferior.
				count++;
			}
		}
	if((columna-1)>0 && (fila-1)>0 && (columna-1)<(c-1) && (fila-1)<(f-1)){
			if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
				count++;
			}
			if(Matriz2[fila][columna-1]=='*'){ //Abajo.
				count++;
			}
			if(Matriz2[fila-1][columna]=='*'){ //Derecha.
				count++;
			}
			if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
				count++;
			}
			if(Matriz2[fila-2][columna-2]=='*'){ //Diagonal Izquierda Superior.
				count++;
			}
			if(Matriz2[fila][columna-2]=='*'){ //Diagonal Izquierda Inferior.
				count++;
			}
			if(Matriz2[fila-2][columna]=='*'){ //Diagonal Derecha Superior.
				count++;
			}
			if(Matriz2[fila][columna]=='*'){ //Diagonal Derecha Inferior.
				count++;
			}
		}
   return;
}

void Pistas(int fila, int columna, int count){
	if (count==1 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='1';
		}
	if (count==2 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='2';
		}
	if (count==3 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='3';
		}
	if (count==4 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='4';
		}
	if (count==5 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='5';
		}
	if (count==6 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='6';
		}
	if (count==7 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='7';
		}
	if (count==8 && Matriz2[fila-1][columna-1]!='*'){
			Matriz1[fila-1][columna-1]='8';
		}
	return;
}

void ColocarPistas(){
	int i,j;
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			if(Matriz1[i][j]==' '){
				int count = ContadorMinas((i+1),(j+1));
				Pistas((i+1),(j+1),count);
				}
			}
		}
   return;
}

int CantidadMinas(){ // Busca determinar número de minas en la Matriz.
	int i,j,minas=0;
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			if(Matriz2[i][j]=='*'){
				minas++;
				}
			}
		}
	return minas;
}

void ColocarMinas(int f, int c, int m){
	int minas = CantidadMinas();
	int i,ranFilas,ranColumnas;
	while(minas<m){
		ranFilas = rand () % f;  // Este está entre 0 y el numero de filas
		ranColumnas = rand () % c; // Este está entre 0 y el numero de columnas
		if(Matriz2[ranFilas][ranColumnas]!='*' && Matriz1[ranFilas][ranColumnas]!=' '){
			Matriz2[ranFilas][ranColumnas]='*'; // Insertará de manera random minas.
			minas = CantidadMinas();
		}
	}
	return;
}

int CantidadBlanco(){ // Busca determinar número de espacios en blanco
	int i, j, blanco;
	blanco = 0;
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			if(Matriz1[i][j]==' ' || Matriz1[i][j]=='1' || Matriz1[i][j]=='2' || Matriz1[i][j]=='3' || Matriz1[i][j]=='4' || Matriz1[i][j]=='5' || Matriz1[i][j]=='6' || Matriz1[i][j]=='7' || Matriz1[i][j]=='8'){
			// También debería ser factible el Matriz1[i][j]!= (char) 169;
			blanco++;
			}
		}
	}
	return blanco;
}

int DetGanador(){
	int minas = CantidadMinas();
	int blanco = CantidadBlanco();
	if((minas+blanco)==(f*c)){
		printf("¡Felicidades! \n¡Has ganado!\n");
		return 1;
	}
	else{
		return 0;
	}
}

char** CrearMatriz2(int f, int c,int m){ // Matriz con las minas incluidas.
	int i, j;
	Matriz2= (char **)malloc(f * sizeof(char *));
	for (i = 0; i < f; ++i){
     	Matriz2[i] = (char *)malloc(c * sizeof(char));
		}
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			Matriz2[i][j]= ' ';
		}
	}
	ColocarMinas(f,c,m);
	FILE* escribirArchivo;
	escribirArchivo=fopen("solucion.out","w");
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			fprintf(escribirArchivo,"[ %c ]", Matriz2[i][j] );
		}
		fprintf(escribirArchivo,"\n");
	}
	fclose(escribirArchivo);
	return Matriz2;
}

void ValidadorEspacios(int fila, int columna){ // Identifica que en los espacios en cruz del indicado hayan minas.
	validador = 0;
	if((f-1) == (fila-1) && (c-1) == (columna-1)){ // Esquina inferior derecha => Sólo hay Ar y I
		if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
			validador++;
		}
		if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
			validador++;
		}
	}
	if ((fila-1) == 0 && (columna-1) == 0){ // Esquina superior izquierda => Sólo hay Ab y D.
		if(Matriz2[fila][columna-1]=='*'){ //Abajo.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
		}
	if((fila-1) == 0 && (columna-1) == (c-1)){ // Esquina superior derecha => Sólo hay Ab y I.
		if(Matriz2[fila][columna-1]=='*'){ //Abajo.
			validador++;
		}
		if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
			validador++;
		}
	}
	if((fila-1) == (f-1) && (columna-1) == 0){ // Esquina superior izquierda => Sólo hay Ar, D, DDS.
		if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
	}
	if((columna-1)<(c-1) && (columna-1)>0 && (f-1) == (fila-1)){
		//Recuadros Centrales Inferiores => Existe Ar,D y I.
		if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
		if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
			validador++;
		}
	}
	if((fila-1)<(f-1) && (fila-1)>0 && 0 == (columna-1)){
		//Recuadros Centrales Izquierda => Existe Ar,Ab y D.
		if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
			validador++;
		}
		if(Matriz2[fila][columna-1]=='*'){ //Abajo.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
	}
	if((fila-1)<(f-1) && (fila-1)>0 && (c-1) == (columna-1)){
		//Recuadros Centrales Derecha => Existe Ar,Ab,I,DIS y DII.
		if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
			validador++;
		}
		if(Matriz2[fila][columna-1]=='*'){ //Abajo.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
	}
	if((columna-1)<(c-1) && (columna-1)>0 && 0 == (fila-1)){
		//Recuadros Centrales Arriba => Existe Ab,I y D.
		if(Matriz2[fila][columna-1]=='*'){ //Abajo.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
		if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
			validador++;
		}
	}
	if((columna-1)>0 && (fila-1)>0 && (columna-1)<(c-1) && (fila-1)<(f-1)){
		//Recuadros centrales de la Matriz.
		if(Matriz2[fila-2][columna-1]=='*'){ //Arriba.
			validador++;
		}
		if(Matriz2[fila][columna-1]=='*'){ //Abajo.
			validador++;
		}
		if(Matriz2[fila-1][columna]=='*'){ //Derecha.
			validador++;
		}
		if(Matriz2[fila-1][columna-2]=='*'){ //Izquierda.
			validador++;
		}
	}
	return;
}

void Abrir(int fila, int columna){
	ColocarPistas(); // 2 for y llamado a dos funciones (ambas son sólo if)
	if((f-1) == (fila-1) && (c-1) == (columna-1)){ // Esquina inferior derecha => Sólo hay Ar y I
		ValidadorEspacios((fila-2),(columna-1)); // Sólo if
		if(Matriz2[fila-2][columna-1] !='*' && validador == 0){
			Matriz1[fila-2][columna-1]=' '; //Arriba.
			ColocarPistas(); // 2 for y llamado a dos funciones (ambas son sólo if)
			Abrir((fila-2),(columna-1));
			}
		ValidadorEspacios((fila-1),(columna-2));
		if(Matriz2[fila-1][columna-2] !='*' && validador == 0){
			Matriz1[fila-1][columna-2]=' ';//Izquierda.
			ColocarPistas();
			Abrir((fila-1),(columna-2));
		}
	}
	if ((fila-1) == 0 && (columna-1) == 0){ // Esquina superior izquierda => Sólo hay Ab y D.
		ValidadorEspacios(fila,(columna-1));
		if(Matriz2[fila][columna-1] !='*' && validador == 0){
			Matriz1[fila][columna-1]=' '; //Abajo.
			ColocarPistas();
			Abrir((fila),(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] !='*' && validador == 0){
			Matriz1[fila-1][columna]=' ';//Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
	}
	if((fila-1) == 0 && (columna-1) == (c-1)){ // Esquina superior derecha => Sólo hay Ab y I.
		ValidadorEspacios(fila,(columna-1));
		if(Matriz2[fila][columna-1] !='*' && validador == 0){
			Matriz1[fila][columna-1]=' ';//Abajo.
			ColocarPistas();
			Abrir(fila,(columna-1));
			}
		ValidadorEspacios((fila-1),(columna-2));
		if(Matriz2[fila-1][columna-2] !='*' && validador == 0){
			Matriz1[fila-1][columna-2]=' '; //Izquierda.
			ColocarPistas();
			Abrir((fila-1),(columna-2));
		}
	}
	if((fila-1) == (f-1) && (columna-1) == 0){ // Esquina inferior izquierda => Sólo hay Ar y D.
		ValidadorEspacios((fila-2),(columna-1));
		if(Matriz2[fila-2][columna-1] !='*' && validador == 0){
			Matriz1[fila-2][columna-1]=' '; //Arriba.
			ColocarPistas();
			Abrir((fila-2),(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] !='*' && validador == 0){
			Matriz1[fila-1][columna]=' '; //Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
	}
	if((columna-1)<(c-1) && (columna-1)>0 && (f-1) == (fila-1)){ // Recuadros Centrales Inferiores => Existe Ar,D y I.
		ValidadorEspacios((fila-2),(columna-1));
		if(Matriz2[fila-2][columna-1] !='*' && validador == 0){
			Matriz1[fila-2][columna-1]=' '; //Arriba.
			ColocarPistas();
			Abrir((fila-2),(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] !='*' && validador == 0){
			Matriz1[fila-1][columna]=' '; //Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
		ValidadorEspacios((fila-1),(columna-2));
		if(Matriz2[fila-1][columna-2] !='*' && validador == 0){
			Matriz1[fila-1][columna-2]=' '; //Izquierda.
			ColocarPistas();
			Abrir((fila-1),(columna-2));
		}
	}
	if((fila-1)<(f-1) && (fila-1)>0 && 0 == (columna-1)){ // Recuadros Centrales Izquierda => Existe Ar,Ab y D.
		ValidadorEspacios((fila-2),(columna-1));
		if(Matriz2[fila-2][columna-1] !='*' && validador == 0){
			Matriz1[fila-2][columna-1]=' '; //Arriba.
			ColocarPistas();
			Abrir((fila-2),(columna-1));
		}
		ValidadorEspacios(fila,(columna-1));
		if(Matriz2[fila][columna-1] !='*' && validador == 0){
			Matriz1[fila][columna-1]=' '; //Abajo.
			ColocarPistas();
			Abrir(fila,(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] !='*' && validador == 0){
			Matriz1[fila-1][columna]=' '; //Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
	}
	if((fila-1)<(f-1) && (fila-1)>0 && (c-1) == (columna-1)){ // Recuadros Centrales Derecha => Existe Ar,Ab,I,DIS y DII.
		ValidadorEspacios((fila-2),(columna-1));
		if(Matriz2[fila-2][columna-1] !='*' && validador == 0){
			Matriz1[fila-2][columna-1]=' '; //Arriba.
			ColocarPistas();
			Abrir((fila-2),(columna-1));
		}
		ValidadorEspacios(fila,(columna-1));
		if(Matriz2[fila][columna-1] !='*' && validador == 0){
			Matriz1[fila][columna-1]=' '; //Abajo.
			ColocarPistas();
			Abrir(fila,(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] != '*' && validador == 0){
			Matriz1[fila-1][columna]=' '; //Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
	}
	if((columna-1)<(c-1) && (columna-1)>0 && 0 == (fila-1)){ // Recuadros Centrales Arriba => Existe Ab,I y D.
		ValidadorEspacios(fila,(columna-1));
		if(Matriz2[fila][columna-1] !='*' && validador == 0){
			Matriz1[fila][columna-1]=' '; //Abajo.
			ColocarPistas();
			Abrir(fila,(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] !='*' && validador == 0){
			Matriz1[fila-1][columna]=' '; //Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
		ValidadorEspacios((fila-1),(columna-2));
		if(Matriz2[fila-1][columna-2] !='*' && validador == 0){
			Matriz1[fila-1][columna-2]=' '; //Izquierda.
			ColocarPistas();
			Abrir((fila-1),(columna-2));
		}
	}
	if((columna-1)>0 && (fila-1)>0 && (columna-1)<(c-1) && (fila-1)<(f-1)){ // Recuadros centrales de la Matriz.
		ValidadorEspacios((fila-2),(columna-1));
		if(Matriz2[fila-2][columna-1] !='*' && validador == 0){
			Matriz1[fila-2][columna-1]=' ';//Arriba.
			ColocarPistas();
			Abrir((fila-2),(columna-1));
		}
		ValidadorEspacios(fila,(columna-1));
		if(Matriz2[fila][columna-1] !='*' && validador == 0){
			Matriz1[fila][columna-1]=' '; //Abajo.
			ColocarPistas();
			Abrir(fila,(columna-1));
		}
		ValidadorEspacios((fila-1),columna);
		if(Matriz2[fila-1][columna] !='*' && validador == 0){
			Matriz1[fila-1][columna]=' '; //Derecha.
			ColocarPistas();
			Abrir((fila-1),columna);
		}
		ValidadorEspacios((fila-1),(columna-2));
		if(Matriz2[fila-1][columna-2] !='*' && validador == 0){
			Matriz1[fila-1][columna-2]=' '; //Izquierda.
			ColocarPistas();
			Abrir((fila-1),(columna-2));
		}
	}
	return;
}

void Espacios(int fila, int columna){
	if(Matriz2[fila-1][columna-1] == ' ' && validador == 0){
		Abrir(fila,columna);
		ColocarPistas();
	}
	return;
}

int Errores(int fila, int columna){
	if((fila-1)>(f-1)){ // Evitar errores de coordenadas del usuario fuera de la matriz.
	    return 1;
	 }
	 else if((columna-1)>(c-1)){ // Evitar errores de coordenadas del usuario fuera de la matriz.
		 return 1;
	 }
	 else if((fila-1)<0){ // Evitar errores de coordenadas del usuario fuera de la matriz.
		 return 1;
	 }
	 else if((columna-1)<0){ // Evitar errores de coordenadas del usuario fuera de la matriz.
	    	return 1;
	 }
	 else if((fila-1)>(f-1) && (columna-1)>(c-1)){ // Evitar errores de coordenadas del usuario fuera de la matriz.
		 return 1;
	 }
	 else if((fila-1)<0 && (columna-1)<0 ){ // Evitar errores de coordenadas del usuario fuera de la matriz.
		 return 1;
	 }
	 else{
		 return 0;
	 }
}

void Jugadas(){
	int fila, columna,i,j;
	printf("\n");
	printf("\n");
	printf("Inserte la fila en que desea realizar su jugada\n");
	scanf("%d", &fila);
	fflush( stdin );// Limpia el buffer del teclado.
	printf("Inserte la columna en que desea realizar su jugada\n");
	scanf("%d", &columna);
	fflush( stdin );// Limpia el buffer del teclado.
	printf("¿Que clase de jugada desea realizar?\n");
	printf("\n");
	fflush( stdin );// Limpia el buffer del teclado.
	printf("Presione O para descubrir la casilla seleccionada.\n");
	printf("Presione X para colocar una marca sobre la casilla seleccionada.\n");
	printf("                     (O/X)\n");
	scanf(" %c", &jugada);

	if(jugada == 'O' || jugada == 'o'){
		int error = 0;
		error = Errores(fila,columna);
	   if(error==1){
			printf("\n");
			printf("Lo lamento, jugada invalida, coordenadas fuera del tablero.\n");
			printf("Vuelva a intentarlo.\n");
			printf("\n");
			Jugadas();
		}
		else{
			if(Matriz2[fila-1][columna-1]!='*'){
				Matriz1[fila-1][columna-1]=' ';
				ValidadorEspacios(fila,columna);
				Espacios(fila,columna);
				ColocarPistas();
				printf("\n");
				for(i=0;i<f;i++){
					for(j=0;j<c;j++){
						printf("[ %c ]", Matriz1[i][j] );
					}
					printf("\n");
				}
				printf("\n");
				if(DetGanador()==0){
					Jugadas();
				}
			}
			else if(Matriz2[fila-1][columna-1]=='*'){
				Matriz1[fila-1][columna-1]='*';
				printf("\n");
				for(i=0;i<f;i++){
					for(j=0;j<c;j++){
						printf("[ %c ]", Matriz1[i][j] );
					}
					printf("\n");
				}
				printf("\n");
				printf("Lo lamento humano has pisado una mina y has perdido tu vida.\n");
				return;
			}
			else{
				printf("Algo malo ha sucedido, reinicie el juego por favor.\n");
				return;
			}
		}
	}
	else if(jugada == 'X' || jugada == 'x'){
		Matriz1[fila-1][columna-1]='X';
		for(i=0;i<f;i++){
			for(j=0;j<c;j++){
				printf("[ %c ]", Matriz1[i][j] );
			}
			printf("\n");
		}
		printf("\n");
		Jugadas();
	}
	else{
		printf("Por favor vuelva a ingresar los datos\n");
		Jugadas();
	}
	return;
}

void PrimeraJugada(){
	int fila, columna,i,j;
   char** Matriz1 = CrearMatriz1();
	printf("\n");
	printf("\n");
	printf("     ¿Podras esquivar todas las minas?\n");
	printf("Inserte la fila en que desea realizar su jugada\n");
	scanf("%d", &fila);
	fflush( stdin );// Limpia el buffer del teclado.
	printf("Inserte la columna en que desea realizar su jugada\n");
	scanf("%d", &columna);
	fflush( stdin );// Limpia el buffer del teclado.
	printf("¿Que clase de jugada desea realizar?\n");
	printf("\n");
	fflush( stdin );// Limpia el buffer del teclado.
	printf("Presione O para descubrir la casilla seleccionada.\n");
	printf("Presione X para colocar una marca sobre la casilla seleccionada.\n");
	printf("                     (O/X)\n");
	scanf(" %c", &jugada); // funcionará siempre y cuando vaya un espacio entre " y %c  => " %c"

	if(jugada == 'O' || jugada == 'o'){
		int error = 0;
	   error = Errores(fila,columna);
	   if(error==1){
			printf("\n");
	    	printf("Lo lamento, jugada invalida, coordenadas fuera del tablero.\n");
	    	printf("Vuelva a intentarlo.\n");
	    	printf("\n");
	    	PrimeraJugada();
	   }
	   else{
			Matriz1[fila-1][columna-1]=' ';
		   CrearMatriz2(f,c,m);
		   ValidadorEspacios(fila,columna);
		   Espacios(fila,columna);
		   ColocarPistas();
			printf("\n");
			for(i=0;i<f;i++){
				for(j=0;j<c;j++){
					printf("[ %c ]", Matriz1[i][j] );
				}
				printf("\n");
			}
			printf("\n\n");
			if(DetGanador()==0){
				Jugadas();
			}
		}
	}
	else if(jugada == 'X' || jugada == 'x'){
		Matriz1[fila-1][columna-1]='X';
		for(i=0;i<f;i++){
			for(j=0;j<c;j++){
				printf("[ %c ]", Matriz1[i][j] );
			}
		}
		PrimeraJugada();
	}
	else{
		printf("Por favor vuelva a ingresar los datos\n");
		PrimeraJugada();
		}
	return;
}
