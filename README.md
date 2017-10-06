# Buscaminas

Se busca crear un Buscaminas: El Buscaminas es un juego en el cual un jugador intenta despejar un tablero descubriendo todas las
casillas  en  las  que  no  se encuentran  minas  o  bombas.  Para  esto  el juego  proporciona  unas  pistas:
cuando  el  jugador  descubre  una  casilla  en  la  que  no se  encuentra  una  bomba,  el  juego  revela  un número, el cual
indica la cantidad de minas alrededor de aquella casilla. El jugador tiene la posibilidad
de descubrir una casilla o marcarla como posible mina.

Características del Buscaminas deseado:
   Entrada:
      Matriz: cantidad de filas y columnas.
      Minas: cantidad de minas que habrá en el tablero.

         Generación de tablero con minas y números "pistas";
         Esto debe ser guardado en un archivo de texto llamado "solución.out".

      Tablero siempre debe ser generado después de la primera jugada del usuario para así asegurar que haya una segunda jugada.

   Salida:
      Tablero debe ser mostrado por consola con casillas ocultas al usuario.

   Entrada:
      Jugadas por coordenadas: Número de fila y Número de columna + tipo de jugada.
      Tipo de jugada:
         O (letra "o" en mayúsculas, no cero): Descubrir casilla.
         X (letra "x" en mayúsculas): Poner bandera indicando que allí hay una mina.

   Salida:
      Tablero con la modificación realizada.

         En caso que el jugador descubra una casilla en la que no se encuentre una mina y que además
         no tenga ninguna mina alrededor, se debe marcar con un espacio vacío la casilla y se deben
         descubrir las casillas que tiene alrededor.


El juego termina si el jugador descubre una mina, perdiendo el juego, o
si logra descubrir todas las casillas sin minas del tablero.


Para realizar este proyecto se necesitará aprender:
		Trabajar con matrices.
		Trabajar con archivos de texto.
		Uso de alguna función o crear un algoritmo que genere secuencias aleatorias.
		Otros.

Se quitaron todos los tildes de las palabras por conflictos con cmd de Windows.
Además de ciertos caracteres que también generan conflictos.
