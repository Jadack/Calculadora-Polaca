#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NODO{
	int Value;
	struct NODO *Puntero;
};
int PassEnte( char Cadena[20] ){
	int lc=strlen(Cadena), Num=0, k;
	for( k=0; k<lc; k++ ){
		Num *= 10;
		Num += Cadena[k]-48;
	};

	return Num;
};
void InsDat( struct NODO **Pila, int Nume ){
	struct NODO *Temp = (struct NODO *) malloc(sizeof(struct NODO));
	Temp->Value		= Nume;
	Temp->Puntero	= *Pila;
	*Pila			= Temp;
};
int ExtDat( struct NODO **Pila ){
	struct NODO *Siguiente;
	int Resp;
	Resp = (*Pila)->Value;
	Siguiente = (*Pila)->Puntero;
	free(*Pila);
	*Pila = Siguiente;
	return Resp;
};
void LibRAM( struct NODO **List ){
	struct NODO *Act, *Siguiente;
	Act = *List;
	while(Act != NULL){
		Siguiente = Act->Puntero;
		free(Act);
		Act = Siguiente;
	};
	*List = NULL;
};

main(){
system("Color 0E");
	struct NODO *Pila;
	char Val[20];
	int X, Y;
	printf( "\nNotacion Polaca\n\n" );
	printf( "Nota:\nEscriba Enter o Espacio para agregar nuevos operadores o cifras e Igual (=) para recibir el resultado.\n\n\n" );
	printf( "Indique la expresion:\n\n" );
	
	do{
		scanf( "%s", Val );
		switch( Val[0] ){
			case '+':
				X = ExtDat( &Pila );
				Y = ExtDat( &Pila );
				InsDat( &Pila, X + Y );
			break;
			case '-':
				X = ExtDat( &Pila );
				Y = ExtDat( &Pila );
				InsDat( &Pila, X - Y );
			break;
			case '*':
				X = ExtDat( &Pila );
				Y = ExtDat( &Pila );
				InsDat( &Pila, X * Y );
			break;
			case '/':
				X = ExtDat( &Pila );
				Y = ExtDat( &Pila );
				InsDat( &Pila, X / Y );
			break;
			case '=':
				printf( "\nEl resultado es: %i\n\n", ExtDat( &Pila ));
			break;
			default:
				InsDat( &Pila, PassEnte(Val) );
			break;
		};

	} while( Val[0] != '=' );
	system("pause");
};
